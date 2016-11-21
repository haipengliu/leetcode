/* Write a function that takes a string as input and returns the string reversed. */

/* Example: */
/* Given s = "hello", return "olleh". */

/*   Subscribe to see which companies asked this question */



string reverseString(string s) {

  int len = s.size();

  if(len==0) return s;

  int i = 0;
  char tmp;
  for(i = 0; i <= (len/2)-1; i++)
    {
      tmp = s[i];
      s[i] = s[len-1-i];
      s[len-1-i] = tmp;      
    }
  
  return s;
}
