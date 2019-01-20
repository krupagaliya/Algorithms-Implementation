#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <boost/dynamic_bitset.hpp>
using namespace std;
int str_pos = 0;
int str_pos_zero = 0;
string recusion(vector<int> &v);
vector<int> sorting(const std::map<char, int> &);
map<char, string> shannon(string rs, int n, map<char, int> &m);

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
map<char, int> probability(string str)
{
  // str = removeSpaces(str);
  // cout<<"Okay "<<str<<"\t";

  map<char, int> revmap;
  map<char, int>::iterator reviit;
  // map<int, char>::iterator it;
  int counter;
  char c;
  for (string::iterator it = str.begin(); it != str.end(); ++it)
  {
    c = (char)*it;
    cout << "char is " << c << "\t";
    counter = count1(str, c);
    cout << "Conter is " << counter << endl;
    revmap.insert(pair<char, int>(c, counter));
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
map<char, string> shannon(string rs, int n, map<char, int> &m)
{
  typedef pair<char, int> pair;
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
  std::map<char, int>::reverse_iterator rit;

  vector<pair> vec;
  copy(m.begin(),
       m.end(),
       back_inserter<vector<pair>>(vec));
  sort(vec.begin(), vec.end(),
       [](const pair &l, const pair &r) {
         if (l.second != r.second)
           return l.second > r.second;

         return l.first > r.first;
       });
  for (auto par : vec)
  {

    ch = (char)par.first;
    temp_str = split(final, word);
    // cout<<"\n temp_str is"<<temp_str;
    map1.insert({ch, temp_str});
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

void write_to_file(boost::dynamic_bitset<> str, string codes)
{
  if (remove("krupa1.dat") != 0)
    perror("Error deleting file");
  else
    puts("File successfully deleted");
  unsigned char buffer = 0;
  unsigned int cnt = 0;
  int index;
  unsigned char bit;
  for (int i = 0; i < codes.size(); i++)
  {

    if (codes[i] == '1')
    {
      str[i] = 1;
    }
    else if (codes[i] == ' ')

      str[i] = 'w';
  }

  ofstream fout("krupa1.dat", ios::out | ios::binary | ios_base::app);
  if (!fout)
  {
    cout << "Cannot open file to write" << endl;
    exit(1);
  }
  index = str.size() - 1;
  for (int i = index; i > -1; i--)
  {
    bit = str.test(i);
    buffer <<= 1;
    if (bit)
    {
      buffer |= 1;
    }
    cnt++;
    if (cnt == 8)
    {
      fout << buffer;
      buffer = 0;
      cnt = 0;
    }
  }
  if (cnt != 0)
  {
    while (cnt != 8)
    {
      cnt++;
      buffer <<= 1;
    }
    fout << buffer;
  }
}
boost::dynamic_bitset<> read_from_file(string file, int m)
{
  ifstream fin(file, ios::in | ios::binary);
  if (!fin)
  {
    cout << "Cannot open file to write" << endl;
    exit(1);
  }
  boost::dynamic_bitset<> str(m);
  int k = 0, cnt = 0;
  unsigned char bit;
  string code = "", tmp;
  while (getline(fin, tmp))
  {
    if (cnt == 0)
      code += tmp;
    else
      code += '\n' + tmp;
    cnt++;
  }
  for (auto t : code)
  {
    bitset<8> s(t);
    for (int i = 7; i > -1; i--)
    {
      bit = s.test(i);

      if (bit)
        str[k++] = 1;
      else if (bit == 'w')
        str[k++] = ' ';
      else
        str[k++] = 0;
      if (k == m)
        break;
    }
  }
  return str;
}

int main()
{

  string data;
  map<char, int> probability_map;
  map<char, string> com;
  map<string, char> reverseMap;
  map<string, char>::iterator revit;

  map<char, int>::iterator it;
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

  if (remove("ouput.txt") != 0)
    perror("Error deleting file");
  else
    puts("File successfully deleted");

  // ofstream codedFile("krupa1.dat", ios_base::app);
  ofstream outputfile("ouput.txt", ios_base::app);
  vector<int> s1;

  string leno = "";
  int assign_bit = 0;

  for (int i = 0; i < data.length(); i++)
  {
    comit = com.find(data[i]);
    if (comit == com.end())
      cout << "Key-value pair not present in map \n";
    else
    {
      cout << "Key-value pair present : "
           << comit->first << "->" << comit->second << endl;
    }
    assign_bit += comit->second.size();
    s1.push_back(comit->second.size());
    leno += comit->second;
  }
  boost::dynamic_bitset<> db(assign_bit);
  boost::dynamic_bitset<> db1(assign_bit);
  write_to_file(db, leno);

  cout << "\n========== Decoding ===========\n";
  db1 = read_from_file("krupa1.dat", assign_bit);

  cout << "\n=========";
  string s = "";
  to_string(db1, s);
  cout << s << endl;
  string str_temp = "";

  int strt_inx = 0;

  int upto = s1.size();
  auto j = s1.begin();

  for (int i = 0; i < upto; i++)
  {
    string ss = s.substr(strt_inx, *j);

    revit = reverseMap.find(ss);
    outputfile << revit->second;
    cout << revit->second;
    strt_inx += ss.size();
    // cout<<" sts os"<<strt_inx<<"\t";
    j++;
    // cout << '\t' << revit->first
    //      << '\t' << revit->second << '\n';
  }
  outputfile.close();
}
