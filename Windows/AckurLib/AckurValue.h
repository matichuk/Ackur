// AckurValue.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurValue_
#define _AckurValue_

#include "AckurThread.h"
#include "AckurFile.h"

class AckurCHAR;
class AckurSS64;
class AckurSU64;
class AckurDU64;
class AckurGUID;
class AckurDATE;
class AckurBYTE;

class AckurValue
{
public:
	typedef enum { START = 0, ERR, RAW, INT, FLOAT, STR, BIN, HEX, TIME, LIST, DB, ID, SYM, SYSSYM, SYSINT, SYSID, SYSSTR, OTHER, RULE, OPERATION, ACTION, POINTER, FAIL, DBOBJ, NETOBJ, X1, MAX } BtMapToken;
	BtMapToken mToken;
};

class AckurBYTE : public AckurValue
{
public:
	u8* mBytes;
	u64 mSize;
	u64 mLength;
	u64 mPos;
	u64 mGrow;
public:
	AckurBYTE();
	AckurBYTE(u64 pSize, const void *pValue = NULL);
	AckurBYTE(const void *pValue, u64 pSize);
	AckurBYTE(const char *pStr);
	AckurBYTE(const AckurBYTE& pBlob);
	~AckurBYTE();
	AckurBYTE& operator=(const AckurBYTE& that);
	AckurBYTE& operator=(const AckurCHAR& that);
private:
	void INIT();
public:
	virtual void FROM(u64 pSize, const void *pValue);
	virtual void FROM(const AckurBYTE& pValue);
	virtual void TO(AckurCHAR& pChar);
	virtual void ToHex(AckurBYTE& pValue);
	virtual void ToRaw(AckurBYTE& pValue);
	virtual void ToStr(AckurCHAR& pValue);
public:
	virtual void* GetPtr();
	virtual void SetNull();
	virtual u64 GetLength();
	virtual void SetLength(u64 pLength, bool pCopy = true);
	virtual void SetSize(u64 pSize, bool pCopy=true);
	virtual u64 GetSize();
	virtual void GrowSize(u64 pSize, bool pCopy=true);
	virtual void Append(const AckurCHAR& pValue);
	virtual void Append(const AckurBYTE& pValue);
	virtual void Append(void *pValue, u64 pSize);
	virtual void Append(const u8 pValue);
	virtual s64 Cmp(AckurBYTE& pValue);
	virtual s64 Cmp(const char* pStr);
	virtual void Pad(u64 pSize, u8 pValue = 0);
	virtual u8 ToDbType();
	virtual void FromDbType(u8 pType);
};

class AckurCHAR : public AckurBYTE
{
public:
	AckurCHAR();
	AckurCHAR(const char *pStr, u64 pLen);
	AckurCHAR(const AckurBYTE& pBlob);
	AckurCHAR(s64 pNum);
	AckurCHAR(u64 pId);
	AckurCHAR(du64 pId);
	AckurCHAR& operator=(const AckurCHAR& that);
	AckurCHAR& operator=(const AckurBYTE& that);
private:
	void INIT();
public:
	virtual void FROM(const char *pStr);
	virtual void FROM(const char* pStr, u64 pLen);
	virtual void FROM(s64 pNum);
	virtual void FROM(u64 pId);
	virtual void FROM(du64 pId);
	virtual void FROM(const AckurCHAR& pChar);
	virtual void FROM(const AckurBYTE& pValue);
	virtual void TO(AckurSS64& pNumber);
	virtual void TO(AckurSU64& pNumber);
	virtual void TO(AckurDU64& pNumber);
public:
	virtual void SetLength(u64 pLength, bool pCopy=true);
	virtual void SetSize(u64 pSize, bool pCopy=true);
	virtual void Append(const char* pStr, u64 pLen);
	virtual void Append(const char* pStr);
	virtual void Append(const char pChar);
	virtual void Append(const AckurBYTE& pChar);
	virtual void Append(s64 pNum);
	virtual void Append(u64 pId);
	virtual s64 StrNCmp(const char* pStr);
	virtual s64 StrCmp(const char* pStr);
	virtual s64 StrCmp(AckurBYTE& pStr);
	virtual s64 StrUpperCmp(const char* pStr, u64 pLen = 0);
	virtual s64 StrUpperCmp(AckurBYTE& pStr);
	virtual s64 StrLowerCmp(const char* pStr, u64 pLen = 0);
	virtual s64 StrLowerCmp(AckurBYTE& pStr);
	virtual void ToUpper();
	virtual void ToLower();
	virtual void RTrim(const char c = ' ');
	virtual void LTrim(const char c = ' ');
	virtual void Trim(const char c = ' ');
	virtual void Pad(u64 pSize, u8 pValue = ' ');
};

