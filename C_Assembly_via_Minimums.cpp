#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int x = n * (n - 1);
    x /= 2;
    set<int> st;
    map<int, int> fr;
    for (int i = 0; i < x; i++)
    {
        int x;
        cin >> x;
        fr[x]++;
        st.insert(x);
    }
    int ff = n - 1;
    int cnt = 0;
    int mx = 0;
    while (!st.empty())
    {
        if (ff == 0)
            break;
        int cur = *st.begin();
        cout << cur << ' ';
        cnt++;
        st.erase(cur);
        mx = max(cur, mx);
        fr[cur] -= ff;
        ff--;
        if (fr[cur])
        {
            st.insert(cur);
        }
    }
    if (cnt == n)
        cout << endl;
    else
        cout << int(1e9) << endl;
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