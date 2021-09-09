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

#define int long long int

template <typename T> class Matrix{
        public:
        int n, m; // dims
        vector <vector <int> > g;
        // parameterized constructor
        Matrix <T> (int rows = 1, int cols = 1){
                n = rows;
                m = cols;
                g.resize(n);
                for(int i = 0; i<n; i++) g[i].assign(m, 0);
        }
        // copy constructor
        Matrix <T> (const Matrix &A){
                n = A.n;
                m = A.m;
                g = A.g;
        }
        Matrix <T> Identity (const int &rows){
                // square matrix of size rows * rows
                Matrix <T> ret(rows, rows);
                for(int i = 0; i<rows; i++) ret.g[i][i] = 1;
                return ret;
        }
        Matrix <T> Ones (const int &rows, const int &cols){
                // matrix of all ones
                Matrix <T> ret(rows, cols);
                for(int i = 0; i<rows; i++){
                        for(int j = 0; j<cols; j++) ret.g[i][j] = 1;
                }
                return ret;
        }
        void Show (){
                // prints the matrix
                for(int i = 0; i<n; i++){
                        for(int j = 0; j<m; j++) cout << g[i][j] << " ";
                        cout << "\n";
                }
        }
        Matrix <T> operator + (int z){
                // Adds constant z to each element of the matrix
                Matrix <T> ret(n, m);
                for(int i = 0; i<n; i++){
                        for(int j = 0; j<m; j++) ret.g[i][j] = this->g[i][j] + z;
                }
                return ret;
        }
        Matrix <T> operator + (const Matrix <T> &A){
                /*
                Matrix Addition
                dims A = (n, m)
                */
                Matrix <T> ret(n, m);
                for(int i = 0; i<n; i++){
                        for(int j = 0; j<m; j++) ret.g[i][j] = g[i][j] + A.g[i][j];
                }
                return ret;
        }
        Matrix <T> operator - (int z){
                // subtracts constant z from each element of the matrix
                Matrix <T> ret(n, m);
                for(int i = 0; i<n; i++){
                        for(int j = 0; j<m; j++) ret.g[i][j] = this->g[i][j] - z;
                }
                return ret;
        }
        Matrix <T> operator - (const Matrix <T> &A){
                /*
                matrix subtraction
                dims A = (n, m)
                */
                Matrix <T> ret(n, m);
                for(int i = 0; i<n; i++){
                        for(int j = 0; j<m; j++) ret.g[i][j] = g[i][j] - A.g[i][j];
                }
                return ret;
        }
        Matrix <T> operator * (int z){
                // multiplies each element of the matrix with z
                Matrix <T> ret(n, m);
                for(int i = 0; i<n; i++){
                        for(int j = 0; j<m; j++) ret.g[i][j] = this->g[i][j] * z;
                }
                return ret;
        }    
        Matrix <T> Multiply (const Matrix <T> &A, const Matrix <T> &B){
                /*
                matrix multiplication
                columns in A = rows in B
                */
                assert(A.m == B.n);
                Matrix <T> ret(A.n, B.m);
                for(int i = 0; i<A.n; i++){
                        for(int j = 0; j<A.m; j++){
                                for(int k = 0; k<B.m; k++){
                                        ret.g[i][k] = (ret.g[i][k] + (A.g[i][j] * B.g[j][k]) % mod) % mod;
                                }
                        }
                }
                return ret;
        }
        Matrix <T> operator / (int z){
                // integer division of each matrix element by z
                Matrix <T> ret(n, m);
                for(int i = 0; i<n; i++){
                        for(int j = 0; j<m; j++) ret.g[i][j] = this->g[i][j] / z;
                }
                return ret;
        }
        Matrix <T> operator % (const int &md){
                /*
                modulo operation on each of the
                matrix element
                */
                Matrix <T> A = (*this);
                for(int i = 0; i<n; i++){
                        for(int j = 0; j<m; j++) A.g[i][j] = (A.g[i][j] % md);
                }
                return A;
        }
        Matrix <T> MatExp (int b){
                /*
                matrix exponentiation
                only for square matrices.
                */
                Matrix <T> ret = Identity(n), A = *this;
                assert(b >= 0);
                while(b > 0){
                        if(b & 1) ret = Multiply(ret, A);
                        A = Multiply(A, A);
                        b >>= 1;
                }
                return ret;
        }
};
 
void TestCase (){
        // your code here
}

#undef int
 
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
