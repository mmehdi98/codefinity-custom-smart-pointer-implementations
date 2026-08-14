-e This file is a merged representation of the entire codebase, combined into a single document

## Purpose
This file contains a packed representation of the entire repository's contents.
It is designed to be easily consumable by AI systems for analysis, code review,
or other automated processes.

## File Format
The content is organized as follows:
1. This summary section
2. Repository information
3. Directory structure
4. Multiple file entries, each consisting of:
  a. A header with the file path (## File: path/to/file)
  b. The full contents of the file in a code block or partial content for large files

## Usage Guidelines
- This file should be treated as read-only. Any changes should be made to the
  original repository files, not this packed version.
- When processing this file, use the file path to distinguish
  between different files in the repository.
- Be aware that this file may contain sensitive information. Handle it with
  the same level of security as you would the original repository.

# Directory Structure
````
./
main.cpp
uniquePtr.cpp
uniquePtr.h
````
-e 
# Files
-e 
## File: main.cpp
````
#include <iostream>
#include "uniquePtr.h"

int main()
{
    UniquePtr<int> pointer(new int(10));
    std::cout << *pointer.get() << std::endl;
    return 0;
}````
-e 
## File: uniquePtr.cpp
````

````
-e 
## File: uniquePtr.h
````
#pragma once

template <typename T>
class UniquePtr{
public:
    explicit UniquePtr(T* ptr);
    UniquePtr(const UniquePtr& other) = delete;
    ~UniquePtr();

    UniquePtr& operator =(const UniquePtr& other) = delete;
    T& operator *();
    const T& operator *() const;
    T* operator ->();
    const T* operator ->() const;

    const T* get () const;
    

private:
    T* ptr_;
};

template <typename T>
UniquePtr<T>::UniquePtr(T* ptr) :ptr_(ptr){}

template <typename T>
UniquePtr<T>::~UniquePtr(){ delete ptr_; }

template <typename T>
T& UniquePtr<T>::operator*(){
    return *ptr_;
}

template <typename T>
const T& UniquePtr<T>::operator*() const{
    return *ptr_;
}

template <typename T>
T* UniquePtr<T>::operator->(){
    return ptr_;
}

template <typename T>
const T* UniquePtr<T>::operator->() const{
    return ptr_;
}

template <typename T>
const T* UniquePtr<T>::get() const{
    return ptr_;
}````
