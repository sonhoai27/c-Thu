#include "iostream"
#include <stdio.h>
#include "./mylib.h"
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
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
	int **M;
	public: 
	Matrix(int row = 0, int col = 0);
//	~Matrix();
	int operator() (int i, int j){
		return M[i][j];
	}
	void getMatrix(int row, int col);
	void putMatrix(int row, int col);
	Matrix& operator+ (Matrix &mt);
	Matrix& operator- (Matrix &mt);
	Matrix& operator* (Matrix &mt);
	friend ostream& operator<< (ostream &os, Matrix &a);
};
Matrix::Matrix(int row, int col) {
	ROW = row;
	COL = col;
	M = new int *[ROW];
	for(int i = 0; i < ROW; i++){
		M[i] = new int[COL];
	}
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			M[i][j] = 0;
		}
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
	cout<<"AA";
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
Matrix& Matrix::operator+ (Matrix &mt) {
	if(COL != mt.COL || ROW != mt.ROW){
		cout<<"2 ma tran không cung row va col!"<<endl;
	}else {
		Matrix matrix(ROW, COL);
		for(int i = 0; i < ROW; i++){
			for(int j = 0; j < COL; j++){
				matrix.M[i][j] = M[i][j]+ mt.M[i][j];
			}
		}
		return matrix;
	}
}
Matrix& Matrix::operator- (Matrix &mt) {
	if(COL != mt.COL || ROW != mt.ROW){
		cout<<"2 ma tran không cung row va col!"<<endl;
	}else {
		Matrix matrix(ROW, COL);
		for(int i = 0; i < ROW; i++){
			for(int j = 0; j < COL; j++){
				matrix.M[i][j] = M[i][j] - mt.M[i][j];
			}
		}
		return matrix;
	}
}
Matrix& Matrix::operator* (Matrix &mt) {
	if(COL != mt.ROW){
		cout<<"2 ma tran không cung row va col!"<<endl;
	}else {
		Matrix matrix(ROW, mt.COL);
		for(int i = 0; i < ROW; i++){
			for(int j = 0; j < mt.COL; j++){
				matrix.M[i][j] = 0;
				for(int z = 0; z < COL;z++){
					matrix.M[i][j] +=  M[i][z]*mt.M[z][j];
				}
			}
		}
		return matrix;
	}
}
//Matrix::~Matrix() {
////	for(int i = 0; i < ROW; i++){
////		delete []M[COL];
////	}
////	delete []M;
//}
int main(){
//	COMPLEX complex(2, -2), complex2(1, -1);
//	complex.display();
//	(complex + complex2).display();
//	complex.display();
	Matrix mt(2,2), mt2(2,3), mt1;
	mt.getMatrix(2,2);
	mt2.getMatrix(2,3);
	(mt * mt2).putMatrix(2,3);
	cout<<endl<<endl;
	system("pause");
	return 0;
}
