#include <bits/stdc++.h>
using namespace std;

#define N 4

// void rotate90Clockwise(int a[N][N])
// {

//     // Traverse each cycle
//     for (int i = 0; i < N / 2; i++)
//     {
//         for (int j = i; j < N - i - 1; j++)
//         {

//             // Swap elements of each cycle
//             // in clockwise direction
//             int temp = a[i][j];
//             a[i][j] = a[N - 1 - j][i];
//             cout << N - 1 - j << ' ' << i << endl;
//             a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
//             a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
//             a[j][N - 1 - i] = temp;
//         }
//     }
// }

void ro(int a[N][N])
{
    int ans[N][N];
    for (int j = 0, k = 0; j < N, k < N; j++, k++)
    {
        for (int i = N - 1, l = 0; i >= 0, l < N; i--, l++)
        {
            ans[k][l] = a[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = ans[i][j];
        }
    }
}
void anit(int a[N][N])
{
    int ans[N][N];
    for (int j = 0, k = N - 1; j < N, k >= 0; j++, k--)
    {
        for (int i = N - 1, l = N - 1; i >= 0, l >= 0; i--, l--)
        {
            ans[k][l] = a[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = ans[i][j];
        }
    }
}
void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}
void muliply(int a[N][N], int b[N][N])
{
    int res[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                res[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
}
void digo(int a[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if(i==j)
                cout<<a[i][j]<<' ';
        }
}
int main()
{
    int arr[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    anit(arr);
    printMatrix(arr);

    return 0;
}
