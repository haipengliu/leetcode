vector<int> twoSum(vector<int> &nums, int target)
{
  vector<int> results;
  map<int, int> mp;

  if ( nums.size() <= 0 )
  {
    return results;
  }

  for ( int i = 0; i < nums.size(); i++ )
  {
    if ( mp.find(nums[i]) == mp.end() )
    {
      mp[target - nums[i]] = i;
    }
    else
    {
      results.push_back(mp[nums[i]] + 1);
      results.push_back(i + 1);
    }
  }

  return results;
}
