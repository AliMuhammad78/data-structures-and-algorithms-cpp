#include <iostream>
using namespace std; 

 int minVal (int arr[], int  size){
 	
 	int min = arr [0];
 	
 	for (int i =1 ; i < size ; i++){
 		if (arr[i] < min ){
 			min = arr[i];
		 }
	 }
 	return min; 
 }
 
 
 int main (){
 	int arr [ ]= {34, 384, 934 , 939 , 9023 ,3049 ,10 };
 	int size = sizeof(arr)/sizeof(arr[0]);
 	
 	int lowestelement = minVal(arr, size);
 	
 	cout << "The lowest element is "<<lowestelement << endl ; 
 	
 	return 0;
 }
