#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
int arr[1000001];
vector<int> nodes[1000001];
int n, m, ans = 0;
bool visited[1000001];

// long long int a, b;
void DFS(int x, int cnt)
{
    if (visited[x])
        return;
    visited[x] = true;
    if (arr[x])
        cnt++;
    if (cnt > m)
        return;
    if (arr[x] == 0)
        cnt = 0;
    for (int i = 0; i < nodes[x].size(); i++)
    {
        DFS(nodes[x][i], cnt);
    }
    if (nodes[x].size() == 1 && x != 1)
        ans++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }
    DFS(1, 0);
    cout << ans << endl;

    return 0;
}