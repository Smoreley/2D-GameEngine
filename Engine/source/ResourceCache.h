#pragma once
class ResourceHandle;
class ResourceCache;

/* Resource Extra Data */
class IResourceExtraData
{
public:
	virtual std::string VToString() = 0;
};

/* Class Resource */
class Resource
{
public:
	std::string m_name;
	Resource(const std::string &name);
};

/* Resource Handle */
class ResourceHandle
{
public:
	ResourceHandle(Resource& resource, char* buffer, unsigned int size, ResourceCache* pResCache);
	virtual ~ResourceHandle();

	const std::string GetName() { return m_resource.m_name; }
	unsigned int GetSize() { return m_size; }
	char* GetBuffer() const { return m_buffer; }
	char* WriteableBuffer() { return m_buffer; }
	std::shared_ptr<IResourceExtraData> GetExtra() { return m_extra; }
	void SetExtra(std::shared_ptr<IResourceExtraData> extra) { m_extra = extra; }

protected:
	Resource m_resource;
	char* m_buffer;
	unsigned int m_size;
	std::shared_ptr<IResourceExtraData> m_extra;
	ResourceCache* m_pResCache;

private:
	friend class ResourceCache;
};

typedef std::list<std::shared_ptr<ResourceHandle>> ResourceHandleList;
typedef std::map<std::string, std::shared_ptr<ResourceHandle>> ResourceHandleMap;
typedef std::list<std::shared_ptr<IResourceLoader>> ResourceLoaderList;

/* Resource Cache */
class ResourceCache
{
public:
	//ResourceCache(const unsigned int sizeInMb, IResourceFile* file);
	virtual ~ResourceCache();

	bool Init();
	void RegisterLoader(std::shared_ptr<IResourceLoader> loader);
	std::shared_ptr<ResourceHandle> GetHandle(Resource* r);
	int Preload(const std::string pattern, void(*progressCallback)(int, bool &));
	std::vector<std::string> Match(const std::string pattern);
	void Flush(void);

	bool UsingDevelopmentDirectories() const;

protected:
	bool MakeRoom(unsigned int size);
	char* Allocate(unsigned int size);
	void Free(std::shared_ptr<ResourceHandle> gone);

	std::shared_ptr<ResourceHandle> Load(Resource* r);
	std::shared_ptr<ResourceHandle> Find(Resource* r);
	void Update(std::shared_ptr<ResourceHandle> handle);

	void FreeOneResource();
	void MemoryHasBeenFreed(unsigned int size);

private:
	friend class ResourceHandle;

	ResourceHandleList m_lru;
	ResourceHandleMap m_resources;
	ResourceLoaderList m_resourceLoaders;

	//IResourceFile* m_pFile;

	unsigned int	m_cacheSize;		// Total memory size
	unsigned int	m_allocared;		// Total memory allocated

};