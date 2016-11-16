# include <queue>
# include <vector>
# include <iostream>

using namespace std;

vector<int> getRow(int rowIndex) {
        
  queue<vector<int> > mp;

  vector<int> elt;

  if(rowIndex==0) return elt;
  elt.push_back(1);
  if(rowIndex==1) return elt;

  mp.push(elt);

  for(int i=1; i<rowIndex; i++){
    vector<int> elt;
    vector<int> *pre;

    pre = &(mp.front());
    
    for(int j=0;j<=pre->size();j++){
      if(j==0) elt.push_back(0+(*pre)[j]);
      else if(j==pre->size()) elt.push_back((*pre)[j-1]+0);
      else elt.push_back((*pre)[j-1]+(*pre)[j]);
    }

    mp.pop();
    mp.push(elt);
  }

  return mp.front();
}

void printVector(vector<int> v){
  for(int i=0; i<v.size(); i++){
    cout << v[i] << ", ";
  }
  cout<<endl;
}
  

int main()
{
  vector<int> res = getRow(2);
  printVector(res);

  return 0;
}
