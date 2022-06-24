//
// Created by Phper on 2022/6/24.
//

#ifndef SOLUTION_NODE_H
#define SOLUTION_NODE_H

#include <memory>
#include <iostream>


class Node {
public:
    int value;
};

class TreeNode : public Node {
public:
    TreeNode *left;
    TreeNode *right;
};

class LinkNode : public Node, public std::enable_shared_from_this<LinkNode> {
public:
    std::shared_ptr<LinkNode> pre;
    std::shared_ptr<LinkNode> next;
};

std::shared_ptr<LinkNode> InitLink(const int *array, int length);
void PrintLink(const std::shared_ptr<LinkNode>& linkHead);
LinkNode *InitTree(int *array, int length);


#endif //SOLUTION_NODE_H
