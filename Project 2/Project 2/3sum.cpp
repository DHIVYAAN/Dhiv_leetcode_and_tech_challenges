//
//  3sum.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 6/17/19.
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> buf(3);
        vector<vector<int>> op;
        sort(nums.begin(), nums.end());
        for(auto i = nums.begin();*i <=0;i++)
        {
            auto j = nums.end();j--;auto k = i+1;
            while(k < j)
            {
                auto buf1 = *i + *k + *j;
                if(buf1 == 0)
                {
                    vector<int> buf;
                                            buf.push_back(*i);
                                            buf.push_back(*j);
                                            buf.push_back(*k);
                                            sort(buf.begin(), buf.end());
                                            if(find(op.begin(),op.end(),buf) == op.end())
                                            op.push_back(buf);
                    k++;j--;
                }
                else if(buf1 < 0)
                {
                    k++;
                }
                else
                {
                    j--;
                }
                
            }
        }
        
        
        
        return op;
    }
};
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<int> buf(3);
//        vector<vector<int>> op;
//        for(auto it = nums.begin();it != nums.end();it++)
//            for(auto end = --nums.end();end >it;end--)
//            {
//                auto i = end;
//                auto sum = *it + *end;
//                i--;
//                while(i > it)
//                {
//                    if((sum + *i) == 0)
//                    {
//                        vector<int> buf;
//                        buf.push_back(*it);
//                        buf.push_back(*end);
//                        buf.push_back(*i);
//                        sort(buf.begin(), buf.end());
//                        if(find(op.begin(),op.end(),buf) == op.end())
//                        op.push_back(buf);
//
//                    }
//                     i--;
//                }
//            }
//
//
//
//        return op;
//    }
//};

//int main()
//{
//    Solution sol;
//    vector<int> v = {-1, 0, 1, 2, -1, -4};
//    vector<vector<int>> o = sol.threeSum(v);
//    cout<<endl;
//    for(auto it : o)
//    {
//        cout<<endl;
//        for(auto j = it.begin(); j!=it.end();j++)
//        {
//            cout<<" "<<*j;
//        }
//    }
//        
//    //cout<<sizeof(size_t);
//    return 0;
//}
