#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace  std;


int moveLeft(vector<int> &nums, int left)
{
  do{
    left++;
  }while(left<nums.size()&&nums[left]==nums[left-1]);
  return left;
}

int moveRight(vector<int> &nums, int right)
{
  do{
    right--;
  }while(right>=0&&nums[right]==nums[right+1]);
  return right;
}

vector< pair<int, int> > twoSum(vector<int> &nums, int left, int right, int target){
  int val=0;
  vector< pair<int, int> > results;
  while(left<right)
  {
    val=nums[left]+nums[right];
    if(val==target){
      results.push_back(make_pair(nums[left], nums[right]));
      left=moveLeft(nums, left);
      right=moveRight(nums, right);
    }else if(val<target){
      left=moveLeft(nums, left);
    }else{
      right=moveRight(nums, right);
    }
  }
  return results;
}

vector< vector<int> > threeSum(vector<int> &nums)
{
  vector< vector<int> > results;
  vector< pair<int, int> > twos;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i=moveLeft(nums, i))
  {
    int head=nums[i];
    int target=0-head;

    twos=twoSum(nums, i+1, nums.size()-1, target);
    for(int j=0; j<twos.size(); j++){
      vector<int> oneResult={head, twos[j].first, twos[j].second};
      results.push_back(oneResult);
    }
    twos.clear();
  }
  return results;
}

void printMatrix(vector<vector<int> > &matrix)
{
    for(int i=0; i<matrix.size(); i++){
        printf("{");
        for(int j=0; j< matrix[i].size(); j++) {
            printf("%3d ", matrix[i][j]) ;
        }
        printf("}\n");
    }
    cout << endl;
}


int main()
{
    // int a[] = {-1, 0, 1, 2, -1, 1, -4};
    // int a[] = {-1, 1, 1, 1, -1, -1, 0,0,0};
    vector<int> n = {-1, 0, 1, 2, -1, 1, -4};
    vector< vector<int> > result = threeSum(n);
    printMatrix(result);
    return 0;
}
