#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> &nums, int target, int start, int end);
void dfs(vector<int> &nums, int left, int right, vector< vector<int> > &rst);
vector< vector<int> > threeSum(vector<int> &nums);

vector< vector<int> > threeSum(vector<int> &nums)
{
  vector< vector<int> > rst;
  
  int N = nums.size();
  int i, left, right;
  
  if ( 0 == nums.size() )
  {
    return rst;
  }  

  sort(nums.begin(), nums.end());

    
  dfs(nums, 0, N-1, rst);
  
  return rst;
}

               
int binarySearch(vector<int> &nums, int target, int start, int end)
{
  int mid = 0;
  
  while ( start + 1 < end )
  {
    mid = start + (end - start) / 2;
    
    if ( nums[mid] == target )
    {
      return 1;
    }
    else if ( nums[mid] > target )
    {
      end = mid;
    }
    else if ( nums[mid] < target )
    {
      start = mid;
    }
  }

  if ( nums[start] == target )
  {
    return 1;
  }

  if ( nums[end] == target )
  {
    return 1;
  }
  return 0;
  
}

void dfs(vector<int> &nums, int left, int right, vector< vector<int> > &rst)
{
  int target;

  if ( left + 1 >= right )
  {
    return;
  }
  
  target = 0 - nums[left] - nums[right];
  
  if ( binarySearch(nums, target, left + 1, right - 1) )
  {
    vector<int> tmp;
    tmp.push_back(nums[left]);
    tmp.push_back(target);
    tmp.push_back(nums[right]);

    rst.push_back(tmp);

    while ( nums[left] == nums[left + 1] && left + 1 < right )
    {
      left++;
    }

    while ( nums[right] == nums[right - 1] && left + 1 < right )
    {
      right--;
    }

    dfs(nums, left+1, right, rst);
    dfs(nums, left, right-1, rst);    
  }
  else if ( nums[left] + nums[right] >= 0 )
  {
    while ( nums[right] == nums[right - 1] && left + 1 < right )
    {
      right--;
    }

    dfs(nums, left, right-1, rst);
  }
  else if ( nums[left] + nums[right] < 0 )
  {
    while ( nums[left] == nums[left + 1] && left + 1 < right )
    {
      left++;
    }
    
    dfs(nums, left+1, right, rst);
  }

}


void print_rst(vector< vector<int> > rst)
{
  int N = rst.size();
  int i, j;

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      cout<<rst[i][j];
    }
    cout<<endl;
  }
  
  
}

vector< vector<int> > threeSum2(vector<int> &nums)
{
  vector< vector<int> > rst;
  int N = nums.size();
  int i, left, right;

  sort(nums.begin(), nums.end());
  
  for ( i = 0; i < N-2; i++ )
  {

    if ( nums[i-1] == nums[i] && i >= 1 )
    {
      continue;
    }
    
    left  = i + 1;
    right = N - 1;

    while ( left < right )
    {
      if ( nums[i] + nums[left] + nums[right] == 0 )
      {
        vector<int> tmp;
        tmp.push_back(nums[i]);
        tmp.push_back(nums[left]);
        tmp.push_back(nums[right]);
        rst.push_back(tmp);

        while ( nums[left] == nums[left + 1] && left < N  )
        {
          left++;
        }

        while ( nums[right] == nums[right - 1] && right  > 0 )
        {
          right--;
        }

        left++;
        right--;
      }
      else if ( nums[i] + nums[left] + nums[right] < 0 )
      {
        while ( nums[left] == nums[left + 1] && left  < N )
        {
          left++;
        }

        left++;
      }
      else if ( nums[i] + nums[left] + nums[right] > 0 )
      {
        while ( nums[right] == nums[right - 1] && right > 0 )
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
  int S[] = {-1, 0, 1, 2, -1, -4, -1, 2};
  vector<int> nums(S, S + sizeof(S) / sizeof(int));
  vector< vector<int> > rst;
  
  rst = threeSum2(nums);

  print_rst(rst);  
}
