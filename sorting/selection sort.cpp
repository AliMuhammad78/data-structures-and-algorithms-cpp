#include <iostream>
using namespace std ;

void selectionsort (int arr[] , int size ){
	
	for ( int i =0 ; i < size-1 ; i++ ){
		int temp ; 
		int smallestindex = i; // starting of unsorted part
		
		for ( int j =  i +1 ; j <  size  ; j++  ){
			 											 // loop to find minimum from unsorted part 
			if (arr[j] < arr[smallestindex ] )    // if there is any element in unsorted , who is less than i (smallest indes) , 
												// to pher smallest index ko j ker do 
			smallestindex = j ; 
		}
		
		temp = arr[i]; 
		arr[i] = arr[smallestindex]  ;
		arr[smallestindex] = temp ; 
	} 
	
	
}


void printarray(int arr[] , int size ){
	
	for (int i = 0 ; i < size ; i++){
		
		cout << arr[i] << " "; 
		
	}
}




int main (){
	
 
	int arr[] = {26, 33 ,43, 100 ,46 ,88 ,52 ,17 ,53 , 77};
	int size = sizeof(arr)/ sizeof(arr[0]) ;
	
	selectionsort (arr , size );
	printarray(arr, size);
	return 0;
	
}
