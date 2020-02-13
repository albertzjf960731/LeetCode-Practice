/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 *
 * https://leetcode.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (52.91%)
 * Likes:    745
 * Dislikes: 146
 * Total Accepted:    86.7K
 * Total Submissions: 163.7K
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * 
 * An image is represented by a 2-D array of integers, each integer
 * representing the pixel value of the image (from 0 to 65535).
 * 
 * Given a coordinate (sr, sc) representing the starting pixel (row and column)
 * of the flood fill, and a pixel value newColor, "flood fill" the image.
 * 
 * To perform a "flood fill", consider the starting pixel, plus any pixels
 * connected 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connected 4-directionally to those pixels
 * (also with the same color as the starting pixel), and so on.  Replace the
 * color of all of the aforementioned pixels with the newColor.
 * 
 * At the end, return the modified image.
 * 
 * Example 1:
 * 
 * Input: 
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: 
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels
 * connected 
 * by a path of the same color as the starting pixel are colored with the new
 * color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally
 * connected
 * to the starting pixel.
 * 
 * 
 * 
 * Note:
 * The length of image and image[0] will be in the range [1, 50].
 * The given starting pixel will satisfy 0  and 0 .
 * The value of each color in image[i][j] and newColor will be an integer in
 * [0, 65535].
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor) return image;
        DFS(image, image[sr][sc], newColor, sr, sc);
        return image;
    }
    void DFS(vector<vector<int>>& image, int pixel, int newColor, int i, int j) {
        if (i<0 || i==image.size() || j<0 || j==image[0].size() || image[i][j]!=pixel) 
            return;
        // cout << i << " " << j << endl;
        image[i][j] = newColor;
        DFS(image, pixel, newColor, i-1, j);
        DFS(image, pixel, newColor, i+1, j);
        DFS(image, pixel, newColor, i, j-1);
        DFS(image, pixel, newColor, i, j+1);
    }
};
// @lc code=end

