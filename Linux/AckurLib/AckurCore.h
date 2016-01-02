// AckurCore.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurCore_
#define _AckurCore_

#include "AckurFile.h"
#include "AckurCoreBlock.h"

class AckurCursor;

class AckurCore
{
public:
	// if another item is added, emums for dependants will also change, so DB version needs to change with it
	enum { SU64_ITEM=0, TREE_ITEM, SDATA_ITEM, BDATA_ITEM, LAST_ITEM, }; 
	enum { SU64_TREE=0, SDATA_TREE, BDATA_TREE, LAST_TREE, };
	enum { BYTE_DATA = 0, FREC_DATA, LAST_DATA, };
	enum { DATA_STORE=0, LAST_STORE, };
	enum { SEARCH_MODE=0, INSERT_MODE, DELETE_MODE, LAST_MODE, };
	enum { ENCODE_NONE = 0, ENCODE_ZIP = 0x01, ENCODE_AES = 0x02, };
	enum { NODE_WIDTH=5 };
	enum { CMP_LT=-1, CMP_EQ=0, CMP_GT=1, };

	u8 mFlags;
	AckurFile *mFile;

public:
    AckurCore();
	virtual ~AckurCore() { SetFile(); mFlags = 0; }

    virtual void    SetFile      (AckurFile *pFile=NULL);

	virtual AckurError OpenFile(const char *fileName, AckurFile::OpenType mode);
	virtual u64 RootTree(u8& pType);
    virtual AckurError CloseFile    ();
	virtual AckurError Create(const char *fileName);
	virtual AckurError RemoveFile(const char *fileName);
    virtual AckurError FlushFile    ();
	virtual AckurError ClearFile    ();
	virtual AckurError PurgeFile    ();
    virtual bool    FileOpened   ();

    virtual AckurError GetFlags (u8& settings);
    virtual AckurError SetFlags (u8 settings);
	virtual AckurError	GetCompressSize(u8& size);
	virtual AckurError	SetCompressSize(u8 size);

	static inline s8 CompareKey(u64 a, u64 b) {return (a > b) ? CMP_GT : ((b > a) ? CMP_LT : CMP_EQ);}
	virtual AckurError CompareKey(s16 compareType, AckurCursor& dataCursor, AckurCursor& treeCursor, s8& result);
    virtual AckurError DeleteKey(AckurCursor& treeCursor);

    virtual AckurError GetWeight(AckurCursor& treeCursor, u64& itemWeight);
    virtual AckurError GainWeight(AckurCursor& treeCursor, u64& treeValue, u64 itemWeight, u64 childWeight);
    virtual AckurError LooseWeight(AckurCursor& treeCursor, u64& treeValue, u64 itemWeight, u64 childWeight);

    virtual AckurError SetFileTree  (u64 firstTree, bool deleteExisting=true);
    virtual u64 FirstTree        (u64 treePtr);

	virtual AckurError NewTree      (u64& treePtr, u8 treeType, u64 parentTree=0L, u8 nodeCount=NODE_WIDTH);
    virtual AckurError DeleteTree   (u64 treePtr);
    virtual AckurError EmptyTree    (AckurCursor& cursor);
    virtual AckurError SetTreeIndex (AckurCursor& cursor, u64 indexTree);
    virtual AckurError GetTreeIndex (AckurCursor& cursor, u64& indexTree);
    virtual AckurError SetTreeStore (AckurCursor& cursor, u64 storeTree, u8 storeType);
    virtual AckurError GetTreeStore (AckurCursor& cursor, u64& storeTree, u8& storeType);
    virtual AckurError GetTreeSize  (AckurCursor& cursor, u64& itemCount);
    virtual AckurError GetTreeDirty (AckurCursor& cursor, bool& isDirty);
    virtual AckurError SetTreeDirty (AckurCursor& cursor, bool isDirty);
	virtual AckurError GetTreeType  (AckurCursor& cursor, u8& treeType);
	virtual AckurError SetTreeType  (AckurCursor& cursor, u8 treeType);
	virtual AckurError GetTreeParent(AckurCursor& cursor, u64& parentTree);

