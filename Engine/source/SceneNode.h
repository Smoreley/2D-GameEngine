#pragma once
#include "BeserkStd.h"
#include "AxisAllignedBox.h"

namespace Beserk {

	class SceneNode {
	public:

		void SetVisible(bool vVisible, bool cascade = true);

	protected:

		AxisAllignedBox m_WorldAABB;

	private:


	};

	class Scene;
	class SceneNodeProperties;


	/* Abstract SceneNode interface */
	class ISceneNode {
	public:
		virtual const SceneNodeProperties* const VGet() const = 0;
		virtual void VSetTransform(const mat4x4* toWorld, const mat4x4* fromWorld = nullptr) = 0;
		virtual bool VOnUpdate(Scene* pScene, DeltaTime const elapsedMs) = 0;
		virtual bool VOnRestore(Scene* pScene) = 0;

		virtual bool VPreRender(Scene* pScene) = 0;
		virtual bool VRender(Scene* pScene) = 0;
		virtual bool VRenderChildren(Scene* pScene) = 0;
		virtual bool VPostRender(Scene* pScene) = 0;

		virtual bool VIsVisable(Scene* pScene) const = 0;
		virtual bool VAddChild(shared_ptr<ISceneNode> child) = 0;
		virtual bool VRemoveChild(ActorId id) = 0;
		virtual bool VOnLostDevice(Scene* pScene) = 0;
		//virtual bool VPick(Scene* pScene, RayCast* pRayCast) = 0;

		virtual ~ISceneNode() {}
	};

}	// End-of Namespace