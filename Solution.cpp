#include <exception>

template <typename T>
T Process(const T& t) { return t; }

struct VoidParam {};

inline void Process(const VoidParam&) 
{
    throw std::exception("'void' parameter is not allowed");
}

template <typename T>
T operator , (const T& t, const VoidParam&) { return t; }

#define PROCESS(x) Process((x, VoidParam()))

void GetVoid() {}

void main()
{
    PROCESS(1);

    PROCESS(GetVoid());
    
    PROCESS(void());
}


