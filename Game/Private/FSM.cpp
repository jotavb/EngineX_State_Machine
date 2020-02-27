#include "FSM.h"
#include "FSMState.h"
#include <assert.h>

FSM::FSM()
	: mCurrent(nullptr)
	, mNext(nullptr)
{
}

FSM::~FSM()
{
}

void FSM::Initialize(FSMState* pState)
{
	assert(mCurrent == nullptr);
	mCurrent = pState;
	mCurrent->OnEnter();
}

void FSM::Next(FSMState* pState)
{
	if (mNext != nullptr)
	{
		delete mNext;
	}

	mNext = pState;
}

void FSM::Update(float fDeltaT)
{
	if (mNext != nullptr)
	{
		mCurrent->OnExit();
		delete mCurrent;

		mCurrent = mNext;
		mCurrent->OnEnter();

		mNext = nullptr;
	}

	mCurrent->OnUpdate(fDeltaT);
}