class Solution {
public:
    int mySqrt(int x) 
    {
        int s=0,e=x,ans=-1;
        while(s<=e)
        {
            int mid =s+(e-s)/2;
            long long int pr=(long long)mid*mid;
            if(pr==x)   return mid;
            else if(pr<x)   {ans=mid;s=mid+1;}
            else            e=mid-1;
        }        
        return ans;
    }
};