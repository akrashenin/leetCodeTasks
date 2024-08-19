// https://leetcode.com/problems/same-tree/
#include <iostream>

using namespace std;

#define EQUAL 1
#define NOEQUAL -1
#define NEXTSTEP 0

// Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// res = 1 equal
// res = 0 next step
// res = -1 no equal
int isEqual(TreeNode* p, TreeNode* q)
{
    int iRes;
    if (p->val == q->val)
    {
        if ((p->left == nullptr && q->left == nullptr) && (p->right == nullptr && q->right == nullptr ))
            return EQUAL;
        if ((p->left == nullptr && q->left == nullptr) && (p->right && q->right))
        {
            iRes = isEqual(p->right, q->right);
            if (iRes == EQUAL || iRes == NOEQUAL)
                return iRes;
        }
        if ((p->left && q->left) && (p->right == nullptr && q->right == nullptr))
        {
            iRes = isEqual(p->left, q->left);
            if (iRes == EQUAL || iRes == NOEQUAL)
                return iRes;
        }
        if ((p->left && q->left) && (p->right && q->right))
        {
            iRes = isEqual(p->left, q->left);
            if (iRes == EQUAL || iRes == NOEQUAL)
                return iRes;
            else
                iRes = isEqual(p->right, q->right);
                if (iRes == EQUAL || iRes == NOEQUAL)
                    return iRes;
        }
        return NOEQUAL;
    }
    else return NOEQUAL;
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int iRes = isEqual(p, q);
        if (iRes == EQUAL)
            return true;
        else
            false;
        return false;
    }
private:
    int isEqual(TreeNode* p, TreeNode* q)
    {
        int iRes;
        if (p->val == q->val)
        {
            if ((p->left == nullptr && q->left == nullptr) && (p->right == nullptr && q->right == nullptr))
                return EQUAL;
            if ((p->left == nullptr && q->left == nullptr) && (p->right && q->right))
            {
                iRes = isEqual(p->right, q->right);
                if (iRes == EQUAL || iRes == NOEQUAL)
                    return iRes;
            }
            if ((p->left && q->left) && (p->right == nullptr && q->right == nullptr))
            {
                iRes = isEqual(p->left, q->left);
                if (iRes == EQUAL || iRes == NOEQUAL)
                    return iRes;
            }
            if ((p->left && q->left) && (p->right && q->right))
            {
                iRes = isEqual(p->left, q->left);
                if (iRes == EQUAL || iRes == NOEQUAL)
                    return iRes;
                else
                    iRes = isEqual(p->right, q->right);
                if (iRes == EQUAL || iRes == NOEQUAL)
                    return iRes;
            }
            return NOEQUAL;
        }
        else return NOEQUAL;
    }
};

int main()
{
    std::cout << "It's work!\n";
    Solution sln;
    /* First data
    TreeNode p2(2);
    TreeNode p3(3);
    TreeNode p1(1,&p2,&p3);

    TreeNode q2(2);
    TreeNode q3(3);
    TreeNode q1(1, &q2, &q3);
    */
    /* Second data
    TreeNode p2(2);
    TreeNode p3;
    TreeNode p1(1, &p2, &p3);

    TreeNode q2;
    TreeNode q3(2);
    TreeNode q1(1, &q2, &q3);
    */

    TreeNode p2(2);
    TreeNode p3(1);
    TreeNode p1(1, &p2, &p3);

    TreeNode q2(1);
    TreeNode q3(2);
    TreeNode q1(1, &q2, &q3);

    cout << sln.isSameTree(&p1, &q1);

    //cout << isEqual(&p1, &q1);
    
}
