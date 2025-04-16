# refs.c
A basic ANSI C program that demonstrates pass-by-reference
and some less known features of the standard library, such
as error checking of output functions and `memcpy`'s return
value.
## What does it do?
Copies a predefined string onto the heap, overwrites the
copy with random lowercase ASCII characters and replaces
every odd character with "a".
## Why?
I originally wrote this to test GCC's optimization
capabilities, then decided to upload it because why not.
## How to build
Clone the repository, `cd` into it and call
```bash
# Check the Makefile for other options.
WARNINGS=all STRICT=1 LTO=1 make
```

To run the only test:
```bash
make check
```

To remove the executable:
```bash
make clean
```
## What about Windows?
You can use any of the mingw64 distributions, for example
MSYS2 or Cygwin. Otherwise compile it manually, which
shouldn't cause any problems since the code is written in
ANSI C.