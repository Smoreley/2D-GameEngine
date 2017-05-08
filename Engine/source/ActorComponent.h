#pragma once
#include "Interfaces.h"

namespace Beserk {
	class ActorComponent
	{
	public:

		virtual bool VInit() = 0;
		virtual void VPostInit(void) { }
		virtual void VUpdate(int delta_ms) { }
		virtual void VOnChanged(void) { }


		//virtual ComponentId vGetId(void) const { return GetIdFromName(VGetName()); }
		virtual const char* VGetName() const = 0;

		//static ComponentId GetIdFromName(const char* component_str) {
		//	void* raw_id = HashedString::hash_name(component_str);
		//	return reinterpret_cast<ComponentId>(raw_id);
		//}

	protected:
		StrongActorPtr m_pOwner;

	private:
		friend class ActorFactory;

		void SetOwner(StrongActorPtr pOwner) { m_pOwner = pOwner; }

	};
}