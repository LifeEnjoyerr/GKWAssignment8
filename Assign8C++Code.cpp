
#include <iostream>

using namespace std;

class Matrix {

public: //functions listed below, descriptions listed where the functions are defined.
	Matrix(); 
	Matrix(int** m, int len, int hig); 
	~Matrix(); 
	Matrix operator+(const Matrix& m1);
	Matrix operator*(const Matrix& m1);
	Matrix operator*(int num);
	Matrix transpose();
	void setMatrix(int** m, int len, int hig);
	void displayMatrix();
	void clear();


private:
	int** matrix; //2D array to hold a given matrix
	int length; //integer to store length of array.
	int hight; //integer to store hight of array.


};

//despite being a library, I left in the main function for ease of use when testing my code, should the graders want it.
int main() {

	
	return 0;

}


//default constructor.
Matrix::Matrix() {
	matrix = nullptr;
	length = 0;
	hight = 0;
}

//constructor that takes predefined matrix.
Matrix::Matrix(int** m, int len, int hig) {
	matrix = m;
	length = len;
	hight = hig;
}

//destructor for the object.
Matrix::~Matrix() {
	if (matrix != nullptr) {
		for (int i = 0; i < length; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

//clears the given object.
void Matrix::clear() {
	if (matrix != nullptr) {
		for (int i = 0; i < length; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

//overloads + operator for matrix addition.
Matrix Matrix::operator+(const Matrix& m1) {
	
	int** ans = new int* [length]; //dynamicly allocate array
	for (int i = 0; i < length; i++) { //createing columns
		ans[i] = new int[hight];
	}

	for (int i = 0; i < length; i++) { //createing columns
		for (int j = 0; j < hight; j++) { //createing columns
			ans[i][j] = this->matrix[i][j] + m1.matrix[i][j];
		}
	}

	return Matrix(ans, length, hight);
}

//overloads the * operator for matrix/matrix multiplication.
Matrix Matrix::operator*(const Matrix& m2) {
	int temp = 0;
	int** ans = new int* [m2.length]; //dynamicly allocate array for answer to return.
	for (int i = 0; i < m2.length; i++) { //createing columns
		ans[i] = new int[hight];
	}

	for (int i = 0; i < m2.length; i++) { //increments through the length of the product array
		for (int j = 0; j < hight; j++) { //increments through the hight of the product array
			
			for (int k = 0; k < length; k++) { //performs dot product of appropriate rows and columns.
				temp += matrix[k][i] * m2.matrix[j][k];
			}
			ans[j][i] = temp;
			temp = 0;
		}
	}

	return Matrix(ans, m2.length, hight);
}

//overloads the * operator for scalor/matrix multiplication.
Matrix Matrix::operator*(int num) {
	int** ans = new int* [length]; //dynamicly allocate array
	for (int i = 0; i < length; i++) { //createing columns
		ans[i] = new int[hight];
	}

	for (int i = 0; i < length; i++) { //increments through the length of the product array
		for (int j = 0; j < hight; j++) { //increments through the hight of the product array
			ans[i][j] = matrix[i][j] * num; //multiplies given matrix cordinate by scaleor.
		}
	}
	return Matrix(ans, length, hight);
}

//function that returns the transpose of the matrix object it is called on.
Matrix Matrix::transpose() {

	int** mat2;
	int h2 = length;
	int l2 = hight;

	mat2 = new int* [l2]; //dynamicly allocate array
	for (int i = 0; i < l2; i++) { //createing columns
		mat2[i] = new int[h2];
	}

	for (int i = 0; i < l2; i++) { //increments through the length of the new array
		for (int j = 0; j < h2; j++) { //increments through the hight of the new array
			mat2[i][j] = matrix[j][i];
		}
	}
	return Matrix(mat2, l2, h2);
}

//function to set the 2D array to a new array for the object.
void Matrix::setMatrix(int** m, int len, int hig) {
	length = len;
	hight = hig;
	matrix = m;

}


void Matrix::displayMatrix() {
	int j = 0;
	cout << endl << endl;
	for (int i = 0; i < hight; i++) { //Display Colunmns

		for (int j = 0; j < length; j++) { //displays rows
			cout << matrix[j][i] << "  ";
		}
		cout << endl;
	}
}