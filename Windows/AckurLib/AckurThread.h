// AckurThread.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurThread_
#define _AckurThread_

#include "AckurType.h"

class AckurCritical
{
public:
	s32 mWaitCount;
	bool mWaiting;

	AckurCritical();
    virtual ~AckurCritical();

	virtual bool TryCritical();
	virtual void WaitCritical();
	virtual void LeaveCritical();
	virtual void WaitCondition(bool noAdd = false);
	virtual void SendCondition(bool force = false);

private:
	void* vInstanceC;
};

class AckurThread : public AckurCritical
{
public:
	AckurError mError;
	bool mStop, mSync;
	AckurCritical mRunning,mSuspend;

	AckurThread();
    virtual ~AckurThread();

	virtual AckurError Start();
	virtual AckurError StartSync();
	virtual void Stop();
	virtual AckurError Suspend();
	virtual AckurError Resume();

	void RunFromStatic();

private:
	void* vInstanceT;
	virtual void Starting() = 0;
	virtual void Running() = 0;
	virtual void Stopping() = 0;
};

#endif //_AckurThread_

////////////////////////////////////////////////////////////////////////////////
