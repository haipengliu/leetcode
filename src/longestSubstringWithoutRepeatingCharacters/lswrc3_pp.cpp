int lengthOfLongestSubstring(string s)
{
  int longest = 0;
  int cnt = 0;
  int start1, start2, i;

  map<char, int> sc;

  start1 = start2 = 0;
  for ( start1 = 0; start1 < s.size(); start1++ )
  {
    for ( i = start2; i < s.size(); i++ )
    {
      if ( sc.find(s[i]) != sc.end() )
      {
        if ( longest < cnt )
        {
          longest = cnt;
        }

        start2 = sc[s[i]] + 1;
        cnt = i - sc[s[i]];
        break;
      }
      else
      {
        sc[s[i]] = i;
        cnt++;
      }
    }
  }

  if ( longest < cnt )
  {
    longest = cnt;
  }

  return longest;

}
