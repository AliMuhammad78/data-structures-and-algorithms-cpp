#include <iostream>
using namespace std;

// Recursive function to find the sum of elements in the array
int sumArray(int arr[], int n) {
    // Base case: if the array has only one element, return it
    if (n == 1) {
        return arr[0];
    }
    // Recursive case: sum the current element and the sum of the rest of the array
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main() {
    int n;

    // Input the size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the elements of the array
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate the sum using the recursive function
    int sum = sumArray(arr, n);

    // Output the result
    cout << "The sum of all elements in the array is: " << sum << endl;

    return 0;
}
