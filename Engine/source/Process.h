#pragma once
class Process;
typedef shared_ptr<Process> StrongProcessPtr;
typedef weak_ptr<Process> WeakProcessPtr;

class Process {
public:
	enum State {
		UNINITIALIZED = 0,
		REMOVED,

		// Living
		RUNNING,
		PAUSED,

		// Dead Processes
		SUCCEEDED,
		FAILED,
		ABORTED
	};

	Process(void);
	virtual ~Process(void);

protected:
	/* Interface Functions */
	virtual void VInit(void) { m_state = RUNNING; }
	virtual void VUpdate(DeltaTime deltaMs) = 0;
	virtual void VSuccess(void) {}
	virtual void VFailed(void) {}
	virtual void VAbort(void) {}

	/* Functions for ending the process */
	inline void Succeed(void) { m_state = SUCCEEDED; };
	inline void Fail(void) { m_state = FAILED; };

	inline void Pause(bool pause);

	/* Accessors */
	State GetState(void) const { return m_state; }
	bool IsAlive(void) const { return (m_state == RUNNING || m_state == PAUSED); }
	bool IsDead(void) const { return (m_state == SUCCEEDED || m_state == FAILED || m_state == ABORTED); }
	bool IsRemoved(void) const { return (m_state == REMOVED); }
	bool IsPaused(void) const { return (m_state == PAUSED); }

	/* Child Functions */
	inline void AttachChild(StrongProcessPtr pChild);
	StrongProcessPtr RemoveChild(void);
	StrongProcessPtr GetChild(void) { return m_pChild; }


private:
	State m_state;
	StrongProcessPtr m_pChild;		// Child Process (if any)

	friend class ProcessManager;
};

/* Inline Functions */
inline void Process::AttachChild(StrongProcessPtr pChild) {
	m_pChild ? m_pChild->AttachChild(pChild) : m_pChild = pChild;
}

inline void Process::Pause(bool pause) {

	if (pause == true) {
		if (m_state == RUNNING) { m_state = PAUSED; }
		else { cout << "Trying to pause a process that is not running." << endl; }
	}
	else {
		if (m_state == PAUSED) { m_state = RUNNING; }
		else { cout << "Trying to unpause a process that isn't paused." << endl; }
	}

}