#ifndef TREE_H
#define TREE_H

#include <vector>
#include "Token.h"

struct Node{
    bool visited = false;
    TypeToken token;
    Token * myToken = nullptr;
    vector<Node*> children;
    Node * father = nullptr;
};

class Tree
{
    public:
        Tree();
        virtual ~Tree();

        void addRoot(TypeToken node);
        bool addChildren(vector<TypeToken> *child);
        bool addTerminalToken(Token *t);
        void printTree();
    private:
        Node *root;
        Node *actualNode;
        vector<Node*> emptyNodes;
        void updateActualNode();
        bool childrenNoTerminal(Node *n);
        void printNode(Node *n, int level);
};

#endif // TREE_H
