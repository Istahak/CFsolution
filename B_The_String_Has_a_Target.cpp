#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> fr(26, 0);
    string s;
    cin >> s;
    auto tem = s;
    sort(tem.begin(), tem.end());
    char c = tem.front();
    int x = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (c == s[i])
        {
            x = i;
            break;
        }
    }
    cout << c;
    for (int i = 0; i < n; i++)
    {
        if (x == i)
            continue;
        cout << s[i];
    }
    cout << endl;
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}