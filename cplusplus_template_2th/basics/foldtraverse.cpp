#include <iostream>

// define binary tree structure and traverse helpers:
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int i=0) : value(i), left(nullptr), right(nullptr) {
    }
    //...
};

auto left = &Node::left;
auto right = &Node::right;

// traverse tree, using fold expression:
template<typename T, typename... TP>
Node* traverse (T np, TP... paths) {
    return (np ->* ... ->* paths);      // np ->* paths1 ->* paths2 ...
}

template<typename T1, typename... TN>
constexpr bool isHomogeneous (T1, TN...) {
    // return (std::is_same<T1,TN>::value && ...); // since C++17
    return (std::is_same_v<T1,TN> && ...); // since C++17
}

int main()
{
    // init binary tree structure:
    Node* root = new Node{0};
    root->left = new Node{1};
    root->left->right = new Node{2};
    //...
    // traverse binary tree:
    Node* node = traverse(root, left, right);
    std::cout << (node ? node->value : INT_MIN) << std::endl; // must add (), there is a priority; error: reference to overloaded function could not be resolved; did you mean to call it?
    //...
    // judge same type
    std::cout << "isHomogeneous(43, -1, \"hello\") " << isHomogeneous(43, -1, "hello") << std::endl;;
    std::cout << std::boolalpha << "isHomogeneous(\"hello\", \"\", \"world\", \"!\") " << isHomogeneous("hello", "", "world", "!") << std::endl;

}
