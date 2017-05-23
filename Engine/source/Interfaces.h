#pragma once
//#include "BeserkStd.h"

class Actor;
class ActorComponent;

typedef unsigned int ActorId;
typedef unsigned int ComponentId;

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
		const { return *lhs < *rhs; }
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