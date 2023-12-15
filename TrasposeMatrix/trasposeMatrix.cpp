#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    int rows, cols;
    rows = matrix.size();
    cols = matrix[0].size();
    vector<vector<int>> matrixT(cols, vector<int>(rows)); // crear para vector de tamanio nxm
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrixT[i][j] = matrix[j][i];
        }
    }
    return matrixT;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<vector<int>> arepa = transpose(matrix);
    // arepa.push_back({10,20});
    // arepa.push_back({20,10});
    for (size_t i = 0; i < arepa.size(); i++)
    {
        for (size_t j = 0; j < arepa[0].size(); j++)
        {
            cout << arepa[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
