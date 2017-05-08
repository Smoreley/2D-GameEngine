#pragma once
class ResourceHandle;
class ResourceCache;


class IResourceExtraData
{
public:
	IResourceExtraData();
	~IResourceExtraData();

private:

};


class ResourceCache
{
public:
	friend class ResourceHandle;

	ResourceCache();
	~ResourceCache();

	unsigned int	m_cacheSize;		// Total memory size
	unsigned int	m_allocared;		// Total memory allocated

protected:


private:

};