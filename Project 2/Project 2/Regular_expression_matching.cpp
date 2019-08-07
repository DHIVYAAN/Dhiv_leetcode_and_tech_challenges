//
//  Regular_expression_matching.cpp
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
        if(j == p.length())
            ans= (i == s.length());
        else{
        bool fm = (i<s.length() && ((s[i] == p[j]) || p[j] == '.'));
        if((j+1 < p.length()) && p[j+1] == '*')
            {
                ans = (isMatchUtil(i, j+2, s, p)) || (fm && isMatchUtil(i+1, j, s, p));
            }
        else {
            ans = fm && isMatchUtil(i+1, j+1, s, p);
        }
        }
        flag[i][j] = ans ? T : F;
        
        
        return ans;
    }
};
//naive approach with no support for .*
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        vector<pair<char, int>> hash;
//        for(auto i =0;i<p.length();i++)
//        {
//            auto x = i+1;
//            if( p[x] == '*')
//            {hash.push_back(make_pair(p[i], -1)); i++;}
//            else
//                hash.push_back(make_pair(p[i], 1));
//        }
//        int j = 0,count = 0;
//        for(auto i=0;i<s.length();i++)
//        {
//            if(j < hash.size())
//            {
//            char ch = hash[j].first; int key = hash[j].second;
//            if(ch == s[i] && key == -1)
//            {continue;}
//            else if(ch == s[i])
//            {
//                j++;continue;
//            }
//            else if(ch == '.')
//            {
//                if(key == -1)
//                {continue;}
//                else
//                {j++;continue;}
//            }
//            else if(key == -1)
//            {
//                j++;i--;continue;
//            }
//            else
//                return false;
//            }
//            else
//                return false;
//        }
//
//
//        return true;
//    }
//};
//int main()
//{
//    //vector<int> v = {1,2},w ={-1,3};
//    Solution sol;
//    string s1="mississippi",s2="mis*is*ip*.";
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
