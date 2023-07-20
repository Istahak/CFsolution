#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1 << 20;
const int bit = 20;
struct node
{
    node *nxt[2];
    int cnt;
    node()
    {
        nxt[0] = NULL;
        nxt[1] = NULL;
        cnt = 0;
    }
} *root;
void insert(int n)
{
    node *cur = root;
    for (int i = bit; i >= 0; i--)
    {
        int x = ((n >> i) & 1);
        if (cur->nxt[x] == NULL)
            cur->nxt[x] = new node();
        cur = cur->nxt[x];
    }
}
int find(int n)
{
    int ans = 0;
    node *cur = root;
    for (int i = bit; i >= 0; i--)
    {
        int ace = ((n >> i) & 1);
        int need = ace;

        if (cur->nxt[need])
            cur = cur->nxt[need], ans <<= 1;
        else
            cur = cur->nxt[!ace], ans <<= 1, ans++;
    }
    return ans;
}
vector<bool> exist(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        exist[x] = true;
    }
    root = new node();
    for (int i = 0; i < N; i++)
    {
        if (exist[i])
            continue;
        insert(i);
    }
    int curx = 0;
    while (m--)
    {
        int x;
        cin >> x;
        curx ^= x;
        int ans = find(curx);
        cout << ans << endl;
    }

    return 0;
}