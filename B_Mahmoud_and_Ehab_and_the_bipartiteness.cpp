#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N = 1e5 + 2;
vector<int> edg[N];
vector<bool> visited(N);
vector<int> colour(N);
// long long int a, b;
void DFS(int x, int c)
{
    if (visited[x])
        return;
    visited[x] = true;
    colour[x] = c+1;
    for(auto child: edg[x]){
        DFS(child, c^1);
    }
}
void solve()
{
    int n;
    cin >> n;
    ll cnta = 0, cntb = 0;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }
    DFS(1, 0);
    // for(int i=0;i<6;i++)
    //     cout<<colour[i]<<' ';cout<<endl;
    for (int i = 0; i < N; i++)
    {
        if (colour[i] == 1)
            cnta++;
        if (colour[i] == 2)
            cntb++;
    }
    ll ans = cnta * cntb;
    cout << ans - (n - 1) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