	// need to add a minByteCount and maxByteCount,
	// and then a way to get the first available block within a size range
	// will be used to string data blocks together for very large BLOBs
	// the BLOCKS will be strung together using a TREE for fast lookups and updates
    virtual AckurError NewData      (u8 dataType, u64 parentTree, u64 dataSize, u64 growBlockSize, u64 growBlocks, u64& itemPtr, bool clear=false);
    virtual AckurError DeleteData   (u64 itemPtr);
	virtual AckurError SetDataSize(u64 itemPtr, u64 dataSize, u64 dataLength, u8 encodeType);
	virtual AckurError GetDataSize(u64 itemPtr, u64& growBlockSize, u64& dataSize, u64& dataLength, u8& encodeType);
	virtual AckurError SetFieldType(u64 itemPtr, u8 fieldType);
	virtual AckurError GetFieldType(u64 itemPtr, u8& fieldType);
	virtual AckurError ClearDataValue(u64 itemPtr, u64 offset, u64 dataSize);
	virtual AckurError SetDataValue(u64 itemPtr, u64 offset, u64 dataSize, void *buffer, u64 *returnSize = NULL);
    virtual AckurError GetDataValue (u64 itemPtr, u64 offset, u64 bufferSize, void *buffer, u64 *returnSize=NULL);
    virtual AckurError InsertDataValue (u64 itemPtr, u64 offset, u64 dataSize, void *buffer, u64 *returnSize=NULL);
	virtual AckurError DeleteDataValue (u64 itemPtr, u64 offset, u64 dataSize, u64 *returnSize=NULL);
    virtual AckurError CopyDataValue (u64 toPtr, u64 toOffset, u64 fromPtr, u64 fromOffset, u64 copySize, u64 *returnSize=NULL);
    virtual AckurError MoveDataValue (u64 toPtr, u64 toOffset, u64 fromPtr, u64 fromOffset, u64 moveSize, u64 *returnSize=NULL);
	virtual AckurError GetDataParent(u64 dataRef, u64& parentTree);

    virtual AckurError Search       (AckurCursor& cursor);
    virtual AckurError Insert       (AckurCursor& cursor);
    virtual AckurError Update       (AckurCursor& cursor);
    virtual AckurError Delete       (AckurCursor& cursor);

    virtual AckurError First        (AckurCursor& cursor);
    virtual AckurError Last         (AckurCursor& cursor);
    virtual AckurError Next         (AckurCursor& cursor);
    virtual AckurError Prev         (AckurCursor& cursor);

protected:
	u8 mBuffer[AckurBlock::COPYSIZE];

protected:
	AckurError FindFirstX(u64 offset, AckurCursor& cursor);
	AckurError FindLastX(u64 offset, AckurCursor& cursor);

	bool SearchNode(u64 rootNode, AckurCursor& key, s8& pos, u64& child, AckurBlockNodeLeaf& foundKey, s16 compareType);
	bool SearchRc(u64 rootNode, AckurCursor& key, AckurBlockNodeLeaf& foundKey);
	AckurError InsInPage(AckurBlockTree& head, AckurCursor& treekey, u64 rootNode, AckurBlockNodeHeader& page, AckurBlockNodeLeaf& key, s8 pos);

	void RotateLeafLeft(u64 headRef, AckurBlockTree& head, s8 pos, u64 rootPage, AckurBlockNodeHeader& rootTree, 
			u64 leftOffset, AckurBlockNodeHeader& leftTree, u64 rightOffset, AckurBlockNodeHeader& rightTree);
	void RotateLeafRight(u64 headRef, AckurBlockTree& head, s8 pos, u64 rootPage, AckurBlockNodeHeader& rootTree, 
			u64 leftOffset, AckurBlockNodeHeader& leftTree, u64 rightOffset, AckurBlockNodeHeader& rightTree);

	void MirgeLeft(u64 headRef, AckurBlockTree& head, u64 rootOffset, s8 pos, AckurBlockNodeHeader& rootTree, 
			u64 leftOffset, AckurBlockNodeHeader& leftTree, u64 rightOffset, AckurBlockNodeHeader& rightTree);
	void Split(u64 headRef, AckurBlockTree& head, u64 rootNode, 
			AckurBlockNodeHeader& oldPage, AckurBlockNodeLeaf& key, s8 inPos, AckurBlockNodeLeaf& pKey);
				
	AckurError SetKey(AckurBlockTree& head, AckurBlockNodeLeaf& leaf, AckurCursor& cursor);
	AckurError InsertRc(u64 headRef, AckurBlockTree& head, u64 rootNode,
			AckurCursor& key, AckurBlockNodeLeaf& pKey, AckurBlockNodeLeaf& fKey, s8& result);
	AckurError PurgeRc(u64 headRef, AckurBlockTree& head, u64 rootNode, AckurCursor& key,
			AckurBlockNodeHeader& rootTree, s8& result);

	AckurError UpdateChildInfo(u64 childBlock, u64 newBlock, s8 newIndex);
	AckurError UpdateLeafInfo(AckurBlockNodeLeaf* key, u64 newBlock, s8 newIndex);
	AckurError MoveLeaf(u64 headRef, AckurBlockTree& head, AckurBlockNodeHeader& oldPage, u64 rootNode, s8 rootIndex, AckurBlockNodeHeader& newPage, u64 newBlock, s8 newIndex);

	AckurError EmptyItem(u64 headRef, AckurBlockTree& head, u64 pagePos);
	AckurError AppendNode(u64 headRef, AckurBlockTree& head, AckurBlockNodeLeaf& promKey);

