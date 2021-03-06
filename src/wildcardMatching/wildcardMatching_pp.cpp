/********************************************************************************** 
* 
* Implement wildcard pattern matching with support for '?' and '*'.
* 
* '?' Matches any single character.
* '*' Matches any sequence of characters (including the empty sequence).
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
* isMatch("aa", "*") → true
* isMatch("aa", "a*") → true
* isMatch("ab", "?*") → true
* isMatch("aab", "c*a*b") → false
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

bool isSame(char s, char p);
bool dfs(string s, string p, int i, int j);
  
bool isMatch(string s, string p)
{
  
  return dfs(s, p, 0, 0);
}

bool dfs(string s, string p, int i, int j)
{
  if ( j >= p.size() )
  {
    if ( i >= s.size() )
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if ( p[j] == '*' && j <= p.size() - 1 )
  {
    int k;

    for ( k = 0; k <= s.size() - i; k++ )
    {
      if ( true == dfs(s, p, i + k, j + 1) )
      {
        return true;
      }
    }

    return false;
  }
  else
  {
    if ( i >= s.size() )
    {
      return false;
    }

    if ( !isSame(s[i], p[j]) )
    {
      return false;
    }

    if ( dfs(s, p, i + 1, j + 1) )
    {
      return true;
    }
    
  }
  
}

bool isSame(char s, char p)
{
  if ( s == p || p == '?' )
  {
    return true;
  }

  return false;
}

bool dp(string s, string p)
{
  int ** m;
  int i, j, k;

  m = new int*[s.size() + 1];
  for ( i = 0; i <= s.size(); i++ )
  {
    m[i] = new int[p.size() + 1];
    memset(m[i], sizeof(int) * (p.size() + 1), 0);
  }

  m[0][0] = 1; // 1 is true

  for ( j = 1; j <= p.size(); j++ )
  {
    if ( p[j] == '*' && m[0][j - 1] )
    {
      m[0][j] = 1;
    }

  }
  

    
  for ( i = 1; i <= s.size(); i++ )
  {
    for ( j = 1; j <= p.size(); j++ )
    {
      if ( p[j] == '*' )
      {
        for ( k = 0; k <= i; k++ )
        {
          if ( m[k][j - 1] )
          {
            m[i][j] = 1;
          }
        }
        
        //dp[i][j] = 0;       
      }
      else
      {
        if ( isSame(s[i], s[j]) && m[i - 1][j - 1])
        {
          m[i][j] = 1;
        }
      }
           
    }
    
  }
  
  if( m[s.size() - 1][p.size() - 1] )
    {return true;}
  else
    {return false;}
}

// For detailed explanation, see http://discuss.leetcode.com/questions/222/wildcard-matching

// Time: O(|s||p|*log|s|), Space: O(|s|)
// Time can also optimize to O(|s||p|)

// public class Solution {

// public boolean isMatch(String s, String p) {
//     // without this optimization, it will fail for large data set
//     int plenNoStar = 0;
//     for (char c : p.toCharArray())
//         if (c != '*') plenNoStar++;
//     if (plenNoStar > s.length()) return false;

//     s = " " + s;
//     p = " " + p;
//     int slen = s.length();
//     int plen = p.length();

//     boolean[] dp = new boolean[slen];
//     TreeSet<Integer> firstTrueSet = new TreeSet<Integer>();
//     firstTrueSet.add(0);
//     dp[0] = true;

//     boolean allStar = true;
//     for (int pi = 1; pi < plen; pi++) {
//         if (p.charAt(pi) != '*')
//             allStar = false;
//         for (int si = slen - 1; si >= 0; si--) {
//             if (si == 0) {
//                 dp[si] = allStar ? true : false;
//             } else if (p.charAt(pi) != '*') {
//                 if (s.charAt(si) == p.charAt(pi) || p.charAt(pi) == '?') dp[si] = dp[si-1];
//                 else dp[si] = false;
//             } else {
//                 int firstTruePos = firstTrueSet.isEmpty() ? Integer.MAX_VALUE : firstTrueSet.first();
//                 if (si >= firstTruePos) dp[si] = true;
//                 else dp[si] = false;
//             }
//             if (dp[si]) firstTrueSet.add(si);
//             else firstTrueSet.remove(si);
//         }
//     }
//     return dp[slen - 1];
// }
// };

bool isMatch_nonrecur(string s, string p)
{
  int is, ip;
  int m = s.size();
  int n = p.size();
  int ss = 0;
  int star_pos = 0;
  int star_tag = 0;

  is = ip = 0;
  while ( is < m )
  {
    if ( s[is] == p[ip] || p[ip] == '?')
    {
      is++;
      ip++;
    }
    else if ( p[ip] == '*' )
    {
      star_tag = 1;
      star_pos = ip;
      ss = is;
      ip++;
    }
    else if ( star_tag == 1 )
    {
      is = ss++;
      ip = star_pos + 1;
    }
    else
    {
      return false;
    }
  }

  while ( p[ip] == '*' )
  {
    ip++;
  }

  if ( ip >= n )
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

 /* isMatch("aa","a") → false */
 /* isMatch("aa","aa") → true */
 /* isMatch("aaa","aa") → false */
 /* isMatch("aa", "*") → true */
 /* isMatch("aa", "a*") → true */
 /* isMatch("ab", "?*") → true */
 /* isMatch("aab", "c*a*b") → false */

  //cout<< isMatch("ab", "?*")<<endl;
  //cout << isMatch_nonrecur("acdbcd", "a*b*d") << endl;
  cout << isMatch_nonrecur("hi", "*?") << endl;
  //cout << isMatch_nonrecur("aab", "c*a*b") << endl;
  //cout<< dp("aab", "c*a*b") <<endl;
  
  bool a = false;
  cout<< a << endl;
  
  return 0;
  
}
