#pragma once
namespace Beserk {

	/* Actor Factory */
	// Puts Actors together with their components
	class ActorFactory
	{
	public:
		ActorFactory(void);

		StrongActorPtr CreateActor(const char* actorResource,
			tinyxml2::XMLElement* overrides,
			const ActorId serversActorId);

		StrongActorPtr CreateActor(const char* actorResource, const ActorId id);		// Creates and actor

		virtual StrongActorComponentPtr VCreateComponent(XMLElement* pData);
		void ModifyActor(StrongActorPtr pActor, XMLElement* overrides);

	protected:
		GenericObjectFactory<ActorComponent, ComponentId> m_componentFactory;

	private:
		ActorId m_lastActorId;

		ActorId GetNextActorId(void) { ++m_lastActorId; return m_lastActorId; }

	};
}	// End-of Namespace