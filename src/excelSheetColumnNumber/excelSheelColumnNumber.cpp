/*********************************************************************************************/
/* Given a column title as appear in an Excel sheet, return its corresponding column number. */
/*                                                                                           */
/* For example:                                                                              */
/*                                                                                           */
/*     A -> 1                                                                                */
/*     B -> 2                                                                                */
/*     C -> 3                                                                                */
/*     ...                                                                                   */
/*     Z -> 26                                                                               */
/*     AA -> 27                                                                              */
/*     AB -> 28                                                                              */
/*********************************************************************************************/

#include <unordered_map>
#include <iostream>
#include <math.h>

using namespace std;


int titleToNumber(string s) {

  int base  = 26;
  int carry = 0;
  int dig   = 0;
  int sum   = 0;
  int len   = s.size();

  unordered_map<char, int> dict;
  dict['A'] = 1;
  dict['B'] = 2;
  dict['C'] = 3;
  dict['D'] = 4;
  dict['E'] = 5;
  dict['F'] = 6;
  dict['G'] = 7;
  dict['H'] = 8;
  dict['I'] = 9;
  dict['J'] = 10;
  dict['K'] = 11;
  dict['L'] = 12;
  dict['M'] = 13;
  dict['N'] = 14;
  dict['O'] = 15;
  dict['P'] = 16;
  dict['Q'] = 17;
  dict['R'] = 18;
  dict['S'] = 19;
  dict['T'] = 20;
  dict['U'] = 21;
  dict['V'] = 22;
  dict['W'] = 23;
  dict['X'] = 24;
  dict['Y'] = 25;
  dict['Z'] = 26;

  for(int i=0; i<len; i++){
    carry = (int)pow(base, len-i-1);
    dig   = dict[s[i]];

    sum += carry * dig;    
  }

  return sum;
}


int main()
{
  cout << titleToNumber("AB") << endl;
  
  return 0;
}
