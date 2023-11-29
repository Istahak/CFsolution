#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct Trie
{
    static const int B = 31;
    struct node
    {
        node *nxt[2];
        int sz;
        node()
        {
            nxt[0] = nxt[1] = NULL;
            sz = 0;
        }
    } *root;
    Trie()
    {
        root = new node();
    }
    void insert(int val)
    {
        node *cur = root;
        cur->sz++;
        for (int i = B - 1; i >= 0; i--)
        {
            int b = val >> i & 1;
            if (cur->nxt[b] == NULL)
                cur->nxt[b] = new node();
            cur = cur->nxt[b];
            cur->sz++;
        }
    }
    int query(int x, int k)
    { // number of values s.t. val ^ x < k
        node *cur = root;
        int ans = 0;
        for (int i = B - 1; i >= 0; i--)
        {
            if (cur == NULL)
                break;
            int b1 = x >> i & 1, b2 = k >> i & 1;
            if (b2 == 1)
            {
                if (cur->nxt[b1])
                    ans += cur->nxt[b1]->sz;
                cur = cur->nxt[!b1];
            }
            else
                cur = cur->nxt[b1];
        }
        return ans;
    }
    int get_max(int x)
    { // returns maximum of val ^ x
        node *cur = root;
        int ans = 0;
        for (int i = B - 1; i >= 0; i--)
        {
            int k = x >> i & 1;
            if (cur->nxt[!k])
                cur = cur->nxt[!k], ans <<= 1, ans++;
            else
                cur = cur->nxt[k], ans <<= 1;
        }
        return ans;
    }
    int get_min(int x)
    { // returns minimum of val ^ x
        node *cur = root;
        int ans = 0;
        for (int i = B - 1; i >= 0; i--)
        {
            int k = x >> i & 1;
            if (cur->nxt[k])
                cur = cur->nxt[k], ans <<= 1;
            else
                cur = cur->nxt[!k], ans <<= 1, ans++;
        }
        return ans;
    }
    void del(node *cur)
    {
        for (int i = 0; i < 2; i++)
            if (cur->nxt[i])
                del(cur->nxt[i]);
        delete (cur);
    }
};
void solve()
{
    int n;
    cin >> n;

    vector<int> b(n);
    b[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        b[i] = b[i - 1] ^ x;
    }

    Trie tt;
    for (auto &x : b)
        tt.insert(x);
    int mxval;
    for (auto &x : b)
    {
        int mx = tt.get_max(x);
        if (mx == n - 1)
        {
            mxval = x;
            break;
        }
    }

    for (auto &x : b)
        x ^= mxval;
    for (auto ans : b)
        cout << ans << ' ';
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}