class AckurSS64 : public AckurValue
{
public:
	s64 mNum;
public:
	AckurSS64();
	AckurSS64(s64 pNum);
	AckurSS64(const char *pStr);
public:
	virtual void FROM(const char *pStr);
	virtual void TO(AckurCHAR& pChar);
	virtual void TO(AckurSS64& pNumber);
public:
	virtual void* GetPtr();
	virtual u64 GetLength();
public:
	void BigEndian();
};

class AckurSU64 : public AckurValue
{
public:
	u64 mNum;
public:
	AckurSU64();
	AckurSU64(u64 pNum);
	AckurSU64(const char *pStr);
	AckurSU64(const char *pStr, u64 pLen);
public:
	virtual void FROM(const char *pStr);
	virtual void FROM(const char *pStr, u64 pLen);
	virtual void TO(AckurCHAR& pChar);
	virtual void TO(AckurSU64& pNumber);
public:
	virtual void* GetPtr();
	virtual u64 GetLength();
public:
	void BigEndian();
};

class AckurDU64 : public AckurValue
{
public:
	du64 mNum;
public:
	AckurDU64();
	AckurDU64(du64 pNum);
public:
	virtual void TO(AckurCHAR& pChar);
	virtual void TO(AckurDU64& pNumber);
public:
	virtual void* GetPtr();
	virtual u64 GetLength();
public:
	void BigEndian();
};

class AckurTIME : public AckurValue
{
public:
	s64 mSec;
public:
	AckurTIME();
	AckurTIME(const AckurCHAR& pChar);
public:
	virtual void Now();
	virtual void ToBytes(AckurCHAR& pChar);
	virtual void FromBytes(const AckurBYTE& pChar);
	virtual void ToString(AckurCHAR& pChar);
	virtual void FromString(const AckurCHAR& pChar);
	virtual s64 LocalOffset();
	AckurCHAR getBytes();
	AckurCHAR getString();
public:
	virtual void* GetPtr();
	virtual u64 GetLength();
};

class AckurVoidArray : public AckurBYTE
{
public:
	AckurVoidArray(u32 pCount=0);
	~AckurVoidArray();
public:
	virtual void Init(u32 pCount=0);
	virtual void Append(void *pItem);
	virtual u32 Count();
	void* GetAt(u32 i);
};

class AckurCHARArray : public AckurVoidArray
{
public:
	AckurCHARArray(u32 pCount=0);
	~AckurCHARArray();
public:
	virtual void Append(char *pStr);
};

class AckurDU64Array : public AckurVoidArray
{
public:
	AckurDU64Array(u32 pCount=0);
	~AckurDU64Array();
public:
	virtual void Append(du64 pNum);
	virtual void Append(u64 key, u64 value);
};

class AckurArray64 : public AckurBYTE
{
public:
	AckurArray64();
	AckurArray64& operator=(const AckurArray64& that);
private:
	void INIT();
public:
	virtual u64 GetCount();
	virtual void SetCount(u64 pCount);
	virtual void GrowCount(u64 pCount);
	virtual void SetItem(u64 pItem, u64 pValue);
	virtual u64 GetItem(u64 pItem);
};

////////////////////////////////////////////////////////////////////////////////

class AckurEvent
{
public:
	AckurEvent();
	virtual ~AckurEvent();
	virtual void Flush();
public:
	virtual void SetNext(AckurEvent* pNext);
	virtual void SetPrev(AckurEvent* pPrev);
	virtual AckurEvent* Next();
	virtual AckurEvent* Prev();
protected:
	AckurEvent *mNext, *mPrev;
};

class AckurState;

class AckurQueue : public AckurCritical
{
public:
	u64 mCount;
	AckurState *mState;
public:
	AckurQueue();
	virtual ~AckurQueue();
	virtual void Flush();
public:
	virtual void PushHead(AckurEvent* pEvent);
	virtual void PushTail(AckurEvent* pEvent);
	virtual void PushNext(AckurEvent* pLocation, AckurEvent* pEvent);
	virtual AckurEvent* Head(u64 mSkip = 0);
	virtual AckurEvent* Tail(u64 mSkip = 0);
	virtual AckurEvent* PopHead();
	virtual AckurEvent* PopTail();
	virtual AckurEvent* PopEvent(AckurEvent* pEvent);
	virtual u64 GenId();
protected:
	AckurEvent *mHead, *mTail;
	u64 mId;
};

