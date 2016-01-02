// AckurBigFloat.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurBigFloat_
#define _AckurBigFloat_

#include "AckurBigInteger.h"

class AckurBigFloat
{
public:
	bool mSigned, mTrunc, mFix;
	s64 mExp, mBits, mMax;
	AckurBigInteger mData;
public:
	AckurBigFloat(bool pFix, s64 pMax, s64 pValue=0);
	AckurBigFloat(bool pFix, s64 pMax, const AckurBigInteger& bi);
	AckurBigFloat(bool pFix, s64 pMax, const AckurBigFloat& bi);
	AckurBigFloat(const AckurBigFloat& bi);
	AckurBigFloat(double pValue);
	void INIT() { mSigned = mTrunc = false; mExp = mBits = 0; mData = 0; mMax = 4 * 8; mFix = false; }
	void FROM(const AckurBigFloat& pData) { mSigned = pData.mSigned; mTrunc = pData.mTrunc; mExp = pData.mExp; mBits = pData.mBits; mMax = pData.mMax; mFix = pData.mFix; mData = pData.mData; }
	void TO(AckurBigInteger& pInteger, s64& pLenI, AckurBigInteger& pFraction, s64& pLenF);
	AckurBigFloat& operator=(const AckurBigFloat& that);
	static void Add(AckurBigFloat& A, AckurBigFloat& B, AckurBigFloat& result);
	AckurBigFloat operator +(const AckurBigFloat& bi2);
	AckurBigFloat operator +(s64 bi);
	AckurBigFloat operator +=(const AckurBigFloat& bi1);
	AckurBigFloat& operator ++();
	AckurBigFloat operator ++(int);
	AckurBigFloat operator -(const AckurBigFloat& bi2);
	AckurBigFloat operator -(s64 bi);
	AckurBigFloat operator -=(const AckurBigFloat& bi1);
	AckurBigFloat& operator --();
	AckurBigFloat operator --(int);
	AckurBigFloat operator *(const AckurBigFloat& bi2);
	AckurBigFloat operator *(const AckurBigInteger& bi2);
	AckurBigFloat operator *(s64 bi);
	AckurBigFloat operator *(double bi);
	AckurBigFloat operator <<(int shiftVal);
	AckurBigFloat operator >>(int shiftVal);
	AckurBigFloat operator ~();
	AckurBigFloat operator -();
	bool operator ==(const AckurBigFloat& bi2);
	bool operator !=(const AckurBigFloat& bi2);
	bool Equals(const AckurBigFloat& bi);
	bool operator >(const AckurBigFloat& bi2);
	bool operator >(s64 i1);
	bool operator <(const AckurBigFloat& bi2);
	bool operator <(s64 bi);
	bool operator >=(const AckurBigFloat& bi2);
	bool operator <=(const AckurBigFloat& bi2);
	AckurBigInteger Div(const AckurBigFloat& bi2, AckurBigFloat& remainder);
	AckurBigFloat operator /(const AckurBigFloat& bi2);
	AckurBigFloat operator /(const AckurBigInteger& bi);
	AckurBigFloat operator /(s64 bi);
	AckurBigFloat operator %(const AckurBigFloat& bi2);
	AckurBigFloat operator %(const AckurBigInteger& bi2);
	AckurBigFloat operator %(s64 bi);
	AckurBigFloat operator %=(const AckurBigFloat& bi1);
	AckurBigFloat operator &(const AckurBigFloat& bi2);
	AckurBigFloat operator |(const AckurBigFloat& bi2);
	AckurBigFloat operator ^(const AckurBigFloat& bi2);
	AckurBigFloat Pow(const AckurBigInteger& pexp);
	AckurBigFloat Pow2(const AckurBigFloat& pexp);
	AckurBigFloat Root(const AckurBigInteger& pexp);
	AckurBigFloat Root2(const AckurBigFloat& pexp);
	static AckurBigFloat Pi(s64 pBits);
	static AckurBigFloat Exp(const AckurBigFloat& pexp, s64 pBits);
	AckurBigFloat LnBase();
	AckurBigFloat Log(const AckurBigFloat& b);
	AckurBigFloat Ln();
	AckurBigFloat Sin();
	AckurBigFloat Cos();
	AckurBigFloat Tan();
	AckurBigFloat Cot();
	AckurBigFloat Sec();
	AckurBigFloat Csc();
	AckurBigFloat ASin();
	AckurBigFloat ACos();
	AckurBigFloat ATan();
	AckurBigFloat ACot();
	AckurBigFloat ASec();
	AckurBigFloat ACsc();
	AckurBigFloat SinH();
	AckurBigFloat CosH();
	AckurBigFloat TanH();
	AckurBigFloat CotH();
	AckurBigFloat SecH();
	AckurBigFloat CscH();
	AckurBigFloat ASinH();
	AckurBigFloat ACosH();
	AckurBigFloat ATanH();
	AckurBigFloat ACotH();
	AckurBigFloat ASecH();
	AckurBigFloat ACscH();
	static AckurBigFloat ATan2(const AckurBigFloat& x, const AckurBigFloat& y);
	static AckurBigFloat Hypot(const AckurBigFloat& x, const AckurBigFloat& y);
	AckurCHAR ToString();
	AckurCHAR ToString(u8 radix);
	AckurBigInteger ToInt();
	void FromString(const AckurBYTE& result, u8 radix, s64 max = 0);
	void FromBytes(const AckurBYTE& result);
	AckurBYTE getBytes();
	void Truncate();
};

#endif //_AckurBigFloat_

////////////////////////////////////////////////////////////////////////////////
