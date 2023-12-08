#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const ll MOD = 1e9 + 7;
inline ll idx(char x) {
    if (x >= 'a' && x <= 'z') return x - 'a';
    return x - 'A' + 26;
}

struct Matrix {
    vector<vector<ll>> mat;
    int n_rows, n_cols;

    Matrix(vector<vector<ll>>values): mat(values), n_rows(values.size()), n_cols(values[0].size())
    {}

    static Matrix identity_matrix(int n) {
        vector<vector<ll>> values(n, vector<ll>(n,0));

        for(int i = 0; i< n;i++) values[i][i] = 1;

        return values;
    }

    Matrix operator*(const Matrix& other) const {
        int n = n_rows, m = other.n_cols;

        vector<vector<ll>> result(n_rows, vector<ll>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j<m ; j++) {
                for(int k = 0; k < n_cols; k++) {
                    result[i][j] += (mat[i][k] * other.mat[k][j]) % MOD;
                    result[i][j] = result[i][j] % MOD;
                }
            }
        }

        return Matrix(result);
    }

};

Matrix fast_exponentiation(Matrix m, ll power) {
    Matrix result  = Matrix::identity_matrix(m.n_rows);

    while(power) {
        if(power & 1) result = result * m;

        m = m * m;
        power >>= 1;
    }

    return result;
}

int main()
{
    ll n, m, k;

    cin >> n >> m >> k;

    Matrix multiplier = Matrix::identity_matrix(m);

    for(int i = 0; i < m; i++) {
        for (int j =0; j < m; j++) multiplier.mat[i][j] = 1;
    }

    while(k--) {
        string s;
        cin >> s;
        multiplier.mat[idx(s[0])][idx(s[1])] = 0;
    }

    Matrix res = fast_exponentiation(multiplier, n-1);

    ll ans = 0;

    for(int i = 0; i<m;i++) {
        for (int j =0; j< m; j++) ans = (ans + res.mat[i][j]) % MOD;
    }

    cout <<ans <<endl;
}