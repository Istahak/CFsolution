#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    map<char, int> s1, ss;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        s1[s[i]]++;
        a[i] = s1.size();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ss[s[i]]++;
        b[i] = ss.size();
    }
    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, a[i] + b[i + 1]);
    }
    cout << ans << endl;
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