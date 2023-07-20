#include<bits/stdc++.h>
using namespace std;

//const int MAX_SIZE = 500;

// stack using Dynamic Array
class Stack
{
public:
    int *a;
    int stack_size;
    int array_cap;

    Stack()
    {
        a = new int[1];
        array_cap = 1;
        stack_size = 0;
    }

    // Makes the Array capacity * 2
    void increase_size()
    {
        int * tmp;
        tmp = new int[array_cap * 2];
        for(int i = 0; i < array_cap; i++)
            tmp[i] = a[i];

        swap(a, tmp);

        delete []tmp;
        array_cap = array_cap * 2;
    }

    // Add an Element in the stack. O(1)
    void push(int val)
    {
        if(stack_size + 1 > array_cap){
            increase_size();
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

