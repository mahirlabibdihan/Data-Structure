#include "SinglyLinkedList.h"
using namespace std;
int main()
{
	SLL list;
	int n;
	cin>>n;
	while(n-->0)
	{
		int tmp;
		cin>>tmp;
		list.push_back(tmp);
	}
	list.display();
	list.erase(3);
	list.display();
}