// AckurCoreBlock.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurCoreBlock_
#define _AckurCoreBlock_

#include "AckurFile.h"

class AckurBlock
{
public:
	enum { BLOCKSIZE = 32, BLOCKS32 = 1, COPYSIZE = 1024 };
	enum { FILE_BLOCK = 0, FIRST_BLOCK, TREE_BLOCK, NODE_BLOCK, LEAF_BLOCK, DATA_BLOCK, PAGE_BLOCK, };
};

class AckurBlockNodeHeader
{
public:
	struct{
		u8 blockType;	// NODE_BLOCK
		u8 flags;
		s8 parentIndex; // need to leave this as signed, a -1 indicates parent is AckurBlockTree
		u8 leafCount;
		u8 reserved[4];
		u64 weight;
		u64 parent;
		u64 firstChild;
	};
	void BigEndian();
	static u16 GetBlocks() { return(AckurBlock::BLOCKS32); }
	static u16 GetSize() { return(AckurBlock::BLOCKSIZE*GetBlocks()); }
	void Init();
	AckurError Write(AckurFile *pFile, u64 blockPos);
	AckurError Read(AckurFile *pFile, u64 blockPos);
};

class AckurBlockNodeLeaf
{
public:
	struct{
		u8 blockType;	// LEAF_BLOCK
		u8 flags;
		u8 valueType; // NUMBER, TREE_BLOCK, DATA_BLOCK
		u8 recordFlags;
		u8 reserved[4];
		u64 key;
		u64 value;
		u64 child;
	};
	void BigEndian();
	static u16 GetBlocks() { return(AckurBlock::BLOCKS32); }
	static u16 GetSize() { return(AckurBlock::BLOCKSIZE*GetBlocks()); }
	static u64 GetOffset(u64 blockPos, s8 indexPos);
	void Init();
	AckurError Write(AckurFile *pFile, u64 blockPos);
	AckurError Write(AckurFile *pFile, u64 blockPos, s8 indexPos);
	AckurError Read(AckurFile *pFile, u64 blockPos);
	AckurError Read(AckurFile *pFile, u64 blockPos, s8 indexPos);
};

class AckurBlockDataHeader
{
public:
	struct{
		u8 blockType;	// DATA_BLOCK
		u8 dataType;   // used by the DB to identify how to process the data
		u8 fieldType;
		u8 encodeType;
		u8 reserved[4];
		u64 parentTree;
		u64 growBlockSize;
		u64 growSize;
		u64 dataSize;
		u64 dataLength;
		u64 dataStart;
		u64 reserved2;
	};
	void BigEndian();
	static u16 GetBlocks() { return(AckurBlock::BLOCKS32 * 2); }
	static u16 GetSize() { return(AckurBlock::BLOCKSIZE*GetBlocks()); }
	void Init();
	AckurError Write(AckurFile *pFile, u64 blockPos);
	AckurError Read(AckurFile *pFile, u64 blockPos);
};

class AckurBlockPage
{
public:
	struct{
		u8 blockType;	// PAGE_BLOCK
		u8 flags;
		u8 reserved[6];
		u64 reserved2;
		u64 blockCount;
		u64 nextPage;
	};
	void BigEndian();
	static u16 GetBlocks() { return(AckurBlock::BLOCKS32); }
	static u16 GetSize() { return(AckurBlock::BLOCKSIZE*GetBlocks()); }
	void Init();
	AckurError Write(AckurFile *pFile, u64 blockPos);
	AckurError Read(AckurFile *pFile, u64 blockPos);
};

class AckurBlockTree
{
public:
	struct{
		u8 blockType;	// TREE_BLOCK
		u8 flags;		// 0x80=dirty
		s8 nodeCount;	// Need to leave this as signed. The logic in AckurCore.cpp depends on negative.
		u8 treeType;
		u8 storeType;
		u8 reserved[3];
		u64 itemCount;
		u64 firstItem;
		u64 storeTree;
		u64 indexTree;
		u64 parentTree;
		u64 reserved2[2];
	};
	void BigEndian();
	static u16 GetBlocks() { return(AckurBlock::BLOCKS32 * 2); }
	static u16 GetSize() { return(AckurBlock::BLOCKSIZE*GetBlocks()); }
	void Init();
	bool GetDirty();
	void SetDirty(bool isDirty);
	AckurError Write(AckurFile *pFile, u64 blockPos);
	AckurError Read(AckurFile *pFile, u64 blockPos);
};

class AckurBlockFileHeader
{
public:
	struct{
		u8 blockType;	// FILE_BLOCK
		u8 flags;	// Bit1 (0=LittleEndian;1=BigEndian)
		u8 fileRef1;	// 'BT'
		u8 fileRef2;	// 'BT'
		u8 version1;
		u8 version2;
		u8 compressSize;
		u8 blockSize;
		u64 firstTree;
		u64 firstBlock;
		u64 reserved1;
		u64 reserved2[4];
	};
	void BigEndian();
	static u16 GetBlocks() { return(AckurBlock::BLOCKS32 * 2); }
	static u16 GetSize() { return(AckurBlock::BLOCKSIZE*GetBlocks()); }
	void Init();
	AckurError Write(AckurFile *pFile, u64 blockPos);
	AckurError Read(AckurFile *pFile, u64 blockPos);
};

class AckurBlockFirst
{
public:
	struct {
		u8 blockType;  //FIRST_BLOCK
		u8 flags;
		u8 reserved[6];
		u64 reserved2;
		u64 blockCount;
		u64 firstPage;
	};
	void BigEndian();
	static u16 GetBlocks() { return(AckurBlock::BLOCKS32); }
	static u16 GetSize() { return(AckurBlock::BLOCKSIZE*GetBlocks()); }
	void Init();
	AckurError Write(AckurFile *pFile, u64 blockPos);
	AckurError Read(AckurFile *pFile, u64 blockPos);
};

#endif //_AckurCoreBlock_

////////////////////////////////////////////////////////////////////////////////
//	20-Jun-01	cmatichuk	Created
