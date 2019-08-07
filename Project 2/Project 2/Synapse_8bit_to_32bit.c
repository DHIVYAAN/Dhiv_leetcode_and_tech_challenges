//
//  Synapse_8bit_to_32bit.c
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 8/3/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
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
                    m--; //decrement column
                }
                k--; //decreemnt row
            }
            optr[ind] = modified_array[i][j];
            ind++;
        }
    }
}
