#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 100005;
int a[N],b[N],n;

int tree[4 * N];

void init(int id,int l,int r) {
    if(l == r) {
        tree[id] = a[l];
        return;
    }

    int m = (l + r) / 2;
    init(id * 2, l, m);
    init(id * 2 + 1, m + 1, r);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}


int query(int id,int l,int r,int L,int R) {
    if(L > r or R < l) {
        return 0;
    }
    if(L <= l and r <= R) {
        return tree[id];
    }
    int m = (l + r) / 2;
    int left = query(2 * id, l, m, L, R);
    int right = query(2 * id + 1, m + 1, r, L, R);
    return left + right;

}

int Khabar_pai_nai(int val) {
    int l = 1,r = n,ans = 0;
    while(l <= r) {
        int m = (l + r) / 2;
        int sum = query(1, 1, n, 1, m);
        if(sum <= val) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return n - ans;

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <=n; i++) {
        cin >> a[i] >> b[i];
    }
    init(1, 1, n);
    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int val; cin >> val;
            int secondans =  Khabar_pai_nai(val);
            cout << secondans << '\n';


        } else {
            int pos, ai, bi; cin >> pos >> ai >> bi;
        }
    }

    return 0;
}
