/* Write a program that outputs the string representation of numbers from 1 to n. */

/* But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”. */

/* Example: */

/* n = 15, */

/*   Return: */
/*   [ */
/*    "1", */
/*    "2", */
/*    "Fizz", */
/*    "4", */
/*    "Buzz", */
/*    "Fizz", */
/*    "7", */
/*    "8", */
/*    "Fizz", */
/*    "Buzz", */
/*    "11", */
/*    "Fizz", */
/*    "13", */
/*    "14", */
/*    "FizzBuzz" */
/*    ] */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

string itoa(int x);

vector<string> fizzBuzz(int n) {

  int i = 0;
  vector<string> res;
  if(n==0) return res;
  int rsd_3 = 0;
  int rsd_5 = 0;

  for (i=1; i<=n; i++)
    {
      rsd_3 = i % 3;
      rsd_5 = i % 5;

      if(rsd_3==0 && rsd_5==0) {res.push_back("FizzBuzz");}
      else if(rsd_3==0) {res.push_back("Fizz");}
      else if(rsd_5==0) {res.push_back("Buzz");}
      else {res.push_back(itoa(i));}
    }

  return res;
}

string itoa(int x)
{
  int div = 0;
  int res = 0;
  int n   = x;
  string ret;
  char c;

  while(n != 0)
  {
    div = n / 10;
    res = n % 10;

    c = res + '0';
    ret.insert(ret.begin(), c);

    n = div;      
  }

  return ret;
}

int main()
{
  cout<< itoa(3) <<endl;
  return 0;
}
