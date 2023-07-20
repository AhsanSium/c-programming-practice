#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 500;

// stack using static Array
class Stack
{
public:
    int a[MAX_SIZE];
    int stack_size;

    Stack()
    {
        stack_size = 0;
    }

    // Add an Element in the stack. O(1)
    void push(int val)
    {
        if(stack_size + 1 > MAX_SIZE){
            cout << "Stack is Full !\n";
            return;
        }
        stack_size ++;
        a[stack_size - 1] = val;
    }

    // Delete the top most element
    void pop()
    {
        if(stack_size == 0){
            cout << "Stack is empty \n";
            return;
        }
        a[stack_size - 1] = 0;
        stack_size --;
    }

    // Returns Top Element of Stack
    void top()
    {
        if(stack_size == 0){
            cout << "Stack Size is Empty \n";
            return;
        }
        cout << a[stack_size - 1] << "\n";

    }
};

int main()
{
    Stack st;
    st.push(3);
    st.top();
    st.push(5);
    st.push(7);
    st.push(2);
    st.push(1);
    st.push(100);
    st.push(4);
    st.top();
    st.pop();
    st.top();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    return 0;
}
