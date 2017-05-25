#pragma once

typedef std::string ActorType;
typedef unsigned int ActorId;
typedef std::map<ComponentId, StrongActorComponentPtr> ActorComponents;

class Actor
{
public:
	/* Constructor Destructor */
	explicit Actor(const ActorId id);
	~Actor(void);

	bool Init(XMLElement* pData);
	void PostInit();
	void Destory();
	void Update(unsigned int deltaMs);

	const ActorComponents* GetComponents(void) { return &m_components; }
	void AddComponent(StrongActorComponentPtr pComponent);

	void GenerateXML();

	// Accessors
	ActorId GetId(void) const { return m_id; }
	ActorType GetTyoe(void) const { return m_type; }

	// Get Component by hashed-id
	template<class ComponentType>
	weak_ptr<ComponentType> GetComponent(ComponentId id) {
		ActorComponents::iterator findIt = m_components.find(id);

		if (findIt != m_components.end()) {
			StrongActorComponentPtr pBase(findIt->second);
			shared_ptr<ComponentType> pSub(static_pointer_cast<ComponentType>(pBase));
			weak_ptr<ComponentType> pWeakSub(pSub);
			return pWeakSub;
		}
		else {
			return weak_ptr<ComponentType>();
		}
	}

	// Get Component by name
	template<class ComponentType>
	weak_ptr<ComponentType> GetComponent(const char* name) {
		ComponentId id = ActorComponent::GetIdFromName(name);
		return GetComponent<ComponentType>(id);
	}

private:
	ActorId m_id;
	ActorComponents m_components;
	ActorType m_type;

	std::string m_resource;

	friend class ActorFactory;
};




/* Old implementation of actor*/
class Old_Actor
{
public:

	const ActorComponents* GetComponents() { return &m_components; }

	void AddComponent(StrongActorComponentPtr pComponent);


	// Template Functions for retrieving components
	template <class ComponentType>
	weak_ptr<ComponentType> GetComponent(ComponentId id) {
		ActorComponents::iterator find_it = m_components.find(id);
		if (find_it != m_components.end()) {
			StrongActorComponentPtr pBase(find_it->second);
			shared_ptr<ComponentType> pSub(static_pointer_cast<ComponentType>(pBase));
			weak_ptr<ComponentType> pWeakSub(pSub);	// Convert strong pointer to weak pointer
			return pWeakSub;								// Return the weak pointer
		}
		else {
			return std::weak_ptr<ComponentType>();
		}
	}	// End-of Template

	// Template for getting component by name
	template <class ComponentType>
	weak_ptr<ComponentType> GetComponent(const char* name) {
		ComponentId id = ActorComponent::GetIdFromName(name);
		ActorComponent::iterator findIt = m_components.find(id);

		if (findIt != m_components.end()) {
			StrongActorComponentPtr pBase(findIt->second);
			shared_ptr<ComponentType> pSub(static_pointer_cast<ComponentType>(pBase));	// Cast to subclass version of pointer
			weak_ptr<ComponentType> pWeakSub(pSub);					// Convert strong pointer to weak pointer
			return pWeakSub;
		}
		else {
			return weak_ptr<ComponentType>();
		}
	}	// End-of Template

private:
	ActorId m_id;					// Unique id for the actor
	ActorComponents m_components;	// All components this actor has
	ActorType m_type;

	std::string m_resource;			// The xml filre from which this actor was initialized

	/* UE4 Implementation */
	
	//// Each actor can run at different time speed. The DeltaTime for a frame is multiplied this CustomTimeDilation for this actor's tick
	//float customTimeDilation;
	//// Allows us to only see this Actor in the Editor, and not in the actual game
	//uint8 bHidden;
	//// Colon :  bitfield specification telling how many bits to use (in this case only 1)
	//uint8 bActorEnableCollision : 1;

};