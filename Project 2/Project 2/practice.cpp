//
//  practice.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 5/11/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
//#include <priority_queue>


using namespace std;

template<class T>
void print_queue(T &q)
{
    T temp = q;
    //temp = q;
    while(!temp.empty())
    {
        cout<<" "<<temp.top();
        temp.pop();
    }
}
struct comp
{
    bool operator()(int &a,int &b)
    {
        return a < b;
    }
};
//int main()
//{
//    priority_queue<int,vector<int>,greater<int>> pq;
//    
//    priority_queue<string> pq1;
//   //template<class T> priority_queue<T> pq;
//    priority_queue<int,vector<int>,comp> pp;
//    for (auto i : {88,7,34,567,2})
//        pp.push(i);
//    cout<<endl<<"custom:";
//    print_queue(pp);
//    cout<<endl;
//    queue<int> q;
//    for (auto i : {88,7,34,567,2})
//        q.push(i);
//    //print_queue(q);
//    
//    
//    vector<int> v{1,2,3,4,5,6,7};
//    
//    for (int i : v)
//        pq.push(i);
//    
//    print_queue(pq);
//    cout<<endl;
//    
//    for (auto i : {"hi","mr","dhivyan","mrs","sindhu"})
//        pq1.push(i);
//    
//    print_queue(pq1);
//    
//    cout<<endl;
//    
//    
//    return 0;
//    
//}
