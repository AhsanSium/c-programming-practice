#include<bits/stdc++.h>
using namespace std;

void deleteValue( list<int> & l , int value)
{
    list<int>::iterator itr1;
    itr1 = l.begin();
    int idx = 0;
    bool found = false;

    for (const int& element : l) {
        if(element == value){
            found = true;
            break;
        }
        idx++;
    }

    if(found == false){
        cout << "\nValue not found in List!\n";
    }
    else{
        advance(itr1, idx);
        l.erase(itr1);
        cout << "\n1st value Removed !\n";
    }
}

int main()
{
    int num, input_number, value;
    list<int> myList;
    cout << "No of List Elements: ";
    cin >> num;

    cout << "\nList Elements: ";
    for(int i = 0; i < num; i++){
        cin >> input_number;
        myList.push_back(input_number);
    }
    cout << "\nValue: ";
    cin >> value;

    deleteValue(myList, value);

    cout << "\nList After removal: ";
    for (const int& element : myList) {
        cout << element << " ";
    }

    return 0;
}
