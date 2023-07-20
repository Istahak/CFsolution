#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> manacher_odd(string s)
{
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
pair<vector<int>, vector<int>> manacher(string s)
{
    string t;
    for (auto c : s)
    {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    res = vector<int>(begin(res) + 1, end(res) - 1);
    vector<int> odd(s.size()), even(s.size());
    for (int i = 0; i < (int)s.size(); i++)
    {
        odd[i] = res[2 * i] / 2;
        if (i)
        {
            even[i] = (res[2 * i - 1] - 1) / 2;
        }
    }
    return {odd, even};
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto [odd, even] = manacher(s);
    vector<int> len[n + 1];
    for (int i = 0; i < n; i++)
    {
        int l = i - odd[i] + 1;
        int r = i + odd[i] - 1;
        int curlen = 2 * odd[i] - 1;
        len[l].push_back(curlen);
        len[r + 1].push_back(-curlen);
        if (even[i])
        {
            l = i - even[i];
            r = i + even[i] - 1;
            curlen = 2 * even[i];
            len[l].push_back(curlen);
            len[r + 1].push_back(-curlen);
        }
    }
    multiset<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (auto x : len[i])
        {
            if (x > 0)
                ans.emplace(x);
            else
                ans.erase(ans.find(abs(x)));
        }
        cout << (*ans.rbegin()) << ' ';
    }
    cout << endl;
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