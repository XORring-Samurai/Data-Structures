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

struct DSU{
        vector <int> g[100001], s, a;
        int n;

        void Initialize (int n){
                s.assign(n + 1, 1);
                for(int i = 1; i<=n; i++){
                        g[i].pb(i);
                        a[i] = i;
                }
        }

        int Root (int x){ return a[x]; }

        void Merge (int x, int y){
                x = Root(x);
                y = Root(y);
                if(x != y){
                        if(s[x] > s[y]){
                                for(auto u: g[y]){
                                        g[x].pb(u);
                                        a[u] = x;
                                }
                                s[x] += s[y];
                        }
                        else{
                                for(auto u: g[x]){
                                        g[y].pb(u);
                                        a[u] = y;
                                }
                                s[y] += s[x];
                        }
                }
        }

        bool Find (int x, int y){
                if(Root(x) == Root(y)) return true;
                else return false;
        }

}dsu;
 
void TestCase (){
        int n, m, a, b;
        cin >> n >> m;
        dsu.Initialize(n);
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