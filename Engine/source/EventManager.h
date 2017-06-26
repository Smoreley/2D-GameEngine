#pragma once

#include <strstream>
//#include "CriticalSection.h"

namespace Beserk {

	/* Forward Declaration */
	class IEventData;

	/* Typedefs */
	typedef unsigned long EventType;
	typedef shared_ptr<IEventData> IEventDataPtr;
	typedef void (*EventListenerDelegate) (IEventDataPtr d);		// Takes an IEventData variable and returns void (nothing)
	//typedef concurrent_queue<IEventDataPtr> ThreadSafeEventQueue;

	extern GenericObjectFactory<IEventData, EventType> g_eventFactory;
#define REGISTER_EVENT(eventClass) g_eventFactory.Register<eventClass>(eventClass::sk_EventType);
#define CREATE_EVENT(eventType) g_eventFactory.Create(eventType);

	/* IEventData - base type for event object hierachy */
	class IEventData {
	public:
		virtual ~IEventData(void) {}
		virtual const EventType& VGetEventType(void) const = 0;
		virtual float GetTimeStamp(void) const = 0;

		/* For Networking */
		virtual void VSerialize(ostream& out) const = 0;
		virtual void VDeserialize(istream& in) = 0;

		virtual IEventDataPtr VCopy(void) const = 0;
		virtual const char* GetName(void) const = 0;
	};

	/* BaseEventData*/
	class BaseEventData : public IEventData {
	public:
		explicit BaseEventData(const float timeStamp = 0.0f) : m_timeStamp(timeStamp) {}

		virtual const EventType& VGetEventType(void) const = 0;
		float GetTimeStamp(void) const { return m_timeStamp; }

		virtual void VSerialize(std::ostream& out) const {}
		virtual void VDeserialize(std::istream& in) {}

	private:
		const float m_timeStamp;
	};


	/* IEventManager */
	class IEventManager
	{
	public:
		enum eConstants { kINFINITE = 0xffffffff };

		explicit IEventManager(const char* pName, bool setAsGlobal);
		virtual ~IEventManager(void);

		virtual bool VAddListener(const EventListenerDelegate& eventDelegate, const EventType& type) = 0;
		virtual bool VRemoveListener(const EventListenerDelegate& eventDelegate, const EventType& type) = 0;
		virtual bool VTriggerEvent(const EventListenerDelegate& eventDelegate, const EventType& type) = 0;


		virtual bool VQueueEvent(const IEventDataPtr& pEvent) = 0;
		virtual bool VThreadSafeQueueEvent(const IEventDataPtr& pEvent) = 0;

		virtual bool VAbortEvent(const EventType& type, bool allOfType = false) = 0;
		virtual bool VUpdate(unsigned long maxMillis = kINFINITE) = 0;

		static IEventManager* Get(void);

	};


	const unsigned int EVENTMANAGER_NUM_QUEUES = 2;
	/* Relization of IEventManager */
	class EventManager : public IEventManager
	{
	public:
		explicit EventManager(const char* pName, bool setAsGlobal);
		virtual ~EventManager(void);

		virtual bool VAddListener(const EventListenerDelegate& eventDelegate, const EventType& type);
		virtual bool VRemoveListener(const EventListenerDelegate& eventDelegate, const EventType& type);

		virtual bool VTriggerEvent(const IEventDataPtr& pEvent) const;
		virtual bool VQueueEvent(const IEventDataPtr& pEvent);
		virtual bool VThreadSafeQueueEvent(const IEventDataPtr& pEvent);
		virtual bool VAbortEvent(const EventType& type, bool allOfType = false);

		virtual bool VUpdate(unsigned long maxMillis = kINFINITE);

	private:
		typedef list<EventListenerDelegate> EventListenerList;
		typedef map<EventType, EventListenerList> EventListenerMap;
		typedef list<IEventDataPtr> EventQueue;

		EventListenerMap m_eventListeners;
		EventQueue m_queues[EVENTMANAGER_NUM_QUEUES];
		int m_activeQueue;

		//ThreadSafeEventQueue m_realtimeEventQueue;

	};

}	// End-off Namespace