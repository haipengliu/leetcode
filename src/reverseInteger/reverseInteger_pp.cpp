/* Reverse digits of an integer. */

/* Example1: x = 123, return 321 */
/*   Example2: x = -123, return -321 */

#include <iostream>
#include <climits>

using namespace std;

int reverse(int x) {
  
  int rst = 0;
  int max = INT_MAX;
  int min = INT_MIN;
  int residue = 0;
  int upbound = 0;
  int lowbound = 0;
  
  while ( 0 != x )
    {
      residue = x%10;
      upbound = (max - residue)/10 - rst;
      
            
      if ( (max - residue)/10 < rst && residue > 0)
        {
          return 0;
        }

      if ( (min - residue)/10 > rst && residue < 0)
      {
        return 0;
      }
      
      rst = rst * 10 + residue;
      x /= 10;      
    }
  
  
  return rst;
}

int main()
{
  int x = 1;
  
  cout << reverse(x) << endl;
  
  return 0;
}
