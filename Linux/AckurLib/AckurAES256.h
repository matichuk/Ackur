// AckurAES256.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurAES256_
#define _AckurAES256_

#include "AckurValue.h"

class AckurAES256
{
public:
	bool mSet;
	AckurAES256();
	virtual ~AckurAES256();
	AckurError SetKey(u8* pKey, u64 pLen);
	AckurError SetKeyPad(u8* pKey, u64 pLen, u8 pPad);
	void ClearKey();

	void Encrypt16(u8* pData, u8* out, u8 padCount=0);
	void Decrypt16(u8* pEnc, u8* out, u8 padCount=0);

	void Encrypt(AckurBYTE& pData);
	void Decrypt(AckurBYTE& pEnc);
	void Encrypt(AckurBYTE& pData, AckurBYTE& pEnc);
	void Decrypt(AckurBYTE& pEnc, AckurBYTE& pData);

	void EncryptPad(AckurBYTE& pData, AckurBYTE& pEnc, u8 pPadCount = 0);
	void DecryptPad(AckurBYTE& pEnc, AckurBYTE& pData, u8 pPadCount = 0);
	void EncryptPad(AckurBYTE& pData, u8 pPadCount = 0);
	void DecryptPad(AckurBYTE& pEnc, u8 pPadCount = 0);

private:
	void* vKey;
};


#endif //_AckurAES256_

////////////////////////////////////////////////////////////////////////////////
