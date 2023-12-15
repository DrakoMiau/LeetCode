#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> myVector = {1, 2, 3, 4};
    myVector.erase(myVector.begin() + 2);
    for (int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i];
    }
    cout << endl
         << myVector.size();
    return 0;
}