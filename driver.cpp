#include "Base_Array.cpp"
#include "Array.cpp"

#include "Fixed_Array.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include <iostream>

using namespace std;


int main (int argc, char * argv [])
{
  // TODO Add code here to test your Array class.

    Array<char> a1;
    cout << a1.size() << endl;

    Array<char> a2(25);
    Array<char> a3(20,'k');

    Array<char> a4(a3);
    a1.fill('t');

    cout << a4.size() << endl;
    a4.printArray();
    a2.printArray();
    a3.printArray();
    a1.resize(40);
    cout << a1.max_size() << endl;
    a1.printArray();
    a1.shrink();
    cout << a1.size() << endl;
    cout << a1.max_size() << endl;


    Fixed_Array<char,40> fixed_a1;
    fixed_a1.fill('d');
    Fixed_Array<char, 40> a;
    a.operator=(fixed_a1);
    fixed_a1.printArray();
    a.printArray();

    Fixed_Array<char,30> fixed_a2('s');

   if(a == fixed_a1) cout << "Equal " << " ";
    else cout << "Not Equal " << " "<<endl;

    fixed_a2.printArray();

    cout << fixed_a2.size();


    fixed_a1.fill('d');
    fixed_a1.printArray();

    cout << fixed_a1.find('i') << endl;

    cout << fixed_a1.size() << endl;

    Fixed_Array<char,40> fa2 (fixed_a1);
    fixed_a1.printArray();
    fa2.printArray();
    Fixed_Array<int,25> fa3 (4);
    fa3.printArray();

    std:: cout<< "Testing Stack ----"<<endl;
    Stack<int> integer_stack;
    integer_stack.push(100);
    integer_stack.push(101);
    integer_stack.push(102);
    integer_stack.push(103);
    integer_stack.push(104);
    integer_stack.push(104);
    integer_stack.push(104);

    Stack<int> integer_stack2(integer_stack);

    Stack<int>integer_stack3 = integer_stack2;

    integer_stack.size();
    integer_stack2.top();
    //integer_stack.pop();
    integer_stack.top();
    integer_stack3.clear();
    integer_stack3.push(2);
    cout << integer_stack3.top()<< endl;


   std:: cout<< "Testing Queue ----"<<endl;

    Queue<size_t> queue;
    Queue<size_t> q2 ;
    queue.enqueue('d');
    queue.enqueue('o');
    queue.enqueue('h');
    queue.enqueue('a');

    queue.enqueue('l');
    queue.enqueue('e');
    queue.enqueue('n');
    queue.enqueue('a');

    queue.enqueue('l');
    queue.enqueue('e');
    queue.enqueue('n');
    queue.enqueue('a');

    queue.enqueue('l');
    queue.enqueue('e');
    queue.enqueue('n');
    queue.enqueue('a');



    queue.enqueue('x');
    queue.enqueue('z');


    Queue<size_t> q3 = queue;
    Queue<size_t> queue2(queue);

     queue.printQueue();
    size_t i = queue2.dequeue();
    cout <<" hello " << i <<endl;

     i = queue2.dequeue();
    cout <<" hello2 " << i <<endl;

    i = queue2.dequeue();
    cout <<" hello3 " << i <<endl;

    queue.dequeue();
    //queue.dequeue();
    queue.printQueue();
    //queue.clear();
    queue.enqueue('r');
    queue.printQueue();
    queue.dequeue();


    cout<< " Q2 elements:- ";
    q2.printQueue();
    queue.clear();
    queue.printQueue();


    cout << queue.size() <<endl;
    queue.clear();
    queue.printQueue();


    return 0;
}


