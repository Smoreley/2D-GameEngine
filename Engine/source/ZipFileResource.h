#pragma once
//#include "ZipFile.h"
class ZipFile;

// Implements the IResourceFile interface with a ZipFile
class ResourceZipFile : public IResourceFile
{
public:
	ResourceZipFile(const wstring resourceFileName) { m_pZipFile = NULL; m_resourceFileName = resourceFileName; }
	virtual ~ResourceZipFile();

	virtual bool VOpen();
	virtual int VGetRawResourceSize(const Resource& r);
	virtual int VGetRawResource(const Resource& r, char* buffer);
	virtual int VGetNumResources() const;
	virtual string VGetResourceName(int num) const;
	virtual bool VUsingDevelopmentDirectories(void) const { return false; }

private:
	ZipFile* m_pZipFile;
	wstring m_resourceFileName;

};

// This class fakes a ZipFile from a normal directory. (Used in the editor)
class DevResourceZipFile : public ResourceZipFile
{
public:
	enum Mode
	{
		DEVELOPMENT,
		EDITOR
	};

	Mode m_mode;
	wstring m_assetDirectory;
	//vector<WIN32_FIND_DATA> m_assetFileInfo;
	ZipContentsMap m_directoryContentsMap;

	DevResourceZipFile(const wstring resFileName, const Mode mode);

	virtual bool VOpen();
	virtual int VGetRawResourceSize(const Resource& r);
	virtual int VGetRawResource(const Resource& r, char* buffer);
	virtual int VGetNumResource() const;
	virtual string VGetResourceName(int num) const;
	virtual bool VUsingDevelopmentDirectories(void) const { return true; }

	int Find(const string& path);

protected:
	void ReadAssetDirectory(wstring fileSpec);

};