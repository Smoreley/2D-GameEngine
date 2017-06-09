#include "BeserkStd.h"
#include "ActorFactory.h"
#include "Actor.h"

/* Components */
#include "ActorComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"

namespace Beserk {

	ActorFactory::ActorFactory(void) {

		m_lastActorId = INVALID_ACTOR_ID;

		m_componentFactory.Register<TransformComponent>(ActorComponent::GetIdFromName(TransformComponent::g_name));
		m_componentFactory.Register<PhysicsComponent>(PhysicsComponent::GetIdFromName(PhysicsComponent::g_name));
	}

	StrongActorPtr ActorFactory::CreateActor(const char* actorResource, XMLElement* overrides, const ActorId id) {

		// Grab the root of the XML
		//XMLElement *pRoot = overrides->get;
		XMLNode* pRoot;

		if (!pRoot) {
			cout << "Failed to create actor from resource" << actorResource << endl;
			return StrongActorPtr();
		}

		StrongActorPtr rtn_val;
		return rtn_val;
	}

	StrongActorPtr ActorFactory::CreateActor(const char* actorResource, const ActorId id) {

		XMLElement* overrides;

		// Load XML from file
		XMLDocument actor_doc;
		actor_doc.LoadFile(actorResource);

		// Grab the root of the XML
		XMLElement *pRoot = actor_doc.RootElement();

		if (!pRoot) {
			cout << "Unable to get root element" << endl;
			return StrongActorPtr();
		}
		else {
			// Create actor instance
			ActorId newActorId = id;
			if (newActorId == INVALID_ACTOR_ID) {
				newActorId = GetNextActorId();
			}

			StrongActorPtr pActor(new Actor(newActorId));

			if (!pActor->Init(pRoot)) {
				cout << "Failed to initialize actor: " << actorResource << endl;
				return StrongActorPtr();
			}

			bool initial_transform_set = false;

			// Loop through each child element and load the component
			for (XMLElement* pNode = pRoot->FirstChildElement(); pNode; pNode = pNode->NextSiblingElement()) {
				StrongActorComponentPtr pComponent(VCreateComponent(pNode));

				if (pComponent) {
					pActor->AddComponent(pComponent);
					pComponent->SetOwner(pActor);
				}
				else {
					// Failed to create component, bail out early instead of building and actor with missing components
					return StrongActorPtr();
				}
			}

			//if (overrides) {
			//	ModifyActor(pActor, overrides);
			//}

			// Now that the actor is setup run the PostInit phase
			pActor->PostInit();
			return pActor;
		}
		return StrongActorPtr();

	}

	StrongActorComponentPtr ActorFactory::VCreateComponent(XMLElement* pData) {

		const char* name = pData->Value();
		StrongActorComponentPtr pComponent(m_componentFactory.Create(ActorComponent::GetIdFromName(name)));

		if (pComponent) {
			if (!pComponent->VInit(pData)) {
				cout << "Component failed to initialize: " << name << endl;
				return StrongActorComponentPtr();
			}
		}
		else {
			cout << "Couldn't find ActorComponent named: " << name << endl;
			return StrongActorComponentPtr();
		}
		return pComponent;

	}

	void ActorFactory::ModifyActor(StrongActorPtr pActor, XMLElement* overrides) {
		// Loop through each child element and load the component

	}
}	// End-of Namespace