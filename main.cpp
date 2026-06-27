#include <stdio.h>
#include <stdint.h>
#include <cstring>
#include "sum-nbo.h"

int main(int argc, char* argv[]) {
    // 인자가 없으면 사용법 출력
    if (argc < 2) {
        printf("syntax: sum-nbo <file1> [<file2>...]\n");
        printf("sample: sum-nbo a.bin b.bin c.bin\n");
        return -1;
    }

    uint32_t total = 0;
    char output[4096] = "";
    char tmp[64];

    for (int i = 1; i < argc; i++) {
        uint32_t val;

        // 파일 읽기 실패시 종료
        if (read_nbo(argv[i], &val) != 0)
            return -1;

        // 출력 문자열 조합
        if (i == 1)
            sprintf(tmp, "%u(0x%08x)", val, val);
        else
            sprintf(tmp, " + %u(0x%08x)", val, val);
        strcat(output, tmp);

        // 합산
        total += val;
    }

    printf("%s = %u(0x%08x)\n", output, total, total);
    return 0;
}
