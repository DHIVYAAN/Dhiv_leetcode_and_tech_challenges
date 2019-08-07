//
//  main.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 5/9/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
//#include<algorithm>

#include "Remove_digits.hpp"
using namespace std;
using namespace removedigits;


class Solution {
public:
    vector<string> time;
    //vector<int> hour(1,2,4,8);
    vector<string> readBinaryWatch(int num) {
        driver(num,time);
        return time;
        
    }
    void driver(int num,vector<string> &time)
    {
        for(auto i = 0;i<=num;i++)
        {
            auto j = num - i;
            cout<<j<<" "<<i;
            vector<int> hour = hourhandler(i);
            //cout<<endl<<"debug";
            vector<string> minutes = minhandler(j);
            //cout<<endl<<"debug";
            for(auto k = hour.begin(); k != hour.end() ; ++k)
            {
                for(auto l = minutes.begin();l != minutes.end() ; ++l)
                {
                    string s = to_string(*k) + ":"+(*l);
                    time.push_back(s);
                }
            }
            
        }
    }
    vector<int> hourhandler(int &n)
    {
        //int digits = 4;
        cout<<n;
        vector<int> hour{0};
        vector<int> buffer{1,2,4,8};
        vector<int> result;
        if (n == 0)
        {
            
            return hour;
        }
        else if (n == 1)
        {
            return buffer;
        }
        else
        {
            //cout<<"here";
            for(int i = 3; i < 11; i++)
            {
                int c = count(i);
                if (c == n)
                {
                    cout<<endl<<"hour:"<<i;
                    result.push_back(i);
                }
            }
            return result;
        }
    }
    
    vector<string> minhandler(int &n)
    {
        
        cout<<endl<<"min"<<n;
        vector<string> result;
        if (n ==0)
        {
            result.push_back("00");
            return result;
        }
        // else if (n = 1)
        // {
        //     return buffer;
        // }
        else
        {
            for(int e = 1; e < 59; e++)
            {
                //cout<<endl<<"e ="<<e;
            
                int c = count(e);
                //cout<<endl<<"i sucks"<<c;
                //cout<<endl<<c;
                if (c == n)
                { //cout<<endl<<"more";
                    string s = to_string(e);
                    if(e < 10)
                    {
                        cout<<endl<<e;
                        s = "0"+s;
                    }
                    result.push_back(s);
                }
                //cout<<endl<<"end";
                
            }
            
        }
        return result;
        
    }
    int count(int &n)
    {
        int temp = n;
        int c = 0;
        //cout<<endl<<"n="<<n;
        while(temp)
        {
            c = c + (temp & 1);
            temp = (temp >> 1);
        }
        return c;
    }
};

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    //string S[]={"1432219","10200","10"};
//    //int n[] = {3,1,2};
//    Solution S;
//    vector<string> str = S.readBinaryWatch(3);
//    //vector<string>::iterator i;
//    for(auto i = 0; i < str.size(); i++)
//    cout<<" "<<endl<<str[i];
//
//
////    int m = 7;
////    auto x = m &(1<<2);
////    cout<<endl<<x<<endl;
//
////    RemoveDigits RD;
////    for(auto i = 0; i < 3; ++i)
////    {
////
////    RD.RemoveDigitsFunction(S[i], n[i]);
////    cout<<endl<<RD.result<<endl;
////        RD.result = "";
////    }
//
//    return 0;
//}
//class Str{
//  multi
//public:

    
//};
int compare(string &s1, string &s2)
{
    string a,b;
    a = s1;b =s2;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return a.compare(b);
    
}
//int main(){
//    vector<string> v = {"abcd","amma","dcba","mama"},b;
//    multimap<string,string> mm;
//    for(string i : v)
//    {
//        string s(i);
//        int l = i.length();
//        sort(i.begin(),i.end());
//        //mm[i] = s;
//        mm.insert({i,s});
//        //cout<<" "<<i;
//        //b.push_back(i);
//    }
//    //sort(b.begin(),b.end());
//    for(auto i = mm.begin(); i != mm.end();i++)
//    {
//        b.push_back(i->second);
//        //cout<<endl<<i;
//    }
//    for(auto i = b.begin(); i != b.end();i++)
//    {
//        cout<<" "<<(*i);
//        //cout<<endl<<i;
//    }
//    cout<<endl;
//    sort(v.begin(),v.end(),compare);
//    for(auto i = b.begin(); i != b.end();i++)
//    {
//        cout<<" "<<(*i);
//        //cout<<endl<<i;
//    }
//    //cout<<v[0];
//    return 0;
//}
void reverseD(char *str)
{
    int size = sizeof(str)/sizeof(char);
    
    cout<<endl<<"size:"<<size;
    char *temp = str;
    //char *temp = (char *)malloc(sizeof(char)*(size));
//    for(auto i = 0; i < size/2; i++)
//    {
//        auto j = size -1-i;
//
//       char c = str[j];
////        //str[i] = c;
//        char temp = c;
////        str[i] = temp2;
////        str[j] = temp;
//    }
//    *str = *temp;
//   // str = strcpy(str, temp);
    while(*temp != '\0')
        temp++;
    temp--;
    while(str<temp)
    {
        char t = *str;
        (*str++) = (*temp);
        *temp-- = t;
    }
}
//int main(){
//    
//    char s[] = "dhivyaan";
//    cout<<endl<<"ip :"<<s;
//    reverseD(s);
//     cout<<endl<<"op :"<<s;
//    return 0;
//}
