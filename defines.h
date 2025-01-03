#ifndef DEFINES_H
#define DEFINES_H

#include <stdbool.h>
#include <stdint.h>

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef float f32;

typedef i8  b8;
typedef i16 b16;
typedef i32 b32;

#define Bytes(value) (value)
#define Kilobytes(value) (value << 10)
#define Megabytes(value) (value << 20)
#define Gigabytes(value) ((u64)(value) << 30)
#define Terabytes(value) ((u64)(value) << 40)

#define ArrayCount(a) (sizeof((a)) / sizeof(*(a)))

#define Clamp(value, min, max)                                                \
    ((value <= min) ? min : (value >= max) ? max : value)
#define ClampTop(value, max) ((value >= max) ? max : value)

#endif // DEFINES_H
