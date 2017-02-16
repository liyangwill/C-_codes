{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;\red38\green38\blue38;\red255\green255\blue255;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural

\f0\fs24 \cf0 /**\
*\cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 Given a singly linked list where elements are sorted in ascending order, \
* convert it to a height balanced BST.\cf0 \cb1 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 \
 * Definition for singly-linked list.\
 * struct ListNode \{\
 *     int val;\
 *     ListNode *next;\
 *     ListNode(int x) : val(x), next(NULL) \{\}\
 * \};\
 */\
/**\
 * Definition for a binary tree node.\
 * struct TreeNode \{\
 *     int val;\
 *     TreeNode *left;\
 *     TreeNode *right;\
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) \{\}\
 * \};\
 */\
class Solution \{\
public:\
    ListNode *list;\
    TreeNode* sortedListToBST(ListNode* head) \{\
        this->list = head;\
        return generate(count(head)); \
    \}\
\
    int count(ListNode *node)\{\
        int size = 0;\
        while (node) \{\
            ++size;\
            node = node->next;\
        \}\
        return size;\
    \}\
    \
    TreeNode *generate(int n)\{\
        if (n == 0)\
            return NULL;\
        TreeNode *node = new TreeNode(0);\
        node->left = generate(n / 2);\
        node->val = list->val;\
        list = list->next;\
        node->right = generate(n - n / 2 - 1);\
        return node;\
    \}\
\};}