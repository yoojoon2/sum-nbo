#pragma once
#include <stdint.h>

// NBO로 저장된 파일에서 uint32_t 값을 읽어오는 함수
int read_nbo(const char* filename, uint32_t* out);
