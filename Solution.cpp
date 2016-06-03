#include <exception>

template <typename T>
void Process(const T& t)
{
    // Some code here
}


struct VoidParam {};

inline void Process(const VoidParam&) 
{
    throw std::exception("'void' parameter is not allowed");
}


template <typename T>
T operator , (const T& t, const VoidParam&)
{
    return t;
}

#define PROCESS(x) Process((x, VoidParam()))

void GetVoid() {}

void main()
{
    PROCESS(1);

    PROCESS(GetVoid());
    
    PROCESS(void());
}


