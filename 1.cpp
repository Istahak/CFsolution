#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<string, int> fr;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.size() > 2)
        {
            sort(s.begin() + 1, s.end() - 1);
        }
        fr[s]++;
    }
    int q;
    cin >> q;
    cin.ignore();
    while (q--)
    {
        int ans = 1;
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> v;
        string sss;
        while (getline(ss, sss, ' '))
        {
            v.push_back(sss);
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].size() > 2)
            {
                sort(v[i].begin() + 1, v[i].end() - 1);
            }
            ans *= fr[v[i]];
        }
        cout << ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        cout << "Case " << cs << ": " << endl;
        solve();
    }
    return 0;
}