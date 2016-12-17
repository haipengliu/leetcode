/************************************************************************************************/
/* Given a positive integer, return its corresponding column title as appear in an Excel sheet. */
/*                                                                                              */
/* For example:                                                                                 */
/*                                                                                              */
/*     1 -> A                                                                                   */
/*     2 -> B                                                                                   */
/*     3 -> C                                                                                   */
/*     ...                                                                                      */
/*     26 -> Z                                                                                  */
/*     27 -> AA                                                                                 */
/*     28 -> AB                                                                                 */
/************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string convertToTitle(int n) {

  string res;
  int base = 26;
  char dict[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  int residue = 0;
  int remain  = 0;

  while(0<n){
    remain  = n / 26;
    residue = n % 26;

    if(residue==0){
      remain--;
      if(remain<0){
        break;
      }
      residue+=26;
    }

    res.push_back(dict[residue-1]);
    n = remain;
  }

  reverse(res.begin(), res.end());

  return res;
}

int main(){

  cout<< convertToTitle(79) <<endl;

  return 0;
}
