#include <bits/stdc++.h>
using namespace std;
int main()
{
    string data;
    int n;
    // n=3;
    cout<<"How mant Alphabets \n";
    cin>>n;
    map<char, float> probability_map;
    map<char, float>::iterator it;
    map<char, float> cum_count;
    map<char, float>::iterator cit;
    map<char, float>::iterator prevs;
    cout<<"Enter char and its probability \n";
    for(int i=0;i<n;i++)
    {
        cout<<i<<endl;
        char s;
        float o;
        cin>>s>>o;
        // cout<<"ans is"<<s<<"\t"<<o<<endl;
  
        probability_map.insert({s,o}); 
    } 
      // probability_map.insert({'1',0.8}); 
      // probability_map.insert({'2',0.02}); 
      // probability_map.insert({'3',0.18});  
    // data = "1321";
    cout<<"Enter a string to be encoded \n";
    cin>>data;
    // probability_map = probability(data);
    std::vector<float> v;
    int sizep = probability_map.size();
    float s = 0.0;
    for (it=probability_map.begin();it!=probability_map.end();it++)
    {
       if (it==probability_map.begin())
       {
            s = it->second;
            cum_count.insert({'0',0.0});
       }
       else
          s+=it->second;
       v.push_back(s);  
       cum_count.insert({it->first,s});        
    }
    
    for(auto i=cum_count.begin();i!=cum_count.end();i++)
    {
        cout<<i->second<<endl;
    }
    float l = 0.0;
    float lnew = 0.0;
    float u = 1.0;
    for(int i=0;i<data.size();i++)
    {
        cit = cum_count.find(data[i]);
        prevs = prev(cum_count.find(data[i]));
        cout<<data[i]<<"--"<<cit->first<<"---"<<cit->second<<endl;
        if (prevs==cum_count.end())
        {
            cout<<"Not found in list \n";
            cout<<data[i]<<endl;

        }
        else
        {
          // cout<<"done \n"<<prevs->first<<"----"<<prevs->second;
        }
          lnew = l + (u-l)* prevs->second;
          u = l + (u-l) * cit->second;
        // cout<<"\n ----"<<l<<"+("<<u<<"-"<<l<<")*"<<cit->second<<"----\n";
        cout<<"l is "<<l<<" u is "<<u<<endl;    
      l = lnew;
    }
    float tag = 0.0;
    tag = (l+u) / 2;
    cout<<"The tag is "<<tag<<endl;
    
    cout<<"\n ------------Decoding--------------\n";
    int dn = 4;
    string ans = "";
    map<char, float>::iterator itr;
    map<float, char> reverseMap;
    map<float, char>::iterator itrr;
    map<float, char>::iterator prevs1;
    for(itr = cum_count.begin(); itr != cum_count.end(); itr++)
     reverseMap[itr->second] = itr->first;
    for(int i=0;i<dn;i++)
    {
        itrr = reverseMap.upper_bound(tag);
        prevs1 = prev(itrr);
        cout<<tag<<endl;
        ans+=itrr->second;
      tag = (tag - prevs1->first) / (itrr->first - prevs1->first);
    }
    cout<<"Decoding is "<<ans;
    return 0;
}
