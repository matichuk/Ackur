// AckurFileIO.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurFileIO_
#define _AckurFileIO_

#include "AckurFile.h"

class AckurFileIO : public AckurFile
{
public:
	int mFp;
public:
	AckurFileIO() : mFp(-1) {}
	virtual ~AckurFileIO() { Close(); }
	virtual AckurError Open(const char *fileName, OpenType mode=ReadOnly);
	virtual AckurError Close();
	virtual AckurError GetSize(u64& pSize);
	virtual AckurError SetSize(u64 pSize);
	virtual AckurError Create(const char *fileName);
	virtual AckurError Delete(const char *fileName);
	virtual AckurError Flush();
	virtual AckurError Purge(u64 blockCount, u16 blockSize);
	virtual AckurError Write(u64 blockPos, u16 blockSize, u64 offset, u64 length, const void *b);
	virtual AckurError Read(u64 blockPos, u16 blockSize, u64 offset, u64 length, void *b);
	virtual AckurError Append(u64 length, const void *b);
};

#endif //_AckurFileIO_

////////////////////////////////////////////////////////////////////////////////
//	20-Jun-01	cmatichuk	Created
