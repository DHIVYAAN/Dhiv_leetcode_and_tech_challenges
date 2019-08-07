//
//  Remove_digits.hpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 5/9/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#ifndef Remove_digits_hpp
#define Remove_digits_hpp

#include <stdio.h>
#include <string>
using namespace std;

namespace removedigits {

class RemoveDigits{
public:
    //int length;
    string result ="";
    void RemoveDigitsFunction(string ,int);
    void RemoveDigitsRec(string ,int,string &);
    void checkresult(string &);
    
};
}

#endif /* Remove_digits_hpp */
