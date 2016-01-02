#ifndef _AckurLink_
#define _AckurLink_

#include "AckurValue.h"

#if defined(_WIN64)
#ifdef _DEBUG
#pragma comment (lib, "AckurWin64Debug.lib")
#else
#pragma comment (lib, "AckurWin64Release.lib")
#endif
#elif defined(_WIN32)
#ifdef _DEBUG
#pragma comment (lib, "AckurWin32Debug.lib")
#else
#pragma comment (lib, "AckurWin32Release.lib")
#endif
#endif

typedef void (*AckurLinkCallback)(const char* pStr, bool pFlush);

class AckurLink
{
public:
    static AckurError Init(AckurLinkCallback pCallback, const AckurCHAR& pHome);
	static AckurError Start();
	static void Stop();
	static bool IsStopped();
	static void ListenStop();
	static AckurError ListenStart(const AckurCHAR& pURL);
	static void SetStartGrammar(const AckurCHAR& pGrammar);
	static AckurCHAR StaticGrammar();
	static int GetChar();
	static AckurCHAR Send(const AckurCHAR& pIn);
	static void SendAsync(const AckurCHAR& pIn, bool pRun=true);
};

#endif //_AckurLink_