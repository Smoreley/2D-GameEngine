#include "BeserkStd.h"
#include "ZipFile.h"

#include <zlib\zlib.h>

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

bool ZipFile::Init(const string& resourceFileName) {
	End();


	return EXIT_SUCCESS;
}

void ZipFile::End() {
	m_ZipContentsMap.clear();
	SAFE_DELETE_ARRAY(m_pDirData);
	m_nEntries = 0;
}