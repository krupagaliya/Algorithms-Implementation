#include <bits/stdc++.h>
#include <fstream>
#include <bitset>
using namespace std;
int str_pos = 0;

string recusion(vector<int> &v);
vector<int> sorting(const std::map<char,int> &);
map<char, string> shannon(string rs, int n, map<char,int> &m);
// void mapping(set<string> &s1, map<int, char> &probability_map, vector<int> &v);

//Removes space from Input string aka from file
string removeSpaces(string str)
{
  int i = 0, j = 0;
  while (str[i])
  {
    if (str[i] != ' ')
      str[j++] = str[i];
    i++;
  }
  str[j] = '\0';
  return str;
}
//Input from file
string get_input()
{
  fstream f("input.txt", fstream::in);
  string s;
  getline(f, s);
  f.close();
  // s = removeSpaces(s);
  cout << s << endl;
  return s;
}
//Count occurance of character
int count1(string s, char c)
{
  int count_var = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == c)
    {
      count_var += 1;
    }
  }
  return count_var;
}

//arranging all things in map
map<char,int> probability(string str)
{
 // str = removeSpaces(str);
  // cout<<"Okay "<<str<<"\t";
 
  map<char,int> revmap;
  map<char,int>::iterator reviit;
  // map<int, char>::iterator it;
  int counter;
  char c;
  for (string::iterator it = str.begin(); it != str.end(); ++it)
  {
    c = (char)*it;
    cout<<"char is "<<c<<"\t";
    counter = count1(str, c);
    cout<<"Conter is "<<counter<<endl;
    revmap.insert(pair<char,int>(c,counter));
  }

  return revmap;
}
// returns vector having decending order
vector<int> sorting(const std::map<char, int> &mymap)
{
  map<char, int> element;
  typedef function<bool(std::pair<char, int>, std::pair<char, int>)> Comparator;
  Comparator compFunctor =
      [](pair<char, int> elem1, pair<char, int> elem2) {
        return elem1.first >= elem2.first;
      };
  set<pair<char, int>, Comparator> setOfWords(mymap.begin(), mymap.end(), compFunctor);
  vector<int> vec;
  vec.reserve(mymap.size());
  cout << "size is" << vec.size();
  for (pair<char, int> mymap : setOfWords)
  {
    cout << mymap.first << " :: " << mymap.second << endl;
    vec.push_back(mymap.second);
  }

  return vec;
}
// parts vector in left and right phase
string recusion(vector<int> &v)
{
  if (v.size() == 1)
    return "";
  vector<int> left;
  vector<int> right;
  string ls, rs;
  vector<int>::iterator it;
  it = v.begin();
  left.push_back(*it);
  ls.append("0");
  it++;
  for (it = it; it != v.end(); ++it)
  {
    right.push_back(*it);
    rs.append("1");
  }
  recusion(left);
  recusion(right);
  return rs;
}
// split final string by space and return code in string
string split(string final, string word)
{
  int i = 0;
  int inttemp;
  int temp;
  char spc = ' ';
  string s = "";
  for (i = str_pos; i < final.size(); i++)
  {
    if (final[i] == spc)
    {
      temp = i;
      break;
    }
  }
  inttemp = temp - str_pos;
  s = final.substr(str_pos, inttemp);
  if (temp != 0)
    str_pos = temp + 1;
  return s;
}
// Encoding logic part
map<char, string> shannon(string rs, int n, map<char,int> &m)
{
  typedef pair<char,int> pair;
  string final = "";
  // map<char, int>::iterator itm ;
  string stk;
  int i = 0;
  final.append("0");
  final.append(" ");

  string ls = "0";
  for (i = 1; i < n - 1; i++)
  {
    final.append(rs, 0, i);
    final.append("0");
    final.append(" ");
  }
  cout << "\n rs is \t" << rs;
  final.append(rs, 0, i);
  final.append(" ");
  cout << "\n ======= final is" << final << endl;
  string word;
  map<char, string> map1;
  char ch;
  string temp_str;
  std::map<char,int>::reverse_iterator rit;

  vector<pair> vec;
  copy(m.begin(),
      m.end(),
      back_inserter<vector<pair>>(vec));
  sort(vec.begin(), vec.end(),
      [](const pair& l, const pair& r) {
        if (l.second != r.second)
          return l.second > r.second;

        return l.first > r.first;
      });
  for (auto par: vec) { 
  // for (rit = m.rbegin(); rit != m.rend(); ++rit)
  // {
    ch = (char)par.first;
    cout<<"\n ch is"<<ch;
    temp_str = split(final, word);
    cout<<"\n temp_str is"<<temp_str;
    map1.insert({ch,temp_str});
    
  }
  std::map<char, string>::iterator itm;

  for (itm = map1.begin(); itm != map1.end(); itm++)
  {
    cout << "(" << (*itm).first << ", "
         << (*itm).second << ")" << endl;
  }
  return map1;
}

// For decoding erase unnecessary code
void eraseDemo(string &str)
{
  int n = str.find("1");
  int m = str.find("0");
  int len = str.length();
  if (n >= 0)
  {
    str.erase(0, n);
  }
  else if (str[len] == 0)
  {
    str.erase(0, len - 1);
  }
}

int main()
{
  
  string data;
  map<char,int> probability_map;
  map<char, string> com;
  map<string, char> reverseMap;
  map<string, char>::iterator revit;

  map<char,int>::iterator it;
  map<char, string>::iterator comit;
  vector<int> vec;
  string ls, rs;
  set<string> set1;

  data = get_input();
 // data = removeSpaces(data);
  probability_map = probability(data);
  cout << "\tKEY\tELEMENT\n";
  for (it = probability_map.begin(); it != probability_map.end(); it++)
  {

    cout << '\t' << it->first
         << '\t' << it->second << '\n';
  }

  vec = sorting(probability_map);
  int n = vec.size();
  rs = recusion(vec);
  


  // //give shannon to int,char map
  com = shannon(rs, n, probability_map);
  for (comit = com.begin(); comit != com.end(); comit++)
    reverseMap[comit->second] = comit->first;

  cout << "\n==================\n";

  if (remove("krupa1.KP11") != 0)
    perror("Error deleting file");
  else
    puts("File successfully deleted");

  if (remove("ouput.txt") != 0)
    perror("Error deleting file");
  else
    puts("File successfully deleted");

  ofstream codedFile("krupa1.KP11", ios_base::app);
  ofstream outputfile("ouput.txt", ios_base::app);

  for (char x : data)
  {
    comit = com.find(x);
    if (comit == com.end())
      cout << "Key-value pair not present in map \n";
    else
      cout << "Key-value pair present : "
           << comit->first << "->" << comit->second << endl;

    std::string alpha_bit_string = comit->second;
    std::bitset<6> b1(alpha_bit_string, 0, alpha_bit_string.size(),
                      '0', '1');
    // cout<<endl<<b1;
    if (codedFile.fail())
    {
      cerr << "Unable to open file for writing." << endl;
      exit(1);
    }
    codedFile << b1 << endl;
  }
  codedFile.close();
  cout << "\n========== Decoding ===========\n";

  string data2;
  fstream f("krupa1.KP11", fstream::in);
  string s;
  string file_contents;
  while (std::getline(f, s))
  {
    // s.erase(0, 2);
    eraseDemo(s);
    revit = reverseMap.find(s);
    if (revit == reverseMap.end())
      cout << "Key-value pair not present in map \n";
    else
    {
      outputfile << revit->second;
    }
    file_contents += s;
    file_contents.push_back('\n');
  }
  f.close();
  outputfile.close();
}
