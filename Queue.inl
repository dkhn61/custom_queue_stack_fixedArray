// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#include <iostream>

//
// size
//
template <typename T>
inline
size_t Queue <T>::size (void) const
{
    return (this->rear - this->front +1);
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    return (front == - 1 || front > rear);
}
