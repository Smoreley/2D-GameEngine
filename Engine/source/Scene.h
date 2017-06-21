// The Scene Graph helps manage transformations
// and in rendering only relevant things.

#pragma once
#include "BeserkStd.h"
#include "SceneNode.h"

#include "EventManager.h"
#include "Events.h"

namespace Beserk {

	// Map that allows fast lookup of a scene node given an ActorId
	typedef map<ActorId, shared_ptr<ISceneNode>> SceneActorMap;
	typedef stack<mat4> MatrixStack;

	// Forward Declarations
	class CameraNode;
	class IRenderer;	// Temp

	class Scene {
	public:
		Scene(shared_ptr<IRenderer> renderer);
		virtual ~Scene();

		void OnRender();
		void OnRestore();
		void OnLostDevice();
		void OnUpdate(DeltaTime dt);
		shared_ptr<ISceneNode> FindActor(ActorId id);

		bool AddChild(ActorId id, shared_ptr<ISceneNode> child);
		bool RemoveChild(ActorId id);

		// Event Delegates
		void NewRenderComponentDelegate(IEventDataPtr pEventData);
		void ModifiedRenderComponentDelegate(IEventDataPtr pEventData);
		void DestroyActorDelegate(IEventDataPtr pEventData);
		void MoveActorDelegate(IEventDataPtr pEventData);

		void SetCamera(shared_ptr<CameraNode> camera) { m_camera = camera; }
		const shared_ptr<CameraNode> GetCamera() const { return m_camera; }

		void PushAndSetMatrix(const mat4 &toWorld) {

		}

		void PopMatrix() {
			m_matrixStack.pop();
			mat4 mat = GetTopMatrix();
			m_renderer->VSetWorldTransform(&mat);
		}

		const mat4 GetTopMatrix() {
			return static_cast<const mat4>(m_matrixStack.top);
			//return static_cast<const mat4>(*m_matrixStack->GetTop());
		}

		//LightManager* GetLightManager() { return m_LightManager; }
		//void AddAlphaSceneNode(AlphaSceneNode* asn) { m_AlphaSceneNode.push_back(asn); }
		//void Pick(RayCast* pRayCast) { return m_root->VPick(this, pRayCast); }
		shared_ptr<IRenderer> GetRenderer() { return m_renderer; }

	protected:
		shared_ptr<SceneNode> m_root;
		shared_ptr<CameraNode> m_camera;
		shared_ptr<IRenderer> m_renderer;

		MatrixStack m_matrixStack;
		//AlphaSceneNodes m_alphaSceneNodes;
		SceneActorMap m_actorMap;
		//LightManager* m_pLightManager;

		void RenderAlphaPass();

	private:

	};

}	// End-of Namespace