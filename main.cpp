#include <iostream>
#include "uniquePtr.h"

int main()
{
    UniquePtr<int> pointer(new int(10));
    std::cout << *pointer.get() << std::endl;
    return 0;
}