class BNode
{
public:
	int data;
	BNode* left, * right;
	BNode()
	{
		data = 0;
		left = right = NULL;
	}
	BNode(int data)
	{
		this->data = data;
		left = right = NULL;
	}
	BNode(const BNode& n)
	{
		this->data = n.data;
		left = right = NULL;
		if(n.left)
		{
			this->left = new BNode();
			*this->left = *n.left;
		}
		if(n.right)
		{
			this->right = new BNode();
			*this->right = *n.right;
		}
	}
	~BNode()
	{
		if(left) delete left;
		if(right) delete right;
	}
};
