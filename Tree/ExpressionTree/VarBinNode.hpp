#ifndef __VAR_BIN_NODE__
#define __VAR_BIN_NODE__
#include <iostream>
using namespace std;
// Node implementation with the composite design pattern
class VarBinNode
{ // Node abstract base class
public:
    virtual ~VarBinNode() {} // Generic destructor
    virtual bool isLeaf() = 0;
    virtual void traverse() = 0;
};
#endif