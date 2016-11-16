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

bool dfs(string s, string p, int startS, int startP, int **m);
bool isSame(char s, char p);

bool dfs(string s, string p, int startS, int startP, int **m)
{
  
  if ( startP >= p.size() )
  {
    if ( startS >= s.size() )
    {
      m[startS][startP] = 1;
      return true;
    }
    else
    {
      m[startS][startP] = 0;
      return false;
    }
  }

  if ( m[startS][startP] == 1 )
  {
    return true;
  }
  else if ( m[startS][startP] == 0 )
  {
    return false;   
  }


  if ( startP < p.size() - 1 && p[startP + 1] == '*' )
  {
    int i = 0;
    
    if ( dfs(s, p, startS, startP + 2, m) )
    {
      m[startS][startP] = 1;
      return true;
    }

    for ( i = 0; i < s.size() - startS; i++ )
    {
      if ( !isSame(s[startS + i], p[startP]) )
      {
        m[startS][startP] = 0;
        return false;
      }
      else if ( dfs(s, p, startS + i + 1, startP + 2, m) )
      {
        m[startS][startP] = 1;
        return true;
      }
            
    }
        
  }
  else
  {
    if( startS >= s.size())
    {
      m[startS][startP] = 0;
      return false;
    }

    if ( !isSame(s[startS], p[startP]) )
    {
      m[startS][startP] = 0;
      return false;
    }

    if( startS <= s.size() - 1 && dfs(s, p, startS + 1, startP + 1, m) )
    {
      m[startS][startP] = 1;
      return true;
    }

    m[startS][startP] = 0;
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
  int** m = NULL;
  int i, j;
  
  m = new int*[s.size() + 1];
  
  for ( i = 0; i <= s.size(); i++ )
  {
    m[i] = new int[p.size() + 1];    
  }
  
  for ( i = 0; i <= s.size(); i++ )
  {
    for ( j = 0; j <= p.size(); j++ )
    {
      m[i][j] = -1;
    }
    
  }

  return dfs(s, p, 0, 0, m);
}


int main()
{
  string s = "b";
  string p = "b.*c";

  //cout<<s<<endl<<p<<endl;

  if ( isMatch(s, p) )
  {
    cout<<"Match"<<endl;
  }
  else
    {cout<<"dont match"<<endl;}
  
  return 0;
  
}
