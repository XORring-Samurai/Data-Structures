#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ins insert
#define sz(x) (int)x.size()
#define dbg(x) cout << x << "\n";
 
const int N = 1e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
 
using namespace std;

struct LCA{
        vector <int> euler, d, f, g[100001], t;
        vector <bool> vis;
        int n;

        void Initialize (int s){
                n = s;
                f.assign(n + 1, 5 * N);
                d.assign(n + 1, INT_MAX);
                d[1] = 0;
                vis.assign(n + 1, false);
                t.assign(524288, 0);
        }

        void Dfs (int t){
                vis[t] = true;
                euler.pb(t);
                for(auto u: g[t]){
                        if(!vis[u]){
                                d[u] = d[t] + 1;
                                Dfs(u);
                                euler.pb(t);
                        }
                }
        }

        void Update (int idx, int node, int v, int tl, int tr){
                if(tl == tr){
                        t[v] = node;
                }
                else{
                        int tm = (tl + tr)/2;
                        if(idx <= tm) Update(idx, node, 2 * v + 1, tl, tm);
                        else Update(idx, node, 2 * v + 2, tm + 1, tr);
                        t[v] = ((d[t[2 * v + 1]] > d[t[2 * v + 2]]) ? t[2 * v + 2] : t[2 * v + 1]);
                }
        }

        int Query (int l, int r, int v, int tl, int tr){
                if(tl == l && tr == r) return t[v];
                else{
                        int tm = (tl + tr)/2;
                        if(r <= tm) return Query(l, r, 2 * v + 1, tl, tm);
                        else if(l > tm) return Query(l, r, 2 * v + 2, tm + 1, tr);
                        else{
                                int left = Query(l, tm, 2 * v + 1, tl, tm);
                                int right = Query(tm + 1, r, 2 * v + 2, tm + 1, tr);
                                if(d[left] < d[right]) return left;
                                else return right;
                        }
                }
        }

        int Ancestor (int x, int y, int k){
                x = f[x], y = f[y];
                if(x <= y) return Query(x, y, 0, 0, k - 1);
                else return Query(y, x, 0, 0, k - 1);
        }
};
 
void TestCase (){
        struct LCA lca;
        int n;
        cin >> n;
        lca.Initialize(n);
        for(int i = 1, u, v; i<n; i++){
                cin >> u >> v;
                lca.g[u].pb(v);
                lca.g[v].pb(u);
        }
        lca.Dfs(1);
        // for(auto x: lca.euler) cout << x << " ";
        for(int i = 0; i<sz(lca.euler); i++) lca.f[lca.euler[i]] = min(i, lca.f[lca.euler[i]]);
        // for(int i = 1; i<=n; i++) cout << lca.f[i] << " ";
        // cout << "\n";
        int k =  sz(lca.euler), msb = -1;
        for(int i = 0; i<32; i++){
                if(k & (1 << i)) msb = max(msb, i);
        }
        k = (1 << (msb + 1));
        // cout << k << "\n";
        while(sz(lca.euler) != k) lca.euler.pb(0);
        // for(auto x: lca.euler) cout << x << " ";
        // cout << "\n";
        for(int i = 0; i<sz(lca.euler); i++) lca.Update(i, lca.euler[i], 0, 0, k - 1);
        // for(int i = 0; i<2 * k; i++) cout << lca.t[i] << " ";
        int q;
        cin >> q;
        while(q--){
                int u, v;
                cin >> u >> v;
                cout << lca.Ancestor(u, v, k) << "\n";                      
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