// AckurType.h
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AckurType_
#define _AckurType_

#ifndef s32
typedef double					d64;
typedef unsigned long long int	u64;
typedef unsigned int			u32;
typedef unsigned short			u16;
typedef unsigned char			u8;
typedef signed long long int	s64;
typedef signed int				s32; // max = 2,147,483,647
typedef signed short			s16; // max = 32,767
typedef signed char				s8;
typedef struct _du64{u64 key,value;} du64;
#endif

typedef s32                 AckurError;

#ifndef NULL
#define NULL 0LL
#endif

#endif //_AckurType_

////////////////////////////////////////////////////////////////////////////////
//	20-Jun-01	cmatichuk	Created
