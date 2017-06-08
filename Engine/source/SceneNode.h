#pragma once
#include "BeserkStd.h"

class Intersection {
	float m_fDist;
	float m_dwFace;
	float m_fBarycentric1, m_fBarycentric2;
	float m_tU, m_tV;

	ActorId m_actorId;
	vec3 m_worldLocation;
	vec3 m_actorLocation;
	vec3 m_normal;
};

typedef vector<Intersection> IntersectionArray;

class Raycast {
public:
	Raycast(vec2 point, int maxIntersections = 16);

	unsigned int m_maxIntersections;
	unsigned int m_countIntersections;
	bool m_allHits;
	vec2 point;

	vec3 m_rayDirection;
	vec3 m_rayOrigin;

	IntersectionArray m_intersections;

	void Sort();		// Sort the intersections

protected:

};


class SceneNode {

};



class Scene;
class SceneNodeProperties;

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