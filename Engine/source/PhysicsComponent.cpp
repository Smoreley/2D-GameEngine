#include "BeserkStd.h"
#include "ActorComponent.h"
#include "PhysicsComponent.h"
#include "TransformComponent.h"

const char* PhysicsComponent::g_name = "PhysicsComponent";

PhysicsComponent::PhysicsComponent(void) {
	m_Velocity.x = 0;
	m_Velocity.y = 0;
	m_Velocity.z = 0;

}

PhysicsComponent::~PhysicsComponent(void) {
	// Remove actor from game physics
}

bool PhysicsComponent::VInit(XMLElement* pData) {
	// TODO: Add to the physics manager


	// TODO: Load data from XMLElement

	return true;
}

void PhysicsComponent::VGenerateXML(XMLDocument *pDoc) {
	// TODO: Generate XMLdata and add element to document

	XMLNode* pRoot = pDoc->RootElement();						// Root Element
	XMLElement* pBaseElement = pDoc->NewElement(g_name);		// Transform Element

	XMLElement* pShapeElement = pDoc->NewElement("Shape");		// Shape Element
	pShapeElement->SetText(m_shape.c_str());

	// Insert into Physics Element
	pBaseElement->InsertEndChild(pShapeElement);

	pRoot->InsertEndChild(pBaseElement);

}

void PhysicsComponent::VPostInit() {

}

void PhysicsComponent::VUpdate(DeltaTime deltaMs) {
	// Get ptr to transform component
	/*shared_ptr<TransformComponent> pTransComp = m_pOwner->GetComponent;*/
}

/* Adding Forces */
void PhysicsComponent::AddForce(const vec3 force) {

}

void PhysicsComponent::AddTorque(const vec3 force) {

}