#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int initColor = 0;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        initColor = image[sr][sc];
        dfs(image,sr,sc,color);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color){
        if(sr < 0 || sc < 0 || sr >= image.size() || 
        sc >= image[0].size() || image[sr][sc] != initColor) return;
        image[sr][sc] = color;
        dfs(image,sr+1,sc,color);
        dfs(image,sr-1,sc,color);
        dfs(image,sr,sc+1,color);
        dfs(image,sr,sc-1,color);
    }
};
