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


bool isSame(char s, char p);
void print_dp(bool ** dp, int m, int n);

void fill_dp(string s, string p, bool ** dp)
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
          dp[i][j] = true; 
        }
        else
        {
          dp[i][j] = false;
        }        
      }
      else if ( 2 <= j && j <= p.size() && p[j-1] == '*' )
      {
        int k = 0, tag = 0;

        for ( k = 0; k <= i; k++ )
        {
          if ( k == 0 && dp[i][j-2] )
          {
            dp[i][j] = true;
            tag = 1;
            break;
          }

          if ( k != 0 && isSame(s[i-k], p[j-2]) && dp[i-k][j-2])
          {
            dp[i][j] = true;
            tag = 1;
            break;
          }
          
        }

        if ( tag == 0 )
        {
          dp[i][j] = false;
        }
        
       
      }
      else
      {
        if ( !isSame(s[i-1], p[j-1]) )
        {
          dp[i][j] = false;
        }
        else 
        {
          if (dp[i - 1][j - 1] && 1 <= i && 1 <= j)
          {
            dp[i][j] = true;
          }
          else
          {
            dp[i][j] = false;
          }
            
        }
        
      }
            
    }    
  }
   
}

bool isSame(char s, char p)
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
  bool ** dp = NULL;
  int i;

  dp = new bool*[s.size() + 1];

  for ( i = 0; i <= s.size(); i++ )
  {
    dp[i] = new bool[p.size() + 1];
  }

  dp[0][0] = true;
  fill_dp(s, p, dp);
  print_dp(dp, s.size(), p.size());
  
  if ( dp[s.size(), p.size()] )
  {
    return true;
  }
  else
  {
    return false;
  }
}

void print_dp(bool ** dp, int m, int n)
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
  string s = "aa";
  string p = "a";

  //cout<<s<<endl<<p<<endl;

  if ( true == isMatch(s, p) )
  {
    cout<<"Match"<<endl;
  }
  else
  {cout<<"dont match"<<endl;}

 
  return 0;
  
}
