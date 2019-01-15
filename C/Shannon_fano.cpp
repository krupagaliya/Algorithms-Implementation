// Old version of Shannon fano code..

#include <bits/stdc++.h>
#include <fstream>
#include <type_traits>
using namespace std;

// void probability(string);
// int count1(string,char);
vector<int> sorting(const std::map<char,int>&);
void shannon(vector<int>&left,vector<int>&leftbit, vector<int>& right,vector<int>& rightbit);
void recusion(vector<int> & bar);
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
  getline( f, s, '\0');
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


map<char,int> probability(string str)
{
   str = removeSpaces(str);
   map<char,int> mymap;
   map<char,int>::iterator it;
   int counter;
   char c;  
   for(auto it = str.begin() ; it != str.end(); ++it)
	{
	 c = (char)*it;
	 // cout<<"ok"<<str<<"pk"<<endl;
	
	 counter = count1(str,c);
	 mymap.insert(pair<char, int>(c, counter));
	}
	it = mymap.begin();
	mymap.erase(it);
	it++;
	mymap.erase(it);
	it++;
   // cout<<"okay";
   return mymap;

}
vector<int> sorting(const std::map<char,int>& mymap)
{
	map<char,int> element;
typedef function<bool(std::pair<char, int>, std::pair<char, int>)> Comparator;
Comparator compFunctor =
		[](pair<char, int> elem1 ,pair<char, int> elem2)
		{
			return elem1.second >= elem2.second;
		};
      set<pair<char, int>, Comparator> setOfWords(mymap.begin(), mymap.end(), compFunctor);

	cout<<"hello \n";
	vector<int> vec;
	vec.reserve(mymap.size());

 for (pair<char, int> mymap : setOfWords)
 {
	cout << mymap.first << " :: " << mymap.second <<endl;
	vec.push_back(mymap.second);
 }
  return vec;
}

void recusion(vector<int> & v) {
    if (v.size() == 1) return;
    vector<int> left;
    vector<int> right;
    vector<int> leftbit;
    vector<int> rightbit;

    vector<int>::iterator it;
  
     it = v.begin();
    left.push_back(*it);
    leftbit.push_back(0);
    it++;

    for (it = it; it != v.end(); ++it) {
            right.push_back(*it);
            rightbit.push_back(1);
    }
    cout<<"left"<<endl;
     std::copy(left.begin(), left.end(), std::ostream_iterator<int>(std::cout, " , ") );
	std::cout<<endl;


 cout<<"right"<<endl;
     std::copy(right.begin(), right.end(), std::ostream_iterator<int>(std::cout, " , ") );
	std::cout<<endl;
    recusion(left);
    recusion(right);
    shannon(left,leftbit, right,rightbit);
}
void shannon(vector<int>&left,vector<int>&leftbit, vector<int>& right,vector<int>& rightbit)
{
   ofstream outdata;
   outdata.open("output.txt",ios::app);
   vector<int>::iterator it;
   for (it= leftbit.begin();it != leftbit.end();it++)

      outdata << *it << endl;
   outdata.close();
   

}



int main()
{
 string data;
 map<char,int>probability_map;
 map<char,int>::iterator it;
 vector<int> vec;
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
 recusion(vec);

 //  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " , ") );
	// std::cout<<endl;


}
