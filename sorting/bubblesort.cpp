#include <iostream>
using namespace std;


void swap (int &a , int &b ){
	int temp ;
	  temp = a ; 
	  a= b ; 
	  b= temp; 
	  
}

void bubblesort (int arr[]  , int size ){

	for ( int i = 0 ; i < size-1 ; i++ ){
		
		for ( int j = 0 ; j < size -i-1 ; j++ ){
			
			if ( arr[j]> arr[j+1]){
				
				swap ( arr[j] , arr[j+1] ) ;
			  
			}
}
	}
	
}


void displayarray(int arr[] , int size ){
	
	for ( int i = 0 ; i< size ; i++)	{
		cout << arr[i]<< " ";
	}
	
	
}



int main (){
	
	int arr[]={ 9,  6,  2,  12,  11,  9,  3,  7};
	
	int size = sizeof (arr)/ sizeof (arr[0]) ;
 
	bubblesort (arr , size ); 
	displayarray( arr , size );
	return 0 ;
}
