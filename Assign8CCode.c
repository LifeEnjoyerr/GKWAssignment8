#include <stdio.h>
#include <stdlib.h>

//matrix strucutre
struct Matrix {

	int **mat; //2D matrix
	int length; //matrix length
	int hight; //matrix hight


};

struct Matrix addMatrix(struct Matrix, struct Matrix);
struct Matrix MultMatrixScal(struct Matrix, int);
struct Matrix MultMatrix(struct Matrix, struct Matrix);
struct Matrix transpose(struct Matrix);
struct Matrix createMatrix(int, int);
void displayMatrix(struct Matrix);

int main() {

	return 0;
}


//function to add two matricies and return the result
struct Matrix addMatrix(struct Matrix m1, struct Matrix m2) {
	struct Matrix ans;
	ans.length = m1.length;
	ans.hight = m1.hight;
	

	ans.mat = (int**)calloc(ans.length, sizeof(int*));
	for (int i = 0; i < ans.length; i++) {
		ans.mat[i] = (int*)calloc(ans.hight, sizeof(int));
	}

	for (int i = 0; i < ans.length; i++) { //createing columns
		for (int j = 0; j < ans.hight; j++) { //createing columns
			
			ans.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
		}
	}

	return ans;

}

//function to multiply a matrix and a scalor
struct Matrix MultMatrixScal(struct Matrix m1, int num) {
	struct Matrix ans;
	
	ans.length = m1.length;
	ans.hight = m1.hight;

	ans.mat = (int**)calloc(ans.length, sizeof(int*));
	for (int i = 0; i < ans.length; i++) {
		ans.mat[i] = (int*)calloc(ans.hight, sizeof(int));
	}

	for (int i = 0; i < ans.length; i++) { //increments through the length of the product array
		for (int j = 0; j < ans.hight; j++) { //increments through the hight of the product array
			
			ans.mat[i][j] = m1.mat[i][j] * num; //multiplies given matrix cordinate by scaleor.
			
		}
	}
	return ans;

}

//function to multiply two matricies
struct Matrix MultMatrix(struct Matrix m1, struct Matrix m2) {
	int temp = 0;
	int test;
	struct Matrix ans;
	ans.length = m2.length;
	ans.hight = m1.hight;

	ans.mat = (int**)calloc(ans.length, sizeof(int*));
	for (int i = 0; i < ans.length; i++) {
		ans.mat[i] = (int*)calloc(ans.hight, sizeof(int));
	}

	for (int i = 0; i < m2.length; i++) { //increments through the length of the product array
		for (int j = 0; j < m1.hight; j++) { //increments through the hight of the product array

			for (int k = 0; k < m1.length; k++) { //performs dot product of appropriate rows and columns.
				test = m1.mat[k][i];
				test = m2.mat[j][k];
				temp += m1.mat[k][i] * m2.mat[j][k];
			}
			ans.mat[j][i] = temp;
			temp = 0;
		}
	}
	return ans;

}

//function calculates and returns transpose of given matrix.
struct Matrix transpose(struct Matrix m) {
	struct Matrix ans;
	ans.length = m.hight;
	ans.hight = m.length;

	ans.mat = (int**)calloc(ans.length, sizeof(int*));
	for (int i = 0; i < ans.length; i++) {
		ans.mat[i] = (int*)calloc(ans.hight, sizeof(int));
	}

	for (int i = 0; i < ans.length; i++) { //increments through the length of the new array
		for (int j = 0; j < ans.hight; j++) { //increments through the hight of the new array
			ans.mat[i][j] = m.mat[j][i];
		}
	}
	return ans;

}

//function to create empty matrix.
struct Matrix createMatrix(int len, int hig) {
	struct Matrix a;
	a.length = len;
	a.hight = hig;

	a.mat = (int**)calloc(a.length, sizeof(int*));
	for (int i = 0; i < a.length; i++) {
		a.mat[i] = (int*)calloc(a.hight, sizeof(int));
	}

	return a;

}

//function to display a given matrix
void displayMatrix(struct Matrix m) {

	
	printf("\n\n");
	for (int i = 0; i < m.hight; i++) { //Display Colunmns

		for (int j = 0; j < m.length; j++) { //displays rows
			
			printf("%d   ", m.mat[j][i]);
		}
		printf("\n");
	}

}