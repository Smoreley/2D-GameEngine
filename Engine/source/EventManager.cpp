#include "BeserkStd.h"
#include "EventManager.h"

namespace Beserk {

	static IEventManager* g_pEventMgr = nullptr;
	GenericObjectFactory<IEventData, EventType> g_eventFactory;

	// IEvent
	IEventManager* IEventManager::Get(void) {
		assert(g_pEventMgr);
		return g_pEventMgr;
	}

	IEventManager::IEventManager(const char* pName, bool setAsGlobal) {
		if (setAsGlobal) {
			if (g_pEventMgr) {
				cout << "ERROR: Attempting to create two global event managers" << endl;
				delete g_pEventMgr;
			}
			g_pEventMgr = this;
		}
	}

	IEventManager::~IEventManager(void) {
		if (g_pEventMgr == this) {
			g_pEventMgr = nullptr;
		}
	}



	// Event Manager Implementation
	EventManager::EventManager(const char* pName, bool setAsGlobal) : IEventManager(pName, setAsGlobal) {
		m_activeQueue = 0;
	}

	EventManager::~EventManager() {
		// TODP: Cleanup
	}

	bool EventManager::VAddListener(const EventListenerDelegate& eventDelegate, const EventType& type) {
		EventListenerList& eventListenerList = m_eventListeners[type];
		for (auto it = eventListenerList.begin(); it != eventListenerList.end(); ++it) {
			if (eventDelegate == (*it)) {
				cout << "Attempting to double-register a delegate" << endl;
				return false;
			}
		}

		eventListenerList.push_back(eventDelegate);
		cout << "Successfully added delegate for event type: " << type << endl;

		return true;
	}


	bool EventManager::VRemoveListener(const EventListenerDelegate& eventDelegate, const EventType& type) {
		bool success = false;

		auto findIt = m_eventListeners.find(type);
		if (findIt != m_eventListeners.end()) {
			EventListenerList& listeners = findIt->second;
			for (auto it = listeners.begin(); it != listeners.end(); ++it) {
				if (eventDelegate == (*it)) {
					listeners.erase(it);

					cout << "Successfully removed delegate function from event type: " << type << endl;

					success = true;
					break;
				}
			}
		}

		return success;
	}

	// VTriggerEvent
	bool EventManager::VTriggerEvent(const IEventDataPtr& pEvent) const {
		
		bool processed = false;
		auto findIt = m_eventListeners.find(pEvent->VGetEventType());
		if (findIt != m_eventListeners.end()) {
			const EventListenerList& eventListenerList = findIt->second;
			for (EventListenerList::const_iterator it = eventListenerList.begin(); it != eventListenerList.end(); ++it) {
				EventListenerDelegate listener = (*it);

				cout << "Events: Sending Event " << string(pEvent->GetName()) << " to delegate" << endl;

				listener(pEvent);	// Call the delegate
				processed = true;
			}
		}
		return processed;
	}

	// VQueueEvent
	bool EventManager::VQueueEvent(const IEventDataPtr& pEvent) {
		
		if (!pEvent) {
			cout << "Invalid event in VQueueEvent()" << endl;
			return false;
		}

		auto findIt = m_eventListeners.find(pEvent->VGetEventType());
		if (findIt != m_eventListeners.end()) {
			m_queues[m_activeQueue].push_back(pEvent);

			cout << "Successfully queued event: " << string(pEvent->GetName()) << endl;
			return true;
		}
		else {
			cout << "Skipping event since there are no delegates registered to receive it: " << string(pEvent->GetName()) << endl;
			return false;
		}
	}

	// AbortEvent
	bool EventManager::VAbortEvent(const EventType& type, bool allOfType) {

		bool success = false;

		EventListenerMap::iterator findIt = m_eventListeners.find(type);
		if (findIt != m_eventListeners.end()) {
			EventQueue& eventQueue = m_queues[m_activeQueue];
			auto it = eventQueue.begin();

			while (it != eventQueue.end()) {

				auto thisIt = it;
				++it;
				if ((*thisIt)->VGetEventType() == type) {
					eventQueue.erase(thisIt);
					success = true;

					if (!allOfType) { break; }
				}
			}
		}

		return success;
	}

	// VUpdateEvent
	bool EventManager::VUpdate(unsigned long maxMillis) {
		//unsigned long currMs = GetTickCount();
		//unsigned long maxMs = ((maxMillis == IEventManager::kINFINITE) ? (IEventManager::kINFINITE) : (currMs + maxMillis));

		//IEventDataPtr pRealtimeEvent;
		//while (!m_realtimeEventQueue.try_pop(pRealtimeEvent)) {

		//}


		return false;
	}

}	// End-of Namespace


long GetTickCount() {
	return 1;
}