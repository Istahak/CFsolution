#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n - 1), a(n), ans;
    for (auto &i : v)
        cin >> i;
    if (n == 2)
    {
        cout << v[0] << ' ' << 0 << endl;
        return;
    }
    cout << v[0] << ' ';
    for (int i = 0; i < n - 2; i++)
    {
        cout << min(v[i], v[i + 1]) << ' ';
    }
    cout << v[n - 2] << endl;
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