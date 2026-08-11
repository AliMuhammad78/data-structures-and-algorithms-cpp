#include <iostream>
using namespace std; 


void insertionsort (int arr[] , int size ){
	
	for (int i = 1 ; i < size  ; i ++ ){
		int current = arr[i];
		int prev = i -1 ; 
		
		while ( prev >= 0 && arr[prev] > current ){  // if < laga diya to decending order ma chla jaye ga 
			
			arr[prev +1 ] = arr [prev] ;
			prev -- ;
		}
		
		
		arr[prev + 1 ] = current ; 
		
		
	}
	
}
void displayarray ( int arr[] , int size ){
	
	for ( int i =0 ; i <  size ; i++ ){
		cout << arr[i] << " ";
	}
}




int main (){

int arr [] = {99 , 55 , 4, 66, 28, 31, 36, 52, 38, 72 };

int size = sizeof (arr) / sizeof (arr[0]) ;
 
insertionsort (arr, size ) ;
displayarray( arr , size ) ;
 



}
