#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

/**
 * TODO:
 * dp로 풀기
 */

using namespace std;

class Solution
{
private:
  vector<vector<bool>> matches;
  int sEND, pEND;

public:
  bool isMatch(string s, string p)
  {
    sEND = s.size() + 1; 
    pEND = p.size() + 1;
    matches = vector<vector<bool>>(sEND, vector<bool>(pEND, false));
    matches[0][0] = true;

    for(int pi=2; pi<pEND; pi++)
      if(p.at(pi - 1) == '*') matches[0][pi] = matches[0][pi-2];
    
    for(int si=1; si<sEND; si++)
    {
      for(int pi=1; pi<pEND; pi++)
      {
        char sc = s.at(si-1);
        char pc = p.at(pi-1);

        if(sc == pc || pc == '.')
          matches[si][pi] = matches[si-1][pi-1];
        else if(pc == '*')
        {
          matches[si][pi] = matches[si][pi-2];

          if(sc == p.at(pi-2) || p.at(pi-2) == '.')
            matches[si][pi] = matches[si][pi] || matches[si-1][pi];
        }
      }
    }

    return matches[s.size()][p.size()];
  }
};

// class Solution
// {
// public:
//   bool isMatch(string s, string p)
//   {
//     int si, pi;
//     int sEND, pEND;
//     si = 0; pi = 0;    
//     sEND = s.size(); pEND = p.size();

//     while(si < sEND && pi < pEND)
//     {
//       if(pi+1 < pEND && p.at(pi+1) == '*')
//       {
//         while(si < sEND && (p.at(pi) == '.' || s.at(si) == p.at(pi)))
//         {
//           if(isMatch(s.substr(si++, sEND), p.substr(pi+2, pEND))) 
//             return true;
//         }
//         pi += 2;
//       }
//       else if(p.at(pi) == '.' || s.at(si) == p.at(pi))
//       {
//         si++;
//         pi++;
//       }
//       else break;
//     }

//     while(pi+1 < pEND && p.at(pi+1) == '*') pi += 2;

//     return (si == sEND && pi == pEND);
//   }
// };

int main(int argc, char *argv[])
{
  setbuf(stdout, NULL);
  freopen("input.txt", "r", stdin);

  string s, p;
  int TC;
  Solution solution;
  scanf("%d", &TC);
  while (TC--)
  {
    cin >> s >> p;
    cout << (solution.isMatch(s, p) ? "true" : "false") << "\n";
  }

  return 0;
}