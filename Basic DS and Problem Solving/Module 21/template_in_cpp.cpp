#include<bits/stdc++.h>
using namespace std;

// Template Based stack using Dynamic Array
template <class T>
class Stack
{
public:
    T *a;
    int stack_size;
    int array_cap;

    Stack()
    {
        a = new T[1];
        array_cap = 1;
        stack_size = 0;
    }

    // Makes the Array capacity * 2
    void increase_size()
    {
        T * tmp;
        tmp = new T[array_cap * 2];
        for(int i = 0; i < array_cap; i++)
            tmp[i] = a[i];

        swap(a, tmp);

        delete []tmp;
        array_cap = array_cap * 2;
    }

    // Add an Element in the stack. O(1)
    void push(T val)
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
        //a[stack_size - 1] = 0;
        stack_size --;
    }

    // Returns Top Element of Stack
    T top()
    {
        if(stack_size == 0){
            cout << "Stack Size is Empty \n";
            //assert(false);
            T a;
            return a;
        }
        return a[stack_size - 1];

    }
};

int main()
{
    Stack <int> st;
    st.push(3);
    cout << st.top() << "\n";
    st.push(5);
    st.push(7);
    st.push(2);
    st.push(1);
    st.push(100);
    st.push(4);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    return 0;
}


