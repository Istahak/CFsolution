#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> sm(26, 0), bi(26, 0);

    for (auto &c : s)
    {
        if (c >= 'a' && c <= 'z')
            sm[c - 'a']++;
        else
            bi[c - 'A']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (sm[i] == bi[i])
            ans += sm[i];
        else if (sm[i] < bi[i])
        {
            ans += sm[i];
            bi[i] -= sm[i];
            while (bi[i] >= 2 && k > 0)
            {
                k--;
                ans++;
                bi[i] -= 2;
            }
        }
        else
        {
            ans += bi[i];
            sm[i] -= bi[i];
            while (sm[i] >= 2 && k > 0)
            {
                k--;
                ans++;
                sm[i] -= 2;
            }
        }
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