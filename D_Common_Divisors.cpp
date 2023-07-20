#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> computeLPS(string pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}
void solve()
{
    string a, b;
    cin >> a >> b;
    int sza = a.size();
    int szb = b.size();
    int comdi = __gcd(sza, szb);
    vector<int> divisor;
    for (int i = 1; i * i * 1LL <= comdi; i++)
    {
        if (comdi % i == 0)
        {
            divisor.push_back(i);
            if (comdi / i == i)
                continue;
            divisor.push_back(comdi / i);
        }
    }
    sort(divisor.begin(), divisor.end());
    int ans = 0;
    for (auto d : divisor)
    {
        string p = a.substr(0, d);
        bool ok = true, okk = true;
        for (int i = 0; i < sza; i++)
        {
            if (a[i] != p[i % d])
                ok = false;
        }
        for (int i = 0; i < szb; i++)
        {
            if (b[i] != p[i % d])
                okk = false;
        }

        if (ok && okk)
        {
            ans++;
            // cout << p << endl;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}