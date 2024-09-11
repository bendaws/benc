# Ben-C v1.0.0 ![GitHub Issues or Pull Requests](https://img.shields.io/github/issues/btd2010/benc) ![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/btd2010/benc/main.yml)
Ben-C is a basic compiled programming language written, inspired, and designed around C. Ben-C is an extension of C, like C++, but Ben-C maps way closer to C in terms of uses. 

> Important!
>
> Ben-C is still in development. It is usable, but is not recommended for regular usage yet.

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
You can download a source release of the current stable build (v1.0.0) [here](https://github.com/btd2010/benc/releases).

You can use GNU Make to build and install Ben-C.
```bash
tar -xf benc-1.0.0.tar.gz # If you downloaded from a source release, extract the files
git clone https://github.com/btd2010/benc # If you didn't, clone the current source
cd benc
make all
```
Target ``install`` will install the binaries to ``/usr/local/bin``.
```bash
make install
```
Test a working compiler with target ``test``.
```bash
make tests
```

## Command Line
Compile a file:
```
ben-c path/to/file.bc
```
Get version:
```
ben-c --version
```
