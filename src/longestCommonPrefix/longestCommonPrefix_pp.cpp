/* Write a function to find the longest common prefix string amongst an array of strings. */

/* Hide Tags String */

#include <vector>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
  int i, j;
  string rst;
  int N = strs.size();
  int tag = 0;
  int end = 0;

  if ( N == 0 )
  {
    return rst;
  }

  if ( N == 1 )
  {
    return strs[0];
  }
  
  for ( j = 0; end == 0; j++ )
  {
    tag = 0;
    
    for ( i = 0; i < N; i++ )
    {
      if ( strs[i][j] == '\0' || strs[0][j] == '\0' )
      {
        end = 1;
      }
      
      if ( strs[0][j] != strs[i][j] )
      {
        tag = 1;
        break;
      }
    }

    if ( tag == 1 || end == 1)
    {
      break;
    }

    else
    {
      rst.push_back(strs[0][j]);
    }
          
  }
    
  return rst;  
    
}

int main()
{
  vector<string> strs;

  strs.push_back("abcde");
  strs.push_back("abc");
  strs.push_back("abcd");
  strs.push_back("abd");

  cout<< longestCommonPrefix(strs) <<endl;
    
}
