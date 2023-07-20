#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1)
    {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    vector<int> fr(26, 0), fr2(26, 0);
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1])
        {
            cnt++;
            fr2[s[i] - 'a']++;

            // cout << s[i] << ' ' << s[n - i-1] << endl;
        }
        fr[s[i] - 'a']++;
        fr[s[n - i - 1] - 'a']++;
    }
    int xx = n / 2 + 1;
    for (auto x : fr)
    {
        if (x >= xx)
        {
            cout << -1 << endl;
            return;
        }
    }
    int mx = *max_element(fr2.begin(), fr2.end());
    if (mx > cnt - mx)
    {
        cout << mx << "\n";
        return;
    }
    cout << (cnt + 1) / 2 << endl;
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