//
//  Mapping_phone_numbers_to_letters.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 5/11/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output ={};
        string temp(digits);
        auto l = temp.length();
        map<char,string> map = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        if(l > 0)
        {
        string last =map.at(temp[l-1]);
        constructor_str(output,last);
        }
        else{
            output.push_back("");
            return output;
        }
        auto static i=0;
        
        for(i = l-2; i>=0;i--)
        {
            cout<<endl<<i;
            helper(map.at(temp[i]),output);
        }
        
        
        return output;
    
                            
                            }
    void constructor_str(vector<string> &o,string &ip)
                            {
                            auto ll = ip.length();
                                cout<<"h";
                            for(auto i =0;i<ll;i++)
                            {
                            string s(1,ip[i]);
                            o.push_back(s);
                            s.erase();
                            }
                            }
      void helper(string str,vector<string> &v)
        {
                            auto v_l = v.size();
                            auto s_l = str.length();
            vector<string> temp;
                            for(auto i = 0;i<v_l;i++)
                            {
                            
                            for(auto j = 0;j<s_l;j++)
                            {
                            string s(1,str[j]);
                            string tt = s + v[i];
                                temp.push_back(tt);
                            }
                            }
            v.clear();
            for(auto i: temp)
            {
                v.push_back(i);
            }
                            
        }
    
};
//int main()
//{
//    string input = "23";
//    Solution sol;
//    vector<string> output = sol.letterCombinations(input);
//    cout<<endl;
//    for (auto i : output)
//    cout<<" "<<i;
//    
//    
//    return 0;
//}
