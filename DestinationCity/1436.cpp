#include <iostream>
#include <vector>
using namespace std;

string destCity(vector<vector<string>> &paths)
{
    string dest;
    bool existPath = false;
    int aux;
    if (paths.size() != 1)
    {
        for (int i = 0; i < paths.size(); i++)
        {
            for (int j = 0; j < paths.size(); j++)
            {
                if (paths[i][1] == paths[j][0])
                {
                    existPath = true;
                    break;
                }
            }

            if (existPath == true)
            {
                existPath = false;
                continue;
            }
            else
            {
                return paths[i][1];
            }
        }
    }
    else
    {
        return paths[0][1];
    }
    return paths[1][1];
}

int main()
{
    vector<vector<string>> paths = {{"B", "C"}, {"D", "B"}, {"C", "A"}};
    cout << destCity(paths) << endl;
    return 0;
}