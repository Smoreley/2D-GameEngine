#pragma once
#include "BeserkStd.h"

class ZipFile;

// Implements the IResourceFile interface with a ZipFile
class ResourceZipFile : public IResourceFile
{
public:
	ResourceZipFile(const string resourceFileName) { m_pZipFile = NULL; m_resourceFileName = resourceFileName; }
	virtual ~ResourceZipFile();

	virtual bool VOpen();
	virtual int VGetRawResourceSize(const Resource& r);
	virtual int VGetRawResource(const Resource& r, char* buffer);
	virtual int VGetNumResources() const;
	virtual string VGetResourceName(int num) const;
	virtual bool VUsingDevelopmentDirectories(void) const { return false; }

private:
	ZipFile* m_pZipFile;
	string m_resourceFileName;

};

class DevResourceZipFile : public ResourceZipFile
{
public:
	enum Mode
	{
		DEVELOPMENT,
		EDITOR
	};

	Mode m_mode;
	string m_assetDirectory;
	
	// m_assetFileInfo

protected:
	void ReadAssetDirectory(string fileSpec);

};