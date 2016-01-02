// AckurFile.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurFile_
#define _AckurFile_

#include "AckurType.h"

class AckurFile
{
public:
	typedef enum _OpenType {
		ReadOnly = 'r',
		WriteOnly = 'o',
		ReadWrite = 'w',
		ReadWriteCreate = 'c',
	} OpenType;
public:
	AckurFile() : mOpened(false), mMode(ReadOnly) {}
	virtual bool    Opened() { return mOpened; }
	virtual AckurError Open(const char *fileName, OpenType mode=ReadOnly ) = 0;
	virtual AckurError Close() = 0;
	virtual AckurError GetSize(u64& pSize) = 0;
	virtual AckurError SetSize(u64 pSize) = 0;
	virtual AckurError Create(const char *fileName) = 0;
	virtual AckurError Delete(const char *fileName) = 0;
	virtual AckurError Flush() = 0;
	virtual AckurError Purge(u64 blockCount, u16 blockSize) = 0;
	virtual AckurError Write(u64 blockPos, u16 blockSize, u64 offset, u64 length, const void *b) = 0;
	virtual AckurError Read(u64 blockPos, u16 blockSize, u64 offset, u64 length, void *b) = 0;
	virtual AckurError Append(u64 length, const void *b) = 0;
protected:
	bool mOpened;
	OpenType mMode;
};


#endif //_AckurFile_

////////////////////////////////////////////////////////////////////////////////
//	20-Jun-01	cmatichuk	Created
