#include "iostream"
using namespace std;

class ARRAY{
	private:
		float *v;
		int n;
	public:
		ARRAY(int N, float a = 0){
			this->n = N;
			v = new float[this->n];
			for(int i = 0; i < this->n;i++) v[i] = a;
		}
		ARRAY(const ARRAY& a){
			this->n = a.n;
			v = new float[n];
			for(int i = 0; i < a.n; i++) v[i] = a.v[i];
		}
		int get(float *&V){
			V = v; return this->n;
		}
		void outPut(){
			for(int i = 0; i< this->n;i++) cout<<v[i]<<" ";
			cout<<endl;
		}
		void inPut(){
			for(int i = 0; i< this->n;i++){
				cout<<"Number "<<i<<": "; cin>>v[i];
			}
		}
		
};

int main(){
	ARRAY A(10);
	A.inPut();
	A.outPut();
	int N;
	float *V;
	N = A.get(V);
	cout<<"Local N: "<<N<<endl;
	cout<<"V: ";
	for(int i = 0; i < N;i++) cout<<V[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}
