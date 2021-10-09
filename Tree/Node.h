#include <vector>
using namespace std;
class Node
{
public:
	int data;
	vector<Node*> children;
	Node()
	{
		data = 0;
	}
	Node(int data)
	{
		this->data = data;
	}
	void addChild(int data)
	{
		children.push_back(new Node(data));
	}
	Node* getChild(int idx)
	{
		return children.at(idx);
	}
};