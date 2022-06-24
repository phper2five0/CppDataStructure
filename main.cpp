#include <iostream>
#include "structure/node.h"

using namespace std;

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::shared_ptr<LinkNode> headPtr = InitLink(array, 10);
    PrintLink(headPtr);
    return 0;
}
