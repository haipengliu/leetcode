/* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution. */

/*   For example, given array S = {-1 2 1 -4}, and target = 1. */

/*   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2). */
/*   Hide Tags Array Two Pointers */

#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
  int i;
  int N = nums.size();
  int rst = target >= 0 ? INT_MAX : INT_MIN;
  int sum = 0;
  int left, right;
  
  sort(nums.begin(), nums.end());

  for ( i = 0; i < N; i++ )
  {

    if ( nums[i] == nums[i - 1] && i > 0 )
    {
      continue;
    }
    
    left  = i + 1;
    right = N - 1;
        
    while ( left < right )
    {
      sum = nums[i] + nums[left] + nums[right];

      if ( abs(sum - target) <= abs(rst - target) )
      {
        rst = sum;
        
        if ( sum == target )
        {
          return rst;
        }
              
      }

      if ( sum < target )
      {
        while ( nums[left] == nums[left + 1] && left  <= N - 2 )
        {
          left++;
        }
          
        left++;
      }
      else if ( sum > target )
      {
        while ( nums[right] == nums[right - 1] && right >= 1 )
        {
          right--;
        }
          
        right--;
      }
      
    }

        
  }
  
  return rst;
  
}

int main()
{
  //int S[] = {-1, 2, 1, -4};
  //int S[] = {1, 1, -1, -1, 3};
  //int S[] = {0, 1, 2};
  int S[] = {1, 2, 4, 8, 16, 32, 64, 128};
  
  vector<int> nums(S, S + sizeof(S)/sizeof(int));
  int target = 82;
  
  cout << threeSumClosest(nums, target) << endl;

  return 0;
}
