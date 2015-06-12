/* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target. */

/*   Note: */
/*   Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie,    d) */
/*   The solution set must not contain duplicate quadruplets. */
/*   For example, given array S = {1 0 -1 0 -2 2}, and target = 0. */

/*   A solution set is: */
/*   (-1,  0, 0, 1) */
/*   (-2, -1, 1, 2) */
/*   (-2,  0, 0, 2) */
/*   Hide Tags Array Hash Table Two Pointers */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector< vector<int> > threeSum(vector<int> &nums, int target);

vector< vector<int> > fourSum(vector<int>& nums, int target)
{
  vector< vector<int> > rst;
  vector< vector<int> > rst_tmp;
  int i, j;
  int N = nums.size();
  
  if ( N <= 0 )
  {
    return rst;
  }

  sort(nums.begin(), nums.end());
  
  for ( i = 0; i < N; i++ )
  {
    if ( nums[i] == nums[i - 1] && i > 0)
    {
      continue;
    }
        
    vector<int> nums_tmp(nums.begin() + i + 1, nums.end());
    
    rst_tmp = threeSum(nums_tmp, target - nums[i]);
    
    for ( j = 0; j < rst_tmp.size(); j++ )
    {
      rst_tmp[j].insert(rst_tmp[j].begin(), nums[i]);
      rst.push_back(rst_tmp[j]);
    }
  }
  
  return rst;
}

vector< vector<int> > threeSum(vector<int> &nums, int target)
{
  vector< vector<int> > rst;
  int N = nums.size();
  int middle, end, i;
  int sum;
  
  if ( N == 0 )
  {
    return rst;
  }

  for ( i = 0; i < N; i++ )
  {
    if ( nums[i] == nums[i - 1] && i > 0 )
    {
      continue;
    }

    middle = i + 1;
    end    = N - 1;

    while ( middle < end )
    {
      sum = nums[i] + nums[middle] + nums[end];
      
      if ( sum == target )
      {
        vector<int> tmp;
        tmp.push_back(nums[i]);
        tmp.push_back(nums[middle]);
        tmp.push_back(nums[end]);
        rst.push_back(tmp);

        while ( nums[middle] == nums[middle + 1] && middle < N - 1 )
        {
          middle++;
        }

        middle++;

        while ( nums[end] == nums[end - 1] && end > 0 )
        {
          end--;
        }

        end--;
      }
      else if ( sum > target )
      {
        while ( nums[end] == nums[end - 1] && end > 0 )
        {
          end--;
        }

        end--;
      }
      else if ( sum < target )
      {
        while ( nums[middle] == nums[middle + 1] && middle < N - 1 )
        {
          middle++;
        }
        
        middle++;
      }
    }
  }
  
  return rst;
}

void print_matrix(vector< vector<int> > nums)
{
  int N = nums.size();
  int i,j;

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < nums[i].size(); j++ )
    {
      cout<< nums[i][j] << " ";
    }

    cout<<endl;
  }
   
}

int main()
{
  int S[] = {1, 0, -1, 0, -2, 2};
  int target = 0;
  vector< vector<int> > rst;
  vector<int> nums(S, S + sizeof(S) / sizeof(int));
  
  rst = fourSum(nums, target);

  print_matrix(rst);

  return 0;
}
