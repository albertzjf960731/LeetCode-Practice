/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (44.03%)
 * Likes:    2184
 * Dislikes: 110
 * Total Accepted:    245.5K
 * Total Submissions: 557.5K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 * 
 */

/**
 * Definition for a binary tree node.
 */
#include<vector>
#include<queue>
#include<iostream>
#include<sstream>
using namespace std;

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
		string str;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
            
            if (node==NULL) 
                str += "# ";
            else {
                str += to_string(node->val) + " ";
				q.push(node->left);
				q.push(node->right);
			}
		}
		return str;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		TreeNode* root = NULL;
        
		queue<TreeNode*> q;
		stringstream ss(data);
		string str;

		if (ss>>str && str!="#") {
			root = new TreeNode(stoi(str));
			q.push(root);
		}
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
            
			if (ss>>str && str!="#") {
				node->left = new TreeNode(stoi(str));
				q.push(node->left);
			}
			if (ss>>str && str!="#") {
				node->right = new TreeNode(stoi(str));
				q.push(node->right);
			}
		}
		return root;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:
    // given this freedom of adding any null, would it be possible though, to recover the tree from only inorder or post order 
    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val<< ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else 
            out << "# ";
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if(val=="#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

int main() {
    Codec codec;
    string data{"[1,2,3,null,null,4,5]"};
    cout << codec.deserialize(data);
    
}