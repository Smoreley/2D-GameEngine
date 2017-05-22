#pragma once

struct TransformData
{
	float pos_x;
	float pos_y;
	float pos_z;

	float rot_y;
	float rot_p;
	float rot_r;

	float scale_x;
	float scale_y;
	float scale_z;
};

class TransformComponent : public ActorComponent {
public:
	static const char* g_name;

	virtual const char* VGetName() const { return g_name; }
	virtual bool VInit(XMLElement* pData) override;
	virtual void VGenerateXML(XMLDocument* pDoc) override;

	// Component Specific functions
	void SetTransform() {}
	void SetPosition() {}

private:
	TransformData m_transData;
};