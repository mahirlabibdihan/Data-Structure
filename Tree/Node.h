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
	Node(const Node& n)
	{
		this->data = n.data;
		for(int i=0;i<n.children.size();i++)
		{
			this->children.push_back(NULL);
			if(n.children[i])
			{
				*this->children[i] = *n.children[i];
			}
		}
	}
	~Node()
	{
		for(int i=0;i<children.size();i++)
		{
			if(children[i]) delete children[i];
		}
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