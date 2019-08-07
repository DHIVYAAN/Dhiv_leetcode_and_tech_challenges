//
//  N_th_element_from_list.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 5/21/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = new ListNode(0);
        temp = head;
        if(head->next == nullptr)
        {
            return head->next;
        }
        else if(head == nullptr)
        {
            return nullptr;
        }
        int k = 1;
        while(temp->next != nullptr)
        {
            temp = temp->next;
            k++;
        }
        int pt = k - n;
        if(pt == 0)
        {
            ListNode *temp3 = new ListNode(0);
            temp3 = head;
            head = temp3->next;
            delete temp3;
            
        }
        else if(pt == 1)
        {
            ListNode *temp3 = new ListNode(0);
            temp3 = head->next;
            head->next = head->next->next;
            delete temp3;
            
        }
        else
        {
            pt--;
        temp = head;
        while(pt > 0)
        {
            temp = temp->next;
            pt--;
        }
        ListNode *temp2 = new ListNode(0);
        temp2 = temp->next;
        temp->next = temp->next->next;
        
    }
        return head;
    }
};
//int main()
//{
////    unordered_map<int,int> m;
////    m.insert(200, 1);
//    vector<int> A = {1,2};
//    int k = 1;
////    Solution S;
////    int o = S.subarraysWithKDistinct(A, k);
////    cout<<endl<<o;
//
//
//    return 0;
//}
