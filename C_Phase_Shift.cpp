#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class DSU
{
public:
    int n;
    vector<int> parent;
    vector<int> size;
    DSU(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i, size[i] = 1;
    }
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void marge(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> used(26, 0), init(26, -1);
    DSU st(26);
    string ans(n, ' ');
    set<char> rem;
    for (int i = 0; i < 26; i++)
        rem.insert(i);
    for (int i = 0; i < n; i++)
    {
        int x = s[i] - 'a';
        if (init[x] == -1)
        {
            if (rem.size() == 1)
            {
                init[x] = (*rem.begin());
                rem.erase(*rem.begin());
            }
            for (int j = 0; j < 26; j++)
            {
                if (j == x)
                    continue;
                if (used[j])
                    continue;
                int rtx = st.find_set(x);
                int rtj = st.find_set(j);
                if (rtx == rtj)
                    continue;

                used[j] = true;
                init[x] = j;
                rem.erase(j);
                st.marge(x, j);
                break;
            }
        }
        ans[i] = 'a' + init[x];
    }
    cout << ans << endl;
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