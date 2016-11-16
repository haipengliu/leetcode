// Source : https://oj.leetcode.com/problems/regular-expression-matching/
// Author : Hao Chen
// Date   : 2014-08-24

/********************************************************************************** 
* 
* Implement regular expression matching with support for '.' and '*'.
* 
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* 
* The matching should cover the entire input string (not partial).
* 
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
* 
* Some examples:
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "a*") → true
* isMatch("aa", ".*") → true
* isMatch("ab", ".*") → true
* isMatch("aab", "c*a*b") → true
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


int isSame(char s, char p);
void print_dp(int ** dp, int m, int n);

void fill_dp(string s, string p, int ** dp)
{
  int i, j;

  for ( i = 0; i <= s.size(); i++ )
  {
    for ( j = 0; j <= p.size(); j++ )
    {
      if ( j == 0 )
      {
        if ( i == 0 )
        {
          dp[i][j] = 1; 
        }
        else
        {
          dp[i][j] = -1;
        }        
      }
      else if (j == 2 && p[j-1] == '*' && p[j-2] == '.')
      {
        dp[i][j] = 1;
      }
      else if ( 2 < j && j <= p.size() && p[j-1] == '*' )
      {
        int k = 0, tag = 0;

        for ( k = 0; k <= i; k++ )
        {
          if ( k >= 2 && !isSame(s[i-k], s[i-k+1]) )
          {
            tag = 0;
            break;
          }
          
          if ( k == 0 && dp[i][j-2] == 1 )
          {
            dp[i][j] = 1;
            tag = 1;
            break;
          }

          if ( k != 0 && isSame(s[i-k], p[j-2]) && dp[i-k][j-2] == 1)
          {
            dp[i][j] = 1;
            tag = 1;
            break;
          }
          
        }

        if ( tag == 0 )
        {
          dp[i][j] = -1;
        }
        
       
      }
      else
      {
        if ( !isSame(s[i-1], p[j-1]) )
        {
          dp[i][j] = -1;
        }
        else 
        {
          if ( 1 <= i && 1 <= j && dp[i - 1][j - 1] == 1 )
          {
            dp[i][j] = 1;
          }
          else
          {
            dp[i][j] = -1;
          }
            
        }
        
      }
            
    }    
  }
   
}

int isSame(char s, char p)
{
  if ( s == p || p == '.' )
  {
    return true;
  }
  else
  {
    return false;
  }
  
}

bool isMatch(string s, string p)
{
  int ** dp = NULL;
  int i;

  dp = new int*[s.size() + 1];

  for ( i = 0; i <= s.size(); i++ )
  {
    dp[i] = new int[p.size() + 1];
    memset(dp[i], sizeof(int)*(p.size()+1), 0);
  }

  dp[0][0] = 1;
  fill_dp(s, p, dp);
  print_dp(dp, s.size(), p.size());
  
  if ( 1 == dp[s.size()][p.size()] )
  {
    return true;
  }
  else if ( -1 == dp[s.size()][p.size()] )
  {
    return false;
  }
}

void print_dp(int ** dp, int m, int n)
{
  int i, j;

  for ( i = 0; i <= m; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      cout<<dp[i][j];
    }
    cout<<endl;
  }
  
}

int main()
{
  string s = "ab";
  string p = ".*";

  //cout<<s<<endl<<p<<endl;

  if ( isMatch(s, p) )
  {
    cout<<"Match"<<endl;
  }
  else
  {cout<<"dont match"<<endl;}

 
  return 0;
  
}
