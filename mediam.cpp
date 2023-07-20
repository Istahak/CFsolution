#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << arr[0] << " ";
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        for (; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;

        if ((i + 1) & 1)
        {
            cout << arr[i / 2] << " ";
        }
        else
        {
            cout << (arr[(i + 1) / 2] + arr[(i + 1) / 2 - 1]) / 2 << " ";
        }
    }
    cout << endl;
}