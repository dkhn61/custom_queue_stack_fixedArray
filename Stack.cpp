// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>


template <typename T>
Stack <T>::Stack (void)
{
    topIndex = -1;
    maxSize = DEFAULT_SIZE;
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
          : array(stack.array)
{
    std:: cout << "Copy Constructor of the Stack \n";
    this->topIndex = stack.topIndex;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    //Did not allocate new variables in Stack, so not using delete[] here in Stack's Destructor
    std::cout << "Deleted the stack "  << std::endl;
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    // COMMENT There is no max size to the stack.
    //Included maxsize for stack, also , a check if it's full
    try{
       if(topIndex >= maxSize)
           throw std::out_of_range ("Out of Range error ");

    // Incrementing the topIndex by one as element is to be inserted
       topIndex = topIndex + 1;

    // Now, adding element to stack
        this->array[topIndex] = element;
        std::cout << "Inserted element in the stack:- " << element << " at topIndex :- " << topIndex << std::endl;

       }catch(const std::out_of_range& ex){
          throw std::out_of_range ("Stack is full");
       }

}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(this->is_empty()){
        throw std::out_of_range ("Stack is empty");
    }
    std::cout << "Popped element:- " << this->array[topIndex] << std::endl;
    topIndex--;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if(this == &rhs)
        return *this;

    this->topIndex = rhs.topIndex;
    this->array = rhs.array;

    return *this;

}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    // COMMENT Just reset the variables instead popping each element, which
    // is expensive.

    //top moved to the initial empty index and maxSize to the default size

    this->topIndex = -1;
    this->maxSize = DEFAULT_SIZE;
    std::cout << "Stack is cleared " << std::endl;

}

#endif
