#include <iostream>
#include <stack>
#include <string>

using namespace std;



// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s; // Stack to hold operators
    string postfix = ""; // To store postfix result
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(c)) {
            postfix += c;
        }
        // If the character is an opening parenthesis, push it to the stack
        else if (c == '(') {
            s.push(c);
        }
        // If the character is a closing parenthesis, pop until '(' is found
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Discard the '('
        }
        // If the character is an operator, handle precedence
        else if (c == '+' || c == '*' || c == '-') {
            // While the stack is not empty and precedence of current operator is less than or equal to the top of stack, pop the stack
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c); // Push the current operator onto the stack
        }
    }
    
    // Pop all remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

int main() {
    string infix = "a+b*c+(d*e+f)*g";
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}

