#include <bits/stdc++.h>
#include <iostream> 
#include <string>
using namespace std;
int main()
{
	int n;
	cout<<"How many codes you will enter ?";
	cin>>n;
	string s= "";
	bool f = true;
	vector<string> v;
	for(int i=0;i<n;i++)
	{
		string code;
		cin>>code;
		v.push_back(code);
	} 
	set<string> set1;
	set<string>::iterator is;
	//check for if all inputs are unique are not
	for(size_t s = 0; s < v.size(); s++)
	{
		set1.insert(v[s]);

	}
	if (v.size()!=set1.size())
	{
		cout<<"Please enter unique codes";
		exit(0);
	}
	
	int i=0;
	for(size_t s = 0; s < v.size()-1; s++)
	{
		string now = v[s];
			 // cout<<"now is "<<now<<"s is"<<s<<endl;
		for(size_t ne= s+1; ne < v.size();ne++)
			 {  
			 string next = v[ne];
			 cout<<"next is"<<next<<"next is "<<ne<<endl;
			 
			 if(next.size()>=now.size())
			 {
				string pref = next.substr(0,now.size());
				 if (pref == now)
				 {
					string dang = next.substr(now.size());
					cout<<"dang is"<<dang<<endl;
						auto iss = set1.find(dang);
					 if (iss == set1.end())
					{
						// set1.insert(dang); 
						cout<<"new danging";
					 }
					 else
					 {
					cout<<"already there";
					f = false;
					break;

					}
					}
				 else
					f = true; //instantaneous code
			 }
			 else if(next.size()<=now.size())
			 {
					string pref = now.substr(0,next.size());

					 if (pref == next)
					 {
						string dang = now.substr(next.size());
						cout<<"dang is"<<dang<<endl;
					auto iss = set1.find(dang);
					 if (iss == set1.end())
					{
						cout<<"new danging";
						 // set1.insert(dang);
						
					 }
					 else
					 {
					cout<<"already there";  
					f = false;
					break;
				 }
					}
				 else
					f = true;
			 }
			 else if(next.size()==now.size())
			 {	
				// int r = strcmp(string(next),string(now));
				if (next.compare(now) == 0)
					{
					f = false;
					break;
					}
				else
				{
					f = true;
				}
			}
		 }
		 if (!f)
		 {
			break;
		 }
		 }
		 for(is = set1.begin();is!=set1.end();is++)
				cout<<*is<<endl;	
		 if(f)
		 {
			cout<<"unique \n";
		 }
		 else{
			cout<<"No unique \n";
		 }	 
	return 0;
}
