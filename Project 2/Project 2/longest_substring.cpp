//
//  longest_substring.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 5/19/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string buf="",buf2;
        int l = s.length();
        if(l == 0)
            return 0;
        else if(l == 1)
            return 1;
        buf = s[0];
        for(int i = 0; i <l;i++)
        {
            int k = i;
            buf2 = s[i];
            auto j = i +1;
            
            while((j<l) && (buf2.find(s[j]) == string::npos))
            {
                buf2 += s[j];
                k++;
                j++;
            }
            auto it = string::npos;
            if(j<l)
            {
                it = buf2.find(s[j]) + i;}
            if(it == i)
            {
                //continue;
            }
            else if(it == (l-1))
            {
                i++;
            }
            else if(it == string::npos)
            {
                if(buf2.length() > buf.length())
                {
                    buf = buf2;
                }
                break;
            }
            else
            {
                i = it-1;
            }
            if(buf2.length() > buf.length())
            {
                buf = buf2;
            }
            
        
        }
        return buf.length();
        
    }
};
//int main(){
//    Solution s;
//    int o = s.lengthOfLongestSubstring("abcabcbb");
//    cout<<endl<<o<<endl;
//    
//    return 0;
//}
