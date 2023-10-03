#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateArrayRight(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // Handle cases where k is greater than array size

    reverseArray(arr, 0, n - 1);       // Reverse the whole array
    reverseArray(arr, 0, k - 1);       // Reverse the first k elements
    reverseArray(arr, k, n - 1);       // Reverse the remaining n-k elements
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 1;

    rotateArrayRight(arr, k);

    cout << "Rotated Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
