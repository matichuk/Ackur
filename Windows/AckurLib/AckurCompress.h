// AckurZip.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurCompress_
#define _AckurCompress_

#include "AckurValue.h"

class AckurCompress
{
public:
	static void Compress(AckurBYTE& pData);
	static void Expand(AckurBYTE& pData);
	static void Compress(AckurBYTE& pData, AckurBYTE& pEnc);
	static void Expand(AckurBYTE& pEnc, AckurBYTE& pData);
};


#endif // _AckurCompress_

////////////////////////////////////////////////////////////////////////////////
