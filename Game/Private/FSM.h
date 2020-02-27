#pragma once

class FSMState;

class FSM
{
public:

	FSM();
	~FSM();

	void Initialize(FSMState* pState);
	
	void Next(FSMState* pState);

	void Update(float fDeltaT);

	template<class T, typename... params>
	T* Create(params... xs)
	{
		return new T(this, xs...);
	}

private:

	FSMState* mCurrent;
	FSMState* mNext;
};