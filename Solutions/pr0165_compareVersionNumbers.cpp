#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = version1.length();
        int v2 = version2.length();
        
        int j = 0 , i = 0;
       while(i < v1 || j < v2){
         string s1 = "" ,  s2 = "";
         while(i < v1 && version1[i] != '.' ) s1 += version1[i++];
         while(j < v2 && version2[j] != '.' ) s2 += version2[j++];

          int n1 = i <= v1 ? stoi(s1) : 0;
          int n2 = j <= v2 ? stoi(s2) : 0;

          if(n1 > n2) return 1;
          else if (n1 < n2) return -1;
          i++, j++;
       }
       return 0; 
    }
};
int main(){
    Solution s;
    cout << s.compareVersion("1.20.1","1.10.4.5.6");
}