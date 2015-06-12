/********************************************************************************** 
* 
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
* 
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
* 
* Note: You may not slant the container.
* 
*               
**********************************************************************************/

int maxArea(vector<int> &height)
{
  int i, j;
  int N = height.size();
  int ret = 0;
  int h = 0, w = 0;
  int area = 0;
  
  for ( i = 0; i <= N - 2; i++ )
  {
    for ( j = i + 1; j <= N - 1; j++ )
    {
      w = j - i;
      h = max(height[i], height[j]);
      area = w * h;

      if ( ret < area )
      {
        ret = area;
      }
      
    }
  }

  return ret;
  

}


int maxArea(vector<int> &height)
{
  int left, right;
  int N = height.size();
  int ret = 0;
  int h = 0, w = 0;
  int area = 0;

  left = 0;
  right = N - 1;
  
  while ( left < right )
  {
    w = right - left;
    h = max(height[left], height[right]);
    area = w * h;
    
    if ( ret < area )
    {
      ret = area;
    }

    if ( left <= right )
    {
      left++;
    }
    else
    {
      right--;
    }  

    
  }

  return ret;
  

}
