// AckurConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void AckurCB(const char*pStr, bool pFlush)
{
	if (pStr) std::cout << (char*)pStr;
	if (pFlush) std::cout.flush();
}

int main()
{
	AckurLink::Init(&AckurCB, AckurCHAR(""));
	AckurLink::SetStartGrammar(AckurLink::StaticGrammar());
	AckurLink::Start();
	AckurLink::ListenStart(AckurCHAR(":12345"));
	while (!AckurLink::IsStopped())
	{
		AckurCHAR sendBuffer;
		int ch, lastch;

		do {
			sendBuffer.SetLength(0);
			lastch = 0;
			while (((ch = AckurLink::GetChar()) != EOF) && (ch != '\n') && (ch != '\r'))
			{
				sendBuffer.Append((char)ch);
				lastch = ch;
			}
			if (sendBuffer.mLength == 1 && sendBuffer.mBytes[0] == '.') { AckurLink::Stop(); break; }
			if (sendBuffer.mLength == 1 && sendBuffer.mBytes[0] == '>') { AckurLink::Start(); break; }
			if (sendBuffer.mLength)
				AckurLink::SendAsync(sendBuffer);
		} while (!AckurLink::IsStopped() && (sendBuffer.mLength || ch == '\n' || ch == '\r'));
	}
	AckurLink::Stop();
	return 0;
}

