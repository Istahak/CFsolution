#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class DSU
{
public:
    int n;
    vector<int> parent;
    vector<int> size;
    int curset;
    DSU(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        size.resize(n + 1);
        curset = 0;
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
            curset++;
        }
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    auto ok = [&](vector<int> a)
    {
        int asz = a.size();
        if(asz==1) return 0LL;
        DSU st(asz);
        ll ans = 0;
        vector<int> prefixmx(asz);
        prefixmx[0] = a[0];
        for (int i = 1; i < asz; i++)
        {
            prefixmx[i] = max(prefixmx[i - 1], a[i]);
        }
        for (int i = 1; i < asz; i++)
        {
            while (i - st.size[st.find_set(i)] >= 0 and a[i] < prefixmx[i - st.size[st.find_set(i)]])
            {
                st.marge(i, i - st.size[st.find_set(i)]);
            }
            ans += st.curset;
        }
        return ans;
    };
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> arr;
        for (int j = i; j < n; j++)
        {
            arr.push_back(v[j]);
        }
        ans += ok(arr);
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