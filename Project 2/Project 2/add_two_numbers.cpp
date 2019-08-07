//
//  add_two_numbers.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 6/25/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *op;
    void addNo(ListNode *n1,ListNode *n2,int carryover){
        int sum = 0;int carry = 0;
        //if(n1 != NULL & n2 != NULL)

        if(n1 == NULL)
        {
            sum = n2->val + carryover;
            if(sum >= 10)
            {
                auto div = sum/10; carry = div; //calculating carryover by divinding by 10;
                div = div*10;//need to multiply by 10 to calculate remainder
                auto digit = sum%div;
                addNode(digit);
                if(n2->next == NULL)
                {
                    addNode(carry);
                    return;}
                else
                    addNo(NULL, n2->next, carry);
            }
            else
            {
                addNode(sum);
                if(n2->next == NULL)
                    return;
                else
                    addNo(NULL, n2->next, carry);
            }
            
        }
        else if(n2 == NULL)
        {
            sum = n1->val + carryover;
            if(sum >= 10)
            {
                auto div = sum/10; carry = div; //calculating carryover by divinding by 10;
                div = div*10;//need to multiply by 10 to calculate remainder
                auto digit = sum%div;
                addNode(digit);
                if(n1->next == NULL)
                {addNode(carry);return;}
                else
                    addNo(n1->next, NULL, carry);
            }
            else
            {
                addNode(sum);
                if(n1->next == NULL)
                    return;
                else
                    addNo(n1->next, NULL, carry);
            }
        }
        else
        {
            sum = n1->val + n2-> val + carryover;
        if(sum >= 10)
        {
            
            auto div = sum/10; carry = div; //calculating carryover by divinding by 10;
            div = div*10;//need to multiply by 10 to calculate remainder
            auto digit = sum%div;
            addNode(digit);
            if(n1->next == NULL & n2->next == NULL)
            {
                addNode(carry);
                return;
            }
            else if(n1->next == NULL)
            {
                addNo(NULL, n2->next, carry);
            }
            else if(n2->next == NULL)
            {
                addNo(n1->next, NULL, carry);
            }
            else
                addNo(n1->next, n2->next, carry);
        }
        else
        {
            addNode(sum);
            if(n1->next == NULL && n2->next == NULL)
            {
                return;
            }
            else if(n1->next == NULL)
            {
                addNo(NULL, n2->next, carry);
            }
            else if(n2->next == NULL)
            {
                addNo(n1->next, NULL, carry);
            }
            else
                addNo(n1->next, n2->next, carry);
        }
        }
        
    }
    void addNode(int x)
    {
        if(op == NULL)
        {
            op = new ListNode(x);
            return;
        }
        else{
            ListNode *temp = new ListNode(x);
            ListNode *temp2 = op;
            while(temp2->next != NULL)
                temp2 = temp2->next;
            temp2->next = temp;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        addNo(l1, l2, 0);
        return op;
        
    }
    
};
//int main()
//{
////    Solution sol;
////    vector<int> v = {-1, 0, 1, 2, -1, -4};
////    vector<vector<int>> o = sol.threeSum(v);
////    cout<<endl;
////    for(auto it : o)
////    {
////        cout<<endl;
////        for(auto j = it.begin(); j!=it.end();j++)
////        {
////            cout<<" "<<*j;
////        }
////    }
//
//    //cout<<sizeof(size_t);
//    return 0;
//}
