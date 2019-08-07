//
//  brackets_probelm.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 5/11/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>


using namespace std;

class Solution {
public:

    vector<string> generateParenthesis(int &n) {
        vector<string> output;
        helper(output,"",0,0,n);
        return output;
    }
    void helper(vector<string> &op,string s, int open, int close, int max)
    {
        if(s.length() == (max*2))
        {
            op.push_back(s);
            return;
        }
        if(open < max)
            helper(op,s+"(",open +1,close,max);
        if(close < open)
            helper(op,s+")",open,close +1,max);
        
    }
        
//    vector<string> helper(int &n)
//        {
//            vector<string> temp_op ={};
//            if(n == 1)
//            {
//                temp_op.push_back("()");
//                return temp_op;
//            }
//            else
//            {
//                int k = n-1;
//                vector<string> tt = helper(k);
//                for(auto i = tt.begin();i!=tt.end();i++)
//                {
//                    string s = *i;
//                    auto l = s.length();
//
//                }
//
//
//        }
};
//class Solution {
//public:
//
//    vector<string> generateParenthesis(int &n) {
//        vector<string> output = helper(n);
//        checkvalid(output);
//        cout<<output.size();
//        return output;
//    }
//    vector<string> helper(int &n)
//    {
//        vector<string> temp_op ={};
//        if(n == 1)
//        {
//            vector<string> temp{"()","(",")"};
//            return temp;
//
//        }
//        else
//        {
//            auto k = n-1;
//            vector<string> temp = helper(k);
//            for(auto i = temp.begin(); i != temp.end(); i++)
//            {
//                vector<string> t ={};
//                t.push_back((*i) + "()");
//                t.push_back("()" + (*i));
//                t.push_back("("+(*i)+")");
//                //t.push_back((*i) + "((");
//                //t.push_back("((" + (*i));
//                t.push_back(")"+(*i)+"(");
//                //t.push_back((*i) + "))");
//                //t.push_back("))" + (*i));
//                t.push_back((*i) + ")(");
//                t.push_back(")(" + (*i));
//                for(string j : t)
//                {
//                    if(find(temp_op.begin(),temp_op.end(),j) == temp_op.end())
//                        temp_op.push_back(j);
//
//                }
//            }
//
//        }
//        return temp_op;
//    }
//    void checkvalid(vector<string> &o)
//    {
//        //
//        for(auto i = o.begin(); i!=o.end(); i++)
//        {
//            string s = *i;
//            auto l = s.length();
//            cout<<endl<<"string:"<<s;
//            bool flag = false;
//            if(s == "()()(")
//            {
//                cout<<"hi";
//            }
//            int count = 0;
//            for(auto j = 0; j<l;j++)
//            {
//                if(s[j] == '(')
//                {
//                    count++;
//                    //cout<<endl<<count;
//                }
//                else
//                {
//                    count--;
//                    //cout<<endl<<count;
//                }
//                if( count < 0 )
//                     flag = true;
//            }
//            cout<<endl<<"end:"<<count;
//
//
//            if ((count != 0) || ((l%2) !=0 ) || (s[0] == ')') || (s[(l-1)] == '(') || (flag == true))
//            {
//                cout<<endl<<"here";
//                o.erase(i);
//                i--;
//                count = 0;
//                if(o.empty())
//                {
//                return;
//                }
//            }
//        }
//    }
//};

//int main()
//{
//    int input = 3;
//    Solution sol;
//    vector<string> op = sol.generateParenthesis(input);
//    cout<<endl;
//    for (auto i : op)
//       cout<<endl<<i;
//    
////   vector<string> v{"hi","bye","said"};
////    auto j = v.begin();
////    v.erase(j);
//    
////    for(auto i = v.begin(); i !=v.end();i++)
////        cout<<(*i);
////    sol.checkvalid(v);
//    
//    
//    return 0;
//}

