//
//  Remove_digits.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 5/9/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include "Remove_digits.hpp"
#include <string>
#include <iostream>

using namespace std;
namespace removedigits{

void RemoveDigits::RemoveDigitsFunction(string str,int n)
{
    //RemoveDigits RD;
    //string result = "";
    RemoveDigitsRec(str,n,RemoveDigits::result);
}
void RemoveDigits::RemoveDigitsRec(string str,int n,string &res)
    {
        int l = (int)str.length();
        cout<<endl<<"length : "<<l;
        if(n == 0)
        {
            res.append(str);
            checkresult(res);
            return;
        }
        if(l <= n)
        {
            checkresult(res);
            return;
        }
        int min = 0;
        for(auto i = 1; i <= n; i++)
        {
            if(str[min] > str[i])
                min = i;
        }
        res.push_back(str[min]);
        cout<<endl<<"pushed : "<<str[min];
        string sub = str.substr(min+1, l-min);
        cout<<endl<<"substring : "<<sub<<" remove digits: "<<(n-min);
        RemoveDigitsRec(sub,n-min,res);
        
        
    }
    void RemoveDigits::checkresult(string &res)
    {
            while(res[0] == '0')
            {
                res.erase(res.begin());
            }
        if(res == "")
         res ="0";
    }
}
