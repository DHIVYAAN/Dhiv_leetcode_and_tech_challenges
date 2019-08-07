//
//  ZigZag.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 5/19/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int l = s.length();
        string o = "";
        if(l == 0)
        {
            return o;
        }
        if(numRows == 1)
        {
            return s;
        }
        vector<string> buf(numRows,"");
        int column = 0;
        int it = 0;
        while(it <= l)
        {
            //if(i <= l)
            column++;
            it = it + numRows;
            if(it <= l)
            column = column +(numRows-2);
            it = it + (numRows -2);
        }

        cout<<endl<<column;
        int k = 0;
        for(int j = 0; j < column; j ++)
        {
            for(int i = 0; i < numRows; i++)
            {
                int c =0 ;
                if(j < (numRows-1))
                    c = (numRows-1)-j;
                else
                {
                    int d = j/(numRows-1);
                    d = d+1;
                    d = d*(numRows-1);
                     c = d-j;
                }
                //int c = abs(numRows - j) -1;
                if((j%(numRows-1)) == 0 && (k < l) )
                {
                    buf[i] += s[k];
                    //buf[i][j] = s[k];
                    k++;
                    
                }
                else if((c == i) && (k < l) )
                {
                    buf[i] += s[k];
                    k++;
                }
                else
                {
                   buf[i] += "";
                }
            }
        }
        for(int i = 0; i < numRows; i++)
        {
            
            o += buf[i];
    }
        return o;
    }
};
//int main()
//{
//    Solution obj;
//    Solution *s;
//   s = &obj;
//    string o = s->convert("PAYPALISHIRING",3);
//               //    cout<<o;"PAYPALISHIRING"
//               //3
//    cout<<endl<<o;
//    return 0;
//}
