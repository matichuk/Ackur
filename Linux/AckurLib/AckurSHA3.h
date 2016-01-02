// AckurSHA3.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurSHA3_
#define _AckurSHA3_

#include "AckurValue.h"
#include "AckurBigInteger.h"

class AckurSHA3
{
public:
	AckurSHA3();
	virtual ~AckurSHA3();
	static AckurError Hash(const u8* pData, u64 pLen, u8* pEnc, u64 pBytes);
	static AckurError Hash(const u8* pData, u64 pLen, AckurBYTE& pEnc, u64 pBytes);
	static AckurError HashByte(const AckurBYTE& pData, AckurBYTE& pEnc, u64 pBytes = 16);
	static AckurError HashInt(AckurBigInteger& pData, AckurBYTE& pEnc, u64 pBytes = 16);
	AckurError Start();
	AckurError Append(const AckurBYTE& pData);
	AckurError Append(const u8* pData, u64 pLen);
	AckurError Append(u8 pData);
	AckurError End(AckurBYTE& pEnc, u64 pBytes);
private:
	void* vInstance;
};


#endif //_AckurSHA3_

////////////////////////////////////////////////////////////////////////////////
