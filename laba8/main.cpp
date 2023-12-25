#include "stack.h"
#include <iostream>

int main() {
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    Stack<int> stack2;
    stack2.push(1);
    stack2.push(2);

    if (stack1 < stack2) {
        std::cout << "Stack 1 is smaller than Stack 2" << std::endl;
    } else if (stack1 == stack2) {
        std::cout << "Stack 1 is equal to Stack 2" << std::endl;
    } else {
        std::cout << "Stack 1 is greater than Stack 2" << std::endl;
    }

    try {
        int item = stack1.pop();
        std::cout << "Popped item: " << item << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Element at index 1 in Stack 1: " << stack1[1] << std::endl;

    return 0;
}