class AckurState : public AckurThread
{
public:
	AckurState();
	virtual ~AckurState();
	virtual void Flush();
public:
	virtual void SetInput(AckurQueue* pInput);
	virtual void SetQueue(AckurQueue* pQueue);
	virtual void SetOutput(AckurQueue* pOutput);
	virtual AckurQueue* GetQueue();
	virtual void PushInputTail(AckurEvent* pEvent);
	virtual void PushOutputTail(AckurEvent* pEvent);
protected:
	AckurQueue *mInput;
	AckurQueue *mQueue;
	AckurQueue *mOutput;
};

////////////////////////////////////////////////////////////////////////////////

class AckurWorkEvent : public AckurEvent, public AckurThread
{
public:
	AckurWorkEvent();
	virtual void Set(AckurQueue *pQueue);
	virtual void Starting();
	virtual void Stopping();
protected:
	AckurQueue *vQueue;
};

class AckurWorkQueue : public AckurQueue
{
public:
	virtual AckurError Start();
};

////////////////////////////////////////////////////////////////////////////////

class AckurCHARFile : public AckurCHAR, public AckurFile
{
public:
	AckurCHARFile();
	virtual AckurError Flush();
public:
	virtual bool    Opened();
	virtual AckurError Open(const char *fileName, OpenType mode = ReadOnly);
	virtual AckurError Close();
	virtual AckurError GetSize(u64& pSize);
	virtual AckurError SetSize(u64 pSize);
	virtual AckurError Create(const char *fileName);
	virtual AckurError Delete(const char *fileName);
	virtual AckurError Purge(u64 blockCount, u16 blockSize);
	virtual AckurError Write(u64 blockPos, u16 blockSize, u64 offset, u64 length, const void *b);
	virtual AckurError Read(u64 blockPos, u16 blockSize, u64 offset, u64 length, void *b);
	virtual AckurError Append(u64 length, const void *b);
};

////////////////////////////////////////////////////////////////////////////////

class AckurCHARQueue;

class AckurCHAREvent : public AckurEvent
{
public:
	u8 mType;
	u64 mId, mPos;
	AckurCHAR mName;
	AckurCHARFile mValue;
	AckurCHARQueue *vQueue;
public:
	AckurCHAREvent();
	AckurCHAREvent(const char* pName, u8 pType = 0, u64 pId = 0, const char* pValue = NULL, u64 pLen = 0);
	AckurCHAREvent(AckurCHAR& pName, u8 pType, u64 pId, AckurBYTE& pValue);
	virtual ~AckurCHAREvent();
	virtual void Flush();
private:
	void INIT();
public:
	virtual void SetItem(const char* pName, u8 pType, u64 pId, const char* pValue, u64 pLen);
	virtual void SetItem(AckurCHAR& pName, u8 pType, u64 pId, AckurBYTE& pValue);
	virtual AckurCHAREvent* Next();
	virtual AckurCHAREvent* Prev();
};

class AckurCHARQueue : public AckurQueue
{
public:
	virtual void Flush();
public:
	virtual AckurCHAREvent* Search(const char* pName);
	virtual AckurCHAREvent* Search(AckurCHAR& pName);
	virtual AckurCHAREvent* Search(u64 pId);
	virtual u64 SearchId(const char* pName);
	virtual u64 SearchId(AckurCHAR& pName);
	virtual AckurCHAREvent* Head(u64 mSkip = 0);
	virtual AckurCHAREvent* Tail(u64 mSkip = 0);
	virtual AckurCHAREvent* PopHead();
	virtual AckurCHAREvent* PopTail();
	virtual AckurCHAREvent* PopEvent(AckurEvent* pEvent);
	virtual void AppendNames(const char* pNameList, const char* pDelimList);
	virtual void AppendNames(AckurCHAR& pNameList, AckurCHAR& pDelimList);
	virtual void ListNames(AckurCHAR& pNameList, const char pDelim);
};

////////////////////////////////////////////////////////////////////////////////

#endif // _AckurValue_

////////////////////////////////////////////////////////////////////////////////
//	20-Jun-01	cmatichuk	Created
