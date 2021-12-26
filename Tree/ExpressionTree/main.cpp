#include "LBinExpressionTree.hpp"
#include "IntlNode.hpp"
#include "LeafNode.hpp"
int main()
{
    LBinExpressionTree<int> *exp = new LBinExpressionTree<int>();
    exp->root = new IntlNode('+');
    ((IntlNode *)exp->root)->setLeft(new LeafNode<int>(10));
    ((IntlNode *)exp->root)->setRight(new IntlNode('-'));
    ((IntlNode *)((IntlNode *)exp->root)->right())->setLeft(new LeafNode<int>(4));
    ((IntlNode *)((IntlNode *)exp->root)->right())->setRight(new LeafNode<int>(6));
    exp->root->traverse();
}