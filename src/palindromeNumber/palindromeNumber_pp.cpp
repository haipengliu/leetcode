/********************************************************************************** 
* 
* Determine whether an integer is a palindrome. Do this without extra space.
* 
* 
* Some hints:
* 
* Could negative integers be palindromes? (ie, -1)
* 
* If you are thinking of converting the integer to string, note the restriction of using extra space.
* 
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
* you know that the reversed integer might overflow. How would you handle such case?
* 
* There is a more generic way of solving this problem.
* 
*               
**********************************************************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

bool isPalindrome(int x)
{
  if ( x < 0 )
  {
    return false;
  }
    
  int len = (x >= 0 ? 1 : -1);
  int left = 0, right = 0;
  int xl, xr;
  
  while ( x/len >= 10 )
  {
    len *= 10;
  }

  xl = xr = x;

  while ( xl != 0 && xr != 0)
  {
    left = xl / len;
    xl %= len;
    len /= 10;

    right = xr % 10;
    xr /= 10;

    if ( abs(left) != abs(right) )
    {
      return false;
    }
    
  }
  
  return true;
}


int main()
{
  int x = -2147483648;
  if ( true == isPalindrome(x) )
  {
    cout<< x <<" is a palindrom." << endl;
  }
  else
  {
    cout << x << " is not a palindrom. " <<endl;
  }
  
  return 0;
}
