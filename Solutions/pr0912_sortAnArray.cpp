#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }

    void mergeSort(vector <int>& array){
        int len = array.size();
        if(len <= 1) return;
        int mid = len / 2;
        vector <int> leftArray(mid,0);
        vector <int> rightArray(len - mid,0);

        int i = 0 , j = 0 ;

        for(; i < len ; i++){
             if(i < mid) leftArray[i] = array[i];
             else {
                rightArray[j] = array[i];
                j++;
             }
            }
            mergeSort(leftArray);
            mergeSort(rightArray);
            merge(leftArray , rightArray , array);
    }
    void merge(vector <int> &left , vector <int>& right , vector <int>& array){
        int leftSize = left.size();
        int rightSize = right.size();
        int i = 0 , l = 0 , r = 0;
        while(l < leftSize && r < rightSize){
            if(left[l] < right[r]){
                array[i] = left[l];
                i++;
                l++;
            }
            else{
                array[i] = right[r];
                i++;
                r++;
            }
        }
        while(l < leftSize){
            array[i] = left[l];
            i++;
            l++;
        }
        while(r < rightSize){
            array[i] = right[r];
            i++;
            r++;
        }

    }
};
int main(){
    Solution s;
    vector<int>v= {9,6,3,7,33,77,7,9,5,7,3,6,3,3,8,9,0};
    vector<int>d= s.sortArray(v);
    for(int i : d)
    cout << i << " ";
}