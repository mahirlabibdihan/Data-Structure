class BNode
{
public:
	int data;
	BNode* left, * right;
	BNode(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};
