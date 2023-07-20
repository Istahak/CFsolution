#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[s[i]]++;
    vector<char> v;
    int flag = n / k;

    for (int i = 1; i <= k; i++)
    {
        int cnt = 0;
        int sv = v.size();
        for (char j = 'a'; j <= 'z'; j++)
        {
            if (cnt == flag)
            {
                if (sv == v.size())
                {
                    v.push_back(j);
                }
                break;
            }
            if (mp[j])
                mp[j]--;
            else
            {

                if (sv != v.size())
                    continue;
                v.push_back(j);
            }
            cnt++;
        }
        if (sv == v.size())
            v.push_back('z');
    }
    sort(v.rbegin(), v.rend());
    for (auto i : v)
        cout << i;
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
