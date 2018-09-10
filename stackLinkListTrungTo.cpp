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

bool isOperator(char x){
	return x == '+' || x == '-' || x == '*' || x == '/';
}

int getPriority(char x){
	if (x == '+' || x == '-') return 1;
	if (x == '*' || x == '/') return 2;
	return 0;
}
bool isOperand(char x){
	if ((x > 64 && x<91) || (x>96 && x < 123) || (x>47 && x < 58)) return true;
	return false;
}

string toPostfix(string &A){
	StackList S;
	string result = "";
	for(int i = 0; i < A.size();i++){
		if(A[i] == '('){
			S.push(Stack,A[i]);
		}else if(true){
			return "";
		}
	}
}

//int main(){
//	StackList A;
//	Stack = A.push(Stack, '3');
//	Stack = A.push(Stack, '2');
//	Stack = A.push(Stack, 'a');
//	A.traverse(Stack);
//	system("pause");
//	return 0;
//}
