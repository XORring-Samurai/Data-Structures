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

/*
used when you can't use the regular vector
and when coordinate compression is not possible
This is my Solution for Little Artem and Time Machine
Codeforces 641E
https://codeforces.com/problemset/problem/641/E
*/

#define int long long int

struct Vertex{
        int lb, ub, sum;
        Vertex *right, *left;
};

struct SegmentTree{
        Vertex *root = new Vertex;

        void Initialize (){
                root->lb = 0;
                root->ub = 1000000000;
                root->sum = 0;
                root->right = NULL;
                root->left = NULL;
        }

        Vertex* Extend(int l, int r){
                Vertex* new_node = new Vertex;
                new_node->lb = l;
                new_node->ub = r;
                new_node->sum = 0;
                new_node->left = NULL;
                new_node->right = NULL;
                return new_node;
        }

        void Update (int idx, int x, Vertex* cur){
                if(cur->lb == cur->ub) cur->sum += x;
                else{
                        int tm = (cur->lb + cur->ub) / 2;
                        if(idx <= tm){
                                if(cur->left == NULL){
                                        cur->left = Extend(cur->lb, tm);
                                }
                                Update(idx, x, cur->left);
                        }
                        else{
                                if(cur->right == NULL){
                                        cur->right = Extend(tm + 1, cur->ub);
                                }
                                Update(idx, x, cur->right);
                        }

                        cur->sum = 0;
                        if(cur->left) cur->sum += cur->left->sum;
                        if(cur->right) cur->sum += cur->right->sum;
                }
        }

        int Sum (int l, int r, Vertex* cur){
                if(l <= cur->lb && cur->ub <= r) return cur->sum;
                else{
                        int tm = (cur->lb + cur->ub) / 2;
                        if(r <= tm){
                                if(cur->left == NULL) return 0;
                                else return Sum(l, r, cur->left);
                        }
                        else if(l > tm){
                                if(cur->right == NULL) return 0;
                                else return Sum(l, r, cur->right);
                        }
                        else{
                                int z = 0;
                                if(cur->left){
                                        z += Sum(l, tm, cur->left);
                                }
                                if(cur->right){
                                        z += Sum(tm + 1, r, cur->right);
                                }
                                return z;
                        }
                }
        }
};
 
void TestCase (){
        int n;
        cin >> n;

        map <int, SegmentTree > m;

        while(n--){
                int a, t, x;
                cin >> a >> t >> x;

                if(a == 1){
                        if(m.find(x) == m.end()){
                                SegmentTree sgmt;
                                sgmt.Initialize();
                                m[x] = sgmt;
                        }
                        m[x].Update(t, 1, m[x].root);
                }
                else if(a == 2){
                        m[x].Update(t, -1, m[x].root);
                }
                else{
                        if(m.find(x) != m.end()) cout << m[x].Sum(0, t, m[x].root) << "\n";
                        else cout << 0 << "\n";
                }
        }
}

#undef int
 
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
