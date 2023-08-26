#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    int l = 0;
    for (int i = 0; i < n - k; i++)
    {
        // cout << s[i] << ' ' << s[i + k] << endl;
        if (s[i] > s[i + k])
        {
            for (int j = 0; j < i; j++)
                cout << s[j];
            for (int j = i + k; j < n; j++)
                cout << s[j];
            cout << endl;
            return;
        }
    }
    for (int i = 0; i < n - k; i++)
    {
        cout << s[i];
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