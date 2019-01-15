#include <bits/stdc++.h>
#include <fstream>
#include <type_traits>
using namespace std;

// void probability(string);
// int count1(string,char);
string stacks(string final);
string recusion(vector<int> & v);
vector<int> sorting(const std::map<char,int>&);

// void shannon(vector<int>&left, vector<int>& right,string ls,string rs,vector<int> v);
set<string> shannon(string rs,int n,map<char,int>& m);
void mapping(set<string>& s1,map<char,int>& probability_map,vector<int>& v);

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
	// mymap.erase(it);
	// it++;
	// mymap.erase(it);
	// it++;
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
	vector<int> vec;
	vec.reserve(mymap.size());

 for (pair<char, int> mymap : setOfWords)
 {
	cout << mymap.first << " :: " << mymap.second <<endl;
	vec.push_back(mymap.second);
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
set<string> shannon(string rs,int n,map<char,int>& m)
{ 
	string final = "";
  // map<char, int>::iterator itm ; 
  vector<char> myvec;
  vector<char>::iterator it;
  set<string> set1;
	string stk;
	int i=0;
	final.append("0");
  final.append(" ");
	string ls = "0";
    for(i=1;i<n-2;i++)
    {
    	// cout<<"\n if "<<rs[i];
       final.append(rs,0,i);
       final.append("0");
       final.append(" ");

    }
    cout<<"\n rs is \t"<<rs;
    final.append(rs,0,i);
    final.append(" ");
    cout<<"\n ======= final is "<<final<<endl;

   
    string word;
    multimap<char,string> map1;
    istringstream iss(final, istringstream::in);
  
  char ch;
   for(std::map<char, int>::iterator itm =m.begin(); itm != m.end(); itm++)
   {
  
    // while( iss >> word )     
    // {
     ch = (char)itm->first;
    // int i=0;
    //    cout<<"\ti is "<<i<<"\t"<<ch;
    //      i++;
     
        map1.insert(pair<char,string>(ch,"abd"));
      
    // }
    }
    
      // map1.insert ( std::pair<char,string>('a',"100") );
      // map1.insert('A',s.c_str());
      // map1.insert('B',s.c_str());
      // map1.insert('C',s.c_str());
    // printf( "%s \n", s.c_str() );
  
    for (auto it=map1.begin(); it != map1.end(); ++it) 
    cout << ' ' << it->first<< ' ' <<it->second<<endl;
    


    string stks;
    int j=0;
     char c = '0';
     for (int i = 0; i < final.size(); i++)
     {
     	  myvec.push_back(final[i]);
     	 
     	 if (final[i]==c)
     	 {
     	 	j++;
     	 	for(it=myvec.begin();it!=myvec.end();it++)
     	 	{
             string stk(myvec.begin(), myvec.end());
             set1.insert(stk);             
             stks = stk;  
     	  	 }
     	  	 myvec.clear();
     	 	}
        }    
  cout<<"\n ================= \n";
     for (auto it=set1.begin(); it != set1.end(); ++it) 
		cout << ' ' << *it; 
	cout<<"\n ================= \n";
  return set1;
}

void mapping(set<string>& set1,map<char,int>& m,vector<int>& v)
{
	multimap<int,string> m2;
	map<char,int>::iterator itm;
	set<string>::iterator its;
	// vector<int>::iterator itv;
	for (auto it=set1.begin(); it != set1.end(); ++it) 
		cout << ' ' << *it;
	
	// for (auto it=m.begin(); it != m.end(); ++it) 
	// 	// cout << ' ' << it->first<< ' ' <<it->second<<endl;
	// {
	// 	if it-second>
	// }

     
  //  map<string,>
  //  for (auto it=v.begin(); it != v.end(); ++it) 
		// cout << ' ' << *it;
	 // cout<<"\n DOne";
  
  //   itm = m.begin();
    
  //   left.push_back(*it);
	 // cout<<itm->first;
  //       for (int i=0;i <5;i++) 
  //       {
        	
		//          // m2.insert(pair<int, string>(,"haha"));
		// }
	
 // //  cout<<endl;
	// 	cout<<"okay";
	// for (auto it=m2.begin(); it != m2.end(); ++it) 
	// {
	// 	for (auto it=v.begin(); it != v.end(); ++it) 
	// 	m2.insert(pair<int, string>(*it,"haha"));
	// }
    
    // vector<int>::iterator itv;
   // map<char,int>::iterator itm;
   // set<string>::iterator its;
   
   
   // int i = 0;
   // itm = m.begin();
   // its = set1.begin();
   // cout<<
   // // m2.insert(pair<int,string>(*itm,*its));
   // while(i< m2.size())
   // { 
   // m2.insert(pair<int,string>(itm->second,*its));
   // itm++;
   // its++;
    // }

   //  for (auto it=v.begin(),set1.begin(); it != v.end(),set1.end(); ++it) 
   // {
		 //      m2.insert(pair<int, string>(*it,"fg"));
   // }
   // for (auto its=set1.begin(); its != set1.end(); ++its) 
   // {
   // 	 m2.insert(pair<int, string>(12,*its));
   // }

   // cout<<"okay2";

   for (auto it=m2.begin(); it != m2.end();++it) 
		cout <<"\n" <<' ' << it->first<< ' ' <<it->second<<endl;
	// vector<int> v( m.size() );
 //     transform( m.begin(), m.end(), v.begin(), get_second );
 //    sort( v.begin(), v.end() );

 //     for (int i=0; i<v.size(); i++) cout << v[i] << endl;
     
     	

}


int main()
{
 string data;
 map<char,int>probability_map;
 map<char,int>::iterator it;
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


 set1 = shannon(rs,n,probability_map);
 mapping(set1,probability_map,vec);
 
 //  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " , ") );
	// std::cout<<endl;


}