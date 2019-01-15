#include <bits/stdc++.h>
#include <fstream>
#include <type_traits>
using namespace std;
int str_pos=0;
// void probability(string);
// int count1(string,char);
string stacks(string final);
string recusion(vector<int> & v);
vector<int> sorting(const std::map<int,char>&);

// void shannon(vector<int>&left, vector<int>& right,string ls,string rs,vector<int> v);
map<string,char> shannon(string rs,int n,map<int,char>& m);
void mapping(set<string>& s1,map<int,char>& probability_map,vector<int>& v);

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
string get_input()
{
  fstream f("input.txt", fstream::in );
  string s;
  getline( f, s);
  f.close();
  s = removeSpaces(s);
  cout << s << endl; 
  return s;

}
int count1(string s, char c)
{
	int count_var = 0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==c)
		{
          count_var+=1;
		}
	}
	return count_var;
}

map<int,char> probability(string str)
{
   str = removeSpaces(str);
   map<int,char> mymap;
   map<int,char>::iterator it;
   int counter;
   char c;  
   for(auto it = str.begin() ; it != str.end(); ++it)
	{
	 c = (char)*it;	
	 counter = count1(str,c);
	  mymap.insert(pair<int, char>(counter, c));
	}
	// it = mymap.begin();
	
   return mymap;

}
vector<int> sorting(const std::map<int,char>& mymap)
{
	map<int,char> element;
typedef function<bool(std::pair<int, char>, std::pair<int, char>)> Comparator;
Comparator compFunctor =
		[](pair<int, char> elem1 ,pair<int, char> elem2)
		{
			return elem1.first >= elem2.first;
		};
      set<pair<int, char>, Comparator> setOfWords(mymap.begin(), mymap.end(), compFunctor);
vector<int> vec;
	vec.reserve(mymap.size());
 cout<<"size is"<<vec.size();
 for (pair<int, char> mymap : setOfWords)
 {
	cout << mymap.first << " :: " << mymap.second <<endl;
	vec.push_back(mymap.first);
 }

  return vec;
}

string recusion(vector<int> & v) {
    if (v.size() == 1) return "";
    vector<int> left;
    vector<int> right;
    string ls,rs;

    vector<int>::iterator it;
  
     it = v.begin();
    left.push_back(*it);
    ls.append("0");
    it++;

    for (it = it; it != v.end(); ++it) {
            right.push_back(*it);
            rs.append("1");

    }
 //    cout<<"left"<<endl;
 //    for(it=leftbit.begin();it!=leftbit.end();it++)
 //    	cout<<*it<<endl;

 // cout<<"right"<<endl;
 //     std::copy(rightbit.begin(), rightbit.end(), std::ostream_iterator<int>(std::cout, " , ") );
	// std::cout<<endl;
    recusion(left);
    recusion(right);
    return rs;
}
// void shannon(vector<int>&left, vector<int>& right,string ls,string rs,vector<int> v)

// {
// 	// cout<<"left string is \t"<<ls<<endl;
	// cout<<"right string is \t"<<rs<<endl;
 //    string final;
 //    vector<int>::iterator it;
    
 //    it = v.begin();
 //    cout<<"\n it was \t"<<*it;
 //    final.append(ls);
 //    it++;
 //    for (it=it; it != v.end()-1; ++it) {
 //    	  cout<<"\n it was \t"<<*it;
 //        final.append(rs.append(ls));
 //    }
 //    it = v.end();
 //    final.append(rs);


 //   for(int i=0;i<final.size();i++)
 //   {
 //   	 cout<<final[i];
 //   }

 //   cout<<"\n final.size() is"<<final.size();



 //    for (it=v.begin(); it != v.end(); ++it) {
 //        cout<<"The vector is \t"<<*it<<endl;
 //    }

   // ofstream outdata;
   // outdata.open("output.txt",ios::app);
   // vector<int>::iterator it;
   // for (it= leftbit.begin();it != leftbit.end();it++)

   //    outdata << *it << endl;
   // outdata.close();
	// vector<int>::iterator it;
	// for(it=leftbit.begin();it!= leftbit.end();it++)
	// {
	//   // for(it=rightbit.begin();it!= rightbit.end();it++)	
	//   // {
	//   	cout<<"\n"<< *it<<"\t";
	// }
// }

string split(string final, string word)
{
  int i=0;
  int inttemp;
  int temp;
 char spc = ' ';
  string s="";
  for(i=str_pos;i<final.size();i++)
  {
    
   if (final[i]==spc)
   {
     // cout<<"od"<<i<<endl;
      temp = i;
      break;
   }
  }
      
 
 
 
  inttemp= temp - str_pos;
  s = final.substr(str_pos,inttemp);
  if (temp!=0)
    str_pos=temp+1;  
  return s;
}
map<string,char> shannon(string rs,int n,map<int,char>& m)
{ 
	string final = "";
  // map<char, int>::iterator itm ; 
	string stk;
	int i=0;
	final.append("0");
  final.append(" ");

	string ls = "0";
    for(i=1;i<n-1;i++)
    {
    	// cout<<"\n if "<<rs[i];
       final.append(rs,0,i);
       final.append("0");
       final.append(" ");

    }
    cout<<"\n rs is \t"<<rs;
    final.append(rs,0,i);
    final.append(" ");
    cout<<"\n ======= final is"<<final<<endl;
    
   
    string word;
    map<string,char> map1;
    
  
  char ch;
  string temp_str;
  std::map<int,char>::reverse_iterator rit;
  
  for (rit=m.rbegin(); rit!=m.rend(); ++rit)
  {
        ch = (char)rit->second;
        temp_str = split(final,word);
       map1.insert(pair<string,char>(temp_str,ch));
     // ch = (char)rit->second;
     //  map1.insert(pair<char,string>(ch,"abd"));
 
  } 
   std::map<string,char>::iterator itm;
  
  for (itm=map1.begin(); itm!=map1.end(); itm++)
  {
   
  cout << "(" << (*itm).first << ", "
      << (*itm).second << ")" << endl;
 } 
  return map1;
}



int main()
{
 string data;
 map<int,char>probability_map;
 map<string,char> com;
 map<int,char>::iterator it;
 vector<int> vec;
 string ls,rs;
 set<string> set1;

 data = get_input(); 
 data = removeSpaces(data);
 probability_map = probability(data);
  cout << "\tKEY\tELEMENT\n"; 
 for(it = probability_map.begin();it != probability_map.end();it++)
 {
   
 	cout << '\t' << it->first 
 	     << '\t' << it->second << '\n'; 
 }

 vec =  sorting(probability_map);
 int n= vec.size();
 rs = recusion(vec);


 com = shannon(rs,n,probability_map);
 
 //  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " , ") );
	// std::cout<<endl;

  

 
  for (it=probability_map.begin() ; it!=probability_map.end() ; it++) 
    cout << "(" << (*it).first << ", "
      << (*it).second << ")" << endl;
  

     //reverse iterator
  //     std::map<int,char>::reverse_iterator rit;
  // for (rit=probability_map.rbegin(); rit!=probability_map.rend(); ++rit)
  //   std::cout << rit->first << " => " << rit->second << '\n';

}
