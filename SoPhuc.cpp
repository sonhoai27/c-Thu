#include "iostream"
#include <stdio.h>
#include "./mylib.h"
using namespace std;

class COMPLEX {
	private:
		int Re, Im; 
	public: 
		COMPLEX(int re = 0, int im = 0){
			Re = re; Im = im;
		}
		void display();
		COMPLEX& operator+ (COMPLEX &complex);
		COMPLEX& operator- (COMPLEX &complex);
		COMPLEX& operator! ();
		~COMPLEX();
};
void COMPLEX::display() {
	cout<<Re<<(Im < 0 ? "" : "+")<<Im<<"i"<<endl;
}
COMPLEX::~COMPLEX() {
}
COMPLEX& COMPLEX::operator+ (COMPLEX &cp) {
	COMPLEX tempCP(this->Re+cp.Re,this->Im+cp.Im);
	return tempCP;
}
COMPLEX& COMPLEX::operator- (COMPLEX &cp) {
	COMPLEX tempCP(this->Re-cp.Re,this->Im-cp.Im);
	return tempCP;
}
COMPLEX& COMPLEX::operator! () {
	COMPLEX tempCP(this->Re,this->Im*(-1));
	return tempCP;
}
class Matrix {
	private: 
	int ROW, COL;
	int** M;
	public: 
	Matrix(int row = 0, int col = 0);
	int operator() (int i, int j);
	void getMatrix(int row, int col);
	void putMatrix(int row, int col);
	Matrix& operator+ (Matrix &mt);
	Matrix& operator- (Matrix &mt);
	Matrix& operator* (Matrix &mt);
	~Matrix();
};
Matrix::Matrix(int row, int col) {
	ROW = row;
	COL = col;
	M = new int *[ROW];
	for(int i = 0; i < ROW; i++){
		M[i] = new int[COL];
	}
}
Matrix::~Matrix() {
	delete [] M;
	for(int i = 0; i < ROW; i++){
		delete [] M[COL];
	}
}
Matrix& Matrix::operator+ (Matrix &mt) {
	for(int i = 0; i < ROW; i++){
		
	}
}
void Matrix::getMatrix(int row, int col) {
	gotoxy(10,2);
	cout<<"NHAP MA TRAN: "<<endl;
	gotoxy(10,4);
	int y = 4;
	for(int i = 0; i < row; i++) {
		int x = 6;
		for(int j = 0; j < col; j++) {
			x = x + 4;
			gotoxy(x, y + 2 + i);
			cin>>M[i][j];
		}
		y = y + 1;
	}
}
void Matrix::putMatrix(int row, int col) {
	gotoxy(70,2);
	cout<<"IN MA TRAN: "<<endl;
	gotoxy(70,4);
	int y = 4;
	for(int i = 0; i < row; i++) {
		int x = 74;
		for(int j = 0; j < col; j++) {
			x = x + 4;
			gotoxy(x, y + 2 + i);
			cout<<M[i][j];
		}
		y = y + 1;
	}
}
int main(){
//	COMPLEX complex(2, -2), complex2(1, -1);
//	complex.display();
//	(complex + complex2).display();
//	complex.display();
	mt.getMatrix(5,5);
	mt.putMatrix(5,5);
	cout<<endl<<endl;
	system("pause");
	return 0;
}
