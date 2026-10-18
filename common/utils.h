#pragma once

#include "structures.h"

#include <initializer_list>
#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

namespace lc {

inline ListNode* make_list(std::initializer_list<int> values) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    return dummy.next;
}

inline void delete_list(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

inline TreeNode* make_tree(const std::vector<std::optional<int>>& values) {
    if (values.empty() || !values[0].has_value()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(*values[0]);
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    std::size_t index = 1;

    while (!nodes.empty() && index < values.size()) {
        TreeNode* parent = nodes.front();
        nodes.pop();

        if (values[index].has_value()) {
            parent->left = new TreeNode(*values[index]);
            nodes.push(parent->left);
        }
        ++index;

        if (index < values.size() && values[index].has_value()) {
            parent->right = new TreeNode(*values[index]);
            nodes.push(parent->right);
        }
        ++index;
    }
    return root;
}

inline void delete_tree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

template <typename T>
inline void print_vector(const std::vector<T>& values, const std::string& name = "") {
    if (!name.empty()) {
        std::cout << name << " = ";
    }
    std::cout << '[';
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << values[i];
    }
    std::cout << "]\n";
}

inline void print_list(const ListNode* head, const std::string& name = "") {
    if (!name.empty()) {
        std::cout << name << " = ";
    }
    std::cout << '[';
    for (const ListNode* node = head; node != nullptr; node = node->next) {
        if (node != head) {
            std::cout << ", ";
        }
        std::cout << node->val;
    }
    std::cout << "]\n";
}

}  // namespace lc
