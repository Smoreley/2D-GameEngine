#pragma once
#include "Entity.h"
//class CEntity;

namespace Beserk {
	class IComponent
	{
	public:
		IComponent();
		~IComponent();

		Entity *parent_entity;

		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void OnDestory() = 0;

	private:

	};
}