/* Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1. */

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    
    if ( s.size() == 0 )
    {
      return 0;
    }

    char c;
    int len = 0;
    int max_len = 0;
    int i, j;
    set<char> st;

    for ( i = 0, j =0; i < s.size(); i++ )
    {
      c = s[i];

      if ( st.count(c) == 1 )
      {
        while ( c != s[j] )
        {
          st.erase(s[j]);
          len--;
          j++;
        }

        st.erase(s[j]);
        j++;
        len--;
      }

      st.insert(c);
      len++;
      if ( len > max_len )
      {
        max_len = len;
      }
    }

    return max_len;
  }
};



class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    
    if ( s.size() == 0 )
    {
      return 0;
    }

    char c;
    int max_len = 0;
    int i, pos = 0;
    map<char, int> st;

    for ( i = 0; i < s.size(); i++ )
    {
      c = s[i];

      if ( st.count(c) == 1 && pos <= st[c])
      {
        pos = st[c] + 1;        
      }

      st[c] = i;
      if ( i - pos + 1 > max_len )
      {
        max_len = i - pos + 1;
      }
    }

    return max_len;
  }
};



