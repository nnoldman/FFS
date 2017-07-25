#ifndef PKG_h__
#define PKG_h__

#include "Default.h"

#pragma pack(push)
#pragma pack(1)

#define zeroArray(arr) memset(arr,0,sizeof(arr))
#define zeroThis(p) memset(p,0,sizeof(*p))

struct PKG {
    u32 opcode;
    u16 length;
    char data[0];
    PKG() {
    }
};

#pragma pack(pop)
#endif // PKG_h__
