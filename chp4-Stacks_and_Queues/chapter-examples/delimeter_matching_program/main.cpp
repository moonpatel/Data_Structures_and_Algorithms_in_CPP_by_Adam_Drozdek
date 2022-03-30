// Program to check if the entered expression is valid or not
// i.e. all the delemiters are properly matched
// This program uses a generic stack implemented by Moon Patel

#include <iostream>

#include "stack/stack.h"
#include "stack/stack.cpp"

using namespace std;


int main() {
    STACK<char> stk;
    cout << "Enter the expression (ended by a ';'): ";
    bool isValid = true;;
    char ch;
    while(cin) {
        cin >> ch;
        if(ch=='(' || ch=='{' || ch=='[')
            stk.push(ch);
        else if(ch==')' || ch=='}' || ch==']') {
            if(stk.isEmpty())   // invalid expression because closing bracket 
                break;          // does not comes before opening bracket
            else
                switch(ch) {
                    case ')':
                        if(stk.top()=='(')
                            stk.pop();
                        else {
                            isValid = false;
                            break;
                        }
                        break;
                    case '}':
                        if(stk.top()=='{')
                            stk.pop();
                        else {
                            isValid = false;
                            break;
                        }
                        break;
                    case ']':
                        if(stk.top()=='[')
                            stk.pop();
                        else {
                            isValid = false;
                            break;
                        }
                        break;
                }
        }
        else if(ch==';')
            break;
    }
    if(stk.isEmpty() && isValid) cout << "Valid" << "\n";
    else cout << "Not valid" << "\n";

    return 0;
}