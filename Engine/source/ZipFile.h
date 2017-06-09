#pragma once

namespace Beserk {

	typedef std::map<std::string, int> ZipContentsMap;

	class ZipFile
	{
	public:
		ZipFile() { m_nEntries = 0, m_pFile = NULL, m_pDirData = NULL; }
		virtual ~ZipFile() { End(); fclose(m_pFile); }

		bool Init(const wstring &resourceFileName);
		void End();

		int GetNumFiles() const { return m_nEntries; }
		string GetFileName(int i) const;
		int GetFileLen(int i) const;
		bool ReadFile(int i, void *pBuf);

		// Multi-threaded decompression
		bool ReadLargeFile(int i, void *pBuf, void(*progressCallback)(int, bool &));

		int Find(const string &path) const;

		ZipContentsMap m_ZipContentsMap;

	private:

		struct	TZipDirHeader;
		struct	TZipDirFileHeader;
		struct	TZipLocalHeader;

		FILE	*m_pFile;			// Zip File
		char	*m_pDirData;		// Raw Data Buffer
		int		m_nEntries;			// Number of Entries

		const TZipDirFileHeader **m_papDir;
	};

}	// End-of Namespace