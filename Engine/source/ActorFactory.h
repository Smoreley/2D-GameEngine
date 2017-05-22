#pragma once

template <class BaseType, class SubType>
BaseType* GenericObjectCreationFunction(void) { return new SubType; }

/* Generic Factory */
template <class BaseClass, class IdType>
class GenericObjectFactory
{
public:

	template<class SubClass>
	bool Register(IdType id) {
		auto findIt = m_creationFunctions.find(id);
		if (findIt == m_creationFunctions.end()) {
			m_creationFunctions[id] = &GenericObjectCreationFunction<BaseClass, SubClass>;
			return true;
		}
		return false;
	}

	BaseClass* Create(IdType id) {
		auto findIt = m_creationFunctions.find(id);
		if (findIt != m_creationFunctions.end()) {
			ObjectCreationFunction pFunc = findIt->second;
			return pFunc();
		}
		return NULL;
	}


private:
	typedef BaseClass* (*ObjectCreationFunction)(void);
	map<IdType, ObjectCreationFunction> m_creationFunctions;

};

/* Actor Factory */
// Puts Actors together with their components
class ActorFactory
{
public:
	ActorFactory(void);

	StrongActorPtr CreateActor(const char* actorResource,
		tinyxml2::XMLElement* overrides,
		const ActorId serversActorId);

	StrongActorPtr CreateActor(const ActorId id);		// My Testing one

	virtual StrongActorComponentPtr VCreateComponent(XMLElement* pData);
	void ModifyActor(StrongActorPtr pActor, XMLElement* overrides);

protected:
	GenericObjectFactory<ActorComponent, ComponentId> m_componentFactory;

private:
	ActorId m_lastActorId;

	ActorId GetNextActorId(void) { ++m_lastActorId; return m_lastActorId; }

};