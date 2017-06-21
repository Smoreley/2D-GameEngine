#pragma once
#include "BeserkStd.h"
#include "AxisAllignedBox.h"

namespace Beserk {

	typedef vector<shared_ptr<ISceneNode>> SceneNodeList;

	// Scene Node Properties
	class SceneNodeProperties
	{
	public:
		SceneNodeProperties(void);
		ActorId const& GetActorId() const { return m_actorId; }
		mat4 const& ToWorld() const { return m_toWorld; }
		mat4 const& FromWorld() const { return m_fromWorld; }
		void Transform(mat4* toWorld, mat4* fromWorld) const;

		const char* Name() const { return m_name.c_str(); }
		//bool HasAlpha() const { return m_material.HasAlpha(); }
		//float Alpah() const { return m_material.GetAlpha(); }
		//AlphaType AlphType() const { return m_alphaType; }

		//RenderPass RenderPass() const { return m_renderPass; }
		//float Radius() const { return m_radius; }

		//Material GetMaterial() const { return m_material; }

	protected:
		ActorId m_actorId;
		string m_name;
		mat4 m_toWorld, m_fromWorld;
		float m_radius;
		
		//RenderPass m_renderPass;
		//Material m_Material;
		//AlphaType m_alphaType;

		//void SetAlpha(const float alpha) { m_AlphaType = AlphaMaterial; m_Material.SetAlpha(alpha); }

	private:
		friend class SceneNode;
	};


	// Scene Node
	class SceneNode : public ISceneNode {
	public:
		//SceneNode(ActorId actorId, WeakBasRenderComponentPtr renderComponent,
		//	RenderPass renderPass, const mat4* to, const mat4* from = nullptr);

		virtual ~SceneNode();

		virtual const SceneNodeProperties* const VGet() const { return &m_props; }
		virtual void VSetTransform(const mat4* toWorld, const mat4* fromWorld = nullptr);


		virtual bool VPreRender(Scene* pScene);
		virtual bool VIsVisible(Scene* pScene) const;
		//virtual bool VRender(Scene* pScene) { return S_OK; }
		virtual bool VRenderChildren(Scene* pScene);
		virtual bool VPostRender(Scene* pScene);

		virtual bool VAddChildren(shared_ptr<ISceneNode> child);
		virtual bool VRemoveChild(ActorId id);

		virtual bool VOnLostDevice(Scene* pScene);
		//virtual bool VPick(Scene* pScene, RayCast* pRayCast);

		//void SetAlpha(float alpha);
		//float GetAlpha() const { return m_props.Alpha(); }

		//vec3 GetPosition() const { return m_props.m_toWorld.GetPosition(); }
		//void SetPosition(const vec3& pos) { m_props.m_toWorld.SetPosition)pos); }

		//const vec3 GetWorldPosition() const;

		//vec3 GetDirection() const { return m_props.m_toWorld.GetDirection(); }

		//void SetRadius(const float radius) { m_props.m_radius = radius; }
		//void SetMaterial(const Material& mat) { m_props.m_material = mat; }


		//void SetVisible(bool vVisible, bool cascade = true);

	protected:

		SceneNodeList m_Children;
		SceneNode* m_pParent;
		SceneNodeProperties m_props;
		//WeakBaseRenderComponentPtr m_renderComponent;

		AxisAllignedBox m_WorldAABB;

	private:
		friend class Scene;

	};

	class Scene;
	class SceneNodeProperties;


	// Abstract SceneNode interface
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