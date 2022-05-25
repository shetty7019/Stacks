#include <iostream>
using namespace std;

#define n 100

class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    // operations

    void push(int x)
    {
        // checks for stack overflow
        if (top == n - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        // push the element to the top of the stack
        top++;
        arr[top] = x;
    }

    void pop()
    {
        // checks for stack underflow
        if (top == -1)
        {
            cout << "The stack is empty, No element to pop." << endl;
            return;
        }
        // popping an element from top of the stack
        top--;
    }

    int peek()
    {
        // checks for stack underflow
        if (top == -1)
        {
            cout << "The stack is empty, No element to pop." << endl;
            return -1;
        }

        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
}; 


int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;

    return 0;
}