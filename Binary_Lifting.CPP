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
 
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
 
using namespace std;

vector <int> g[N], h(N);
vector <vector <int> > up(N);
int LOG;

void Dfs (int t, int p){
        up[t].resize(LOG);
        up[t][0] = p;
        for(int i = 1; i<LOG; i++){
                up[t][i] = up[ up[t][i - 1] ][i - 1];
        }
        for(auto u: g[t]){
                if(u != p){
                        h[u] = h[t] + 1;
                        Dfs(u, t);
                }
        }
}
 
void TestCase (){
        int n, q;
        cin >> n >> q;
        for(int i = 2, x; i<=n; i++){
                cin >> x;
                g[i].pb(x);
                g[x].pb(i);
        }
        LOG = __lg(n);
        if((1 << LOG) < n) LOG++;
        h[1] = 0;
        Dfs(1, 1);
        while(q--){
                int v, k;
                cin >> v >> k;
                if(k > h[v]){
                        cout << -1 << "\n";
                        continue;
                }
                for(int i = LOG - 1; i>=0; i--){
                        if(k & (1 << i)){
                                v = up[v][i];
                        }
                }
                cout << v << "\n";
        }
}
 
int main(){
        IOS;
        int T = 1;
        // cin >> T;
        while(T--){
                TestCase();
                // cout << "\n";
        }
        return 0;
}