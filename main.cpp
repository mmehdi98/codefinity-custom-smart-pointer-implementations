#include <iostream>
#include "uniquePtr.h"

int main()
{
    UniquePtr<int> pointer10(new int(10));
    UniquePtr<int> pointer20(std::move(pointer10));

    // pointer20 = std::move(pointer10);
    std::cout << *pointer20.get() << std::endl;
    return 0;
}