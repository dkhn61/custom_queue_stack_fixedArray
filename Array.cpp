// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


#ifndef ARRAY_CPP
#define ARRAY_CPP
#define DEFAULT_SIZE 10
#include <iostream>
#include "Array.h"

template <typename T>
Array <T>::Array (void)
        : Base_Array<T>()
{
    std:: cout << "Default Constructor of the Array class \n";
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
        : Base_Array<T>(length)
{
    std:: cout << "Initializing Constructor of the Array class \n";
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
        : Base_Array<T>(length, fill)
{
    std:: cout << "Initializing Constructor of the Array class with fill\n";
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
        : Base_Array<T>(array)
{
    std:: cout << "Copy Constructor of the Array class \n";
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    //Did not allocate new variables in Array, so not using delete[] here in Array's Destructor
    std:: cout << "Destructor of the Array class \n";

}
//
// resize
//
template <typename T>
void Array<T>::resize (size_t new_size)
{
    // COMMENT The resize method should only increase the size of the allocation if
    // the new size is larger than the current memory allocation for the array. If resized,
    // you need to preserve the old data. Otherwise, you can just update cur_size_ to
    // reflect the new size.

    if(new_size > this->cur_size_ ) {

        // COMMENT There is no need to do a double copy for the data to resize
        // the array. Just create a new array, copy over the data, and then swap
        // the pointers.
        this->max_size_=0;
        T *temp = new char[new_size];
        for (int i = 0; i < new_size; i++) {
            temp[i] = this->data_[i];
            this->max_size_++;
        }

        T *swap = this->data_;
        this->data_ = temp;
        temp = swap;

        this->max_size_ = new_size;

    }
    else if(new_size < this->cur_size_){
        this->cur_size_ = new_size;
    }
}


template <typename T>
void Array<T>::shrink (void)
{
    // COMMENT Purpose of the shrink method is to recover an unused
    // memory allocation. For example, if the array has allocated 10, and
    // the current size is 5, then 5 spaces us wasted. The shrink method
    // we reclaim the 5 unused spaces so the array only has an allocation
    // large enough to fits is current size (i.e., 5 in this example).

    // COMMENT You should use the cur_size_ and max_size_ to determine if you
    // must shrink the array allocation.

    if(this->cur_size_ < this->max_size_)
    {
        this->max_size_ = this->cur_size_;
    }

}

#endif