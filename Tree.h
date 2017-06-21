#ifndef TREE_H
#define TREE_H

#include <vector>
#include "Token.h"

struct Node{
    bool leaf = false;
    vector<Node> children;
    Token * myToken;
};

class Tree
{
    public:
        Tree();
        virtual ~Tree();

        bool addNode(string node);
        bool addChildren();
    private:
        Node *root;
};

#endif // TREE_H
