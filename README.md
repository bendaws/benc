# Ben-C ![Issues](https://img.shields.io/github/issues/btd2010/benc) ![Current Commit Status](https://img.shields.io/github/actions/workflow/status/btd2010/benc/main.yml) ![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/btd2010/benc/nightly.yml?label=nightly%20build)

Ben-C is a basic compiled programming language written, inspired, and designed around C. Ben-C is an extension of C, like C++, but Ben-C maps way closer to C in terms of uses. 

> Important!
>
> Ben-C is still a very in-development language. It's current release ``v1.0.0-rc-2``, still segmentation faults while compiling code. It is not ready to use. v1.0.0 should be ready to use and stable.

## Table of Contents
- [Advantages](#advantages): Shows off some features of the language
- [Installation](#installation): Install

## Resources
- [bc.tmbundle](https://github.com/btd2010/bc.tmbundle): Provides a grammar for Ben-C.

## Advantages
### Syntaxically simular
Ben-C and C are pretty much the same, like how C/C++ are near simular. Ben-C is much closer to C than C++.
#### hello_world.c
```c
#include <stdio.h>

int main() {
    printf("Hello world");
    // i am a comment

    return 0;
}
```
#### hello_world.bc
```c
#include <stdio.h>

int main() {
    printf("Hello world");
    // i am a comment

    return 0;
}
```
### String Support
Ben-C looks to improve how strings are used and supported. The ``string`` type is natively supported by Ben-C and works with C header files (for example, ``stdlib.h``).
#### string_test.c
```c
// Note: a snippet of C. is not syntaxically valid (is missing a main())

char* string1 = "i am a string";
char string2[] = "i am also a string";
```
#### string_test.bc
```c
// Note: a snippet of ben-C. is not syntaxically valid (is missing a main())

string string1 = "i am a string";
char* string2 = "i am also a string";
char string3[] = "i am also also a string";
```
In the compiler, the ``string`` type is still just a ``char*``, so any header files used by C can still access it like a regular character array.

## Installation
You can use GNU Make to build and install Ben-C.
```
git clone https://github.com/btd2010/benc
cd benc
make
```
Target ``install`` will install the binaries to ``/usr/local/bin``.
```
make install
```

## Command Line
Compile a file:
```
bc path/to/file.bc
```
Get version:
```
bc --version
```
