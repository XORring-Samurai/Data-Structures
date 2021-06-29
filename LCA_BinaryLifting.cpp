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
 
const int N = 1e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
const long double Eps = 1e-9;
 
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
 
using namespace std;

vector <int> g[N];
int up[N][20];
vector <int> tin(N), tout(N);
int timer;

void Dfs (int t, int p){
        tin[t] = timer;
        timer++;

        up[t][0] = p;
        for(int i = 1; i<20; i++){
                up[t][i] = up[ up[t][i - 1] ][i - 1];
        }

        for(auto u: g[t]){
                if(u != p) Dfs(u, t);
        }

        tout[t] = timer;
        timer++;
}

bool isAncestor (int x, int y){
        if(tin[x] < tin[y] && tout[x] > tout[y]) return true;
        return false;
}

int LCA (int x, int y){
        if(isAncestor(x, y)) return x;

        if(isAncestor(y, x)) return y;

        for(int i = 19; i>=0; i--){
                if(isAncestor(up[x][i], y) == false) x = up[x][i]; 
        }
        return up[x][0];
}
 
void TestCase (){
        int n;
        cin >> n;

        timer = 0;
        for(int i = 1, u, v; i<n; i++){
                cin >> u >> v;
                g[u].pb(v);
                g[v].pb(u);
        }

        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);

        Dfs(1, 1);

        int q;
        cin >> q;
        while(q--){
                int u, v;
                cin >> u >> v;
                cout << LCA(u, v) << "\n";
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