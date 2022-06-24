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
