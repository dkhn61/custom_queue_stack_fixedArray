//
// Created by Doha Ara on 06/10/22.
//
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef ARRAY_BASE_CPP
#define ARRAY_BASE_CPP
#include "Base_Array.h"

#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>

#define DEFAULT_SIZE 10
//
////
//// Base_Array
////
template <typename T>
Base_Array <T>::Base_Array (void)
        : data_(nullptr),
          cur_size_(0),
          max_size_(0)
{
    this->data_ = new T[DEFAULT_SIZE];
    this->cur_size_ = DEFAULT_SIZE;
    this->max_size_ = DEFAULT_SIZE;

}

////
//// Base_Array (size_t)
////
template <typename T>
Base_Array <T>::Base_Array (size_t length)
        : data_(nullptr),
          cur_size_(0),
          max_size_(0)
{
    size_t max_size = (length == 0) ? DEFAULT_SIZE : length;
    this->data_ = new T[max_size];
    this->cur_size_ = length;
    this->max_size_ = max_size;

}

//
// Base_Array (size_t, char)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fill)
        : Base_Array(length)

{
    this->fill(fill) ;
}

//
// Base_Array (const Base_Array &)
//
template <typename T>
Base_Array <T>::Base_Array (const Base_Array & array)
        : data_(nullptr),
          cur_size_(0),
          max_size_(0)
{
//              for( T *iter = array.data_, *end_iter = this->data_ + this->cur_size_, *max_iter = this->data_)
//              {
//
//              }
    size_t max_size = (array.max_size_ == 0) ? DEFAULT_SIZE : array.max_size_;
    this->data_ = new T[max_size];
    for(int i=0;i<array.max_size_;i++){
        this->data_[i] = array.data_[i];
    }
    this->cur_size_ = DEFAULT_SIZE;
    this->max_size_ = max_size;
}

//
// Base_Arrayy
//
template <typename T>
Base_Array <T>::~Base_Array (void)
{
    delete [] this->data_;
    std:: cout << "Destructor of the Base_Array class \n";

}

//
// operator =
//
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array & rhs)
{
    if(this == &rhs)
        return *this;

    this->cur_size_ = rhs.cur_size_;
    this->max_size_ = rhs.max_size_;

    for(int i=0;i<rhs.max_size_;i++){
        this->data_[i] = rhs.data_[i];
    }

    return *this;
}

//
// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
    if (index >= this->max_size_) {
        throw std::out_of_range ("Out of Range error ");
    }
    return this->data_[index];
}

//
// operator []
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
    if (index >= this->max_size_) {
        throw std::out_of_range ("Out of Range error ");
    }

    return this->data_[index];
}

//
// get
//
template <typename T>
T Base_Array <T>::get (size_t index) const
{
    T ch;

        ch = data_[index];

    return ch;

}

//
// set
//
template <typename T>
void Base_Array <T>::set (size_t index, T value)
{
    data_[index]=value;
}

//
// find (char)
//
template  <typename T>
int Base_Array <T>::find (T value) const
{
    for (int i = 0; i < this->cur_size_; ++i) {
        if(this->data_[i] == value) return i;
    }
    return -1;
}

//
// find (char, size_t)
//
template <typename T>
int Base_Array <T>::find (T val, size_t start) const
{
    int size = this->size();

    if(start<0 || start> size-1){
        throw std::out_of_range ("Out of Range error ");
    }
    for (int i = start; i < this->cur_size_; ++i) {
        if (this->data_[i] == val) return i;
    }

    return -1;

}

//
// operator ==
//
template <typename T>
bool Base_Array<T>::operator == (const Base_Array & rhs) const
{
    if(this == &rhs)
        return true;

    if(this->cur_size_ != rhs.cur_size_)
        return false;

    for(int i=0;i<rhs.cur_size_;i++){
        if(this->data_[i] != rhs.data_[i])
            return false;
    }

    return true;
}

template <typename T>
bool Base_Array<T>::operator != (const Base_Array & rhs) const
{
    if(this == &rhs)
        return false;

    if(this->cur_size_ != rhs.cur_size_)
        return true;

    for(int i=0;i<rhs.cur_size_;i++){
        if(this->data_[i] != rhs.data_[i])
            return true;
    }
    return false;
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill (T value)
{
    for(int i=0; i<this->max_size_;i++){
        this->data_[i] = value;
    }
}

template <typename T>
void Base_Array<T>::printArray ()
{
    int i;
    for (i = 0; i < this->max_size_; i++)
        std::cout << this->data_[i] << " ";
    std::cout << std::endl;
}

#endif