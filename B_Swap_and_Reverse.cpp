#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (~k & 1)
    {
        sort(s.begin(), s.end());
        cout << s << endl;
    }
    else
    {
        string odd, even;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                even.push_back(s[i]);
            }
            else
            {
                odd.push_back(s[i]);
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        reverse(odd.begin(), odd.end());
        reverse(even.begin(), even.end());
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                cout << even.back();
                even.pop_back();
            }
            else
            {
                cout << odd.back();
                odd.pop_back();
            }
        }
        cout << endl;
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
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}