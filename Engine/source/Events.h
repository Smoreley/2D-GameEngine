#pragma once
#include "EventManager.h"


typedef int GameViewId;
const GameViewId gc_invalidGameViewId = 0xffffffff;

namespace Beserk {

	class EventData_New_Actor : public BaseEventData
	{
	public:
		static const EventType sk_eventType;

		EventData_New_Actor(void) {
			m_actorId = INVALID_ACTOR_ID;
			m_viewId = gc_invalidGameViewId;
		}

		explicit EventData_New_Actor(ActorId actorId, GameViewId viewId = gc_invalidGameViewId)
			: m_actorId(actorId), m_viewId(viewId) {}

		virtual void VDeserialize(std::istream& in) {
			in >> m_actorId;
			in >> m_viewId;
		}

		virtual const EventType& VGetEventType(void) const {
			return sk_eventType;
		}

		virtual IEventDataPtr VCopy(void) const {
			return IEventDataPtr(new EventData_New_Actor(m_actorId, m_viewId));
		}

		virtual void VSerialize(std::ostream& out) const {
			out << m_actorId << " ";
			out << m_viewId << " ";
		}

		virtual const char* GetName(void) const {
			return "EventData_New_Actor";
		}

		const ActorId GetActorId(void) const {
			return m_actorId;
		}

		GameViewId GetViewId(void) const {
			return m_viewId;
		}


	private:
		ActorId m_actorId;
		GameViewId m_viewId;

	};


} // End-of Namespace