#include <iostream >
#include <queue>

using namespace std ; 


queue <int> bankqu ; 

int main (){
	
	
	bankqu.push(4);
	bankqu.push(6);
	bankqu.pop(); 
while (! bankqu.empty()){
	cout << bankqu.front() << endl ; 
	bankqu.pop();
}
	return 0 ; 
}
