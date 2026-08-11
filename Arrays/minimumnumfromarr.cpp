#include <iostream>
using namespace std;

//int main (){
//	
//	int min ; 
//	int arr [12] = { 23, 393 ,22 , 56 , 59 , 36, 22 , 11, 5, 9 , 4, 94 };
//	min = arr [0];
// 
//	for ( int i =1  ; i < 12 ;  i++ ){
// if (arr[i] <= min ){
// 	   min = arr[i];
// }
//}
//	 	cout << "The minimum number is "<<  min << endl; 
//	 	return 0;
//}
// 
// 
										 // print array 
// int main (){
// 	
// 	int arr [4]= {34, 595, 934, 345};
//  for ( int i = 0 ; i < 4 ; i++){
//  	cout << arr[i] << " "  ;  
//  }
// }





 									// to insert element in arr and moving elements to the right 
// 									
//  void  insertAtposition (int arr[], int &size , int element , int position ){
//  	if (position <0 || position > size){
//  		cout << " Invalid entry"<<endl ;
//  		return ;
//  	
//	  }
//	  for (int i = size; i > position; i--) {
//        arr[i] = arr[i - 1];
//    }
//
//    // Insert the new element
//    arr[position] = element;
//
//    // Increase the size of the array
//    size++;
//}
//
//void printArray(int arr[], int size) {
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//	 
//	 
//int main(){
//	int arr []= {34, 595, 934,313,  345};
//	int size;
//	int element ; 
//	int position ; 
//	cout << "Enter the element you want to insert "<< endl;
//	cin >> element ; 
//	cout << "Enter the position where you want to insert the value "<< endl;
//	cin >> position ;
//	insertAtposition (arr, size, element , position );
//	cout << "The array after insertion is ";
//	 printArray(arr, size);
//	
//	return 0;
//	






							// to delete the element and pushing the values to left
 

//void deleteAtIndex(int arr[], int& size, int index) {
//    // Check if the index is valid
//    if (index < 0 || index >= size) {
//        cout << "Invalid index!" << endl;
//        return;
//    }
//
//    // Shift elements to the left to fill the gap
//    for (int i = index; i < size - 1; i++) {
//        arr[i] = arr[i + 1];
//    }
//
//    // Decrease the size of the array by 1
//    size--;
//}
//
//void printArray(int arr[], int size) {
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//    int A[] = {2, 6, 8, 7, 1}; // Initial array
//    int size = 5; // Size of the array
//
//    cout << "Original array: ";
//    printArray(A, size);
//
//    int index = 2; // Index to delete
//    deleteAtIndex(A, size, index);
//
//    cout << "Array after deletion: ";
//    printArray(A, size);
//
//    return 0;
//}

									// to swap array elements
									
//								 
//// Function to reverse the entire array
// void reverseArray(int arr[], int size) {
//    int start = 0;         // Start from the beginning
//    int end = size - 1;    // Start from the end
//
//    // Swap elements until start meets end
//    while (start < end) {
//        int temp = arr[start];
//        arr[start] = arr[end];
//        arr[end] = temp;
//
//        // Move towards the middle
//        start++;
//        end--;
//    }
//}
//
//void printArray(int arr[], int size) {
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//    int A[] = {2, 6, 8, 7, 1}; // Array from the previous example
//    int size = 5;
//
//    cout << "Original array: ";
//    printArray(A, size);
//
//    reverseArray(A, size);
//
//    cout << "Array after reversing: ";
//    printArray(A, size);
//
//    return 0;
//}
//
//

