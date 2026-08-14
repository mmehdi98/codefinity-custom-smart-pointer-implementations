#include <iostream>
#include "uniquePtr.h"

int main()
{
    UniquePtr<int> pointer10(new int(10));
    UniquePtr<int> pointer20(std::move(pointer10));
    int* ptr;

    // pointer20 = std::move(pointer10);
    ptr = pointer20.release();
    std::cout << ptr << std::endl;
    // std::cout << *pointer20.get() << std::endl;
    return 0;
}