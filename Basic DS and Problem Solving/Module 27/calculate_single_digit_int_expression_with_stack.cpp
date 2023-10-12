#include<bits/stdc++.h>
using namespace std;

int prec(int ch)
{
    if(ch == '+' || ch == '-'){
        return 1;
    }
    if(ch == '*' || ch == '/'){
        return 2;
    }
    return 0;
}

int operation_result (int item1, int item2, char op)
{
    if(op == '+'){
        return (item1 + item2);
    }
    else if(op == '-'){
        return (item1 - item2);
    }
    else if(op == '*'){
        return (item1 * item2);
    }
    else if(op == '/'){
        return (item1 / item2);
    }
}

int main()
{
    string s;
    cout << "Enter equation: ";
    getline(cin, s);
    stack <int> digits;
    stack <char> operations;
    int ans = 0;

    for(int i = 0; i < s.size(); i++){

        //cout << "Now: " << s[i] << "  \n";

        if(s[i] == ' '){
            //cout << "Space \n";
            continue;
        }
        else if(s[i] == '('){
            operations.push(s[i]);
        }
        else if(isdigit(s[i])){
            int val = 0;

            while(i < s.size() && isdigit(s[i]))
            {
                val = (val*10) + (s[i]-'0');
                i++;
            }
            //cout << "Val: " << val << " ";

            digits.push(val);
            i--;
        }
        else if(s[i] == ')'){

            while(operations.size() && operations.top() != '('){
                int dig1 = digits.top();
                digits.pop();
                int dig2 = digits.top();
                digits.pop();

                char op = operations.top();
                operations.pop();

                int cal = operation_result(dig2, dig1, op);

                digits.push(cal);
            }

            if(operations.size()){
                operations.pop();
            }
        }
        else{

            while(operations.size() && (prec( operations.top()) >= prec(s[i])) ){
                int dig1 = digits.top();
                digits.pop();
                int dig2 = digits.top();
                digits.pop();

                char op = operations.top();
                operations.pop();

                int cal = operation_result(dig2, dig1, op);

                digits.push(cal);
            }

            operations.push(s[i]);

        }

         //cout << "\nDigits top: "<< digits.top() <<"\n";
//         if(operations.size())
//            cout << "Operations top: "<< operations.top() <<"\n";

    }


    while(operations.size()){
        int dig1 = digits.top();
        digits.pop();
        int dig2 = digits.top();
        digits.pop();

        char op = operations.top();
        operations.pop();

        int cal = operation_result(dig2, dig1, op);

        digits.push(cal);
    }

    cout << "\nCalculated Value: "<< digits.top() <<"\n";

    return 0;
}

