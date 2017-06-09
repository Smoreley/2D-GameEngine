#pragma once
#include "BeserkStd.h"

namespace Beserk {

	/* Forward Declaration */
	class IEventData;

	/* Typedefs */
	typedef unsigned long EventType;
	typedef std::shared_ptr<IEventData> IEventDataPtr;


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


	class BaseEventData : public IEventData {
	public:
		explicit BaseEventData(const float timeStamp = 0.0f) : m_timeStamp(timeStamp) {}

		virtual const EventType& VGetEventType(void) const = 0;
		float GetTimeStamp(void) const { return m_timeStamp; }

	private:
		const float m_timeStamp;
	};

}	// End-off Namespace