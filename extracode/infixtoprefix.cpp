#include <iostream>
#include <stack>
#include <algorithm> // for reverse()
#include <cctype>    // for isalnum()

using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to reverse and swap parentheses in the expression
string reverseExpression(string exp) {
    reverse(exp.begin(), exp.end());  // Reverse the entire expression
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') exp[i] = ')';  // Swap '(' with ')'
        else if (exp[i] == ')') exp[i] = '(';  // Swap ')' with '('
    }
    return exp;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    // Step 1: Reverse the infix expression
    infix = reverseExpression(infix);
    
    stack<char> s;  // Stack to hold operators
    string prefix = "";  // Resultant prefix expression

    // Step 2: Process the reversed expression
    for (char &c : infix) {
        if (isalnum(c)) {
            // If the character is an operand, add to the prefix
            prefix += c;
        }
        else if (c == '(') {
            // Push '(' onto the stack
            s.push(c);
        }
        else if (c == ')') {
            // Pop until '(' is encountered
            while (!s.empty() && s.top() != '(') {
                prefix += s.top();
                s.pop();
            }
            s.pop();  // Remove '(' from the stack
        }
        else if (isOperator(c)) {
            // Pop from the stack while the precedence of the operator on the stack
            // is greater or equal to the precedence of the current operator
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                prefix += s.top();
                s.pop();
            }
            s.push(c);  // Push the current operator onto the stack
        }
    }

    // Step 3: Pop remaining operators from the stack
    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    // Step 4: Reverse the resultant expression to get the final prefix expression
    reverse(prefix.begin(), prefix.end());
    
    return prefix;
}

int main() {
    string infix = "a+b*c+(d*e+f)*g";
    cout << "Infix expression: " << infix << endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}

