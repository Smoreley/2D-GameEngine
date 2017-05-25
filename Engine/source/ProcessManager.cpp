#include "BeserkStd.h"
#include "ProcessManager.h"

ProcessManager::~ProcessManager(void) {
	ClearAllProcesses();
}

int ProcessManager::UpdateProcesses(DeltaTime deltaMs) {

	ProcessList::iterator it = m_processes.begin();
	while (it != m_processes.end()) {
		// Grab the next process
		StrongProcessPtr pCurrProcess = (*it);

		// Save th iterator and increment
		ProcessList::iterator prevIt = it;
		++it;

		// Process is uninitialized so initialize it
		if (pCurrProcess->GetState() == Process::UNINITIALIZED) {
			pCurrProcess->VInit();
		}

		// Give the process an update tick
		if (pCurrProcess->GetState() == Process::RUNNING) {
			pCurrProcess->VUpdate(deltaMs);
		}

		// Check to see if the process is dead
		if (pCurrProcess->IsDead()) {

			// Run the appropriate exit function
			switch (pCurrProcess->GetState())
			{
			case Process::SUCCEEDED:
			{
				pCurrProcess->VSuccess();

				StrongProcessPtr pChild = pCurrProcess->RemoveChild();
				if (pChild) {
					AttachProcess(pChild);
				}
				break;
			}
			case Process::FAILED:
			{
				pCurrProcess->VFailed();
				break;
			}
			case Process::ABORTED:
			{
				pCurrProcess->VAbort();
				break;
			}
			}

			// Remove process and destroy it
			m_processes.erase(prevIt);
		}

	}

	return 0;
}

WeakProcessPtr ProcessManager::AttachProcess(StrongProcessPtr pProcess) {
	m_processes.push_front(pProcess);
	return WeakProcessPtr(pProcess);
}

void ProcessManager::ClearAllProcesses(void) {
	m_processes.clear();
}

void ProcessManager::AbortAllProcesses(bool immediate) {

	ProcessList::iterator it = m_processes.begin();

	while (it != m_processes.end()) {
		ProcessList::iterator refIt = it;
		++it;

		StrongProcessPtr pProcess = *refIt;
		if (pProcess->IsAlive()) {
			pProcess->SetState(Process::ABORTED);
			if (immediate) {
				pProcess->VAbort();
				m_processes.erase(refIt);
			}
		}
	}

}