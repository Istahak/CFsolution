#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

void solve(){
    int n,ans=0; cin >> n;
    int x=ceil((double)n/2.0),y=ceil((double)n/3.0);
    cout<<x<<' '<<y<<endl;
    for(int i=y;i<=x;i++)
    {   
        int p=n-i;
        //cout<<p<<endl;
        ans+=min(p/2,i-p/2);
       cout<<p/2<<' '<<i-p/2<<endl;
    }
    cout << ans << '\n';
}

signed main(){
    fastio; int tc = 1; cin >> tc;
    while(tc--){
        solve();
    }
}