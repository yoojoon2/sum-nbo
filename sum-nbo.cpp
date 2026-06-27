#include "sum-nbo.h"
#include <stdio.h>
#include <arpa/inet.h>

// 파일을 열어 4바이트를 읽고 HBO로 변환해서 반환
int read_nbo(const char* filename, uint32_t* out) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        fprintf(stderr, "error: cannot open file %s\n", filename);
        return -1;
    }

    uint32_t nbo;
    size_t res = fread(&nbo, sizeof(nbo), 1, f);
    fclose(f);

    if (res != 1) {
        fprintf(stderr, "error: cannot read 4 bytes from %s\n", filename);
        return -1;
    }

    // NBO(빅엔디안) → HBO(리틀엔디안) 변환
    *out = ntohl(nbo);
    return 0;
}
