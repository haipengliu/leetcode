/* Implement strStr(). */

/* Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. */

#include <string>
#include <iostream>

using namespace std;

int strStr(string haystack, string needle)
{
  int i, j;
  int start, end;
  int m = haystack.size() - 1;
  int n = needle.size() - 1;
  int win = 0;
  
  if ( needle.size() == 0 )
  {
    return 0;
  }

  for (i = j = 0; i <= m && j <= n; i++, j++);

  if ( i > m && j <= n )
  {
    return -1;
  }

  for( start = 0, end = i - 1; end <= m; start++, end++ )
  {
    i = start;
    j = 0;
    win = 0;
    
    while ( i <= end && j <= n )
    {      
      if ( haystack[i] == needle[j] )
      {
        i++;
        j++;
      }
      else
      {
        break;
      }

      if ( 0 == win && needle[j] == haystack[start] )
      {
        win = i - start;
      }
    }
    
    if ( i > end && j > n )
    {
      return start;
    }

    start += win > 0? win - 1: win;
    end += win > 0 ? win - 1 : win;
  }

  return -1;
}

int main()
{
  //  string haystack("cdabcabc");
  //  string needle("abcabc");

  //  string haystack("mississippi");
  //  string needle("a");

  string haystack("baaa");
  string needle("abbb");

  
  cout<< strStr(haystack, needle) << endl;

  return 0;
}
