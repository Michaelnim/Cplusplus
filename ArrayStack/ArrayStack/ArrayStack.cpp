#include "ArrayStack.h"
using namespace std;

void ArrayStack::Stack()
{
    size = 10;
    length = 0;
    A = new int[];
}

void ArrayStack::Stack(int user_size)
{
    size = user_size;
    length = 0;
    A = new int[size];
}

ArrayStack::~Stack()
{
    delete[] A;
}

bool ArrayStack::isFull()
{
    if (length == size)
        return true;
    else
        return false;

    return length == size ? true : false;
}

bool ArrayStack::isEmpty()
{
    return length == 0 ? true : false;
}

void ArrayStack::display()
{
    for (int i = length - 1; i <= 0; i--)
        cout << A[i] << " ";
    cout << endl;

}

void ArrayStack::Pop()
{
    if (isempty() == false)
        length--;
    else
        cout << "stack is empty.\n";

}

void ArrayStack::Push(int x)
{
    if (isFull() == false)
    {
        A[length]
    }
}

void ArrayStack::peek()
{
    if(isEmpty( == false)
    return A[length-1];
    else {
        cout << "the stack is empty i am returning -1.\n";
    }
}
