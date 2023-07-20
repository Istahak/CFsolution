#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> a;
    for (auto &i : v)
        cin >> i, a.insert(i);
    if (a.size() == 1)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    cout << v[0] << ' ' << v[n - 1] << ' ';
    for (int i = n - 2; i >= 1; i--)
        cout << v[i] << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}