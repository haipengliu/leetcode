/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. */

/*   For example, given n = 3, a solution set is: */

/*   "((()))", "(()())", "(())()", "()(())", "()()()" */

/*   Hide Tags Backtracking String */

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;


void dfs(vector<string> &rst, string &tmp, stack<char> &st, int leftP, int rightP);

vector<string> generateParenthesis(int n)
{
  vector<string> rst;
  stack<char> st;
  string tmp;
  int leftP, rightP;

  if ( 0 == n )
  {
    return rst;
  }

  leftP = rightP = n;

  st.push('(');
  tmp.push_back('(');
  leftP--;

  dfs(rst, tmp, st, leftP, rightP);

  return rst;
}

void dfs(vector<string> &rst, string &tmp, stack<char> &st, int leftP, int rightP)
{
  if ( leftP == 0 && rightP == 0 && st.empty() )
  {
    string s(tmp);
    rst.push_back(s);


    
    return;
  }

  if ( leftP != 0 )
  {
    st.push('(');
    tmp.push_back('(');

    dfs(rst, tmp, st, leftP - 1, rightP);
  }

  
  
  if ( rightP != 0 )
  {
    if ( st.empty() )
    {
      return;
    }
    else if ( st.top() == '('  )
    {
      st.pop();
      tmp.push_back(')');
      
      dfs(rst, tmp, st, leftP, rightP - 1);
    }
  }


  
  return;
}


void print_matrix(vector<string> &rst)
{
  int i, j;

  for ( i = 0; i < rst.size(); i++ )
  {
    for ( j = 0; j < rst[i].size(); j++ )
    {
      cout<< rst[i][j] << " "; 
    }
    
    cout<< endl;
  }
}

int main()
{
  vector<string> rst;

  rst = generateParenthesis(2);

  print_matrix(rst);

  return 0;
}
