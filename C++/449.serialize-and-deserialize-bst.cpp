/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (50.27%)
 * Likes:    997
 * Dislikes: 61
 * Total Accepted:    85.4K
 * Total Submissions: 169.9K
 * Testcase Example:  '[2,1,3]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You just need to ensure that a binary search tree can be serialized to
 * a string and this string can be deserialized to the original tree
 * structure.
 * 
 * The encoded string should be as compact as possible.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 * 
 */
#include<vector>
#include<string>
#include<istream>
#include<sstream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
class Codec {
public:
   // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        
        // istringstream in(data);
        // return deserialize(in);
        istringstream in(data);
        string val;

        vector<int> preorder;
        while (in>>val) 
            preorder.push_back(stoi(val));
        return deserialize(preorder);
    }

private:
    void serialize(TreeNode* root, ostringstream& out) {
        if (root==NULL) return;
        
        out << root->val<< " ";
        serialize(root->left, out);
        serialize(root->right, out);
    }

    int idx_ = 0;
    TreeNode* deserialize(vector<int>& preorder, int bound=INT_MAX) {
        if (idx_==preorder.size() || preorder[idx_]>bound) 
            return NULL;
        
        TreeNode *node = new TreeNode(preorder[idx_++]);
        
        node->left = deserialize(preorder, node->val);
        node->right = deserialize(preorder, bound);
        return node;
    }
    
    // TreeNode* deserialize(istringstream& in) {
    //     string val;
    //     in >> val;
    //     TreeNode* root = new TreeNode(stoi(val));
        
    //     while (in >> val) 
    //         DFS(root, stoi(val));
    //     return root;
    // }
    // void DFS(TreeNode* root, int num) {
    //     if (root->val > num) {
    //         if (root->left==NULL) 
    //             root->left = new TreeNode(num);
    //         else 
    //             DFS(root->left, num);
    //     }
    //     else {
    //         if (root->right==NULL)
    //             root->right = new TreeNode(num);
    //         else 
    //             DFS(root->right, num);
    //     }
    // }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

