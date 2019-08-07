//
//  wild_card_matching.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 6/8/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
enum val{
    NF=-1,
    F=0,
    T=1
};
class Solution {
public:
    vector<vector<val>> flag;
    
    bool isMatch(string s, string p) {
        vector<val> temp(p.length()+1,NF);
        vector<vector<val>> temp2(s.length()+1,temp);
        flag = temp2;
        int st=0,en=p.length()-1;
        if(p[st] == '*' && p[en] == '*')
        {
            while(p[st] == '*')
                st++;
            while(p[en] == '*')
                en--;
            p = p.substr(st,p.length() - (en+st));
        }
        
            
        return isMatchUtil(0,0,s,p);
    }
    bool isMatchUtil(int i,int j, string s, string p)
    {
        char a = s[i],b = p[j];
        if(flag[i][j] != NF)
        {
            return (flag[i][j] == T);
        }
        bool ans;
        if(p[j] == '*' && i == s.length())
        {
            while(p[j] == '*')
                j++;
            if(j == p.length()) ans = true;
            else ans = false;
        }
            
        else{
        if(j == p.length())
            ans= (i == s.length()) || (p[j-1] == '*');
       
        else{
            bool fm = false;
            fm = (i<s.length() && ((s[i] == p[j]) || p[j] == '?'));
            if((j < p.length()) && p[j] == '*' && i < s.length())
            {
                ans = (isMatchUtil(i, j+1, s, p)) || (isMatchUtil(i+1, j, s, p)) || (isMatchUtil(i+1, j+1, s, p));
            }
            else if(fm && i < s.length()){
                ans = fm && isMatchUtil(i+1, j+1, s, p);
            }
            else
            {
                ans = false;
            }
        }
        }
        flag[i][j] = ans ? T : F;
        
        
        return ans;
    }
};
//int main()
//{
//    //vector<int> v = {1,2},w ={-1,3};
//    Solution sol;
//    string s1="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",s2="*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa*";
//    bool b = sol.isMatch(s1
//                         , s2);
//    //float o = sol.findMedianSortedArrays(v, w);
//    cout<<endl<<b<<endl;
//    //     vector<int> n1(v.begin(), v.begin() +1+1);
//    //    //vector<int> n1(v.begin() + 1, v.end());
//    //"mississippi"
//    
//    //    for(auto i : n1)
//    //        cout<<" "<<i;
//    return 0;
//}
//""
//""
