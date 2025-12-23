#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());   // optional, can remove
        int n = piles.size();
        int low = 1;                        // cannot be 0
        int high = piles[n-1];
        int ans = high;

        while(low <= high){                 // include equality to check final speed
            int mid = low + (high - low)/2;
            if(canEat(mid, piles, h)){
                ans = mid;                  // store current mid as possible answer
                high = mid - 1;             // try smaller speed
            } else {
                low = mid + 1;              // need higher speed
            }
        }

        return ans;
    }

    bool canEat(int speed, vector<int> piles, int h){
        long long hours = 0;                 // use long long for large numbers
        for(auto banana : piles){
            // ceil division ensures leftover bananas count as a full hour
            hours += (banana + speed - 1) / speed;
        }
        return hours <= h;                   
    }
};

