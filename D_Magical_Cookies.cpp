#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cin>>grid[i][j];
        }
    }
    bool row[n], column[m];
    memset(row, false, sizeof(row));
    memset(column, false, sizeof(column));
    while(true){
        vector<int> v1, v2;
        for(int i = 0; i<n; ++i){
            if(row[i]) continue;
            char ch = '#';
            int cnt = 0;
            bool flag = true;
            for(int j = 0; j<m; ++j){
                if(column[j]){
                    // cnt++;
                    continue;
                }
                if(ch=='#'){
                    cnt++;
                    ch = grid[i][j];
                    continue;
                }
                if(grid[i][j]!=ch){
                    flag = 0;
                }
                else{
                    cnt++;
                }
            }
            if(cnt>1 && flag) v1.push_back(i);
        }
        for(int i = 0; i<m; ++i){
            if(column[i]) continue;
            char ch = '#';
            int cnt = 0;
            bool flag = true;
            for(int j = 0; j<n; ++j){
                if(row[j]){
                    // cnt++;
                    continue;
                }
                if(ch=='#'){
                    ch = grid[j][i];
                    cnt++;
                    continue;
                }
                if(grid[j][i]!=ch){
                    flag = 0;
                }
                else{
                    cnt++;
                }
            }
            if(cnt>1 && flag) v2.push_back(i);
        }
        if(v1.size()==0 && v2.size()==0) break;
        for(auto val: v1) row[val] = true;
        for(auto val: v2) column[val] = true;
    }
    int ans = 0;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if(row[i] || column[j]) continue;
            else ans++;
        }
    }
    cout<<ans<<endl;
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