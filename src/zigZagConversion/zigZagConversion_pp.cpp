/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility) */

/*   P   A   H   N */
/*   A P L S I I G */
/*   Y   I   R */
/*   And then read line by line: "PAHNAPLSIIGYIR" */
/*   Write the code that will take a string and make this conversion given a number of rows: */

/*   string convert(string text, int nRows); */
/* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". */

string convert(string s, int numRows)
{
  string rst;
  if ( 0 == s.size() )
  {
    return rst;
  }

  if ( numRows <= 1 || numRows >= s.size() )
  {
    return s;
  }

  vector<string> m(numRows);
  int row = 0;
  int step = 1;
  int i = 0;

  for ( i = 0; i < s.size(); i++ )
  {
    if ( 0 == row )
    {
      step = 1;
    }

    if ( numRows - 1 == row )
    {
      step = -1;
    }
    
    m[row] += s[i];
    row += step;    
  }

  for ( i = 0; i < numRows; i++ )
  {
    rst += m[i];
  }
  
  
  return rst;
}
