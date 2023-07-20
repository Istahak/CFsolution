#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q;
string s;
int tree[26][4 * N];
int lazy[26][4 * N];
void propagate(int c, int id, int l, int r)
{
    if (lazy[c][id] == -1)
        return;
    if (l != r)
    {
        lazy[c][2 * id + 1] = lazy[c][id];
        lazy[c][2 * id + 2] = lazy[c][id];
    }

    tree[c][id] = lazy[c][id] * (r - l + 1);
    lazy[c][id] = -1;
}
void build(int c, int id, int l, int r)
{
    lazy[c][id] = -1;
    if (l == r)
    {
        tree[c][id] = (s[l] - 'a' == c);
        return;
    }
    int mid = (l + r) / 2;
    build(c, 2 * id + 1, l, mid);
    build(c, 2 * id + 2, mid + 1, r);
    tree[c][id] = tree[c][2 * id + 1] + tree[c][2 * id + 2];
}
int query(int c, int id, int l, int r, int L, int R)
{
    propagate(c, id, l, r);
    if (R < l || r < L)
        return 0;
    if (L <= l && r <= R)
        return tree[c][id];

    int mid = (l + r) / 2;
    auto left = query(c, 2 * id + 1, l, mid, L, R);
    auto right = query(c, 2 * id + 2, mid + 1, r, L, R);
    return left + right;
}
void update(int c, int id, int l, int r, int L, int R, int x)
{
    propagate(c, id, l, r);
    if (r < L || R < l)
        return;
    if (L <= l && r <= R)
    {
        lazy[c][id] = x;
        propagate(c, id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(c, 2 * id + 1, l, mid, L, R, x);
    update(c, 2 * id + 2, mid + 1, r, L, R, x);
    tree[c][id] = tree[c][2 * id + 1] + tree[c][2 * id + 2];
}
void print(int c, int id, int l, int r)
{
    propagate(c, id, l, r);
    if (l == r)
    {
        if (tree[c][id] == 1)
        {
            // cout<<l<<' '<<(char)(c+'a')<<endl;
            s[l] = c + 'a';
        }
        return;
    }
    int mid = (l + r) / 2;
    print(c, 2 * id + 1, l, mid);
    print(c, 2 * id + 2, mid + 1, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < 26; i++)
    {
        build(i, 0, 0, n - 1);
    }
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        vector<int> cnt(26, 0);
        for (int i = 0; i < 26; i++)
        {
            cnt[i] = query(i, 0, 0, n - 1, l, r);
            update(i, 0, 0, n - 1, l, r, 0);
        }
        if (k)
        {
            for (int i = 0; i < 26; i++)
            {
                r = l + cnt[i] - 1;
                update(i, 0, 0, n - 1, l, r, 1);
                l += cnt[i];
            }
        }
        else
        {
            for (int i = 25; i >= 0; i--)
            {
                r = l + cnt[i] - 1;
                update(i, 0, 0, n - 1, l, r, 1);
                l += cnt[i];
            }
        }
    }
    for (int i = 0; i < 26; i++)
        print(i, 0, 0, n - 1);
    cout << s << endl;
    return 0;
}
