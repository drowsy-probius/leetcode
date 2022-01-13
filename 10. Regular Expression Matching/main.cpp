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
public:
  bool isMatch(string s, string p)
  {
    int si, pi;
    int sEND, pEND;
    si = 0; pi = 0;    
    sEND = s.size(); pEND = p.size();

    while(si < sEND && pi < pEND)
    {
      if(pi+1 < pEND && p.at(pi+1) == '*')
      {
        while(si < sEND && (p.at(pi) == '.' || s.at(si) == p.at(pi)))
        {
          if(isMatch(s.substr(si++, sEND), p.substr(pi+2, pEND))) 
            return true;
        }
        pi += 2;
      }
      else if(p.at(pi) == '.' || s.at(si) == p.at(pi))
      {
        si++;
        pi++;
      }
      else break;
    }

    while(pi+1 < pEND && p.at(pi+1) == '*') pi += 2;

    return (si == sEND && pi == pEND);
  }
};

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