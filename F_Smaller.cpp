#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    map<char, int> a;
    map<char, int> b;
    int q;
    cin >> q;
    int size_1 = 0, size_2 = 0;
    while (q--)
    {
        int x, k;
        string s;
        cin >> x >> k >> s;
        for (auto c : s)
        {
            if (x == 1)
            {
                a[c] += k;
                size_1 += k;
            }
            else
            {
                size_2 += k;
                b[c] += k;
            }
        }
        // cout<<size_1<<' '<<size_2<<endl;
        bool flag = false;
        for (char c = 'b'; c <= 'z'; ++c)
        {
            if (b[c] > 0)
                flag = true;
        }
        if (flag)
        {
            cout << "YES" << endl;
            continue;
        }
        if (size_1 - a['a'] == 0)
        {
            if (size_1 >= size_2)
            {
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
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
