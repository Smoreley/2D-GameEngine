#pragma once

namespace Beserk {

	// Forward Declarations
	class Actor;
	class ActorComponent;

	typedef unsigned int ActorId;
	typedef unsigned int ComponentId;

	typedef unsigned int DeltaTime;

	const ActorId INVALID_ACTOR_ID = 0;
	const ComponentId INVALID_COMPONENT_ID = 0;

	typedef shared_ptr<Actor> StrongActorPtr;
	typedef weak_ptr<Actor> WeakActorPtr;

	typedef shared_ptr<ActorComponent> StrongActorComponentPtr;
	typedef weak_ptr<ActorComponent> WeakActorComponentPtr;

	template<class T>
	struct SortBy_SharedPtr_Content {

		// Overload function call 
		bool operator() (const shared_ptr<T> &lhs, const std::shared_ptr<T> &rhs)
			const {
			return *lhs < *rhs;
		}
	};


	//// Game Logic Interface
	//class IGameLogic
	//{
	//public:
	//	virtual WeakActorPtr VGetActor(const ActorId id) = 0;
	//
	//	virtual StrongActorPtr VCreateActor(const std::string &actorResource,
	//		TiXmlElement *overrides,
	//		const Mat4x4 *initialTransform = NULL,
	//		const ActorId serversActorId = INVALID_ACTOR_ID) = 0;
	//
	//private:
	//
	//};



	class Resource;
	class IResourceFile;
	class ResourceHandle;
	
	//
	// Resource Loader Interface
	//
	class IResourceLoader
	{
	public:
		virtual std::string VGetPattern() = 0;
		virtual bool VUseRawFile() = 0;
		virtual bool VDiscardRawBufferAfterLoad() = 0;
		virtual bool VAddNullZero() { return false; }
		virtual unsigned int VGetLoadedResourceSize(char* rawBuffer, unsigned int rawSize) = 0;
		virtual bool VLoadResource(char* rawBuffer, unsigned int rawSize, std::shared_ptr<ResourceHandle> handle) = 0;
	};

	//
	// Resoruce File Interface
	//
	class IResourceFile
	{
	public:
		virtual bool VOpen() = 0;
		virtual int VGetRawResourceSize(const Resource& r) = 0;
		virtual int VGetRawResource(const Resource& r, char* buffer) = 0;
		virtual int VGetNumResources() const = 0;
		virtual std::string VGetResourceName(int num) const = 0;
		virtual bool VUsingDevelopmentDirectories(void) const = 0;
		virtual ~IResourceFile() {}
	};

	class IRenderState
	{
	public:
		virtual std::string ostringstream() = 0;
	};

	// IRenderer
	class IRenderer
	{
	public:
		virtual void VSetBackgroundColor(int bgA, int bgR, int bgG, int bgB) = 0;
		virtual void VShutDown() = 0;
		virtual void VPreRender() = 0;
		virtual void VPostRender() = 0;

		//virtual void VCalcLighting(Lights* lights, int maximumLights) = 0;
		virtual void VSetWorldTransform(const mat4x4* m) = 0;
		virtual void VSetViewTransform(const mat4x4* m) = 0;
		virtual void VSetProjectionTransform(const mat4x4* m) = 0;

		virtual shared_ptr<IRenderState> VPrepareAlphaPass() = 0;
		virtual shared_ptr<IRenderState> VPrepareSkyBoxPass() = 0;
		//virtual void VDrawLine(const vec3& from, const vec3& to, const Color& color) = 0;
	};

}	// End-of Namespace