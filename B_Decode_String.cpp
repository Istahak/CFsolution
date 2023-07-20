#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    string s, sa;
    cin >> s;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            int a = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            sa.push_back(a + 'a' - 1);
            i--;
            i--;
        }
        else
        {
            sa.push_back(s[i] - '0' + 'a' - 1);
        }
    }
    reverse(sa.begin(), sa.end());
    cout << sa << endl;
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