#include "yaz0.h"

// modified from
// https://gist.github.com/khang06/e407b25d86923bb881ff1923a4447667

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

namespace Yaz0 {
    struct Header {
        uint16_t magic[4];
        uint32_t decmp_size;
        int32_t unknown[2];
    };

    int GetDecompressedSize(const char *src) {
        Header header;

        header = *reinterpret_cast<const Header*>(src);

        if (memcmp(&header.magic, "Yaz0", 4)) {
            throw "Input is not Yaz0!";
        }

        return header.decmp_size;
    }

    void Decompress(const char *src, char *dst) {
        Header header;
        uint16_t code_byte;
        uint32_t valid_bit_count = 0;
        uint32_t src_pos = 16;
        uint32_t dst_pos = 0;

        uint16_t byte1;
        uint16_t byte2;
        uint32_t copy_src;
        uint32_t copy_len;

        header = *reinterpret_cast<const Header*>(src);

        if (memcmp(&header.magic, "Yaz0", 4)) {
            throw "Input is not Yaz0!";
        }

        code_byte = src[16];

        while (dst_pos < header.decmp_size) {
            if (valid_bit_count == 0) {
                code_byte = src[src_pos];
                src_pos++;
                valid_bit_count = 8;
            }

            if ((code_byte & 0x80) != 0) {
                dst[dst_pos] = src[src_pos];
                src_pos++;
                dst_pos++;
            }
            else {
                byte1 = src[src_pos];
                src_pos++;
                byte2 = src[src_pos];
                src_pos++;

                copy_src = dst_pos - ((byte1 & 0x0f) << 8 | byte2) - 1;
                copy_len = byte1 >> 4;

                if (copy_len == 0) {
                    copy_len = src[src_pos] + 0x12;
                    src_pos++;
                }
                else {
                    copy_len += 2;
                }

                for (uint32_t i = 0; i < copy_len; i++) {
                    if (copy_src > header.decmp_size)
                        printf("oob copy_src: %08X\n", copy_src);
                    if (dst_pos > header.decmp_size)
                        printf("oob dst_pos: %08X\n", dst_pos);
                    dst[dst_pos] = dst[copy_src];
                    copy_src++;
                    dst_pos++;
                }
            }

            code_byte <<= 1;
            valid_bit_count -= 1;
        }
    }
}
