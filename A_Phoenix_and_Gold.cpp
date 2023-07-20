#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    ll sum = 0, flag = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum == x)
        {
            flag = i;
        }
    }
    if (sum == x)
    {
        cout << "NO" << endl;
        return;
    }
    if (flag != -1)
        swap(v[flag], v[n - 1]);
    cout << "YES" << endl;

    for (auto i : v)
    {

        cout << i << ' ';
    }
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