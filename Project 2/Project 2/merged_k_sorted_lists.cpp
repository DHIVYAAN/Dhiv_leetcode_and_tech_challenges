//
//  merged_k_sorted_lists.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 6/30/19.
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

struct comp
{
    bool operator()(int &a,int &b)
    {
        return a > b;
    }
};
 struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
//     ListNode(ListNode * ptr)
//     {
//         val = ptr->val;
//         next = ptr->next;
//     }
 };
//class Solution {
//public:
//    ListNode *op;
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        priority_queue<int> pq;
//        int size = lists.size();
//        for
//
//
//        return op;
//    }
//};
//struct compare{
//    bool operator(){
//
//    }
//};
void printList(ListNode **ln)
{ListNode *temp = *ln;
    while(temp != NULL)
{
    
    cout<<" "<<temp->val;
    temp = (temp)->next;
}
    return;
    
}
void arrayb(vector<ListNode *> &vv,ListNode **ln)
{
    if(*ln != NULL)
        vv.push_back(*ln);
    
    return;
        
}
class Solution {
public:
    ListNode *op = NULL;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,comp> pq;
        cout<<"Size:"<<lists.size()<<endl;
        for(auto i = lists.begin(); i != lists.end();++i)
        {
            printList(&(*i));cout<<endl;
            ListNode *curr = *i;
            while(curr != NULL)
            {
                pq.push(curr->val);
                curr = curr->next;
            }
        }
        while(!pq.empty())
        {
            int c = pq.top();
            if(op == NULL)
                op = new ListNode(c);
            else
            {
                ListNode *temp = new ListNode(c);
                ListNode *temp2 = op;
                while(temp2->next != NULL)
                    temp2 = temp2->next;
                temp2->next = temp;
            }
            pq.pop();
        }

        return op;
    }
    void addNode(int x,ListNode **lnn)
    {
       // cout<<"*lnn:"<<(*lnn)<<endl;
        if(*lnn == NULL)
        {
            *lnn = new ListNode(x);
            if((*lnn)->next == NULL)
            return;
        }
        else{
            ListNode *temp = new ListNode(x);
            ListNode *temp2;
            temp2 = *lnn;
            while(temp2->next != NULL)
                temp2 = temp2->next;
            temp2->next = temp;
            return;
        }
    }
};

//int main()
//{
//    Solution sol,sol1;
//    ListNode *l1,*l2;
//
//    vector<ListNode *> v;
//    ListNode **p1 = &l1,**p2 = &l2;
//    for(auto i = 1; i<=5;i++)
//    {
//        sol.addNode(i, p1);
//        sol1.addNode(2*i, p2);
//    }
//
//    printList(p1);cout<<endl;//ln    ListNode **    0x7ffeefbff550    0x00007ffeefbff550*ln    ListNode *    0x100512360    0x0000000100512360
//    printList(p2);cout<<endl;
////    cout<<"p1:"<<(p1)<<endl;
////    cout<<"&ln:"<<(&l1)<<endl;
////   // cout<<"ln:"<<l1<<endl;
////    //cout<<"ln val:"<<(l1->val)<<endl;
////   // cout<<"ln next:"<<(l2->next)<<endl;
////    //ListNode **temp = &l1;
////    //v.push_back(*p1);
////    //temp = &l2;
////    //v.push_back(*p2);
//    arrayb(v, p1);
//    arrayb(v, p2);
////    for(auto i : v)
////    {
////        cout<<"i : "<<i<<endl;
////        printList(&i);cout<<endl;
////    }
//    ListNode *o = sol.mergeKLists(v);
//    printList(&o);cout<<endl;
//
//    cout<<"hi";
//    return 0;
//}
