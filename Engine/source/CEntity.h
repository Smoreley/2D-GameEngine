#pragma once
#include <glm\vec3.hpp>

typedef glm::vec3 vec3;

// Position, Rotation, Scale
struct prs
{
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

namespace Beserk {
	class CEntity
	{
	public:
		prs transform;

		CEntity();
		~CEntity();

		void Start(void);
		void Update(const double dt);
		void OnDestory(void);

		// Getters
		const vec3 GetPosition() { return transform.position;  }
		const vec3 GetRotation() { return transform.rotation; }
		const vec3 GetScale() { return transform.scale; }

	private:
		unsigned int entity_ID;


	};
}