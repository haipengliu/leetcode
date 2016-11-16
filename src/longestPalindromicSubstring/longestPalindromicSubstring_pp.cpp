// Source : https://oj.leetcode.com/problems/longest-palindromic-substring/
// Author : Hao Chen
// Date   : 2014-07-17

/********************************************************************************** 
* 
* Given a string S, find the longest palindromic substring in S. 
* You may assume that the maximum length of S is 1000, 
* and there exists one unique longest palindromic substring.
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int isPalindrome(string s, int i, int j)
{
  int cnt = 0;
  
  while ( j <= i )
  {
    if ( s[i] == s[j] )
    {
      if ( i != j )
      {
        i--;
        j++;
        cnt += 2;
      }
      else
      {
        i--;
        j++;
        cnt++;
      }
      
    }
    else
    {
      cnt = 0;
      break;      
    }
  }

  return cnt;  
}


string longestPalindrome(string s) {

  int i, j;
  string rst;

  int len = 0;
  int maxlen = 0;
  
  if ( 0 == s.size() )
  {
    return rst;
  }

  for ( i = 0; i < s.size(); i++ )
  {
    for ( j = 0; j <= i; j++ )
    {
      len = isPalindrome(s, i, j);

      if ( len > maxlen )
      {
        maxlen = len;
        rst = s.substr(j, i - j + 1);
      }
    }
    
  }

  cout << "maxlen : " << maxlen << endl; 
  return rst;
}

string longestPalindrome_dp(string s) {

  int i, j;
  string rst;
  
  int len = 0;
  int maxlen = 0;
  int n = s.size();
  
  //Construct a matrix, and consdier matrix[i][j] as s[i] -> s[j] is Palindrome or not.
  vector< vector<int> > dp (n, vector<int>(n));
  
  if ( 0 == s.size() )
  {
    return rst;
  }
  
  // if i == j, matrix[j][i] == true;
  // if s[i] == s[j] && i - j > 2  && matrix[j+1][i-1], matrix[j][i] = true;
  // if s[i] == s[j] && i - j <= 2
  for ( i = 0; i < s.size(); i++ )
  {
    for ( j = 0; j <= i; j++ )
    {
      if ( i == j )
      {
        dp[j][i] = 1;
        
        if ( rst.size() < i - j + 1 )
        {
          rst = s.substr(j, i - j + 1);
        }
      }
      //else if ( s[j] == s[i] && ((i - j > 2 && dp[j+1][i-1]) || i - j <= 2) )
      else if ( s[j] == s[i] && i - j > 2 && dp[j+1][i-1] )
      {
        dp[j][i] = 1;

        if ( rst.size() < i - j + 1 )
        {
          rst = s.substr(j, i - j + 1);
        }
      }
      else if (  s[j] == s[i] && i - j <= 2 )
      {
        dp[j][i] = 1;

        if ( rst.size() < i - j + 1 )
        {
          rst = s.substr(j, i - j + 1);
        }
      }
      else
      {
        dp[j][i] = 0;
      }
            
    }// for j
    
  }// for i

  cout << "maxlen : " << rst.size()  << endl; 
  return rst;
}

string findPalindrome(string s, int start, int end)
{
  while ( 0 <= start && end <= s.size() - 1 && s[start] == s[end] )
  {
    start--;
    end++;
  }

  return s.substr(start + 1, end - start - 1);  
}


string longestPalindrome_two_pointers(string s)
{
  string rst;
  string str;
  int i;

  if ( s.size() <= 1 )
  {
    return rst;
  }

  for ( i = 0; i < s.size(); i++ )
  {
    str = findPalindrome(s, i, i);
    if ( str.size() > rst.size() )
    {
      rst = str;
    }

    str = findPalindrome(s, i, i+1);
    if ( str.size() > rst.size() )
    {
      rst = str;
    }
  }

  cout << " max length using two pointers : " << rst.size() << endl;
  
  return rst;
}


int main()
{
  string s = "abacdfgdcabac";
  //string s = "cabac";
  
  //cout << s << " : " << longestPalindrome(s) <<endl;

  //cout << s << " : " << longestPalindrome_dp(s) <<endl;

  cout << s << " : " << longestPalindrome_two_pointers(s) << endl;
  return 0;
}

