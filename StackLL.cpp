#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

struct node
{
	char info;
	struct node *link;
}* Stack;

class StackList {
	public:
		node *push(node *, char);
		node *pop(node *);
		void traverse(node *);
				StackList(){
			Stack = NULL;
		}
};

node *StackList::push(node *Stack, char item){
	node *tmp;
	tmp = new (struct node);
	tmp->info = item;
	tmp->link = Stack;
	Stack = tmp;
	return Stack;
}

node *StackList::pop(node *Stack){
	node *tmp;
	if(Stack == NULL){
		cout<<"NULL\n";
	}else {
		tmp = Stack;
		cout<<"Delete: "<<tmp->info<<endl;
		Stack = Stack->link;
		free(tmp);
	}
	return Stack;
}
void StackList::traverse(node *Stack){
	node *ptr;
	ptr = Stack;
	if(Stack == NULL){
		cout<<"NULL\n";
	}else {
		cout<<"Content: ";
		while(ptr != NULL){
			cout<<ptr->info<<"-";
			ptr = ptr->link;
		}
	}
}
