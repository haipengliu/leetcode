vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
  vector<vector<int> > results;
  
  if ( candidates.size() <= 0 )
  {
    return results;
  }

  vector<int> solution;

  solution.push_back(candidates[0]);
  helper(candidates, 0, target - candidates[0], solution, results);

  return results;
}

void helper(vector<int> &candidates, int start, int target, vector<int> solution, vector<vector<int> > results)
{
  if ( target == 0 )
  {
    results.push_back(solution);
    return;
  }

  if ( target < 0 )
  {
    return;
  }

  for ( int i = start; i < candidates.size(); i++ )
  {
    if ( i > start && candidates[i] == candidates[i-1] )
    {
      continue;
    }    
    
    solution.push_back(candidates[i]);
    helper(candidates, i, target - candidates[i], solution, results);
    solution.pop_back();
  }
    
}
