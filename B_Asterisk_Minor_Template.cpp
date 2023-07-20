#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void solve()
{
    string a, b;
    cin >> a >> b;
    if (a[0] == b[0])
    {
        cout << "YES" << endl;
        cout << a[0] << '*' << endl;
        return;
    }
    if (a[a.size() - 1] == b[b.size() - 1])
    {
        cout << "YES" << endl;
        cout << '*' << a[a.size() - 1] << endl;
        return;
    }
    bool flag = false;
    string as = "";
    for (int i = 0; i < a.size() - 1; ++i)
    {
        for (int j = 0; j < b.size() - 1; ++j)
        {
            if (a[i] == b[j] && a[i + 1] == b[j + 1])
            {
                flag = true;
                as.push_back(a[i]);
                as.push_back(a[i + 1]);
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag)
    {
        cout << "YES" << endl;
        cout << '*' << as << '*' << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    cin >> tt;
    for (int ii = 1; ii <= tt; ++ii)
    {
        // cout << "Case #" << ii << ": ";
        solve();
    }
    return 0;
}