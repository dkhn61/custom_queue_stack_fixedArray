//
// Created by Doha Ara on 29/09/22.
//

// -*- C++ -*-
// $Id: Queue.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include <exception>
#include <stdexcept>
#include "Base_Array.h"

/**
* @class Queue
*
* Basic queue for arbitrary elements.
*/
template <typename T>
class Queue
{
public:
    /// Type definition of the type.
    typedef T type;
    void printQueue();

    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the queue is empty.
     */
    class empty_exception : public std::exception
    {
    public:
        /// Default constructor.
        empty_exception (void)
                : std::exception () { }

        /**
         * Initializing constructor.
         *
         * @param[in]      msg         Error message.
         */
        empty_exception (const char * msg)
                : std::exception (exception()) { }
    };

    /// Default constructor.
    Queue (void);

    /// Copy constructor.
    Queue (const Queue & s);

    /// Destructor.
    ~Queue (void);

    /**
     * Assignment operator
     *
     * @param[in]      rhs           Right-hand side of operator
     * @return         Reference to self
     */
    const Queue & operator = (const Queue & rhs);

    /**
     * adds the element to the end of the list
     *
     * @param[in]      element       Element to add to the list
     */
    void enqueue (T element);

    /**
     * Removes the element at the front of the list.If there are no elements in the
     * queue, this method throws empty_exception.
     *
     * @exception      empty_exception    The queue is empty.
     */
    T dequeue (void);

    /**
     * Test if the queue is empty
     *
     * @retval         true          The queue is empty
     * @retval         false         The queue is not empty
     */
    bool is_empty (void) const;

    /**
     * Number of element on the queue.
     *
     * @return         Size of the queue.
     */
    size_t size (void) const;

    /// Remove all elements from the queue.
    void clear (void);

private:
    // add member variable here
    int front;
    int rear;
    int max;
    Base_Array<T>  queue;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_QUEUE_H_

