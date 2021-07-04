
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ff first
#define ss second
#define ins insert
#define sz(x) (int)x.size()
#define dbg(x) cout << x << "\n";
 
const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
const long double Eps = 1e-9;
 
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
 
using namespace std;
 
vector <int> g[N], gt[N], order, roots;
vector <bool> vis(N);
 
void Dfs0 (int t){
        vis[t] = true;
        for(auto u: g[t]){
                if(!vis[u]) Dfs0(u);
        }
        order.pb(t);
}
 
void Dfs1 (int t){
        vis[t] = true;
        for(auto u: gt[t]){
                if(!vis[u]) Dfs1(u);
        }
}
 
void TestCase (){
        int n, m;
        cin >> n >> m;
 
        for(int i = 1, u, v; i<=m; i++){
                cin >> u >> v;
                g[u].pb(v);
                gt[v].pb(u);
        }
 
        vis.assign(n + 1, false);
        for(int i = 1; i<=n; i++){
                if(!vis[i]) Dfs0(i);
        }
 
        reverse(order.begin(), order.end());
        // for(auto x: order) cout << x << " ";
        
        vis.assign(n + 1, false);
        for(auto x: order){
                if(!vis[x]){
                        Dfs1(x);
                        roots.pb(x);
                }
        }
 
        if(sz(roots) == 1) cout << "YES";
        else{
                cout << "NO\n";
                cout << roots[1] << " " << roots[0];
        }
        
}
 
int main(){
        IOS;
        int T = 1;
        // cin >> T;
        while(T--){
                TestCase();
                cout << "\n";
        }
        return 0;
}
