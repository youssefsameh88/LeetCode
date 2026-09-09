#include <iostream>
class Solution {
public:
    int lastRemaining(int n) {
       return func(n,1,0);
    }
    int func(int n ,bool removeFirst , bool clock){
        if(n <= 1) return 1;
        if(n == 2 && removeFirst) return 2; 
        if(n == 2 && !removeFirst) return 1; 
        if(n == 3 && removeFirst) return 2;
        clock = !clock;

        if(removeFirst)
             return 2 * func(n/2 , (n/2)%2 || !clock, clock) ;
        
        else
             return 2 * func(n/2 , (n/2)%2 || !clock, clock) -1;
    }
};
