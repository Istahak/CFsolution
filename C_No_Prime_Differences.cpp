#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool isPrime(int number)
{
    if (number <= 1)
    {
        return false; // 1 and numbers less than 1 are not prime
    }

    int sqrtNum = sqrt(number);
    for (int i = 2; i <= sqrtNum; ++i)
    {
        if (number % i == 0)
        {
            return false; // Number is divisible by i, hence not prime
        }
    }

    return true; // Number is prime
}

void solve(int n, int m)
{

    bool ok = false;
    if (n > m)
        swap(n, m), ok = true;
    vector<vector<int>> v(n, vector<int>(m));
    int x = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[i][j] = x++;
        }
        rotate(v[i].begin(), v[i].begin() + i, v[i].end());
    }
    if (ok)
    {
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                cout << v[i][j] << ' ';
            }
            cout << endl;
        }
        return;
    }
    for (auto vv : v)
    {
        for (auto x : vv)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        int n, m;
        cin >> n >> m;
        if ((!isPrime(n) and !isPrime(m)) || (isPrime(n) and !isPrime(m)))
        {
            int x = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << x++ << ' ';
                }
                cout << endl;
            }
            continue;
        }
        solve(n, m);
    }
    return 0;
}