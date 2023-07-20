#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int bit = 31;
map<int, int> fr;
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
        cur->cnt++;
    }
}
void remove(int n)
{
    node *cur = root;
    for (int i = bit; i >= 0; i--)
    {
        int x = ((n >> i) & 1);
        cur = cur->nxt[x];
        cur->cnt--;
    }
}
int find(int n)
{
    int ans = 0;
    node *cur = root;
    for (int i = bit; i >= 0; i--)
    {
        int ace = ((n >> i) & 1);
        int need = !ace;
        ans *= 2;
        if (cur->nxt[need] and cur->nxt[need]->cnt)
            cur = cur->nxt[need], ans++;
        else
            cur = cur->nxt[ace];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    root = new node();
    insert(0);
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
        {
            if (fr[x] == 0)
                insert(x);
            fr[x]++;
        }
        if (c == '-')
        {
            fr[x]--;
            if (fr[x] == 0)
                remove(x);
        }
        if (c == '?')
        {
            int ans = find(x);
            cout << ans << endl;
        }
    }
    return 0;
}