// AckurBigInteger.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurBigInteger_
#define _AckurBigInteger_

#include "AckurValue.h"
#include "AckurThread.h"

class AckurArray32
{
public:
	bool dataSigned;
	u8* mBytes;
	u64 mSize, mLength, mGrow;
public:
	AckurArray32();
	~AckurArray32();
	AckurArray32& operator=(const AckurArray32& that);
private:
	void INIT();
public:
	virtual void SetLength(u64 pLen = 0, bool pCopy = true);
	virtual void SetSize(u64 pLen = 0, bool pCopy = true);
	virtual void FROM(const AckurArray32& pData);
	virtual u64 GetCount();
	virtual u64 GetByteCount();
	virtual void SetCount(u64 pCount);
	virtual void GrowCount(u64 pCount);
	virtual void SetItem(u64 pItem, u32 pValue);
	virtual u32 GetItem(u64 pItem);
	virtual void RTrim();
	virtual bool IsNull();
	virtual bool IsNeg();
	virtual bool IsSignNeg();
	virtual bool IsZero();
	virtual bool IsItem(u32 pItem);
};

class AckurBigInteger : public AckurArray32, public AckurCritical
{
public:
	AckurBigInteger();
	AckurBigInteger(s64 value);
	AckurBigInteger(const AckurBigInteger& bi);
	AckurBigInteger(const char* value, s32 radix);
	AckurBigInteger(const u8* inData, u32 inLen);
	AckurBigInteger(u32* inData, u32 inCount);
	AckurBigInteger(const AckurBYTE& inData);
	~AckurBigInteger();
	AckurBigInteger& operator=(const AckurBigInteger& that);
	void operator =(s64 bi);
	AckurBigInteger operator +(const AckurBigInteger& bi2);
	AckurBigInteger operator +(s64 bi);
	AckurBigInteger operator +=(const AckurBigInteger& bi1);
	AckurBigInteger& operator ++();
	AckurBigInteger operator ++(int);
	AckurBigInteger operator -(const AckurBigInteger& bi2);
	AckurBigInteger operator -(s64 bi);
	AckurBigInteger operator -=(const AckurBigInteger& bi1);
	AckurBigInteger& operator --();
	AckurBigInteger operator --(int);
	AckurBigInteger operator *(const AckurBigInteger& bi2);
	AckurBigInteger operator *(s64 bi);
	AckurBigInteger operator *(u64 bi);
	AckurBigInteger operator <<(u64 shiftVal);
	int shiftLeft(u32* inData, u32 inCount, u64 shiftVal);
	AckurBigInteger operator >>(u64 shiftVal);
	int shiftRight(u32* inData, u32 inCount, u64 shiftVal);
	AckurBigInteger operator ~();
	AckurBigInteger operator -();
	bool operator ==(const AckurBigInteger& bi2);
	bool operator !=(const AckurBigInteger& bi2);
	bool Equals(const AckurBigInteger& bi);
	bool operator >(const AckurBigInteger& bi2);
	bool operator >(u64 i1);
	bool operator <(const AckurBigInteger& bi2);
	bool operator <(s64 bi);
	bool operator >=(const AckurBigInteger& bi2);
	bool operator <=(const AckurBigInteger& bi2);
	void multiByteDivide(const AckurBigInteger& bi2, AckurBigInteger& outQuotient, AckurBigInteger& outRemainder);
	void singleByteDivide(const AckurBigInteger& bi2, AckurBigInteger& outQuotient, AckurBigInteger& outRemainder);
	AckurBigInteger Div(const AckurBigInteger& bi2, AckurBigInteger& remainder);
	AckurBigInteger operator /(const AckurBigInteger& bi2);
	AckurBigInteger operator /(u64 bi);
	AckurBigInteger operator %(const AckurBigInteger& bi2);
	AckurBigInteger operator %(u64 bi);
	AckurBigInteger operator %=(const AckurBigInteger& bi1);
	AckurBigInteger operator &(const AckurBigInteger& bi2);
	AckurBigInteger operator |(const AckurBigInteger& bi2);
	AckurBigInteger operator ^(const AckurBigInteger& bi2);
	//AckurBigInteger bxor(const AckurBigInteger& bi);
	AckurBigInteger bmax(const AckurBigInteger& bi);
	AckurBigInteger bmin(const AckurBigInteger& bi);
	AckurBigInteger babs();
	d64 blog();
	d64 blog2();
	d64 blog10();
	AckurBigInteger LargestPrimeFactor();
	static u64 LargestPrimeFactor64(u64 a);
	AckurCHAR ToString();
	AckurCHAR ToString(u32 radix);
	void FromString(const AckurBYTE& result, u32 radix);
	void FromBytes(const AckurBYTE& result);
	//AckurBigInteger Factorial();
	AckurBigInteger Pow(const AckurBigInteger& exp);
	AckurBigInteger modPow(const AckurBigInteger& exp, const AckurBigInteger& n);
	static AckurBigInteger BarrettReduction(const AckurBigInteger& x, const AckurBigInteger& n, const AckurBigInteger& constant);
	AckurBigInteger gcd(const AckurBigInteger& bi);
	AckurBigInteger gcd(s64 i1);
	void genRandomBits(u64 bits);
	u64 bitCount();
	u64 bitStart();
	s32 IntValue();
	s64 LongValue();
	AckurBigInteger modInverse(const AckurBigInteger& modulus);
	AckurBYTE getBytes(bool pRaw=false);
	static AckurCHAR Base(AckurBYTE& pInput, u64 pFrom, u64 pTo);
	void setBit(u32 bitNum);
	void unsetBit(u32 bitNum);
	bool testBit(u64 bitNum);
	AckurBigInteger bsqrt();
	static void MulDivTest(u32 rounds);
	static void SqrtTest(u32 rounds);
	static u64 gcd64(u64 a, u64 b);
	static u64 mulinv64(u64 exponent, u64 modulus);
	static u64 Inv64(u64 n, u64 m);
	static u64 modpow64(u64 base, u64 exponent, u64 modulus);
	static u64 Powm64(u64 n, u64 e, u64 m);
	static u64 mul64(u64 a, u64 b, u64 mod);
	static u64 pow64(u64 a, u64 p, u64 mod);
	static u64 sqrt64(u64 ull);
};

class AckurPolyMod
{
protected:
	// (mod x^r - 1, n)
	u64 m_r, m_deg;
	AckurBigInteger *mp_a, m_n, zero, one, two;
private:
	AckurPolyMod();
public:
	// default value is x
	AckurPolyMod(u64 r, const AckurBigInteger& n);
	AckurPolyMod(const AckurPolyMod & p);
	virtual ~AckurPolyMod();
public:
	AckurPolyMod & operator = (const AckurPolyMod & p);
	int operator != (const AckurPolyMod & p) const;
	AckurPolyMod & operator += (const AckurBigInteger& i);
	AckurPolyMod & operator += (u64 i);
	AckurPolyMod & operator -= (const AckurBigInteger& i);
	AckurPolyMod & operator -= (u64 i);
	AckurPolyMod Pow(const AckurBigInteger& e);
private:
	void _polySquare();
	void _polyMul(const AckurPolyMod & p);
	void _Mod();
	void _Norm();
};


#endif //_AckurBigInteger_

////////////////////////////////////////////////////////////////////////////////
