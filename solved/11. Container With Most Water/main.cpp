#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int result = 0;

    int begin, end;
    begin = 0; end = height.size();
    while(begin < end)
    {
      result = max(result, (end - begin - 1)*min(height.at(begin), height.at(end-1)));

      if(height.at(begin) < height.at(end-1)) begin++;
      else end--;
    }    

    return result;
  }
};

int main(int argc, char *argv[])
{
  setbuf(stdout, NULL);
  freopen("input.txt", "r", stdin);

  int TC;
  vector<int> height;
  int n, t;
  Solution solution;
  scanf("%d", &TC);
  while (TC--)
  {
    scanf("%d", &n);
    while(n--)
    {
      scanf("%d", &t);
      height.push_back(t);
    }
    cout << solution.maxArea(height);
  }

  return 0;
}