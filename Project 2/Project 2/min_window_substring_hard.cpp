//
//  min_window_substring_hard.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 6/1/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    string op ="";
    string minWindow(string s, string t) {
        unordered_map<char, int> hash,temp;
        if(s.length() < t.length())
        {
            return op;
        }
        for(auto c : t)
        {auto it = hash.find(c);
            if(it != hash.end())
            {
                it->second++;
            
            }
            else
            hash.insert({c,1});
        }
        int req = hash.size();
        int start = 0,end = 0;
        int output_arr[] = {-1,0,0};
        int formed = 0;
        while(end < s.length())
        {
            char c = s[end];
            auto it1 = temp.find(c);
             auto it2 = hash.find(c);
            if(it1 != temp.end())
            {
                it1->second++;
                
            }
            else
            {
                temp.insert({c,1});
                it1 = temp.find(c);
            }
            if((hash.find(c) != hash.end()) & (temp.find(c) != temp.end()))
            {
                if((it1->second) == (it2->second))
                formed++;
            }
            while((start <= end) & (formed == req))
                  {
                      
                      if((output_arr[0] == -1) | (end - start + 1 < output_arr[0]))
                      {
                          output_arr[0] = end-start+1;
                          output_arr[1] = start;
                          output_arr[2] = end;
                      }
                      char b = s[start];
                      auto it3 = temp.find(b);
                      auto it4 = hash.find(b);
                      it3->second--;
                      if((it3->second < it4->second) & (it4 != hash.end()))
                      {
                          formed--;
                      }
                      start++;
                      
                      
                      
                  }
                  end++;
        }
        if(output_arr[0] == -1)
            return op;
        else{
            int length = output_arr[0];
            op = s.substr(output_arr[1],length);
        }
        return op;
    }
   
};

//int main()
//{
//    string s = "aaaaaaaaaaaabbbbbcdd",t="abcdd";
//    Solution sol;
//    string o = sol.minWindow(s, t);
//    cout<<endl<<o<<endl;
//    return 0;
//}
