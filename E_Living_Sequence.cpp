#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    vector<int> v;
    while (n)
    {
        v.push_back(n % 9);
        n /= 9;
    }
    reverse(v.begin(), v.end());
    for (auto x : v)
    {
        if (x >= 4)
        {
            cout << (++x);
        }
        else
            cout << x;
    }
    cout << endl;
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}