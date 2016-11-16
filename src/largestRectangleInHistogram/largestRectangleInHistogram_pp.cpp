/********************************************************************************** 
* 
* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
* find the area of largest rectangle in the histogram.
* 
* Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
* 
* The largest rectangle is shown in the shaded area, which has area = 10 unit.
* 
* For example,
* Given height = [2,1,5,6,2,3],
* return 10.
* 
*               
**********************************************************************************/

#include <vector>

using namespace std;

int largestRectangleArea(vector<int> &height)
{
  if ( 0 == height.size() )
  {
    return 0;
  }

  int i = 0;
  int topIdx = 0;
  int high = 0;
  int len = 0;
  int area = 0;
  int maxArea = 0;

  vector<int> stack;

  height.push_back(0); // promise to pop all

  for ( i = 0; i < height.size(); i++ )
  {
    
    if ( stack.empty() || height[stack.back()] <= height[i] )
    {
      stack.push_back(i);
      continue;
    }
    

    topIdx = stack.back();
    
    high = height[topIdx];
    stack.pop_back();

    len = stack.empty() ? i : i - stack.back() - 1;

    area = high * len;

    if ( area > maxArea )
    {
      maxArea = area;
    }

    i--;
  }
  
  return maxArea;
  
}


int main(int argc, char *argv[])
{
  vector<int> height;
  height.push_back(1);
  height.push_back(2);
  height.push_back(3);

  int maxArea = largestRectangleArea(height);

  std::cout << maxArea << std::endl;
  
  return 0;
}
