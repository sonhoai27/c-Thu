#include "iostream"
#define MAX 200
using namespace std;
class MyStack {
	private:
		int data[MAX];
		int top;
	public:
		MyStack();
		int Push(int); // them vao 1 gia tri, tr ket qua dung sai
		int Pop(int &); // tra ve dung hay sai, va 1 gia tri lay ra
		int Empty(); // co rong hay khong
		int Full(); // co day hay khong
		void Traverse();
		~MyStack();
};
MyStack::MyStack(){
	this->top = -1;
}
MyStack::~MyStack(){
	
}
int MyStack::Empty(){
	if(this->top == -1){
		return 1;
	}
	return 0;
}
int MyStack::Full(){
	if(this->top == MAX){
		return 1;
	}
	return 0;
}
int MyStack::Push(int number){
	if(this->Full() == 0){
		this->data[++top] = number;
		return 1;
	}
	return 0;
}
int MyStack::Pop(int &result){
	if(this->top == -1){
		return 0;
	}else {
		--this->top;
		return 1;
	}
}
void MyStack::Traverse(){
	int i = this->top;
	while(i>=0){
		cout<<this->data[i]<<"-";
		i--;
	}
}
int main(){
	int result = 0;
	int soNguyen = 0;
	MyStack stack;
	
	cout<<"Nhap vao so: "<<endl;
	cin>>soNguyen;
	
	int temp = soNguyen;
	while(temp>0){
		if(temp%2 == 0){
			stack.Push(0);
		}else {
			stack.Push(1);
		}
		temp = temp/2;
	}
	stack.Traverse();
	system("pause");
	return 0;
}
