// AckurPrime.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurPrime_
#define _AckurPrime_

#include "AckurBigInteger.h"

class AckurPrime : public AckurBigInteger
{
public:
	u32 mBits;
	bool mFound;
	AckurCritical* vCond;

public:
	AckurPrime();
	AckurPrime(s64 value);
	AckurPrime(int value);
	AckurPrime(u64 value);
	AckurPrime(const AckurBigInteger& bi);
	AckurPrime(const u8* inData, u32 inLen);
	virtual ~AckurPrime();
	AckurPrime& operator=(const AckurPrime& that);
	AckurPrime& operator=(const AckurBigInteger& that);
	void operator =(s64 bi);
public:
	void GenPrime(u32 bits, u32 confidence, AckurBigInteger& randP);
	bool TestPrime(u32 confidence);
	bool AKS();
public:
	bool FermatLittleTest(int confidence);
	bool RabinMillerTest(int confidence);
	bool SolovayStrassenTest(int confidence);
	bool LucasStrongTest();
	bool LucasStrongTestHelper(const AckurBigInteger& thisVal);
	bool DivisorTest();
	bool ConfidenceTest(int confidence);
	bool StrongTest();
	bool isProbablePrime();
	static s32 Jacobi(const AckurBigInteger& a, const AckurBigInteger& b);
	static s32 Jacobi(s64 a, const AckurBigInteger& b);
	AckurBigInteger genCoPrime(u32 bits);
	void GenPrimes16();
	void GenPrimesDiv(u32 *primeList, u32 *numPrimes, u32 *maxPrime);
	bool isPrime32(u32 candidatePrime);
	u32 GenPrime16(u32 min, u32 max);
	static void LucasSequence(AckurBigInteger& P, AckurBigInteger& Q, AckurBigInteger& k, AckurBigInteger& n,
		AckurBigInteger& Uk, AckurBigInteger& Vk, AckurBigInteger& Qn);
	static void LucasSequenceHelper(AckurBigInteger& P, AckurBigInteger& Q, AckurBigInteger& k, AckurBigInteger& n,
		AckurBigInteger& Uk, AckurBigInteger& Vk, AckurBigInteger& Qn,
		AckurBigInteger& constant, s32 s);
	static void LucasSequenceHelper(s64 P, s64 Q, AckurBigInteger& k, AckurBigInteger& n,
		AckurBigInteger& Uk, AckurBigInteger& Vk, AckurBigInteger& Qn,
		AckurBigInteger& constant, s32 s);
	static void RSATest(u32 rounds);
	static void RSATest2(u32 rounds);
	static AckurBigInteger StaticPrime(int bits);

//private:
//	virtual void Running();
//	virtual void Stopping();
};


#endif //_AckurPrime_

////////////////////////////////////////////////////////////////////////////////

