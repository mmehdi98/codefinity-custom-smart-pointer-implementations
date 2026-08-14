#pragma once

template <typename T>
class UniquePtr{
public:
    explicit UniquePtr(T* ptr);
    UniquePtr(const UniquePtr& other) = delete;
    UniquePtr(UniquePtr&& other) noexcept;
    ~UniquePtr();

    UniquePtr& operator =(const UniquePtr& other) = delete;
    UniquePtr& operator =(UniquePtr&& other) noexcept;
    T& operator *();
    const T& operator *() const;
    T* operator ->();
    const T* operator ->() const;

    const T* get () const;
    void reset(T* newPtr = nullptr);
    T* release();

private:
    T* ptr_;
};

template <typename T>
UniquePtr<T>::UniquePtr(T* ptr) :ptr_(ptr){}

template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& other) noexcept
    : ptr_(other.ptr_) {
    other.ptr_ = nullptr;
}

template <typename T>
UniquePtr<T>::~UniquePtr(){ delete ptr_; }

template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& other) noexcept {
    if (this != &other) {
        delete ptr_;
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }
    return *this;
}

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
}

template <typename T>
void UniquePtr<T>::reset(T* newPtr){
    if (ptr_ != newPtr){
        delete ptr_;
        ptr_ = newPtr;
    }
}

template <typename T>
T* UniquePtr<T>::release(){
    T* temp = ptr_;
    ptr_ = nullptr;
    return temp;
}