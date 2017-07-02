// AckurBlockFile.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurBlockFile_
#define _AckurBlockFile_

#include "AckurFile.h"
#include "AckurBTree.h"
#include "AckurValue.h"
#include "AckurFileCache.h"
#include "AckurAES256.h"

class AckurBlockFile : public AckurFile
{
public:
	AckurBlockFile();
	virtual ~AckurBlockFile();
    virtual void    SetFile(AckurFile *pFile=NULL);
	virtual void SetCode(AckurCHAR& mCode);
	virtual bool    Opened() { return mBtree.mFile ? mBtree.mFile->Opened() : mOpened; }
	virtual AckurError Open(const char *fileName, OpenType mode=ReadOnly);
	virtual AckurError Close();
	virtual AckurError	GetSize(u64& pSize);
	virtual AckurError	SetSize(u64 pSize);
	virtual AckurError Create(const char *fileName);
	virtual AckurError Delete(const char *fileName);
	virtual AckurError Flush();
	virtual AckurError Purge(u64 blockCount, u16 blockSize);
	virtual AckurError Write(u64 blockPos, u16 blockSize, u64 offset, u64 length, const void *b);
	virtual AckurError Read(u64 blockPos, u16 blockSize, u64 offset, u64 length, void *b);
	virtual AckurError Append(u64 length, const void *b) {return(0);}

public:
	virtual AckurCHAREvent* GetData(u64 blockId);
	virtual AckurError SetData(u64 blockId, AckurBYTE& value);
	virtual AckurError FlushCache();
	virtual AckurError ClearCache();

protected:
	AckurBTree mBtree;
	u32 mBlockSize;
	u64 mRoot;
	u8* vBuffer;
	AckurCHARQueue mCache;
	AckurAES256 mCode;
};

#endif //_AckurBlockFile_

////////////////////////////////////////////////////////////////////////////////
//	20-Jun-01	cmatichuk	Created
