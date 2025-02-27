#include<iostream>
using namespace std;

void printArray(int *arr, int n) {
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

void fillArray(int *arr, int i, int n, int val) {
    // base case 
    if(i == n) {
        printArray(arr, n);
        return;
    }
    // rec case 
    arr[i] = val;
    fillArray(arr, i+1, n, val+1);

    // backtracking
    arr[i] = -1 * arr[i];
}

int main() {
    int arr[100] = {0};
    int n;
    cin >> n;

    fillArray(arr, 0, n, 1);
    printArray(arr, n);
}

// backtracking code mostly return after the function call
// STL are passed by value