#include <vector>
#include <map>
#include <string>
#include <iostream>

struct ocurr
{
  int expect;
  int actual;  
};

using namespace std;

int allWordsFromWinMatch(int winStart, string s, map<string, ocurr> &mapDict, int sizeDict, int sizeWord, int sizeWin);

vector<int> findSubstring(string s, vector<string> &words)
{
  vector<int> result;
  map<string, ocurr> mapDict;
  int N = s.size();
  int sizeDict = words.size();
  int sizeWord = words[0].size();
  int winStart = 0;
  int sizeWin = sizeDict * sizeWord;
  int i;
  
  if ( 0 == N || 0 == sizeDict || 0 == sizeWord )
  {
    return result;
  }

  for ( i = 0; i < sizeDict; i++ )
  {
    if ( 0 == mapDict.count(words[i]) )
    {
      mapDict[words[i]].expect = 1;
      mapDict[words[i]].actual = 0;
    }
    else
    {
      mapDict[words[i]].expect++;
    }  
  }
    
  for ( winStart = 0; winStart <= N - sizeWin + 1; winStart++ )
  {
    if ( 1 == allWordsFromWinMatch(winStart, s, mapDict, sizeDict, sizeWord, sizeWin) )
    {
      result.push_back(winStart);
    }
  }

  return result;
}

int allWordsFromWinMatch(int winStart, string s, map<string, ocurr> &mapDict, int sizeDict, int sizeWord, int sizeWin)
{
  int N = s.size();
  int i;
  int winEnd = winStart + sizeWin - 1;
  string tmp;
  map<string, ocurr>::iterator it;
  int error;
  
  for ( i = winStart; i <= winEnd - sizeWord + 1; i += sizeWord )
  {
    tmp = s.substr(i, sizeWord);

    if ( 0 == mapDict.count(tmp) )
    {
      for ( it = mapDict.begin(); it != mapDict.end(); it++ )
      {
        it->second.actual = 0;
      }
            
      return -1;
    }
    else
    {
      mapDict[tmp].actual++;      
    }    
  }

  error = 0;
  for ( it = mapDict.begin(); it != mapDict.end(); it++ )
  {
    if ( it->second.expect != it->second.actual )
    {
      error = 1;
    }
    
    it->second.actual = 0;
  }
  
  if ( 1 == error )
  {
    return -1;
  }

  return 1;  
}

int main()
{
  //string s = "barfoothefoobarman";
  string s = "wordgoodgoodgoodbestword";
  vector<string> words;
  vector<int> result;
  int i;
  
  //words.push_back("foo");
  //words.push_back("bar");

  words.push_back("word");
  words.push_back("good");
  words.push_back("best");
  words.push_back("good");
  
  result = findSubstring(s, words);

  for ( i = 0; i < result.size(); i++ )
  {
    cout<<result[i]<<" ";
  }
  cout<<endl;
  
  return 0;
}
