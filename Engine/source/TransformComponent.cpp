#include "BeserkStd.h"
#include "ActorComponent.h"
#include "TransformComponent.h"

using namespace Beserk;

const char* TransformComponent::g_name = "TransformComponent";

// Helper Functions
float GetFloat(XMLElement* pData, const char* search_term) {
	return pData->FloatAttribute(search_term);
}

float GetDouble(XMLElement* pData, const char* search_term) {
	return pData->DoubleAttribute(search_term);
}

bool TransformComponent::VInit(XMLElement* pData) {

	// Helper typedef for easy attribute changing (i.e. float, double, int)
	typedef float(*GetAttribute)(XMLElement*, const char*);
	GetAttribute getAttrib = &GetFloat;

	// Get Pointer to first variable in transform data struct
	float* pTo_trans = &m_transData.pos_x;

	// Position Data
	XMLElement* pPositionElement = pData->FirstChildElement("Position");
	if (pPositionElement) {
		pTo_trans[0] = getAttrib(pPositionElement, "x");
		pTo_trans[1] = getAttrib(pPositionElement, "y");
		pTo_trans[2] = getAttrib(pPositionElement, "z");
	}

	// Rotation/Orientation Data
	XMLElement* pRotationElement = pData->FirstChildElement("Rotation");
	if (pRotationElement) {
		pTo_trans[3] = getAttrib(pRotationElement, "y");		// Yaw
		pTo_trans[4] = getAttrib(pRotationElement, "p");		// {itch
		pTo_trans[5] = getAttrib(pRotationElement, "r");		// Roll
	}

	// Scale
	XMLElement* pScaleElement = pData->FirstChildElement("Scale");
	if (pScaleElement) {
		pTo_trans[6] = getAttrib(pScaleElement, "x");
		pTo_trans[7] = getAttrib(pScaleElement, "y");
		pTo_trans[8] = getAttrib(pScaleElement, "z");
	}

	return true;

}

void TransformComponent::VGenerateXML(XMLDocument* pDoc) {

	XMLNode* pRoot = pDoc->RootElement();							// Root Element
	XMLElement* pBaseElement = pDoc->NewElement(g_name);			// Transform Element

	XMLElement* pPositionElement = pDoc->NewElement("Position");	// Position Element
	pPositionElement->SetAttribute("x", m_transData.pos_x);
	pPositionElement->SetAttribute("y", m_transData.pos_y);
	pPositionElement->SetAttribute("z", m_transData.pos_z);

	XMLElement* pRotationElement = pDoc->NewElement("Rotation");	// Rotation Element
	pRotationElement->SetAttribute("y", m_transData.rot_y);
	pRotationElement->SetAttribute("p", m_transData.rot_p);
	pRotationElement->SetAttribute("r", m_transData.rot_r);

	XMLElement* pScaleElement = pDoc->NewElement("Scale");			// Scale Element
	pScaleElement->SetAttribute("x", m_transData.scale_x);
	pScaleElement->SetAttribute("y", m_transData.scale_y);
	pScaleElement->SetAttribute("z", m_transData.scale_z);

	// Insert into transform Element
	pBaseElement->InsertEndChild(pPositionElement);
	pBaseElement->InsertEndChild(pRotationElement);
	pBaseElement->InsertEndChild(pScaleElement);

	// Insert transform into root element
	pRoot->InsertEndChild(pBaseElement);

}