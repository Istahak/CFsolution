#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int gc = 0, mx = INT_MIN;
    for (auto &i : v)
    {
        cin >> i;
        gc = __gcd(gc, i);
        mx = max(mx, i);
    }
    cout << (mx / gc) << endl;
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