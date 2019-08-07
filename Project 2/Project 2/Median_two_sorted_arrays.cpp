//
//  Median_two_sorted_arrays.cpp
//  Project 2
//
//  Created by Dhivyaan S Ramesh on 6/2/19.
//  Copyright © 2019 Dhivyaan S Ramesh. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    float op;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(),l2=nums2.size();
      if(l1 > l2)
      {
          vector<int> temp = nums1;
          nums1 = nums2;
          nums2 = temp;
          int temp2 = l1;l1=l2;l2=temp2;
      }
        int imin = 0, imax = l1, hl = (l1+l2+1)/2;
        while(imin <= imax)
        {
            int i = (imin + imax)/2, j = hl -i;
            if(i < imax && nums1[i] < nums2[j-1])
                imin = i +1;
            else if (i > imin && nums1[i-1] > nums2[j])
                                                  imax = i -1;
            else
            {
                float maxl = 0,minr =0;
                if(i ==0) maxl = nums2[j-1];
                else if(j==0) maxl = nums1[i-1];
                else maxl = (float)max(nums2[j-1],nums1[i-1]);
                if((l1+l2)%2 == 1) return maxl;
                
                if(i == l1) minr = nums2[j];
                else if(j == l2) minr = nums1[i];
                else minr = (float)min(nums2[j],nums1[i]);
                return ((minr+maxl)/2.0);
                
            }
        }
        return 0.0;
        
    }
};
//approach 1
//class Solution {
//public:
//    float op;
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int l1 = nums1.size(),l2=nums2.size();
//        op = util(nums1,nums2,l1,l2);
//        return op;
//    }
//    float util(vector<int>& nums1,vector<int>& nums2,int l1,int l2)
//    {
//        if(l1<=l2)
//            op = findMedianBig(nums1,nums2,l1,l2);
//            else
//            op = findMedianBig(nums2,nums1,l2,l1);
//        return op;
//    }
//    float findMedianBig(vector<int>& nums1,vector<int>& nums2,int l1,int l2)
//    {
//        float o = 0.0;
//        auto m2 = l2/2,m1 = l1/2;
//        if(l1 == 0)
//        {
//            if(l2%2 == 0)
//                o = float((nums2[m2] + nums2[m2 -1]))/2;
//            else
//                o = nums2[m2];
//
//        }
//        else if(l1 == 1)
//        {
//            if(l2 == 1)
//                o = float((nums2[0] + nums1[0]))/2;
//            else if((l2%2) != 0)
//            {
//                if(nums1[0] < nums2[m2-1])
//                    o = (nums2[m2-1] +nums2[m2])/2;
//                else if(nums1[0] > nums2[m2+1])
//                    o = (nums2[m2+1] +nums2[m2])/2;
//                else if( (nums1[0] > nums2[m2-1]) & (nums1[0] < nums2[m2]))
//                    o = (nums1[0]  +nums2[m2])/2;
//                else if( (nums1[0] < nums2[m2+1]) & (nums1[0] > nums2[m2]))
//                    o = (nums1[0]  +nums2[m2])/2;
//            }
//            else{
//                if(nums1[0] < nums2[m2-1])
//                    o = nums2[m2-1];
//                else if(nums1[0] > nums2[m2])
//                    o = nums2[m2];
//                else
//                    o = nums1[0];
//
//            }
//        }
//        else if(l1 == 2)
//        {
//            vector<int> buf;
//            if(l2 == 2)
//            {
//                buf.push_back(nums2[0]);buf.push_back(nums2[1]);buf.push_back(nums1[0]);buf.push_back(nums1[1]);
//                o=Media(buf);
// }
//            else if((l2%2) != 0)
//            {
//                buf.push_back(nums2[m2]);
//                int temp1 = nums2[m2-1];
//                temp1 = max(temp1, nums1[0]);
//                int temp2 = nums2[m2+1];
//                temp2 = min(temp2, nums1[1]);
//                buf.push_back(temp1);buf.push_back(temp2);
//                o = Media(buf);
//            }
//            else
//            {
//                buf.push_back(nums2[m2]);
//                buf.push_back(nums2[m2-1]);
//                int temp1 = nums2[m2-2];
//                temp1 = max(temp1, nums1[0]);
//                int temp2 = nums2[m2+1];
//                temp2 = min(temp2, nums1[1]);
//                buf.push_back(temp1);buf.push_back(temp2);
//                o = Media(buf);
//
//            }
//
//        }
//        else
//        {
//
//            if(nums1[m1] > nums2[m2])
//            {
//                if((nums1.size()%2) != 0)
//                {
//                vector<int> n1(nums1.begin(), nums1.begin() +m1+1);
//                    int n = nums1.size() - n1.size();
//                    vector<int> n2(nums2.begin()+n, nums2.end());
//                    o = util(n1,n2,n1.size(),n2.size());
//                                }
//                else
//                {
//                vector<int> n1(nums1.begin(), nums1.begin() +m1);
//               int n = nums1.size() - n1.size();
//                    vector<int> n2(nums2.begin()+n, nums2.end());
//                    o = util(n1,n2,n1.size(),n2.size());
//
//                }
//
//
//
//            }
//            else
//            {
//
//                 if((nums2.size()%2) != 0)
//                 {
//                vector<int> n2(nums2.begin(), nums2.begin() + m2+1);
//                     int n = nums2.size() - n2.size();
//                     vector<int> n1(nums1.begin() + n, nums1.end());
//                o = util(n1,n2,n1.size(),n2.size());
//                 }
//                else
//                {
//                vector<int> n2(nums2.begin(), nums2.begin() + m2);
//                    int n = nums2.size() - n2.size();
//                    vector<int> n1(nums1.begin() + n, nums1.end());
//                o = util(n1,n2,n1.size(),n2.size());
//                }
//
//
//            }
//
//        }
//        return o;
//}
//    float Media(vector<int> &j)
//    {float oo;
//        sort(j.begin(), j.end());
//        if(j.size() == 4)
//            oo = float((j[2] + j[1]))/2;
//        else
//            oo = j[1];
//        return oo;
//    }
//};
//int main()
//{
//    vector<int> v = {1,2},w ={-1,3};
//    Solution sol;
//    float o = sol.findMedianSortedArrays(v, w);
//    cout<<endl<<o<<endl;
////     vector<int> n1(v.begin(), v.begin() +1+1);
////    //vector<int> n1(v.begin() + 1, v.end());
////    for(auto i : n1)
////        cout<<" "<<i;
//    return 0;
//}

