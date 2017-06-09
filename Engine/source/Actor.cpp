#include "BeserkStd.h"
#include "Actor.h"
#include "ActorComponent.h"

namespace Beserk {

	Actor::Actor(const ActorId id) {
		m_id = id;
		m_type = "Unknown";
	}

	Actor::~Actor() {
		cout << "Destroying Actor: " << m_id << endl;
		assert(m_components.empty());	// If this fires then the actor was destoryed with out calling Actor::Destroy
	}

	bool Actor::Init(XMLElement* pData) {

		cout << "Initializing Actor: " << m_id << endl;
		m_type = pData->Attribute("type");
		m_resource = pData->Attribute("resource");
		return true;

	}

	void Actor::PostInit() {

	}

	void Actor::Destory() {
		m_components.clear();
	}

	void Actor::Update(unsigned int deltaMs) {

	}

	void Actor::GenerateXML() {

		XMLDocument* pOutDoc;
		pOutDoc = new XMLDocument();

		// Actor Element
		XMLElement* pActorElement = pOutDoc->NewElement("Actor");

		// Set Attributes
		pActorElement->SetAttribute("type", m_type.c_str());
		pActorElement->SetAttribute("resource", m_resource.c_str());

		// Insert into document
		pOutDoc->InsertFirstChild(pActorElement);

		// Components
		for (auto it = m_components.begin(); it != m_components.end(); ++it) {
			StrongActorComponentPtr pComponent = it->second;
			pComponent->VGenerateXML(pOutDoc);
		}
		delete pOutDoc;

	}

	void Actor::AddComponent(StrongActorComponentPtr pComponent) {
		pair<ActorComponents::iterator, bool> success = m_components.insert(make_pair(pComponent->VGetId(), pComponent));
	}
}	// End-of Namespace