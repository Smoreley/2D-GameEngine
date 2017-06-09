#include "BeserkStd.h"

#include "ResourceCache.h"
#include "ZipFile.h"

#include "ZipFileResource.h"

namespace Beserk {

	ResourceZipFile::~ResourceZipFile() {
		//SAFE_DELETE(m_pZipFile);
	}

	bool ResourceZipFile::VOpen() {

		m_pZipFile = new ZipFile;
		if (m_pZipFile) {
			return m_pZipFile->Init(m_resourceFileName.c_str());
		}
		return false;

	}

	int ResourceZipFile::VGetRawResourceSize(const Resource& r) {

		int resourceNum = m_pZipFile->Find(r.m_name.c_str());
		if (resourceNum == -1) {
			return -1;
		}
		return m_pZipFile->GetFileLen(resourceNum);

	}

	int ResourceZipFile::VGetRawResource(const Resource& r, char* buffer) {
		int size = 0;
		//optional
		// TODO: IMPLEMENT THIS LATER
		return size;

	}

	string ResourceZipFile::VGetResourceName(int num) const {

		string resName = "";
		if (m_pZipFile != NULL && num >= 0 && num < m_pZipFile->GetNumFiles()) {
			resName = m_pZipFile->GetFileName(num);
		}
		return resName;

	}


	DevResourceZipFile::DevResourceZipFile(const wstring resFileName, const Mode mode) : ResourceZipFile(resFileName) {

		m_mode = mode;


	}

}	// End-of Namespace