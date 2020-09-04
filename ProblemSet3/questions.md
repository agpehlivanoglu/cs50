# Questions

## What's `stdint.h`?

In the C programming language there is no requirement about the size of integral data types, such as int or long. These data types may be 1 byte on particular architecture, 2 bytes on another, 4 or 8 on yet another. To solve this, stdint.h was created to define integer types, specify exact-width integer types, along with the defined min and max values for each type, using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

- to get unsigned/signed integers with exact width of 8, 32 or 16
- If you don't specify whether the number is signed or not, then you can interpret them incorrectly and get the wrong value. "1111 1101" is either -3 or 253, depending on whether you read it as a signed or unsigned value. Using well-defined types makes the code far easier and safer to port

### What is unsigned means?

(If you run sizeof(int) in the cs50 IDE, you'll notice that an int is 4 bytes in size (or 32 bits), this means that it can store numbers in the [−32,767, +32,767] range. An unsigned int is also 32 bits in size but it can only store numbers in the [0, 65535] range. As you can see, unsigned literally means that it can't store numbers with a sign, i.e. negative numbers, and instead can store twice as many positive numbers.)

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

- A BYTE is an 8-bit unsigned value (1 byte)
- A DWORD is a 32-bit unsigned integer (4 byte)
-A LONG is a 32-bit signed integer (4 byte)
- A WORD is a 16-bit unsigned integer (2 byte)

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x42 in hexadecimal ("B" in ASCII) and 0x4D in hexadecimal ("M" in ASCII) 

## What's the difference between `bfSize` and `biSize`?

biSize is the size of the BITMAPINFOHEADER only. It is 40 bytes.
bfSize is the size, in bytes, of the bitmap file. (bfSize = biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)) *Both in bytes.*

## What does it mean if `biHeight` is negative? 

biHeight is the height of the bitmap, in pixels. If biHeight is positive, the bitmap is a **bottom-up** DIB and its origin is the lower-left corner. *If biHeight is negative, the bitmap is a **top-down** DIB and its origin is the upper-left corner.*

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount (determines the number of bits that define each pixel and the maximum number of colors in the bitmap.)

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Because the file that we are reading or writing doesn't exist.

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)

fread's third argument is always 1 because we are iterating over every pixel.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4 *This step ensures the number of bytes in every row is a multiple of 4*
(b.biWidth = 3, sizeof(RGBTRIPLE) = 3)
= 3

## What does `fseek` do?

Allows you to rewind or fast-forward within a file.

## What is `SEEK_CUR`?

It moves file pointer position to given location.
