class Node
{
public:
	int data;
	vector<Node*> next;
	Node()
	{
		data = 0;
	}
	Node(int data)
	{
		this->data = data;
	}
	void add(int data)
	{
		children.push_back(new Node(data));
	}
};