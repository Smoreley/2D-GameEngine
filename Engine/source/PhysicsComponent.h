#pragma once

namespace Beserk {

	class PhysicsComponent : public ActorComponent {
	public:
		static const char* g_name;

		PhysicsComponent(void);
		virtual ~PhysicsComponent(void);

		virtual const char* VGetName() const override { return PhysicsComponent::g_name; }
		virtual void VGenerateXML(XMLDocument* pDoc) override;

		virtual bool VInit(XMLElement* pData) override;
		virtual void VPostInit(void) override;
		virtual void VUpdate(DeltaTime deltaMs) override;

		// Component Specific
		void AddForce(const vec3 force);								// Should be vector3
		//void AddForce(const float x, const float y, const float z);		// apply force along axis
		void AddTorque(const vec3 force);

		vec3 GetVelocity(void) { return m_Velocity; }
		vec3 GetAngluarVelocity(void) { return m_AngularVelocity; }

	private:
		vec3 m_Position;
		vec3 m_Rotation;
		vec3 m_Velocity;
		vec3 m_AngularVelocity;

		string m_shape;		// Collision-Shape
		string m_material;	// Material

	};

}	// End-of Namespace