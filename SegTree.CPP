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
 
const int N = 4e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
 
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
 
using namespace std;

struct SegmentTree{
        vector <int> t;

        void Initialize () {t.assign(N, 0); }

        void Update (int idx, int val, int v, int tl, int tr){
                if(tl == tr) t[v] = val;
                else{
                        int tm = (tl + tr) >> 1;
                        if(idx <= tm) Update(idx, val, 2 * v + 1, tl, tm);
                        else Update(idx, val, 2 * v + 2, tm + 1, tr);

                        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
                }
        }

        int Max (int l, int r, int v, int tl, int tr){
                if(tl == l && tr == r) return t[v];
                else{
                        int tm = (tl + tr) >> 1;
                        if(r <= tm) return Max(l, r, 2 * v + 1, tl, tm);
                        else if(l > tm) return Max(l, r, 2 * v + 2, tm + 1, tr);
                        else return max(Max(l, tm, 2 * v + 1, tl, tm), Max(tm + 1, r, 2 * v + 2, tm + 1, tr));
                }
        }
};
 
void TestCase (){
        int n, m;
        cin >> n >> m;
        struct SegmentTree sgmt;
        sgmt.Initialize();
        
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