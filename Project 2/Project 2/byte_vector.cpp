//
//  byte_vector.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 6/16/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class bytevector{
private:
    char *bytearray;
    size_t bytesize;
    size_t bytenumber(size_t index);
    char mask(size_t index);
public:
    bytevector(size_t index)
    {
       bytesize = (index+7)/8;
        bytearray = new char[bytesize];
        for(auto i = 0 ;i<bytesize;i++)
            bytearray[i] = 0;
        
    }
    bytevector(const bytevector &)
    {}
    ~bytevector(){};
    void set(size_t index);
    void notset(size_t index);
    void flip(size_t index);

    
};
size_t bytevector::bytenumber(size_t index)
{
    index = index >> 3 ;//divide 8
    return index;
}
char bytevector::mask(size_t index)
{
    size_t shift = index & 0x07; //have to do & with n-1 i.e 8-1
     return 0x01 << shift;
}
void bytevector::set(size_t index)
{
    size_t byteno = bytenumber(index);
    char maskm = mask(index);
    bytearray[byteno] |= maskm;
}
void bytevector::notset(size_t index)
{
    size_t byteno = bytenumber(index);
    char maskm = mask(index);
    bytearray[byteno] |= maskm;
}
//int main()
//{
//    cout<<sizeof(size_t);
//    return 0;
//}
