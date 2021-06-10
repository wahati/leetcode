#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

struct treenode {
    int val;
    treenode *left;
    treenode *right;
    treenode() : val(0), left(nullptr), right(nullptr) {}
    treenode(int x) : val(x), left(nullptr), right(nullptr) {}
    treenode(int x, treenode *left, treenode *right) : val(x), left(left), right(right) {}
};

int depth(treenode*);

int main() {
    treenode* root = new treenode(3);
    root->left = new treenode(9);
    root->right = new treenode(20);
    root->right->left = new treenode(15);
    root->right->right = new treenode(7);
    root->right->left->left = new treenode(9);
    root->right->left->right = new treenode(2);
    cout << depth(root) << endl;
    return 0;
}

int depth(treenode* root) {
    if (root == nullptr) {
        return 0;
    }
    int depth = 1;
    int depthest = 1;
    stack<treenode*> nodestack;
    unordered_set<treenode*> nodeblocked;
    nodeblocked.insert(nullptr);
    while(true) {
        if (nodeblocked.find(root->left) == nodeblocked.end()) {
            nodestack.push(root);
            root = root->left;
            depth++;
        } else if (nodeblocked.find(root->right) == nodeblocked.end()) {
            nodestack.push(root);
            root = root->right;
            depth++;
        } else if (!nodestack.empty()) {
            nodeblocked.insert(root);
            root = nodestack.top();
            nodestack.pop();
            if (depthest < depth) {
                depthest = depth;
            }
            depth--;
        } else {
            return depthest;
        }
    }
}