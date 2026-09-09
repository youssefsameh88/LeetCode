#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string real1 = "" , real2 = "";
        string imag1 = "" , imag2 = "";
        vector <int> v;
        
        int i,j;
        for( i = 0 ;num1[i] != '+' ; i++)
                real1 += num1[i];
        for( j = 0 ;num2[j] != '+' ; j++)
                real2 += num2[j];

                i++;
                j++;

        for(;num1[i] != 'i' ; i++)
                imag1 += num1[i];
        for(;num2[j] != 'i' ; j++)
                imag2 += num2[j];

        v.push_back(stoi(real1));
        v.push_back(stoi(imag1));
        v.push_back(stoi(real2));
        v.push_back(stoi(imag2));
        return(to_string(v[0]*v[2] - v[1]*v[3]) + '+' + to_string(v[0]*v[3] + v[2]*v[1]) + 'i');
    }
};