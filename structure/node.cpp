//
// Created by Phper on 2022/6/24.
//

#include "node.h"

using namespace std;

/**
 * @brief 从数组初始化出一条链表
 * @param array 数组的首指针
 * @param length 数组的长度
 * @return 链表的首指针
 */
std::shared_ptr<LinkNode> InitLink(const int *array, int length) {
    std::shared_ptr<LinkNode> start, tail;
    for (int i = 0; i < length; i++) {
        std::shared_ptr<LinkNode> node = std::make_shared<LinkNode>();
        node->value = array[i];
        if (i == 0) {
            start = node;
            tail = node;
            continue;
        }
        tail->next = node;
        node->pre = tail;
        tail = tail->next;
    }
    return start;
}

/**
 * @brief 根据首指针打印链表
 * @param linkHead 链表首指针
 */
void PrintLink(const std::shared_ptr<LinkNode>& linkHead) {
    if (linkHead == nullptr) {
        return;
    }
    std::cout << linkHead->value;
    std::shared_ptr<LinkNode> tmp = linkHead;
    for (; tmp->next != nullptr;) {
        tmp = tmp->next;
        std::cout << " -> " << tmp->value;
    }
    std::cout << std::endl;
}

/**
 * @brief 根据数组创建一颗二叉排序树
 * @param array 数组的首指针
 * @param length 数组的长度
 * @return 二叉树根节点
 */
std::shared_ptr<TreeNode> InitTree(int *array, int length) {
    if (length < 1) {
        return nullptr;
    }
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>();
    root->value = array[0];
    for (int i = 1; i < length; i++) {
        InsertToTree(root, array[i]);
    }
    return root;
}

/**
 * @brief 将数值插入到一颗二叉排序树中
 * @param root 二叉排序树的根节点
 * @param value 需要插入的值
 */
void InsertToTree(std::shared_ptr<TreeNode>& root, int value) {
    if (root == nullptr) {
        root = make_shared<TreeNode>();
        root->value = value;
        return;
    }
    if (value < root->value) {
        InsertToTree(root->left, value);
    } else {
        InsertToTree(root->right, value);
    }
}

/**
 * @brief 前序遍历输出二叉树
 * @param root 二叉树的根节点
 */
void PrintPreOrderTree(const std::shared_ptr<TreeNode>& root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->value << "  ";
    if (root->left != nullptr) {
        PrintPreOrderTree(root->left);
    }
    if (root->right != nullptr) {
        PrintPreOrderTree(root->right);
    }
}

/**
 * @brief 中序遍历输出二叉树
 * @param root 二叉树的根节点
 */
void PrintMidOrderTree(const std::shared_ptr<TreeNode>& root) {
    if (root == nullptr) {
        return;
    }
    if (root->left != nullptr) {
        PrintMidOrderTree(root->left);
    }
    std::cout << root->value << "  ";
    if (root->right != nullptr) {
        PrintMidOrderTree(root->right);
    }
}
