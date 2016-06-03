##### VoidParam Puzzle

In the code:

```C++
template <typename T> void Process(const T& t) 
{ 
   // Some code here 
} 

#define PROCESS(x) Process(x)
```

PROCESS, can be called with any parameter except 'void', since call Process(void) is illegal,
for instance for a function

```C++
void GetVoid() {}

PROCESS(GetVoid())
```

won't compile.

What modifications should be made that for all parameters other than 'void', PROCESS works as before,
but call PROCESS(GetVoid()) (as well as PROCESS(void()) throws exception that 'void' is not allowed as a parameter.
```C++ 
template <typename T> void Process(const T& t) 
``` 
should remain without modifications.

Solution is in https://github.com/amarmer/VoidParam/blob/master/Solution.cppp
