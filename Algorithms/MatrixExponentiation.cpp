#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const ll MOD = 1e9 + 7;

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
                }
            }
        }

        return Matrix(result);
    }

    static Matrix fast_exponentiation(Matrix m, int power) {
        Matrix result  =
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
    int t;
    Matrix M({ 
            {4, 0, 0}, 
            {2, 3, 0}, 
            {0, 1, 2} });

    Matrix initial({ {0, 1, 2} });

    cout << (initial * fast_exponentiation(n - 1)).mat[0][0] << "\n";
}