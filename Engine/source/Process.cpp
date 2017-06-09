#include "BeserkStd.h"
#include "Process.h"

namespace Beserk {

	Process::Process(void) {
		m_state = UNINITIALIZED;
	}

	Process::~Process(void) {
		if (m_pChild) {
			m_pChild->VAbort();
		}
	}

	StrongProcessPtr Process::RemoveChild(void) {

		if (m_pChild) {
			StrongProcessPtr pChild = m_pChild;
			m_pChild.reset();
			return pChild;
		}
		return StrongProcessPtr();

	}

}	// End-of Namespace