//
//  test.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 7/10/19.
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
//char maximumOccurringCharacter(string text) {
//    int flag[500] = {};
//    for(auto ch : text)
//    {
//        int j = ch;
//        cout<<ch<<endl;
//        cout<<j<<endl;
//        flag[j]++;
//    }
//    int max = 0;
//    int cch;
//    for(auto i = 0; i <500;++i)
//    {
//        if(flag[i] > max)
//        {
//            cout<<"i:"<<i<<endl;
//            cout<<flag[i]<<endl;
//            cout<<endl<<"m:"<<max;
//            max = flag[i];
//            cch = i;
//            cout<<endl<<"new m:"<<max<<endl;
//        }
//    }
//    char c = cch;
//    return c;
//
//}
//bool vowel(char c)
//{
//    if((c == 'A') || (c == 'E')||(c == 'I')||(c == 'O') || (c == 'U') ||
//       (c == 'a') || (c == 'e')||(c == 'i')||(c == 'o') || (c == 'u')
//       )
//        return true;
//    else
//        return false;
//}
//string reverseVowels(string word) {
//    string o = word;
//    int l = word.length();
//    if(l == 0)
//        return "";
//    if(l == 1)
//        return word;
//
//    int end = l-1;
//    int start = 0;
//    while(start < end)
//    {bool s = false,e = false;
//        while(start < end && (s == false))
//        {
//            s = vowel(word[start]);
//            if(s == false)
//                start++;
//        }
//        if(start == end)
//            break;
//        while(end > start && (e == false))
//        {
//            e = vowel(word[end]);
//            if(e == false)
//                end--;
//        }
//        if(start == end)
//            break;
//        else if((s==true) && (e==true))
//        {
//            char temp = o[start];
//            o[start] = o[end];
//            o[end] = temp;
//            start++;
//            end--;
//        }
//    }
//    return o;
//
//}
//void push(string s, vector<string> &v)
//{
//    auto it = find(v.begin(), v.end(), s);
//    if(it == v.end())
//        v.push_back(s);
//}
//vector<string> PowerSet(string inputStr) {
//    vector<string> o;
//    //o.push_back(inputStr);
//    int l = inputStr.length();
//    if(l == 1)
//    {
//        o.push_back(inputStr);
//        return o;
//    }
//    else if(l ==0)
//    {
//        o.push_back("");
//        return o;
//    }
//    else
//        l = l-1;
//    for(auto i = l; i >=0;--i)
//    {
//        string temp (1,inputStr[i]);
//        vector<string> vt = o;
//        if(!vt.empty())
//        {
//        for(auto ss : vt)
//        {
//            string t = temp+ss;
//            push(t, o);
//        }
//        }
//        push(temp,o);
//    }
//
//    return o;
//}

vector<int> mergeArrays(vector<int> a, vector<int> b) {
    int a_l = a.size(),b_l = b.size();
    cout<<a_l<<b_l<<endl;
    int aa = 0,bb = 0;
    vector<int> c;
    while((a_l > aa) && (b_l > bb))
    {
        if(a[aa] == b[bb])
        {
            c.push_back(a[aa]);
            c.push_back(b[bb]);
            aa++;bb++;
            cout<<aa<<" "<<bb<<endl;
        }
        else if(a[aa] < b[bb])
        {
            c.push_back(a[aa]);
            aa++;
            cout<<aa<<" "<<bb<<endl;
        }
        else {
                
                c.push_back(b[bb]);
                bb++;
                cout<<aa<<" "<<bb<<endl;
            
        }
        
    }
    if( aa == a_l)
    {
        while( bb < b_l)
            c.push_back(b[bb]);
    }
    if(bb == b_l)
    {
        while( aa < a_l)
            c.push_back(a[aa]);
        
    }
    return c;
}
//int main()
//{
//    //string s = reverseVowels("Hello World");
////    char c = maximumOccurringCharacter("hello");
//    vector<int> ss = mergeArrays({1,2,3,4,5}, {2,2,3,4,4});
//    for(auto s : ss)
//    cout<<s<<endl;
//    return 0;
//}



