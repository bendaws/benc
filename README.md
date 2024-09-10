# Ben-C ![GitHub Issues or Pull Requests](https://img.shields.io/github/issues/btd2010/benc) ![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/btd2010/benc/make.yml)
Ben-C is a general-purpose basic programming language inspired by C. It transpiles to C code. It is close to about the same as C, but is also slightly different in keywords and use cases.

## Table of Contents
- [Advantages](#advantages): Shows off some features of the language

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
