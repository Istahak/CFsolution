#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 30;

void solve()
{
    int n;
    cin >> n;
    int p;
    for (int x = 2;; x++)
    {
        if (n % x != 0)
        {
            p = x;
            break;
        }
    }
    char cc = 'a';
    for (int i = 1; i <= n; i++)
    {
        cout << cc;
        if (i % p == 0)
        {
            cc = 'a';
        }
        else
            cc++;
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}