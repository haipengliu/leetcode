#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows){

  vector<vector<int>> res;

  if (numRows==0) return res;

  vector<int> elt;
  elt.push_back(1);
  res.push_back(elt);

  if (numRows==1) return res;

  for(int i=1; i<numRows; i++){
    vector<int> elt;
    for(int j=0; j<=res[i-1].size(); j++){
      if(j==0) elt.push_back(0+res[i-1][j]);
      else if(j==res[i-1].size()) elt.push_back(res[i-1][j-1]+0);
      else elt.push_back(res[i-1][j-1]+res[i-1][j]);
    }
    res.push_back(elt);
  }
  return res;
}

