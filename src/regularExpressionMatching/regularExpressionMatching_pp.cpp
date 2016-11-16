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

bool dfs(string s, string p, int startS, int startP);
bool isSame(char s, char p);

bool dfs(string s, string p, int startS, int startP)
{
  if ( startP >= p.size() )
  {
    if ( startS >= s.size() )
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  if ( startP < p.size() - 1 && p[startP + 1] == '*' )
  {
    int i = 0;
    
    if ( dfs(s, p, startS, startP + 2) )
    {
      return true;
    }

    for ( i = 0; i < s.size(); i++ )
    {
      if ( !isSame(s[startS + i], p[startP]) )
      {
        return false;
      }
      else if ( dfs(s, p, startS + i + 1, startP + 2) )
      {
        return true;
      }
            
    }
        
  }
  else
  {
    if( startS >= s.size())
    {
      return false;
    }

    if ( !isSame(s[startS], p[startP]) )
    {
      return false;
    }

    if( dfs(s, p, startS + 1, startP + 1) )
    {
      return true;
    }
    
    return false;
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
  if ( s.size() == 0 || p.size() == 0 )
  {
    return false;
  }

  return dfs(s, p, 0, 0);
}


int main()
{
  string s = "aa";
  string p = "a";

  cout<<s<<endl<<p<<endl;

  if ( isMatch(s, p) )
  {
    cout<<"Match"<<endl;
  }
  else
    {cout<<"dont match"<<endl;}
  
  return 0;
  
}
