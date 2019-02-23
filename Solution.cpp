#include <stdexcept>

template <typename T> 
void Process(const T&) {}

struct VoidParam {};

void Process(VoidParam&&) 
{
  throw std::runtime_error("`void` is not alloud as a parameter");
}

template <typename T>
const T& operator , (const T& t, const VoidParam&) 
{
  return t; 
}

// In case if `x` is `void()', macro - `Process((void(), VoidParam()))` -> `Process(VoidParam())`, calls `void Process(VoidParam&&)`.
// In case if `x` is not `void()', macro - `Process((x, VoidParam()))` -> `Process(x)`, calls `template <typename T> void Process(const T&)`.
#define PROCESS(x) Process((x, VoidParam()))

int main() 
{
  // Calls `template <typename T> void Process(const T&)`.
  PROCESS(int());
  PROCESS(VoidParam());
  
  // Calls `void Process(VoidParam&&)`.
  PROCESS(void());
  
  return 0; 
}
