/* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. */

/*   The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not. */

/*   Hide Tags Stack String */

#include <stack>
#include <iostream>

using namespace std;

bool isValid(string s)
{ 
  stack<char> a; // ()
  stack<char> b; // {}
  stack<char> c; // []

  int i;
  int N = s.size();

  for ( i = 0; i < N; i++ )
  {
    if ( s[i] == '(' )
    {
      a.push('(');
    }
    else if ( s[i] == '{' )
    {
      b.push('{');
    }
    else if ( s[i] == '[' )
    {
      c.push('[');
    }
    else if ( s[i] == ')' )
    {
      if ( !a.empty() )
      {
        a.pop();
      }
      else
      {
        return false;
      }
    }
    else if ( s[i] == '}' )
    {
      if ( !b.empty() )
      {
        b.pop();
      }
      else
      {
        return false;
      }
    }
    else if ( s[i] == ']' )
    {
      if ( !c.empty() )
      {
        c.pop();
      }
      else
      {
        return false;
      }
    }
    
  }

  if ( !a.empty() || !b.empty() || !c.empty() )
  {
    return false;
  }
  else
  {
    return true;    
  }

  
}


bool isValid2(string s)
{
  stack<char> st;
  int N = s.size();
  int i;

  for ( i = 0; i < N; i++ )
  {
    if ( s[i] == '(' || s[i] == '{' || s[i] == '[' )
    {
      st.push(s[i]);
    }
    else if ( s[i] == ')' )
    {
      if ( st.empty() || st.top() != '(' )
      {
        return false;
      }
      else
      {
        st.pop();
      }
    }
    else if ( s[i] == '}' )
    {
      if ( st.empty() || st.top() != '{' )
      {
        return false;
      }
      else
      {
        st.pop();
      }
    }
    else if ( s[i] == ']' )
    {
      if ( st.empty() || st.top() != '[' )
      {
        return false;
      }
      else
      {
        st.pop();
      }
    }
   
  }
  
  if ( st.empty() )
  {
    return true;
  }
  else
  {
    return false;
  }
  
}
  
int main()
{
  string s = "]";

  cout<< isValid2(s) <<endl;

  return 0;
}
