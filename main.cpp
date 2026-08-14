#include <iostream>
#include "uniquePtr.h"

int main()
{
    UniquePtr<int> pointer10(new int(10));
    UniquePtr<int> pointer10_new(std::move(pointer10));
    int* ptr;

    ptr = pointer10_new.release();
    std::cout << ptr << std::endl;
    std::cout << pointer10.get() << std::endl;

    UniquePtr<int> pointer44(new int(44));
    pointer44.reset();
    std::cout << pointer44.get() << std::endl;


    
    return 0;
}