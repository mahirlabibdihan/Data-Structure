#include "SinglyLinkedList.h"
using namespace std;
int main()
{
	SinglyLinkedList list;
	int n;
	cin>>n;
	while(n-->0)
	{
		int tmp;
		cin>>tmp;
		list.push_front(tmp);
	}
	list.display();
}