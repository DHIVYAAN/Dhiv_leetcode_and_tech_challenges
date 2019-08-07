//
//  Synapse_2d_problem.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 8/3/19.
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


void func(int *iptr,int *optr,int rows,int cols)
{
    int read_array[rows][cols];
    int modified_array[rows][cols];
    int i; int j; //to iterate over array
    int ind = 0;
    
    //below for loop will iterate over input to read into array
    for(i = 0; i < rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            read_array[i][j] = iptr[ind];
            int k = i;
            while(k >= 0)
            {
                int m = j;
                while(m >= 0)
                {
                    if((k==i) & (m == j))
                        modified_array[i][j] = read_array[k][m]; //add the current element
                    
                    else
                        modified_array[i][j] = modified_array[i][j] + read_array[k][m]; //add previous column and row element
                    m--;
                }
                k--;
            }
            optr[ind] = modified_array[i][j];
            ind++;
        }
    }
}
    //the below loops will iterate over input and add preceeding elements to produce output array
//    for(i = 0; i < rows;i++)
//    {
//        for(j=0;j<cols;j++)
//        {
//            int k = i;
//            while(k >= 0)
//            {
//                int m = j;
//                while(m >= 0)
//                {
//                    if((k==i) & (m == j))
//                        modified_array[i][j] = read_array[k][m]; //add the current element
//
//                    else
//                        modified_array[i][j] = modified_array[i][j] + read_array[k][m]; //add previous column and row element
//                    m--;
//                }
//                k--;
//            }
//            optr[ind] = modified_array[i][j];
//            ind++;
//        }
//    }
    

int main() {
    int input[] = {1,3,5,6,2,3,8,10,3,2,1,0,5,4,3,2};
    int output[12];
    int index = 0;
    int *i_ptr = &input[0];
    cout<<"bye";
    func(i_ptr, &output[0], 4, 4);
    cout<<"hi";
    for(int i = 0; i < 4; i++)
    {
        printf("\n");
        for(int j = 0 ; j < 4; j++)
        {
            printf("%d",output[index]);
            printf(" ");
           // cout<<output[index];
            index++;
        }
        
    }
    
    return 0;
}
