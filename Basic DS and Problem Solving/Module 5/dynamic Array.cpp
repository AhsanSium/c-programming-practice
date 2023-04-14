#include <bits/stdc++.h>

using namespace std;

// Memory Complexity O(n)
class Array {
private:
    int *arr;
    int cap;
    int sz;

    void increaseSize(){
        cap = cap * 2;
        int *tmp = new int[cap];
        for(int i = 0; i < sz; i++) {tmp[i] = arr[i];}
        delete [] arr;
        arr = tmp;
    }

    void decreaseSize(){
        if(sz = cap / 2) cap = cap / 2;
    }

public:
    Array()
    {
        arr = new int [1];
        cap = 1;
        sz = 0;
    }

    // Time Complexity for normal O(1) but Total Time Complexity O(nlog(n))
    void pushBack(int x)
    {
        if(cap == sz) {increaseSize();}
        arr[sz] = x;
        sz ++;
    }

    // O(sz - pos) worst case -> O(sz)

    void insertItem( int pos, int value )
    {
        if(cap == sz) {increaseSize();}

        for(int i = sz - 1; i <= pos; i--){
            arr[i + 1] = arr[i];
        }
        arr[pos] = value;
        sz ++;
    }

    void print()
    {
        for(int i = 0; i < sz; i++) cout << arr[i]<< " ";

        cout << " \n";
    }

    int getSize()
    {
        return sz;
    }

    int getElement( int idx )
    {
        if(idx >= sz){ cout <<"Error:Index out of bound"; return -1; }
        return arr[idx];
    }

    // Time Complexity O(1)

    void popBack(){
        if(sz == 0) return;
        sz--;
    }

    // Time Complexity O(sz)

    void Erase(int pos){
        if(pos >= sz){ cout <<"Error:Position Does not Exists"; return; }

        for(int i = pos + 1; i < sz; i++){
            arr[i - 1] = arr[i];
            //swap(arr[i - 1] = arr[i]);
        }
        sz --;

    }



};

int main()
{
    Array a;

    a.pushBack(10);
    a.pushBack(20);
    a.pushBack(30);
    a.pushBack(40);

    a.print();

    cout << a.getSize() << " \n";

    cout << a.getElement(2) << " \n";

    //a.insertItem(1, 5);

    a.print();

    a.popBack();
    a.print();

    a.Erase(2);
    a.print();

    return 0;
}
