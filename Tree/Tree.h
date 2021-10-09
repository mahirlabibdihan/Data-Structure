#include "Node.h"
using namespace std;
class Tree
{
	Node* root;
public:
	Tree()
	{
		root = NULL;
	}
	Tree(const Tree& t)
	{
		if (t.root)
		{
			this->root = new Node(*t.root);
		}
		else
		{
			this->root = NULL;
		}
	}
	~Tree()
	{
		if (root) delete root;
	}
};

// Driver code
int main()
{
	Tree t;
	return 0;
}
