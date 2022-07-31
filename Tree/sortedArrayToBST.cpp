/*
Code by:Eeshan Chanpura
Cooded on: 01-06-2022 21:51
*/
#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1) return new TreeNode(nums[0]);
        
        int middle = nums.size()/2;
        TreeNode* root = new TreeNode(nums[middle]);
        
        vector<int> leftInts(nums.begin(), nums.begin()+middle);
        vector<int> rightInts(nums.begin()+middle+1, nums.end());
        
        root->left = sortedArrayToBST(leftInts);
        root->right = sortedArrayToBST(rightInts);
        
        return root;
    }

void display(TreeNode *ans){
    if (ans != NULL)
     {
        display(ans->left);
        cout<<ans->val<<" ";
        display(ans->right);
    }
}

int main(){
    vector<int> nums={1,2,3,4,5};
    TreeNode *ans = sortedArrayToBST(nums);
     
    return 0;
}
