//
//  Longest_palindrome.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 5/16/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    string op;
    string longestPalindrome(string s) {
        
        int length = s.length();
        longeststring(s,length,op);
        
        return op;
        
        
    }
    void longeststring(string &ss,int &l,string &o)
           {
               string out;
               if(l == 0)
                   out = "";
               else
               out = ss[0];
               map<pair<int, int>,int> map;
               for(int i = 0; i < l; i++)
               {
                   pair<int, int> p,q;
                   p = make_pair(i, i);
                   map[p] = 1;
                   for(int j = i+1; j < l; j++)
                   {
                       q = make_pair(i, j);
                       map[q] = -1;
                       
                   }
               }
               bool min = false;
               for(int i = 0; i < l-1; i++)
               {
                   pair<int, int> q;
                   q = make_pair(i, i+1);
                   if(ss[i] == ss[i+1])
                   {
                       map[q] = 1;
                   if(min == false)
                   {
                       out = ss.substr(i,2);
                       min = true;
                   }
                   }
                   
                   else
                       map[q] = 0;
               }
               
               for(auto i = 0;i<(l-2); i++)
               {
                   for(auto j = i+2; j<l;j++)
                   {
                            int b = det(i,j,map,ss);
                           if(b ==1)
                           {
                               if(out.length() < (j-i+1))
                               {
                                   out = ss.substr(i,j-i+1);
                               }
                           }
                       
                   }
               }
               o = out;
           }
               int det(int &m, int &n,map<pair<int, int>,int> &map,string &ss)
               {
                   int i =m,j=n;
                   int a = i+1,b=j-1;
                   pair<int, int> q = make_pair(a, b);
                       if(map[q] == -1)
                          map[q] = det(a,b,map,ss);
                       if(ss[i] == ss[j])
                       return (map[q] * 1);
                       else
                        return 0;
                   
               }
    
    
};
               


