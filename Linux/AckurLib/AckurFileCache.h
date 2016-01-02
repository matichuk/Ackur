// AckurFileCache.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurFileCACHE_
#define _AckurFileCACHE_

#include "AckurFile.h"
#include "AckurCore.h"

class BtCacheBlock;

class AckurFileCache : public AckurFile
{
public:
	enum { BLOCKSIZE=AckurBlock::BLOCKSIZE, BLOCKSPERPAGE=8, BLOCKPAGESIZE=BLOCKSIZE*BLOCKSPERPAGE, };
	enum { DEFAULT_HEIGHT=4, DEFAULT_SIZE=(1024*8*4)};
public:
    AckurFileCache();
	virtual ~AckurFileCache() { Close(); FreeCache();}
    virtual void    SetFile(AckurFile *pFile=NULL);
    virtual AckurError SetCache(u64 pSize=DEFAULT_SIZE, void *pCache=NULL);
	virtual bool    Opened() { return mFile?mFile->Opened():mOpened; }
	virtual AckurError Open(const char *fileName, OpenType mode=ReadOnly);
	virtual AckurError Close();
	virtual AckurError	GetSize(u64& pSize);
	virtual AckurError	SetSize(u64 pSize);
	virtual AckurError Create(const char *fileName);
	virtual AckurError Delete(const char *fileName);
	virtual AckurError Flush();
	virtual AckurError Purge(u64 blockCount, u16 blockSize);
	virtual AckurError Write(u64 blockPos, u16 blockSize, u64 offset, u64 length, void *b);
	virtual AckurError Read(u64 blockPos, u16 blockSize, u64 offset, u64 length, void *b);
	virtual AckurError Append(u64 length, void *b) {return(0);}

protected:
	virtual AckurError ClearCache();
	virtual AckurError GetCacheBlock(u64 blockPos, void* value);
	virtual AckurError SetCacheBlock(u64 blockPos, void* value, bool dirty);
	virtual AckurError FlushCache();

protected:
	virtual void    FreeCache();
	virtual AckurError GetCache(u64 blockPos, u16 blockSize, u64 offset, void* value, u64 length);
	virtual AckurError SetCache(u64 blockPos, u16 blockSize, u64 offset, void* value, u64 length, bool dirty);

private:
	u64 FindCache(BtCacheBlock *cache, u64 key, u64 first);
	u64 FindCacheFree(BtCacheBlock *cache, u64 first);

protected:
	AckurFile *mFile;

protected:
	u64 mCacheWidth,mCacheHeight;
	BtCacheBlock *mCache;
	u64* mFirstCache;
	bool mLocalyAllocated;

};

#endif //_AckurFileCACHE_

////////////////////////////////////////////////////////////////////////////////
//	20-Jun-01	cmatichuk	Created
