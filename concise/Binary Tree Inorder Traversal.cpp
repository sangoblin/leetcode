void in_order_traversal_iterative(BinaryTree *root) {
    stack<BinaryTree*> s;
    BinaryTree *current = root;
    while (!s.empty() || current) {
        if (current) {
            s.push(current);
            current = current->left;
        } else {
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
}
