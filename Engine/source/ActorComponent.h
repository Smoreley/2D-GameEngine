#pragma once

class ActorComponent
{
public:
	virtual ~ActorComponent() { m_pOwner.reset(); }

	/* Interface Functions */
	virtual bool VInit(XMLElement* pData) = 0;
	virtual void VPostInit(void) {}
	virtual void VUpdate(DeltaTime dt) {}
	virtual void VOnChanged(void) {}

	virtual void VGenerateXML(XMLDocument* pDoc) = 0;		// For the editor (to create its own XML of this component)

	virtual ComponentId VGetId(void) const { return GetIdFromName(VGetName()); }
	virtual const char *VGetName() const = 0;

	static ComponentId GetIdFromName(const char* componentStr) {
		// TODO: Implement Hashing to get Id from Name

		// Simple Hash
		hash<string> ptr_hash;
		return ptr_hash(componentStr);
	}

protected:
	StrongActorPtr m_pOwner;

private:
	bool save_flag;

	void SetOwner(StrongActorPtr pOwner) { m_pOwner = pOwner; }

	friend class ActorFactory;
};