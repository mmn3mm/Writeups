#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    
    int Arr[]= {65, 41, 217, 101, 161, 241, 225, 201, 25,9, 147, 19, 161,9, 185, 73, 185, 137, 221, 97, 49, 105, 161, 241, 113, 33, 157, 213, 61, 21, 213};
    string y="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890{}";
    char v1;

    unsigned __int8 v2;
    int C=0;
    string Flag="";
    int RKM=-256;
    for(int j=0; j<29; j++)
    {
        string  x=y;
        for(int i=0; i<x.size(); i++)
        {
            v1 = 2 * (x[i] & 0x55) | (x[i] >> 1) & 0x55;
            v2 = 4 * (v1 & 0x33) | (v1 >> 2) & 0x33;
            x[i] = 16 * v2 | (v2 >> 4);
            x[i]=~x[i];
            int temp=(int)x[i];

            if(x[i]<0)temp^=RKM;

            if(temp==Arr[j])
            {
                C++;
                Flag+=y[i];
                break;
            }
        }

    }
    reverse(Flag.begin(),Flag.end());
    cout<<Flag<<endl;
    return 0;
}
