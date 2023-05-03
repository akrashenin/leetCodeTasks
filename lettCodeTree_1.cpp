/* task condition
https://leetcode.com/problems/same-tree/
*/
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
        //cout << "TreeNode(int x)" << endl;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
        cout << "TreeNode(int x, TreeNode *left, TreeNode *right)" << '\n';
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p->val != q->val)
            return false;
        if(p->left != nullptr && q->left != nullptr)
        {
            if(p->left->val != q->left->val)
                return false;
            if(!isSameTree(p->left, q->left))
                return false;
        }
        if(!(p->left == nullptr) && (q->left == nullptr))
            return false;

        if(p->right != nullptr && q->right != nullptr)
        {
            if(p->right->val != q->right->val)
                return false;
            if(!isSameTree(p->right, q->right))
                return false;
        }
        if(!(p->right == nullptr) && (q->right == nullptr))
            return false;
        return true;
    }
};

int main()
{
    //Example 1
    TreeNode pLeft(2);
    TreeNode pRight(3);
    TreeNode qLeft(2);
    TreeNode qRight(3);
    TreeNode p(1, &pLeft, &qRight);
    TreeNode q(1, &qLeft, &qRight);

    /* Example 2
    TreeNode pLeft(2);
    TreeNode qRight(2);
    TreeNode p(1, &pLeft, nullptr);
    TreeNode q(1, nullptr, &qRight);
    */

    Solution sln;
    cout << sln.isSameTree(&p, &q);
    return 0;
}
