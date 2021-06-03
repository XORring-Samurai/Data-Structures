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

/*
Lazy Propagating a SegTree,
Operations are Adding v, on a segment (l, r)
and finding Maximum on a segment (l, r).
*/

struct SegmentTree{
        vector <long long int> t, lazy;

        void Initialize (long long int n){
                t.assign(4 * n, 0);
                lazy.assign(4 * n, 0);
        }

        void Push (long long int v){
                lazy[2 * v + 1] += lazy[v];
                lazy[2 * v + 2] += lazy[v];
                t[2 * v + 1] += lazy[v];
                t[2 * v + 2] += lazy[v];
                lazy[v] = 0;
        }

        void Update (long long int l, long long int r, long long int add, long long int v, long long int tl, long long int tr){
                if(tl == l && tr == r){
                        t[v] += add;
                        lazy[v] += add;
                }
                else{
                        Push(v);
                        int tm = (tl + tr) / 2;
                        if(r <= tm) Update(l, r, add, 2 * v + 1, tl, tm);
                        else if(l > tm) Update(l, r, add, 2 * v + 2, tm + 1, tr);
                        else{
                                Update(l, tm, add, 2 * v + 1, tl, tm);
                                Update(tm + 1, r, add, 2 * v + 2, tm + 1, tr);
                        }
                        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
                
                }
        }

        long long int Min (long long int l, long long int r, long long int v, long long int tl, long long int tr){
                if(tl == l && tr == r){
                        return t[v];
                }
                else{
                        Push(v);
                        long long int tm = (tl + tr) / 2;
                        if(r <= tm) return Min(l, r, 2 * v + 1, tl, tm);
                        else if(l > tm) return Min(l, r, 2 * v + 2, tm + 1, tr);
                        else{
                                return min(Min(l, tm, 2 * v + 1, tl, tm), Min(tm + 1, r, 2 * v + 2, tm + 1, tr));
                        }
                }
        }
};
 
void TestCase (){
        int n, m;
        cin >> n >> m;
        SegmentTree sgmt;
        sgmt.Initialize(n);
        while(m--){
                int ty;
                cin >> ty;
                if(ty == 1){
                        int l, r, v;
                        cin >> l >> r >> v;
                        sgmt.Update(l, r - 1, v, 0, 0, n - 1);
                }
                else{
                        int l, r;
                        cin >> l >> r;
                        cout << sgmt.Min(l, r - 1, 0, 0, n - 1) << "\n";
                }
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
