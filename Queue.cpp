//
// Created by Doha Ara on 29/09/22.
//

#ifndef QUEUE_CPP
#define QUEUE_CPP
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>
#include "Queue.h"


template <typename T>
Queue <T>::Queue (void)
{
    front = -1;
    rear = -1;
    max = 10;
}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & queue)
        : queue(queue.queue)
{
    std:: cout << "Copy Constructor of the Queue \n";
    this->front = queue.front;
    this->rear = queue.rear;
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
    //Did not allocate new variables in Stack, so not using delete[] here in Queue's Destructor
    std::cout << "Deleted the queue "  << std::endl;
}

//
// push
//
template <typename T>
void Queue <T>::enqueue(T element)
{

    // COMMENT The queue will fail if the array runs out of space. Since this
    // is an unbounded queue, you need to resize the array to make space for
    // new elements. Also, make sure you do not waste any space if you must
    // resize the array to accommodate new elements. This will require updates
    // to your dequeue method.
    //doubling the queue size if the queue is full
    if(this->size() >= max){
         int newSize = max*2;
         rear = max - 1;
         max = newSize;

        Base_Array<T> temp(newSize);
        // copy existing elements into temp
        for (int i = 0; i < newSize; ++i) {
            int index = (front + i) % newSize;
            temp.set(i, this->queue.get(index));
        }
        front = 0;
        queue = temp;

    }
    // Incrementing the front by one as element is to be inserted
    if (front == - 1){
        front = 0;
    }

    try{
        rear++;
        this->queue.set(rear, element);
        std::cout << "Inserted element in the queue:- " << element << " at the rear Index: " << rear << std::endl;

    }catch(const std::out_of_range& ex){
        throw std::out_of_range ("Queue Overflow");
    }

}

//
// pop
//
template <typename T>
T Queue <T>::dequeue (void)
{
    // COMMENT This solution will work, but you are wasting space at the front
    // of the array since those "unused" spaces will never be used again. Please
    // come up with a better design that uses memory more efficiently.
   // Reordering the elements to index 0 after dequeue so that front spaces are not getting wasted
    T dequeued_element;
    if (this->is_empty()){

        std::cout<<"Queue Underflow " << std::endl;
        throw empty_exception ("Queue is empty");

    } else {
        dequeued_element = this->queue.get(front);
        std::cout<<"Element deleted from queue is : "<< dequeued_element <<std::endl;
        front++;
        if(front>0){
            Base_Array<T> temp(this->size());
            // shifting existing elements to 0th index after dequeue
            for (int i= 0; i < this->size(); i++) {
                int index = front+ i;
                temp.set(i, queue.get(index));
            }
            front = 0;
            rear = rear - 1;
            queue = temp;

        }
    }
    return dequeued_element;
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    if(this == &rhs)
        return *this;

    this->front = rhs.front;
    this->rear = rhs.rear;
    this->array = rhs.array;

    return *this;

}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
    // COMMENT This works, but is a very expensive operation. You should find a
    // way to just reset the state without having to dequeue every element.

   //front and rear indices moved to the initial empty index
    this->front = -1;
    this->rear = -1;
    std::cout << "Queue is cleared " << std::endl;

}

template <typename T>
void Queue<T>::printQueue() {
    if (front == - 1)
        std::cout<<"Queue is empty"<<std::endl;
    else {
        std::cout<<"Queue elements are : ";
        for (int i = front; i <= rear; i++)
            std:: cout<< this->queue.get(i) <<" ";
        std::cout<<std::endl;
    }
}

#endif

