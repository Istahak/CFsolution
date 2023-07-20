#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void print(pair<int, int> p)
{
    cout << p.second << ' ';
}
bool flag(pair<int,int>stp,pair<int,int>vp)
{
    return (stp.first<vp.first);
}
void solve()
{
    int n;
    cin >> n;
    std::vector<pair<int, int>> v(n + 1);
    stack<pair<int, int>> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
        while (!st.empty())
        {
            if (flag(st.top(),v[i]))
            {
                print(st.top());
                break;
            }
            else
            {
                st.pop();
            }
        }
        if (st.empty())
        {
            cout << 0 << ' ';
        }
        st.push(v[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {

        solve();
    }

    return 0;
}