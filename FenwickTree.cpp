#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define pf push_front
#define ppf pop_front
#define ppb pop_back
#define fi first
#define se second
#define ins insert
#define sz(x) (int)x.size()

const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;

using namespace std;

int dx[9] = {0, 1, -1, 0, 0, 1, -1, 1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, 1, -1, -1};

struct FenwickTree{
        vector <int> bit;
        int n;


        void Initialize (int s){
                n = s;
                bit.assign(s, 0);
        }

        void Update (int idx, int val){
                while(idx < n){
                    bit[idx] += val;
                    idx = (idx | (idx + 1));
                }
        }

        int Sum (int idx){
                int res = 0;
                while(idx >= 0){
                    res += bit[idx];
                    idx = (idx & (idx + 1)) - 1;
                }
                return res;
        }
};

void TestCase (){
        struct FenwickTree ftw;
        ftw.Initialize(100);
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