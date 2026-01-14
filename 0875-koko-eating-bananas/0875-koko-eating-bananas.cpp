#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());   
        int n = piles.size();
        int low = 1;                        
        int high = piles[n-1];
        int ans = high;

        while(low <= high){                
            int mid = low + (high - low)/2;
            if(canEat(mid, piles, h)){
                ans = mid;                  
                high = mid - 1;             
            } else {
                low = mid + 1;           
            }
        }

        return ans;
    }

    bool canEat(int speed, vector<int> piles, int h){
        long long hours = 0;                 
        for(auto banana : piles){
           
           int div=banana/speed;
           hours+=div;
           if(banana%speed!=0) hours++;
        }
        return hours <= h;                   
    }
};

