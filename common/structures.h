#pragma once

// Local test-only data structures. LeetCode supplies equivalent definitions
// in its editor, so do not copy these definitions into a submission.
namespace lc {

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int value) : val(value), next(nullptr) {}
    ListNode(int value, ListNode* next_node) : val(value), next(next_node) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* left_node, TreeNode* right_node)
        : val(value), left(left_node), right(right_node) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    explicit Node(int value) : val(value), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int value, Node* left_node, Node* right_node, Node* next_node)
        : val(value), left(left_node), right(right_node), next(next_node) {}
};

}  // namespace lc
