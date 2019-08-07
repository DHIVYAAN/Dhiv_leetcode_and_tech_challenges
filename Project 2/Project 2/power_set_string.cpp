//
//  power_set_string.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 7/29/19.
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

class solution{
public:
    vector<string> powerset(string ip)
    {
        vector<string> ps = {""};
        if(ip.length() == 0)
            return ps;
        
        for(auto i = 0 ; i < ip.length();i++)
        {
            vector<string> temp = ps;
            for(auto j : temp)
            {
                string temp = j + ip[i];
                cout<<" "<<temp;
                ps.push_back(temp);
            }
        }
        
        
        return ps;
    }
   // vector<int> cache;
    unordered_map<int, int> cache;
    int minrecursivehelper(int num)
    {
        ////cout<<cache[num];
        
        auto it = cache.find(num);
        if(it != cache.end())
        return cache[num];
//        if(cache[num] != -1)
//            return cache[num];
        
        int v2,v3;
        if((num % 2) == 0)
            v2 = minrecursivehelper(num/2);
        else
            v2 = INT_MAX;
        
        if((num % 3) == 0)
            v3 = minrecursivehelper(num/3);
        else
            v3 = INT_MAX;
        
        int op = min(minrecursivehelper(num-1),v2);
        op = min(op, v3) + 1;
        
        cache[num] = op;
        //cache.insert(make_pair(num, op));
        
        return op;
        
    }
    
    int minimumStepsToOne(int num) {
        
       cache[1] = 0; cache[2] = 1; cache[3] = 1;//cache[0] = 0;
        //vector<int> c;
//        for(auto i = 0 ; i<=num; i++)
//        {
//            cache.push_back(-1);
//        }
        //cout<<cache[num]<<endl;
        //cache = c;
        
        int steps = minrecursivehelper(num);
        
        return steps;
        
    }
    
};
//int main()
//{
//    string i = "abc";
//    solution sol;
//    int o = sol.minimumStepsToOne(100000);
//    cout<<o;
////    vector<string> o = sol.powerset(i);
////    for(auto j : o)
////        cout<<j<<endl;
//    
//    return 0;
//    
//}
/*
 //mega function
 //create result container
 //create function to build our strings take a current string and an index
 //if the index is out of bounds/longer than the string
 //add our result to the result container
 //call the function recursively adding the character at the index with index++
 //call the function recursively without adding the character index with index++
 
 //call our helper function with the empty string and 0
 
 //return result
 
 
 const powerSet = function powerSet(inString) {
 console.log('hello');
 const result = [];
 
 const buildStrings = function buildStrings(currentString, index) {
 if(index >= inString.length) {
 result.push(currentString);
 return;
 }
 
 buildStrings(currentString + inString.charAt(index), index + 1);
 buildStrings(currentString, index + 1);
 
 }
 
 buildStrings('', 0);
 return result;
 }
 
 
 //Lattice Paths
 //outer function (n, m)
 //result counter if we aren't using tail recursion
 //mover function takes column and row indexes
 //if the column is out of bounds or the row the row is out of bounds
 //stop/return and don't add a path
 //if we've reached the endpoint (n,m)
 //add 1 to our result
 //return
 //move right recursively (column+1, row)
 //move down recursively (column, row + 1)
 //call our mover at (0, 0)
 //return result;
 
 const latticePaths = function latticePaths(n, m) {
 let result = 0;
 const mover = function mover(column, row) {
 if(column > n || row > m) {
 return;
 }
 if(column === n && row === m) {
 result++;
 return;
 }
 mover(column+1, row);
 mover(column, row+1);
 }
 mover(0,0);
 return result;
 }
 
 console.log(latticePaths(-1,0));
 */
