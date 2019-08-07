//
//  substring_k_integers.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 5/21/19.
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
    int count;
    int subarraysWithKDistinct(vector<int>& A, int K) {
        if( (K > A.size()) ||  (A.size() > 20000))
        {
            return 0;
        }
        
        for(auto i = A.begin(); i != A.end();i++)
        {
            unordered_set<int> set;
            bool flag = true; int n = 1, set_l = 1;
            if (K == 1)
            count++;
            set.insert(*i);
            if( *i > A.size())
            {
                return 0;
            }
            auto j = i;
            while( flag && (++j != A.end()))
            {
                //j++;
                auto it = set.find(*j);
                if((it == set.end()) && (n < K))
                {
                    n++;
                    set.insert(*j);
                    set_l++;
                    if( n == K)
                        count++;
                    
                }
                else if(it != set.end() && (n <= K))
                {
                    set.insert(*j);
                    set_l++;
                    if( n == K)
                        count++;
                }
                else
                        {
                            flag = false;
                        }
            
                        }
            
                        }
                        return count;
            
        }
    
};
//int main()
//{
////    unordered_map<int,int> m;
////    m.insert(200, 1);
//    vector<int> A = {1,2};
//    int k = 1;
//    Solution S;
//    int o = S.subarraysWithKDistinct(A, k);
//    cout<<endl<<o;
//    
//    
//    return 0;
//}
