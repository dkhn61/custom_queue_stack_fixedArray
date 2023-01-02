// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
#ifndef FIXED_ARRAY_CPP
#define FIXED_ARRAY_CPP
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>
#include "Fixed_Array.h"


template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
                   : Base_Array<T>(N)
{
    std:: cout << "Constructor of the Fixed_Array class \n";
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
                   : Base_Array<T>(N)
{
    std:: cout << "Copy Constructor of the Fixed_Array class \n";
    for(int i=0; i<N; i++)
    this->fill(arr[i]);
}

// Not using the below constructor as discussed in class
// Fixed_Array
//
//template <typename T, size_t N>
//template <size_t M>
//Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
//                   : Base_Array<T>(N)
//{
//    std:: cout << "Initializing Constructor of the Fixed_Array class \n";
//    for(int i=0; i<M; i++)
//        this->fill(arr[i]);
//}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
                   : Base_Array<T>(N, fill)
{
    std:: cout << "Initializing Fill Constructor of the Fixed_Array class \n";

}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
    //Did not allocate new variables in Fixed_Array, so not using delete[] here in Fixed_Array's Destructor
    std:: cout << "Destructor of the Fixed_Array class \n";
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
    if(this == &rhs)
        return *this;

    for(int i=0;i<N; i++) {
        this->set(i,rhs.get(i));
    }

    return *this;
	
}

// Not using the below assignment operator as discussed in class
// operator =
//
//template <typename T, size_t N>
//template <size_t M>
//const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
//{
//    if(this == &rhs)
//        return *this;
//
//    for(int i=0;i<M; i++) {
//        this->set(i,rhs.get(i));
//    }
//
//    return *this;
//
//}

#endif