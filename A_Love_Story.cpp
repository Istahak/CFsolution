#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    const string ss = "codeforces";
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ss[i])
            cnt++;
    }
    cout << cnt << endl;
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