#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, x;
    cin >> n >> x;
    if (n % x)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        v[i] = i;
    }
    v[1] = x;
    v[n] = 1;

    for (int i = 2; i * i <= (n / x); i++)
    {
        while ((n / x) % i == 0)
        {
            v[x] = x * i;
            x *= i;
        }
    }
    if (x < n)
        v[x] = n;
    for (int i = 1; i <= n; i++)
        cout << v[i] << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}