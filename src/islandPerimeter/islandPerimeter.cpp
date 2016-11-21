/* You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island. */

/* Example: */

/* [[0,1,0,0], */
/*  [1,1,1,0], */
/*  [0,1,0,0], */
/*  [1,1,0,0]] */

/* Answer: 16 */
/* Explanation: The perimeter is the 16 yellow stripes in the image below:""' */


#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {

  int cnt = 0;
  int rowSize = grid.size();
  int colSize = 0;

  if (rowSize == 0) return cnt;

  int i, j;

  for(i=0; i<rowSize; i++)
    {
      colSize = grid[i].size();

      for(j=0; j<colSize; j++)
        {
          if(grid[i][j]==0) continue;
          
          if((i-1)<0 || grid[i-1][j]==0) cnt++;
          if((i+1)>(rowSize-1) || grid[i+1][j]==0) cnt++;

          if((j-1)<0 || grid[i][j-1]==0) cnt++;
          if((j+1)>(colSize-1) || grid[i][j+1]==0) cnt++;
        }
    }
  
  return cnt;
}



