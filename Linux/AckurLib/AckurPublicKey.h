// AckurPublicKey.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurPublicKey_
#define _AckurPublicKey_

#include "AckurPrime.h"

class AckurPublicKey
{
public:
	u32 mKeySize, mEncSize, mDataSize;
	AckurBigInteger mPrivateKey, mPublicKey, mConstant;
	AckurPrime mRandP, mRandQ;
	AckurBigInteger mPrivateP, mPrivateQ, mPrivateI;
	AckurBigInteger cZero, cOne;
	u32 mConfidence;

public:
	AckurPublicKey();
	bool MakeKey(u32 pSize);
	bool SetPrivateKey(AckurBigInteger pPublicKey, AckurBigInteger pRandP);
	bool SetPublicKey(AckurBigInteger pPublicKey);
	bool SetConstant(AckurBigInteger pConstant);
	bool Encrypt(AckurBYTE& pData, AckurBYTE& pDataIn, AckurBYTE& pEnc, u8 pOpt = 0);
	bool Decrypt(AckurBYTE& pEnc, AckurBYTE& pData, u8& pOpt);
	bool Decrypt3(AckurBYTE& pEnc, AckurBYTE& pData, u8& pOpt);
	bool Sign(const AckurBYTE& pData, AckurBYTE& pSignature);
	bool Verify(const AckurBYTE& pData, AckurBYTE& pSignature);
	void TestGenKeys(u32 pSize, u32 pKeyCount, u32 pTestCount);
	bool TestEncrypt(u32 pSize, AckurCHAR& pData, AckurCHAR& pInput, AckurBYTE& pEnc, AckurCHAR& pOutput);

private:
	bool Encrypt(AckurBigInteger& pConstant, AckurBigInteger& pPublicKey, AckurBYTE& pData, AckurBYTE& pDataIn, AckurBYTE& pEnc, u8 pOpt);
	bool Decrypt(AckurBigInteger& pPrivateKey, AckurBigInteger& pPublicKey, AckurBYTE& pEnc, AckurBYTE& pData, u8& pOpt);
	bool Decrypt3(AckurBigInteger& pPrivateKey, AckurBigInteger& pPublicKey, AckurBYTE& pEnc, AckurBYTE& pData, u8& pOpt);
};


#endif //_AckurPublicKey_

////////////////////////////////////////////////////////////////////////////////
