#pragma once

// Puts Actors together with their components
class ActorFactory
{
public:
	ActorFactory();
	~ActorFactory();

	// This function can be overridden by a subclass so you can create game-specific C++ components
	//virtual StrongActorComponentPtr VCreateComponent(TIXmlElement* pData);

protected:

	//GenericObjectFactory<ActorComponent, ComponentId> m_componentFactory;


private:
	ActorId m_lastActorId;

	ActorId GetNextActorId(void) { ++m_lastActorId; return m_lastActorId; }

};