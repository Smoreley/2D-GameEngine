#include "BeserkStd.h"
#include "ZipFile.h"

//#include <cctype>
#include <zlib\zlib.h>

namespace Beserk {

	typedef unsigned long dword;
	typedef unsigned short word;
	typedef unsigned char byte;

	struct ZipFile::TZipLocalHeader
	{
		enum {
			SIGNATURE = 0x04034b50,
		};
		dword sig;
		word version;
		word flag;
		word compression;
		word modTime;
		word modDate;
		dword crc32;
		dword cSize;
		dword ucSize;
		word fnameLen;
		word xtraLen;
	};

	struct ZipFile::TZipDirHeader
	{
		enum {
			SIGNATURE = 0x06054b50
		};
		dword   sig;
		word    nDisk;
		word    nStartDisk;
		word    nDirEntries;
		word    totalDirEntries;
		dword   dirSize;
		dword   dirOffset;
		word    cmntLen;
	};

	struct ZipFile::TZipDirFileHeader
	{
		enum {
			SIGNATURE = 0x02014b50,
		};
		dword sig;
		word verMade;
		word verNeeded;
		word flag;
		word compression;
		word modTime;
		word modDate;
		dword crc32;
		dword cSize;
		dword ucSize;
		word fnameLen;
		word xtraLen;
		word cmntLen;
		word diskStart;
		word intAttr;
		dword extAttr;
		dword hdrOffset;

		char* GetName() const { return (char*)(this + 1); }
		char* GetExtra() const { return GetName() + fnameLen; }
		char* GetComment() const { return GetExtra() + xtraLen; }
	};

	bool ZipFile::Init(const wstring& resourceFileName) {
		End();

		_wfopen_s(&m_pFile, resourceFileName.c_str(), _T("rb"));
		if (!m_pFile)
			return EXIT_FAILURE;

		TZipDirHeader dh;
		fseek(m_pFile, -(int)sizeof(dh), SEEK_END);
		long dhOffSet = ftell(m_pFile);
		memset(&dh, 0, sizeof(dh));
		fread(&dh, sizeof(dh), 1, m_pFile);

		// Check
		if (dh.sig != TZipDirHeader::SIGNATURE)
			return EXIT_FAILURE;

		// Go to the beginning of the directory
		fseek(m_pFile, dhOffSet - dh.dirSize, SEEK_SET);

		// Allocate the data buffer, and read the whole thing
		m_pDirData = new char[dh.dirSize + dh.nDirEntries * sizeof(*m_papDir)];
		if (!m_pDirData)
			return EXIT_FAILURE;
		memset(m_pDirData, 0, dh.dirSize + dh.nDirEntries * sizeof(*m_papDir));
		fread(m_pDirData, dh.dirSize, 1, m_pFile);

		// Process each entry
		char *pfh = m_pDirData;
		m_papDir = (const TZipDirFileHeader **)(m_pDirData + dh.dirSize);

		bool success = true;

		for (int i = 0; i < dh.nDirEntries && success; i++) {
			TZipDirFileHeader& fh = *(TZipDirFileHeader*)pfh;

			// Store address of nth file for quick access
			m_papDir[i] = &fh;

			// Check the directory entry integrity
			if (fh.sig != TZipDirFileHeader::SIGNATURE) {
				success = false;
			}
			else {
				pfh += sizeof(fh);

				// Convert UNIX slashes to DOS backslashes
				for (int j = 0; j < fh.fnameLen; j++) {
					if (pfh[j] == '/')
						pfh[j] = '\\';
				}

				char fileName[_MAX_PATH];
				memcpy(fileName, pfh, fh.fnameLen);
				fileName[fh.fnameLen] = 0;
				_strlwr_s(fileName, _MAX_PATH);
				string spath = fileName;
				m_ZipContentsMap[spath] = i;

				// Skip name, extra and comment fields
				pfh += fh.fnameLen + fh.xtraLen + fh.cmntLen;
			}
		}

		if (!success) {
			SAFE_DELETE_ARRAY(m_pDirData);
		}
		else {
			m_nEntries = dh.nDirEntries;
		}

		return success;
	}

	void ZipFile::End() {

		m_ZipContentsMap.clear();
		SAFE_DELETE_ARRAY(m_pDirData);
		m_nEntries = 0;

	}

	int ZipFile::Find(const string& path) const {

		string lowerCase = path;
		transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), (int(*)(int)) tolower);
		ZipContentsMap::const_iterator i = m_ZipContentsMap.find(lowerCase);
		if (i == m_ZipContentsMap.end()) {
			return -1;
		}
		return i->second;

	}

	string ZipFile::GetFileName(int i) const {

		string fileName = "";
		if (i >= 0 && i < m_nEntries) {
			char pszDest[_MAX_PATH];
			memcpy(pszDest, m_papDir[i]->GetName(), m_papDir[i]->fnameLen);
			pszDest[m_papDir[i]->fnameLen] = '\0';
			fileName = pszDest;
		}
		return fileName;

	}

	int ZipFile::GetFileLen(int i) const {

		if (i < 0 || i >= m_nEntries) {
			return -1;
		}
		else {
			return m_papDir[i]->ucSize;
		}

	}

	bool ZipFile::ReadFile(int i, void *pBuf) {
		if (pBuf == NULL || i < 0 || i >= m_nEntries) {
			return false;
		}

		// Go to the file and read the local header
		fseek(m_pFile, m_papDir[i]->hdrOffset, SEEK_SET);
		TZipLocalHeader h;

		memset(&h, 0, sizeof(h));
		fread(&h, sizeof(h), 1, m_pFile);
		if (h.sig != TZipLocalHeader::SIGNATURE)
			return false;

		// Skip extra fields
	}

	bool ZipFile::ReadLargeFile(int i, void* pbuf, void(*progressCallback)(int, bool &)) {


		bool ret = true;


		return ret;
	}

}	// End-of Namespace