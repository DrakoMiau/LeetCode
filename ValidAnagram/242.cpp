#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// first try
//  bool isAnagram(string s, string t)
//  {
//      string aux;
//      for (int i = s.size() - 1; i >= 0; i--)
//      {
//          for (int j = 0; j < t.size(); j++)
//          {
//              if (t[j] == s[i])
//              {
//                  s.pop_back();
//              }
//          }
//      }

//     if (s.size() == 0)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// second try, it takes a lot of time

// bool isAnagram(string s, string t)
// {
//     if (s.length() != t.length())
//     {
//         return false;
//     }

//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] != t[i])
//         {
//             for (int j = i; j < t.length(); j++)
//             {
//                 if (s[i] == t[j])
//                 {
//                     swap(t[i], t[j]);
//                 }
//             }
//         }
//     }

//     if (s == t)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "gator", t = "toga";
    if (isAnagram(s, t))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}