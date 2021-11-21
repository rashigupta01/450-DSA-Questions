// MY SOLUTION - 
// NOTE: no need to have visited matrix, as the visited node's colour would be equal to newColour hence different from current colour
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited (image.size());
        for (int i=0; i<image.size(); i++) {
            visited[i] = vector<bool> (image[0].size(), false);
        }
        
        util (image, sr, sc, newColor, visited);
        return image;
    }
        
    void util(vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<bool>>& visited) {
        int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        visited[sr][sc] = true;
        for (int i=0; i < 4; i++) {
            int newsr = sr + dir[i][0];
            int newsc = sc + dir[i][1];
            
            if (newsr < 0 || newsr >= image.size() || newsc < 0 || newsc >= image[0].size() || visited[newsr][newsc] || image[newsr][newsc] != image[sr][sc]) {
                continue;
            }
            
            util (image, newsr, newsc, newColor, visited);
        }
        
        image[sr][sc] = newColor;
    }
};


// 9 liner code : https://leetcode.com/problems/flood-fill/discuss/109584/Java-9-liner-DFS
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    private void fill(int[][] image, int sr, int sc, int color, int newColor) {
        if (sr < 0 || sr >= image.length || sc < 0 || sc >= image[0].length || image[sr][sc] != color) return;
        image[sr][sc] = newColor;
        fill(image, sr + 1, sc, color, newColor);
        fill(image, sr - 1, sc, color, newColor);
        fill(image, sr, sc + 1, color, newColor);
        fill(image, sr, sc - 1, color, newColor);
    }
}