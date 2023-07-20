#include<bits/stdc++.h>
#include <string>

using namespace std;

bool checkPalindrome(string input, int left, int right)
{
    if(left >= right) return true;
    else if(input[left] == input[right]){
        return checkPalindrome(input, left+1, right-1);
    }
    else{
        return false;
    }
}

int main()
{

    string input_str;

    getline(cin, input_str);

    bool ans = checkPalindrome(input_str, 0, input_str.size() - 1);

    cout << (ans ? "YES":"NO");

    return 0;
}



