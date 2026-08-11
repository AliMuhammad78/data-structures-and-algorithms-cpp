#include <iostream> 
#include <stack>
 #include <string> 
using namespace std;

// logic ;  ham ko aik infix notation di gai ho gi , ab uss ma 3  trah ki cheezein ho skti ha operand , brackets aur perator 
// operand ko  to seeda seeda print kerwana ha , q k postfix ma operator end py hoty , 
//agar { ho gi to push into stack 
// agar } ho gi to pop from stack until we see { 
// agar operator hua to pop krein gy jab tak uss operator sy less precedence wala operator na a jaye
// end py pop ker lein gy sab ko


string IntoPostfix( string infix){
    stack <char> st;
    string postfix = "";
    for ( i = 0 ; i < infix.length() ; i ++ )
    char c = infix [i];
    
    if ( c>= a && c<=z)  ( c>= A && c<=Z)  ( c>= 0 && c<=9) 
    postfix = postfix + c ; 

// for opening bracket
    else if (c == '(') {
        st.push(c);
    }
     
    // for closing bracket 
    else if {

    }

    // for handling operator 
    else if (c == '+' || c == '*' || c == '-') {

    } 

    // to pop all elements at the end


    return postfix ;
}







int main (){

 string infix = "a+b*c+(d*e+f)*g";

 string postfix = IntoPostfix(infix);

 cout << "Postfix expression: " << postfix << endl;
    return 0;

}