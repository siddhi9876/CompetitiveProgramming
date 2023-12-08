#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int MOD = 1e9 + 7;

struct Matrix
{
    vector <vector<int>> mat;
    int n_rows, m_cols;
    Matrix(vector<vector<int>> values) : mat(values), n_rows(values.size()), m_cols(values[0].size()) {}

    static Matrix identity_matrix(int m)
    {
        vector < vector <int>> values(m, vector<int>(m,0));

        for(int i =0; i <m;i++) values[i][i] = 1;

        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        int n = n_rows, m = other.m_cols;

        vector< vector <int >> result(n, vector <int> (m,0));

        for(int i =0; i<n ;i++)
        {
            for(int j =0; j<m; j++)
            {
                for(int k = 0; k < m_cols; k++)
                {
                    result[i][j] = (result[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }

        return Matrix(result);
    }

    int get(int i, int j)
    {
        return mat[i][j];
    }
};

Matrix fast_exponentiation(Matrix m, int power)
{
    Matrix result = Matrix::identity_matrix(m.n_rows);

    while(power)
    {
        if(power & 1)
        {
            result = result * m;
        }

        m = m * m;
        power >>= 1;
    }

    return result;
}

int main()
{
    vector<vector<int>> m(2, vector<int>(2,0));
    vector<vector<int>> F_initial(1, vector<int>(2,0));

    F_initial[0][0] = 1;
    F_initial[0][1] = 1;

    m[0][0] = m[0][1] = m[1][0] = 1;

    for(int i = 0; i <=5; i++)
    {
        Matrix result_temp= fast_exponentiation(m, i);
        Matrix result = Matrix(F_initial) * result_temp;
        cout << result.n_rows <<"  "<< result.m_cols <<"  "<<result.get(0,0)<<" "<<result.get(0,1)<<endl;
    }

    
}
