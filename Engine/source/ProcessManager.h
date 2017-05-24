#pragma once
#include "Process.h"

typedef list<StrongProcessPtr> ProcessList;

class ProcessManager {
public:
	~ProcessManager(void);

	/* Interface Functions */
	int UpdateProcesses(DeltaTime deltaMs);
	WeakProcessPtr AttachProcess(StrongProcessPtr pProcess);
	void AbortAllProcesses(bool immediate);

	unsigned int GetProcessCount(void) { return m_processes.size(); }

private:
	ProcessList m_processes;

	void ClearAllProcesses(void);

};