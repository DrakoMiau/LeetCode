#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
{
    vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size()));
    vector<int> nOnesRow(grid.size()), nZerosRow(grid.size()), nOnesCol(grid[0].size()), nZerosCol(grid[0].size());
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                nOnesRow[i]++;
            }
            else
            {
                nZerosRow[i]++;
            }
        }
    }

    for (int i = 0; i < grid[0].size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[j][i] == 1)
            {
                nOnesCol[i]++;
            }
            else
            {
                nZerosCol[i]++;
            }
        }
    }

    for (int i = 0; i < grid.size(); i++)
    {

        for (int j = 0; j < grid[0].size(); j++)
        {
            diff[i][j] = nOnesRow[i] + nOnesCol[j] - nZerosRow[i] - nZerosCol[j];
        }
    }

    return diff;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
    vector<vector<int>> diff = onesMinusZeros(grid);

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << diff[i][j];
        }
        cout << endl;
    }

    return 0;
}