/********************************************************************************** 
* 
* Given a digit string, return all possible letter combinations that the number could represent.
* 
* A mapping of digit to letters (just like on the telephone buttons) is given below.
* 
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
* 
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
* 
*               
**********************************************************************************/

#include <string>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<string> &rst, string &digits, char phone[10][4], string &str_tmp, int i)
{
  if ( i > digits.size() - 1 )
  {
    rst.push_back(str_tmp);
    return;
  }

  int j, k;
  char c;
  
  if ( !isdigit(digits[i]) )
  {
    return;
  }
  
  for ( j = 0; j < 4; j++ )
  {
    
    k = digits[i] - '0';
    
    c = phone[k][j];

    if ( !isalpha(c) )
    {
      continue;
    }

    str_tmp += c;

    dfs(rst, digits, phone, str_tmp, i + 1);

    str_tmp.pop_back();    
  }
  
  
}

vector<string> letterCombinations3(string digits)
{
  vector<string> rst;
  string str_tmp;
  char phone[10][4] =
    {
      {'\0', '\0', '\0', '\0'}, // 0
      {'\0', '\0', '\0', '\0'}, // 1
      {'a', 'b', 'c', '\0'}, // 2
      {'d', 'e', 'f', '\0'}, // 3
      {'g', 'h', 'i', '\0'}, // 4
      {'j', 'k', 'l', '\0'}, // 5
      {'m', 'n', 'o', '\0'}, // 6
      {'p', 'q', 'r', 's'}, // 7
      {'t', 'u', 'v', '\0'}, // 8
      {'w', 'x', 'y', 'z'}, // 9      
    };

  
  if ( 0 >= digits.size() )
  {
    return rst;
  }

  dfs(rst, digits, phone, str_tmp, 0);

  return rst;  
}




vector<string> letterCombinations2(string digits)
{

char phone[10][4] =
    {
      {'\0', '\0', '\0', '\0'}, // 0
      {'\0', '\0', '\0', '\0'}, // 1
      {'a', 'b', 'c', '\0'}, // 2
      {'d', 'e', 'f', '\0'}, // 3
      {'g', 'h', 'i', '\0'}, // 4
      {'j', 'k', 'l', '\0'}, // 5
      {'m', 'n', 'o', '\0'}, // 6
      {'p', 'q', 'r', 's'}, // 7
      {'t', 'u', 'v', '\0'}, // 8
      {'w', 'x', 'y', 'z'}, // 9      
    };

  vector<string> rst;
  
  if ( 0 == digits.size() )
  {
    return rst;
  }

  queue<string> q1;
  queue<string> q2;
  queue<string> *p1 = NULL;
  queue<string> *p2 = NULL;
  
  int i,j,k;
  char c;
  int d;
  
  for ( i = 0; i < digits.size(); i++ )
  {
    if ( !isdigit(digits[i]) )
    {
      rst.clear();
      return rst;
    }

    d = digits[i] - '0';
    
    if ( 0 == q1.size() && 0 == q2.size() )
    {
      p1 = &q1;

      for ( j = 0; j < 4; j++ )
      {
        c = phone[d][j];

        if ( isalpha(c) )
        {
          string s;
          s += c;
          p1->push(s);
          
        }
        
      }

      continue;
    }    

    if ( 0 != q2.size() )
    {
      p1 = &q2;
      p2 = &q1;
    }
    else if ( 0 != q1.size() )
    {
      p1 = &q1;
      p2 = &q2;
    }

    while ( !p1->empty() )
    {
      string s = p1->front();
      p1->pop();
      
      for ( j = 0; j < 4; i++ )
      {
        c = phone[d][j];
        
        p2->push(s);
                
      }
            
    }
    
  }// for digits
  
  rst.clear();

  if ( q1.empty() )
  {
    p2 = &q2;
  }
  else
  {
    p2 = &q1;
  }

  while ( !p2->empty() )
  {
    string s = p2->front();
    p2->pop();

    rst.push_back(s);
    
  }

  
  return rst;

  

}

vector<string> letterCombinations(string digits)
{

  char phone[10][4] =
    {
      {'\0', '\0', '\0', '\0'}, // 0
      {'\0', '\0', '\0', '\0'}, // 1
      {'a', 'b', 'c', '\0'}, // 2
      {'d', 'e', 'f', '\0'}, // 3
      {'g', 'h', 'i', '\0'}, // 4
      {'j', 'k', 'l', '\0'}, // 5
      {'m', 'n', 'o', '\0'}, // 6
      {'p', 'q', 'r', 's'}, // 7
      {'t', 'u', 'v', '\0'}, // 8
      {'w', 'x', 'y', 'z'}, // 9      
    };

  vector<string> rst;
  
  if ( 0 == digits.size() )
  {
    return rst;
  }

  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  char c;
  
  for ( i = 0; i < digits.size(); i++ )
  {
    if ( !isdigit(digits[i]) )
    {
      rst.clear();
      return rst;
    }

    k = digits[i] - '0';

    if ( 0 == rst.size() )
    {
      for ( j = 0; j < 4; j++ )
      {
        c = phone[k][j];
        
        if ( isalpha(c) )
        {
          string stmp;
          stmp += c;
          rst.push_back(stmp);
        }
      }
      continue;
    }

    vector<string> r;
    for ( l = 0; l < rst.size(); l++ )
    {
      for ( j = 0; j < 4; i++ )
      {
        c = phone[k][j];

        if ( isalpha(c) )
        {
          string stmp = rst[l] + c;
          r.push_back(stmp);          
        }
      }
    }

    rst = r;
  }
  
  return rst;
}



int main(int argc, char *argv[])
{
  string s = "2";
  vector<string> out;

  out = letterCombinations3(s);
    
  return 0;
}
