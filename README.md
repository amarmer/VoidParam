##### VoidParam Puzzle

In the code:

```C++
template <typename T> T Process(const T& t) { return t; } 

#define PROCESS(x) Process(x)
```

PROCESS can be called with any parameter except 'void', Process(void) is illegal, for instance code bellow won't compile:

```C++
void GetVoid() {}

PROCESS(GetVoid())
```

What modifications should be made that for all parameters other than 'void', PROCESS works as before,
but call PROCESS(GetVoid()) (as well as PROCESS(void()) throws exception that 'void' is not allowed as a parameter.
```C++ 
template <typename T> void Process(const T& t) { return t; }
``` 
should remain without modifications.

Solution is in https://github.com/amarmer/VoidParam/blob/master/Solution.cppp
