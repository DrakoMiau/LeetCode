#include <iostream>
#include <vector>
using namespace std;

// first attempt

// int numSpecial(vector<vector<int>> &mat)
// {
//     int specialP = 0;
//     vector<int> v1(mat.size()), v2(mat[0].size());

//     for (int i = 0; i < mat.size(); i++)
//     {
//         for (int j = 0; j < mat[0].size(); j++)
//         {
//             if (mat[i][j] == 1)
//             {
//                 v2[j]++;
//                 v1[i]++;
//             }
//         }
//     }

//     for (int i = 0; i < v1.size(); i++)
//     {
//         for (int j = 0; j < v2.size(); j++)
//         {
//             if (v1[i] == 1 && v2[j] == 1)
//             {
//                 specialP++;
//             }
//         }
//     }
//     return specialP;
// }

int numSpecial(vector<vector<int>> &mat)
{
    vector<int> candidates(mat.size());
    int nOnes = 0, pOneOnRow, nOnesCol = 0, specialPositions = 0;

    for (int i = 0; i < candidates.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                nOnes++;
                pOneOnRow = j;
            }
        }
        if (nOnes == 1)
        {
            candidates[i] = pOneOnRow;
        }
        else
        {
            candidates[i] = -1;
        }

        nOnes = 0;
    }

    for (int i = 0; i < candidates.size(); i++)
    {
        if (candidates[i] != -1)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                if (mat[j][candidates[i]] == 1)
                {
                    nOnesCol++;
                }
            }
            if (nOnesCol == 1)
            {
                specialPositions++;
            }
            nOnesCol = 0;
        }
    }
    return specialPositions;
}

int main()
{
    vector<vector<int>> arepuela = {{0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}};
    cout << numSpecial(arepuela) << endl;
    return 0;
}