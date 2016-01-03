#ifndef _AckurScript_
#define _AckurScript_

#include "AckurValue.h"

typedef void (*AckurScriptCallback)(const char* pStr, bool pFlush);

class AckurScript
{
public:
    static AckurError Init(AckurScriptCallback pCallback, const AckurCHAR& pHome);
	static AckurError Start();
	static void Stop();
	static bool IsStopped();
	static void ListenStop();
	static AckurError ListenStart(const AckurCHAR& pURL);
	static void SetGrammar(const AckurCHAR& pGrammar);
	static AckurCHAR DefaultGrammar();
	static int GetChar();
	static AckurCHAR Send(const AckurCHAR& pIn);
	static void SendAsync(const AckurCHAR& pIn, bool pRun=true);
};

#endif //_AckurScript_