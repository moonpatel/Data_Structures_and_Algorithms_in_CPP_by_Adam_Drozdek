// This program takes as input two large numbers and returns the result of their sum

#include <iostream>
#include <string>

#include "stack/stack.h"
#include "stack/stack.cpp"

char TOP(STACK<char> &stk) {
    if(stk.isEmpty()) return char{0};
    char temp = stk.top();
    return temp;
}

using namespace std;

int main() {
    STACK<char> stack1,stack2,resultStack;
    string num1,num2,result;

    cout << "Enter first number: " << "\n";
    cin >> num1;
    cout << "Enter second number: " << "\n";
    cin >> num2;

    for(int i=0; i<num1.size(); i++)        // push the digits of the number on stack
        stack1.push(num1[i]);
    for(int i=0; i<num2.size(); i++)
        stack2.push(num2[i]);
    
    int carry=0,temp=0;
    while(!(stack1.isEmpty() && stack2.isEmpty())) {
        if(!stack1.isEmpty()) {   
            temp = stoi(string{stack1.top()});
            stack1.pop();
        }
        if(!stack2.isEmpty()) {
            temp += stoi(string{stack2.top()});
            stack2.pop();
        }
        temp += carry;
        carry = temp/10;
        temp = temp%10;
        result = to_string(temp) + result;
    }

    if(carry!=0)
        result = to_string(carry) + result;

    cout << "SUM: " << result << "\n";

    return 0;
}