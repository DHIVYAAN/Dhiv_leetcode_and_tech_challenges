//
//  division_without_operator.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 6/12/19.
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
    int divide(int dividend, int divisor) {
        
        if(divisor == 1)
            return dividend;
        else if(divisor == -1)
        {
            if(dividend > INT_MIN)
            return -dividend;
            else
                return INT_MAX;
        }
        
        if(divisor == INT_MAX)
        {
            if(dividend == divisor || dividend == INT_MIN)
                return 1;
            else
                return 0;
        }
        else if(divisor == INT_MIN)
        {
            if(dividend == divisor)
                return 1;
            else
                return 0;
        }
            
        
        long div=0,divd=0;
        //cout<<INT_MIN;
        div = abs(divisor);
        if(dividend > INT_MIN)
        divd = abs(dividend);
        else
            divd = INT_MAX;
        int op = (divd >= div) ? 1 : 0;
       
       if(div <= (INT_MAX)/2)
       {
        while((div+abs(divisor)) <= divd)
        {
           
            div += abs(divisor);
            op++;
            if(div+abs(divisor) >= (INT_MAX -abs(divisor)))
                return ++op;
        }
           
           
       }
        if((abs(dividend) == dividend && abs(divisor) == divisor) || (abs(dividend) != dividend && abs(divisor) != divisor))
            op =op;
        else
            op = -1*op;
        
        return op;
        
    }
};
//int main(){
//    
//    
//    Solution sol;
//   // int a = 10,b =3;
////    -2147483648
////    1
//    int o = sol.divide(INT_MIN,2);
//    cout<<endl<<o<<endl;
//    return 0;
//}
