/********************************************************************************** 
* 
* Given an array of integers, find two nums such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two nums such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: nums={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
* 
*               
**********************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {

      vector<int> rst;
      map<int, int> hash_table;
      int i;

      for ( i = 0; i < nums.size(); i++ )
      {
        if ( hash_table.find(nums.[i]) == hash_table.end() )
        {
          hash_table[target - nums[i]] = i;
        }
        else
        {
          rst.push_back(hash_table[nums[i]] + 1);
          rst.push_back(i + 1);
          return rst;
        }
      }
    }
};
