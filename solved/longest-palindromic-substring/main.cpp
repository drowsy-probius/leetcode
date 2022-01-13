#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    if(s.size() < 2) return s;

    string result = "";
    for(int i=0; i<s.size(); i++)
    {
      if(s.size() - i < result.size()/2) break;
      int left = i, right = i;

      while(right + 1 < s.size() && s.at(right+1) == s.at(right)) right++;
      // count for duplicate charaters
      // and skip
      i = right;

      while(left - 1 >= 0 && right + 1 < s.size() && s.at(left-1) == s.at(right+1))
      {
        right++; 
        left--;
      }

      if(result.size() < right - left + 1) result = s.substr(left, right-left+1);
    }
    return result;
  }
};

// int main(int argc, char* argv[])
int main(int argc, char* argv[])
{
  setbuf(stdout, NULL);
  freopen("input.txt", "r", stdin);
  
  int TC;
  char input[1001];
  Solution solution;
  scanf("%d", &TC);
  while(TC--)
  {
    scanf("%s", input);
    cout << solution.longestPalindrome(input) << "\n";
  }

  return 0;
}


