#include "yaz0.h"

#include <byteswap.h>
#include <nn/types.h>

namespace Yaz0 {

#define __int8 s8

void Decompress(const char* src, char* dst) {
    int v2;               // w6
    unsigned int v3;      // w4
    int v4;               // w2
    char* v5;             // x1
    unsigned int v6;      // w5
    int v7;               // t1
    u8* v8;  // x1
    int v9;               // w3
    int v10;              // t1
    int v11;              // t1
    unsigned int v12;     // w3
    unsigned int v13;     // w9
    int v14;              // w3
    unsigned int v15;     // w7
    int v16;              // t1
    char v17;             // t1

    v3 = __bswap_32(*((s32*)src + 1));
    v4 = v3;
    v5 = (char*)src + 16;
    v6 = 0;
    do {
        while (1) {
            v6 >>= 1;
            if (!v6) {
                v7 = (u8)*v5++;
                v2 = v7;
                v6 = 128;
            }

            if ((v2 & v6) == 0)
                break;

            v17 = *v5++;
            --v3;
            *(u8*)dst = v17;
            dst = (char*)dst + 1;
            if (!v3)
                return;
        }

        v10 = (u8)*v5;
        v8 = (u8*)(v5 + 1);
        v9 = v10;
        v11 = *v8;
        v5 = (char*)(v8 + 1);
        v12 = v11 + (v9 << 8);
        v13 = v12 >> 12;
        v14 = (v12 & 0xFFF) + 1;
        v15 = v13 + 2;
        if (!v13) {
            v16 = (u8)*v5++;
            v15 = v16 + 18;
        }

        v3 -= v15;
        do {
            --v15;
            *(u8*)dst = *((u8*)dst - v14);
            dst = (char*)dst + 1;
        } while (v15);
    } while (v3);

    return;
}

}  // namespace Yaz0
