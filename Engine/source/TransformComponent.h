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

	TransformData() : pos_x(0), pos_y(0), pos_z(0) {};
};

class TransformComponent : public ActorComponent {
public:
	static const char* g_name;

	TransformComponent(void) : m_transData() {}

	virtual const char* VGetName() const override { return TransformComponent::g_name; }
	virtual bool VInit(XMLElement* pData) override;
	virtual void VGenerateXML(XMLDocument* pDoc) override;

	// Component Specific functions
	void SetTransform() {}
	void SetPosition() {}

private:
	TransformData m_transData;
};