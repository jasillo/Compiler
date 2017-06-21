#include "Tree.h"

Tree::Tree()
{
    root =  nullptr;
    actualNode = nullptr;
}

Tree::~Tree()
{
    //dtor
}

void Tree::addRoot(TypeToken t)
{
    root = new struct Node;
    root->token = t;
    actualNode = root;
    root->visited = true;
}

bool Tree::addChildren(vector<TypeToken> *child)
{
    if (!actualNode)
        return false;
    //cout<<" add "<<actualNode->token;
    for (unsigned int i=0; i<child->size(); ++i){
        actualNode->children.push_back(new struct Node);
        actualNode->children.back()->token = child->at(i);
        actualNode->children.back()->father = actualNode;
    }
    updateActualNode();
    return true;
}

void Tree::updateActualNode()
{
    Node *tmp = actualNode;

    if (!childrenNoTerminal(tmp)){
        tmp = tmp->father;
        while (tmp){
            if (childrenNoTerminal(tmp))
                return;
            tmp = tmp->father;
        }
        actualNode = nullptr;
    }
}

bool Tree::childrenNoTerminal(Node *n)
{
    for (int i=0; i<n->children.size(); ++i){
        if (!n->children[i]->visited){
            n->children[i]->visited = true;
            if (n->children[i]->token != vacio){
                actualNode = n->children[i];
                return true;
            }
        }
        n->children[i]->visited = true;
    }
    return false;
}

void Tree::printTree()
{
    cout<<root->token<<endl;
    for (int i=0; i<root->children.size(); ++i)
        printNode(root->children[i],2);
}

void Tree::printNode(Node *n, int level)
{
    string space(level, '-');
    cout<<space<<n->token<<endl;

    for (int i=0; i<n->children.size(); ++i)
        printNode(n->children[i],level+2);
}

bool Tree::addTerminalToken(Token *t)
{
    if (!actualNode)
        return false;
    if (actualNode->token != t->token)
        cout<<"error de token "<<actualNode->token<<" - "<< t->token <<endl;
    actualNode->myToken = t;
    updateActualNode();
    return true;
}

