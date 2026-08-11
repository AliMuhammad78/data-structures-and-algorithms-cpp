#include <iostream>
using namespace std ;

void isprime (int n ){
	if ( n <= 1 ){
		cout << "Enter some number greater than one " << endl ;	}
		for ( int i = 2 ; i <= n ; i++ ){
			
			if ( n% i == 0 ){
				cout << " The number you entered is not prime "<< endl ; 
			}
		}
	cout << "The number is prime "<< endl; 
}


int main (){
	
	int n; 
	cout << "Enter number to calculate whether it is prime or not :  " << endl ; 
	cin >> n; 
	isprime(n); 
	return 0; 
}
