/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time. */

/*   push(x) -- Push element x onto stack. */
/*   pop() -- Removes the element on top of the stack. */
/*   top() -- Get the top element. */
/*   getMin() -- Retrieve the minimum element in the stack. */
/*   Hide Tags Stack Data Structure */

class MinStack {
public:

  stack<int> st;
  stack<int> minSt;
  
  void push(int x)
  {
    st.push(x);

    if ( minSt.empty() || ( !minSt.empty() && x < minSt.top() ) )
    {
      minSt.push(x);
    }
  }

  void pop()
  {

    if ( st.top() == minSt.top() )
    { 
      minSt.pop();
    }

    st.pop();    
    
  }

  int top()
  {
    return st.top();
  }

  int getMin()
  {
    return minSt.top();
  }
  
};
