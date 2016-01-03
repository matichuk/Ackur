// AckurConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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

void AckurCB(const char*pStr, bool pFlush)
{
	if (pStr) std::cout << (char*)pStr;
	if (pFlush) std::cout.flush();
}

int main()
{
	AckurScript::Init(&AckurCB, AckurCHAR(""));
	AckurScript::SetGrammar(AckurScript::DefaultGrammar());
	AckurScript::Start();
	AckurScript::ListenStart(AckurCHAR(":12345"));
	while (!AckurScript::IsStopped())
	{
		AckurCHAR sendBuffer;
		int ch, lastch;

		do {
			sendBuffer.SetLength(0);
			lastch = 0;
			while (((ch = AckurScript::GetChar()) != EOF) && (ch != '\n') && (ch != '\r'))
			{
				sendBuffer.Append((char)ch);
				lastch = ch;
			}
			if (sendBuffer.mLength == 1 && sendBuffer.mBytes[0] == '.') { AckurScript::Stop(); break; }
			if (sendBuffer.mLength == 1 && sendBuffer.mBytes[0] == '>') { AckurScript::Start(); break; }
			if (sendBuffer.mLength)
				AckurScript::SendAsync(sendBuffer);
		} while (!AckurScript::IsStopped() && (sendBuffer.mLength || ch == '\n' || ch == '\r'));
	}
	AckurScript::Stop();
	return 0;
}

