// AckurZip.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurZip_
#define _AckurZip_

#include "AckurValue.h"

class AckurZip
{
public:
	static void Compress(AckurBYTE& pData);
	static void Expand(AckurBYTE& pData);
	static void Compress(AckurBYTE& pData, AckurBYTE& pEnc);
	static void Expand(AckurBYTE& pEnc, AckurBYTE& pData);
};


#endif // _AckurZip_

////////////////////////////////////////////////////////////////////////////////
