//
//  atoi.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 6/27/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;
class Solution {
public:
    int op = 0;
    queue<int> q;
    int myAtoi(string str) {
        int flag =1,i =0;
        if(str.length() == 0)
            return op;
        while(str[i] == ' ')
            i++;
        if(str[i] == '0')
        {
            while(str[i] == '0')
        {
            i++;
        }
            if(str[i] < 48 | str[i] > 57)
                return 0;
            
        }
       
        if(str[i] == '-')
        {
            flag = -1;
            i++;
            while(str[i] == '0')
                i++;
        }
        else if(str[i] == '+')
        {
            i++;
            while(str[i] == '0')
                i++;
        }
        if(str[i] < 48 || str[i] > 57)
            return op;
        if(str.length() == 0)
            return 0;
        string s = str.substr(i,str.length()-i);
        for(auto j = 0; j < s.length();++j)
        {
            if(s[j] < 48 | s[j] > 57)
                break;
            int c = s[j] - 48;
            if(q.size() < 10)
            q.push(c);
            else
            {
                op = (flag == 1) ? INT_MAX : INT_MIN;
                return op;
            }
            
        }
        if(q.size() == 10)
        {
            int b = q.front();
            if(b > 2)
            {
            op = (flag == 1) ? INT_MAX : INT_MIN;
                return op;}
        }
        long long oo =0;//long to store
        int size = q.size() - 1;
        while(!q.empty())
        {
            int a = q.front();q.pop();
            oo += (a*(int)pow(10, size));
            size--;
            if(flag == 1 & oo > INT_MAX)
                return INT_MAX;
            else if (flag == -1 & ((-1)*oo < INT_MIN))
                return INT_MIN;
        }
        op = oo*flag;
        
        return op;
    }
};

//int main()
//{
//    Solution sol;
//    string s = "-42";
//    int o = sol.myAtoi(s);
//    cout<<o<<endl;   // return 0;
//    return 0;
//}
//function minStepsToOne(n) {

//function traverse(current) {
//    if (current === 1) {
//        return 0;
//    }
//
//    // subtract 1
//    let option = traverse(current - 1);
//
//    // divide by 3
//    if (current % 3 === 0) {
//        let divide3 = traverse(current / 3);
//        option = Math.min(option, divide3);
//    }
//
//    // divide by 2
//    if (current % 2 === 0) {
//        let divide2 = traverse(current / 2);
//        option = Math.min(option, divide2);
//    }
//
//    return option + 1;
//}
//
//return traverse(n);
//}
//
//
//// 1) Create cache
//// 2) Check cache
//// 3) Write to cache
//
//let cache = {};
//
//function minStepsToOneMemo(n) {
//    function traverse(current) {
//        if (current in cache) {
//            return cache[current];
//        }
//        if (current === 1) {
//            return 0;
//        }
//
//        // subtract 1
//        let option = traverse(current - 1);
//
//        // divide by 3
//        if (current % 3 === 0) {
//            let divide3 = traverse(current / 3);
//            option = Math.min(option, divide3);
//        }
//
//        // divide by 2
//        if (current % 2 === 0) {
//            let divide2 = traverse(current / 2);
//            option = Math.min(option, divide2);
//        }
//
//        cache[current] = option + 1;
//        return cache[current];
//    }
//
//    return traverse(n);
//}
//
//let result = new Array(500 + 1);
//
//function minStepsToOneTab(n) {
//    if (result[n] !== undefined) {
//        return result[n];
//    }
//    result[1] = 0;
//
//    for (let i = 2; i < result.length; i++) {
//        // subtract 1
//        let option = result[i - 1];
//
//        // divide by 3
//        if (i % 3 === 0) {
//            let divide3 = result[i / 3];
//            option = Math.min(option, divide3);
//        }
//
//        // divide by 2
//        if (i % 2 === 0) {
//            let divide2 = result[i / 2];
//            option = Math.min(option, divide2);
//        }
//
//        result[i] = option + 1;
//    }
//
//
//    return result[n];
//}
//
//
//
//// console.time("RECURSION: ");
//// console.log(minStepsToOne(500));
//// console.timeEnd("RECURSION: ");
//
//
//
//// console.time("MEMOIZATION: ");
//// console.log(minStepsToOneMemo(500));
//// console.timeEnd("MEMOIZATION: ");
//
//
//
//// console.time("TABULATION: ");
//// console.log(minStepsToOneTab(500));
//// console.timeEnd("TABULATION: ");
//
//
//
//
//
//console.time("MEMOIZATION MANY: ");
//for (let i = 0; i < 1000; i++) {
//    minStepsToOneMemo(500);
//}
//console.timeEnd("MEMOIZATION MANY: ");
//
//
//
//console.time("TABULATION MANY: ");
//for (let i = 0; i < 1000; i++) {
//    minStepsToOneTab(500);
//}
//console.timeEnd("TABULATION MANY: ");

