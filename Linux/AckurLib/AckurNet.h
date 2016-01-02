// AckurNet.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurNet_
#define _AckurNet_

#include "AckurThread.h"
#include "AckurValue.h"

class AckurNet : public AckurCritical
{
public:
	bool mStarted, mConnected, mBound;
	char mHostName[256];
	char mIpName[256];
	s16 mFamily;
	u16 mPort;
	u64 mMAC;
	char mName[256];

	AckurNet();
    virtual ~AckurNet();

	virtual AckurError Connect(AckurCHAR& pURL);
	virtual AckurError Bind(AckurCHAR& pURL);
	virtual AckurError Listen(AckurNet& pClient);
	virtual AckurError Disconnect();

	virtual AckurError Send(u8* sendbuf, u64 sendbuflen, u64& sendlen);
	virtual AckurError Recieve(u8* recvbuf, u64 recvbuflen, u64& recvlen);

	virtual AckurError Send(AckurBYTE& sendbuf);
	virtual AckurError Recieve(AckurBYTE& recvbuf, u64& hasmore);

	virtual void GetService(AckurCHAR& pURL, AckurCHAR& pNodeName, AckurCHAR& pServiceName, bool& isIPv6);
	virtual AckurError GetPeerName();
	virtual AckurError GetLocalName();
	static AckurError GetMac(char* pName, char* pIp, u64& pMAC);
	static void GetInterfaces(AckurCHARFile& pIf);

private:
	void* vInstance;
	virtual AckurError Startup();
	virtual void Shutdown();
};

////////////////////////////////////////////////////////////////////////////////

class AckurNetListen : public AckurThread
{
public:
	AckurNet mNet;
	bool mWaiting;

	AckurNetListen() { mWaiting = true; }
	virtual ~AckurNetListen();

	virtual AckurError Disconnect();
	virtual void Stop();
	virtual void Starting();
	virtual void Running();
	virtual void Stopping();
};

class AckurNetBind : public AckurThread
{
public:
	AckurNet mNet;
	AckurCHAR mURL;

public:
	AckurNetBind();
	virtual ~AckurNetBind();

	virtual void Set(AckurCHAR& mURL);
	virtual AckurError Start();
	virtual void Stop();
	virtual void Cleanup();

	virtual void Starting();
	virtual void Running();
	virtual void Stopping();
};

class AckurNetConnect : public AckurThread
{
public:
	AckurNet mNet;
	AckurCHAR mURL;

public:
	AckurNetConnect();
	virtual ~AckurNetConnect();

	virtual void Set(AckurCHAR& pURL);
	virtual void Stop();
	virtual AckurError Connect();
	virtual AckurError Disconnect();

	virtual void Starting();
	virtual void Running();
	virtual void Stopping();
};

////////////////////////////////////////////////////////////////////////////////

#endif //_AckurNet_
