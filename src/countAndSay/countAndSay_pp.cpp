string vec2Str(vector<int> v)
{
  stringstream ss;
  for ( i = 0; i < v.size(); i++ )
  {
    ss<<v[i];
  }

  return ss.str();
}

vector<int> getNextV(vector<int> v)
{
  vector<int> newv;
  int cnt, val, i;

  for ( i = 0; i < v.size(); i++ )
  {
    if ( i == 0 )
    {
      cnt = 1;
      val = v[i];
      continue;
    }

    if ( v[i] == val )
    {
      cnt++;
      continue;
    }
    else
    {
      newv.push_back(cnt);
      newv.push_back(val);

      cnt = 1;
      val = v[i];
      continue;
    }

  }

  newv.push_back(cnt);
  newv.push_back(val);

  return newv;
}

string countAndSay(int n)
{
  string s;
  vector<int> v;

  if ( n <= 0 )
  {
    return s;
  }

  if ( n == 1 )
  {
    s = "1";
    return s;
  }

  v.push_back(1);

  for ( int i = 2; i <= n; i++ )
  {
    v = getNextV(v);
  }

  s = vec2str(v);

  return s;
}
