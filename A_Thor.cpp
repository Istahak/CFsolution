#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<bool> state(q);
    int ans = 0, top = 0;
    queue<int> unread;
    vector<stack<int>> app(n + 1);
    while (q--)
    {
        int type, x;
        cin >> type >> x;
        if (type == 1)
        {
            app[x].push(top);
            unread.push(top);
            state[top] = true;
            top++, ans++;
        }
        if (type == 2)
        {
            while (!app[x].empty())
            {
                int current = app[x].top();
                app[x].pop();
                if (state[current])
                    ans--;
                state[current] = false;
            }
        }
        if (type == 3)
        {
            while (!unread.empty() && unread.front() < x)
            {
                int current = unread.front();
                unread.pop();
                if (state[current])
                    ans--;
                state[current] = false;
            }
        }
        cout << ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}