	void RotateParrentRight(u64 headRef, AckurBlockTree& head, u64 middleOffset, AckurBlockNodeHeader& middleTree);
	void RotateParrentLeft(u64 headRef, AckurBlockTree& head, u64 middleOffset, AckurBlockNodeHeader& middleTree);

protected:
	AckurError GetChildWeight(u64 childBlock, u64& childWeight);
	AckurError RotateItemWeight(u64 headRef, AckurBlockTree& head, u64 rootTree, AckurBlockNodeLeaf& fromKey, AckurBlockNodeHeader& fromTree, AckurBlockNodeLeaf& toKey, AckurBlockNodeHeader& toTree, u64 child);
	AckurError LooseWeightCascading(AckurCursor& cursor, u64 rootTree, AckurBlockNodeHeader& oldPage, u64 child);
	AckurError GainWeightCascading(AckurCursor& cursor, u64 rootTree, AckurBlockNodeHeader& newPage, u64 child, u64 fistChild);
	AckurError GainChildWeightCascading(AckurCursor& cursor, u64 rootTree, AckurBlockNodeHeader& newPage, u64 child, u64 fistChild);

protected:
	bool SearchNodeFrag(u64 rootNode, AckurCursor& key, s8& pos, u64& child, AckurBlockNodeLeaf& foundKey, s16 compareType);

	AckurError NewDataByte(AckurBlockDataHeader& data, bool clear=false);
    AckurError DeleteDataByte(AckurBlockDataHeader& data);
	AckurError	SetDataSizeByte(u64 itemPtr, AckurBlockDataHeader& data, u64 dataSize, u64 dataLength);
	AckurError	GetDataSizeByte(AckurBlockDataHeader& data, u64& growBlockSize, u64& dataSize, u64& dataLength);
	AckurError	SetDataValueByte(u64 itemPtr, AckurBlockDataHeader& data, u64 offset, u64 dataSize, void *buffer, u64 *returnSize);
	AckurError	GetDataValueByte(AckurBlockDataHeader& data, u64 offset, u64 bufferSize, void *buffer, u64 *returnSize);
    AckurError InsertDataValueByte(u64 itemPtr, AckurBlockDataHeader& data, u64 offset, u64 dataSize, void *buffer, u64 *returnSize=NULL);
	AckurError DeleteDataValueByte(u64 itemPtr, AckurBlockDataHeader& data, u64 offset, u64 dataSize, u64 *returnSize=NULL);
    AckurError MoveDataValueByte(u64 toPtr, AckurBlockDataHeader& toData, u64 toOffset, u64 fromPtr, AckurBlockDataHeader& fromData, u64 fromOffset, u64 moveSize, u64 *returnSize=NULL);

    AckurError NewDataFrag(AckurBlockDataHeader& data, bool clear=false);
    AckurError DeleteDataFrag(AckurBlockDataHeader& data);
	AckurError	SetDataSizeFrag(u64 itemPtr, AckurBlockDataHeader& data, u64 dataSize, u64 dataLength);
	AckurError	GetDataSizeFrag(AckurBlockDataHeader& data, u64& growBlockSize, u64& dataSize, u64& dataLength);
	AckurError	SetDataValueFrag(u64 itemPtr, AckurBlockDataHeader& data, u64 offset, u64 dataSize, void *buffer, u64 *returnSize);
	AckurError	GetDataValueFrag(AckurBlockDataHeader& data, u64 offset, u64 bufferSize, void *buffer, u64 *returnSize);
    AckurError InsertDataValueFrag(u64 itemPtr, AckurBlockDataHeader& data, u64 offset, u64 dataSize, void *buffer, u64 *returnSize=NULL);
	AckurError DeleteDataValueFrag(u64 itemPtr, AckurBlockDataHeader& data, u64 offset, u64 dataSize, u64 *returnSize=NULL);
    AckurError MoveDataValueFrag(u64 toPtr, AckurBlockDataHeader& toData, u64 toOffset, u64 fromPtr, AckurBlockDataHeader& fromData, u64 fromOffset, u64 moveSize, u64 *returnSize=NULL);
    AckurError UpdateDataKeyFrag(AckurCursor& cursor);

protected:
	u64 FindFreePage(AckurBlockPage& newHole, u64 maxBlockCount, u64 minBlockCount=0, u64* blocksReturned=NULL);
	u64 NewPage(u64 byteCount, bool clear);
	AckurError PurgePage(u64 pagePos, u64 byteCount);

};

class AckurCursor
{
public:
	AckurCursor() {Set(0);}
    virtual void Set(u64 pTreeRef, s8 pValueType=0, u64 pKey=0, u64 pValue=0, u8 pFlags=0)
	{
		mValueType = pValueType;
		mNodeIndex = 0;
		mFlags = pFlags;
		mTreeType = 0;
		reserved = 0;
		mTreeRef = pTreeRef;
		mKey = pKey;
		mValue = pValue;
		mNodeRef = 0;
		mLength = 0;
	}
public:
	s8 mValueType;
	s8 mNodeIndex;
	u8 mFlags;
	u8 mTreeType;
	u32 reserved;
	u64 mTreeRef;
	u64 mKey;
	u64 mValue;
	u64 mNodeRef;
	u64 mLength;
};

#endif //_AckurCore_

////////////////////////////////////////////////////////////////////////////////
//	20-Jun-01	cmatichuk	Created
