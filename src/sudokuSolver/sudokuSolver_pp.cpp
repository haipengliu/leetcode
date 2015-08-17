


const int cnt = 9;
bool rowMask[cnt][cnt] = {false};
bool colMask[cnt][cnt] = {false};
bool areaMask[cnt][cnt] = {false};

bool check(vector< vector<char> > &board)
{
  int i, j, idx, num;
  for ( i = 0; i < cnt; i++ )
  {
    for ( j = 0; j < cnt; j++ )
    {
      if ( board[i][j] == '.' ) continue;

      idx = (i/3)*3 + j/3;
      num = board[i][j] - '1';

      if ( rowMask[i][num] || colMask[j][num] || areaMask[idx][num] )
      {
        return false;
      }

      rowMask[i][num] = colMask[j][num] = areaMask[idx][num] = true;
    }
  }

  return true;
}

bool helper(int r, int c, vector< vector<int> > &board )
{
  if ( cnt <= r ) return true;

  if ( cnt <= c ) return helper(r+1, 0, board);

  if ( board[r][c] == '.' ) return helper(r, c+1, board);

  int num, idx;
  for ( num = 0; num < cnt; num++ )
  {
    idx = (r/3)*3 + c/3;

    if ( rowMask[r][num] || colMask[c][num] || areaMask[idx][num] )
    {
      continue;
    }

    board[r][c] = num + '1';
    rowMask[r][num] = colMask[c][num] = areaMask[idx][num] = true;

    if ( helper(r, c+1, board) == true )
    {
      return true;
    }

    board[r][c] = '.';
    rowMask[r][num] = colMask[c][num] = areaMask[idx][num] = false;
  }

  return false;
}

void solveSudoku(vector< vector<char> > &board)
{
  if ( ! check(board) )
  {
    return;
  }

  helper(0, 0, board);

}
