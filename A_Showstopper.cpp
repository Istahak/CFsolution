#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        int x = a[i], y = b[i];
        a[i] = min(x, y);
        b[i] = max(x, y);
    }
    int mxa = *max_element(a.begin(), a.end());
    int mxb = *max_element(b.begin(), b.end());
    cout << ((mxa == a[n - 1] && mxb == b[n - 1]) ? "Yes" : "No") << endl;
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
