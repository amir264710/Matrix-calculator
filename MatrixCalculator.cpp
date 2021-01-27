#include <iostream>
#include<stdlib.h>
#include<math.h>
#include<iomanip>


using namespace std;

// Global Variables

float MatrixA[100][100];
float MatrixB[100][100];
float TempMatrixB[100][100];
float TempMatrix[100][100];
float Temp_B_Inverse[100][100];
float MultiplyMatrix[100][100];
int MatrixARow;
int MatrixAColumn;
int MatrixBRow;
int MatrixBColumn;
int process;

// Prototype 

void GetMatrixA(); // 1
void GetMatrixB(); // 2
void MatrixAToMatrixB(); // 3
void MatrixBToMatrixA(); // 4
void MatrixAMultiplyByMatrixB(); //5
void MatrixAplusMatrixB(); // 6
//void MatrixADividedByMatrixB(); // 7
void MatrixAminusMatrixB(); // 8
void MarixAMultiplyByNum(); // 9
void Minor(float TempMinorMatrix[100][100], float TempMatrix[100][100], int RowElementPosition, int SizeMatrix); 
// Minor Function Is Auxiliary Function For Calculate Determinant
float Det(float TempMatrix[100][100], int SizeMatrix); // 10 & 11
void ShowMatrixA(); // 12
void ShowMatrixB(); // 13
int menu(); // Menu For Choosing Progress




// Main Function
int main() {
	cout << "Matrix Calculator Version 1.0 All Rights Resevrd";
	cout << endl << "----------------------" << endl << endl;
	menu();
}



//---------------------------------------------------------------------
// 1
void GetMatrixA() {
	cout << "Please Entre Your Matrix A Dimension" << endl;
	cout << "My Matrix Row is: ";
	cin >> MatrixARow;
	cout << "My Matrix Column is: ";
	cin >> MatrixAColumn;
	cout << "Matrix A" << endl;
	for (int i = 0; i < MatrixARow; i++) {
		for (int j = 0; j < MatrixAColumn; j++) {
			cout << "A[" << i + 1 << "]" << "[" << j + 1 << "]:";
			cin >> MatrixA[i][j];
		}
	}
	cout << endl;
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// 2
void GetMatrixB() {
	cout << "Please Entre Your Matrix B Dimension" << endl;
	cout << "My Matrix Row is: ";
	cin >> MatrixBRow;
	cout << "My Matrix Column is: ";
	cin >> MatrixBColumn;
	cout << "Matrix B" << endl;
	for (int i = 0; i < MatrixBRow; i++) {
		for (int j = 0; j < MatrixBColumn; j++) {
			cout << "B[" << i + 1 << "]" << "[" << j + 1 << "]:";
			cin >> MatrixB[i][j];
		}
	}
	cout << endl;

}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// 3
void MatrixAToMatrixB() {
	if (MatrixAColumn == MatrixBColumn && MatrixARow == MatrixBRow) {
		for (int i = 0; i < MatrixARow; i++) {
			for (int k = 0; k < MatrixAColumn; k++) {
				MatrixA[i][k] = MatrixB[i][k];
			}
		}
		cout << "--------------------------" << endl;
		cout << "Matrix A Succesfully Transfare To Matrix B" << endl;
		cout << "--------------------------" << endl;
	}
	else
	{
		cout << "Your Given Matrices Can Not Transfare" << endl;
		cout << "Becuse Their Row and Column Are Not Same" << endl;
		cout << "Please Entre Another Matrices" << endl;
	}
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// 4
void MatrixBToMatrixA() {
	if (MatrixAColumn == MatrixBColumn && MatrixARow == MatrixBRow) {
		for (int i = 0; i < MatrixARow; i++) {
			for (int k = 0; k < MatrixAColumn; k++) {
				MatrixB[i][k] = MatrixA[i][k];
			}
		}
		cout << "--------------------------" << endl;
		cout << "Matrix B ASuccesfully Transfare To Matrix A" << endl;
		cout << "--------------------------" << endl;
	}
	else
	{
		cout << "Your Given Matrices Can Not Transfare" << endl;
		cout << "Becuse Their Row and Column Are Not Same" << endl;
		cout << "Please Entre Another Matrices" << endl;
	}
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// 5
void MatrixAMultiplyByMatrixB() {
	if (MatrixAColumn == MatrixBRow) {
		for (int i = 0; i < MatrixARow; ++i)
			for (int j = 0; j < MatrixBColumn; ++j)
				for (int k = 0; k < MatrixAColumn; ++k)
				{
					MultiplyMatrix[i][j] += MatrixA[i][k] * MatrixB[k][j];
				}
		cout << "--------------------------" << endl;
		cout << "A * B :" << endl;
		for (int i = 0; i < MatrixARow; i++) {
			cout << endl;
			for (int k = 0; k < MatrixBColumn; k++) {
				cout << MultiplyMatrix[i][k] << "  ";
			}
		}
		cout << endl;
		cout << "--------------------------" << endl;
		for (int qe = 0; qe < MatrixARow; qe++) {
			for (int qa = 0; qa < MatrixARow; qa++) {
				MatrixA[qe][qa] = MultiplyMatrix[qe][qa];
			}
		}
	}
	else {
		cout << "Matrix A Can Not Multiply By Matrix B" << endl;
	}
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
//6
void MatrixAplusMatrixB() {
	if (MatrixAColumn == MatrixBColumn && MatrixARow == MatrixBRow) {
		for (int i = 0; i < MatrixARow; i++) {
			for (int k = 0; k < MatrixAColumn; k++) {
				MatrixA[i][k] = MatrixA[i][k] + MatrixB[i][k];
			}
		}
		cout << "--------------------------" << endl;
		cout << "A + B: " << endl;
		for (int i = 0; i < MatrixARow; i++) {
			cout << endl;
			for (int k = 0; k < MatrixAColumn; k++) {
				cout << MatrixA[i][k] << "  ";
			}
		}
		cout << endl;
		cout << "--------------------------" << endl;
		

	}
	else
	{
		cout << "Your Given Matrices Can Not plus";
		cout << "Becuse Theire Row and Column Are Not Same";
		cout << "Please Entre Another Matrices";
	}
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// 7
void MatrixADividedByMatrixB() {
	int i, j, k; double d;
	int n = MatrixBColumn;
	for (int c = 0; c < MatrixBColumn; c++) {
		for (int e = 0; e < MatrixBColumn; e++) {
			TempMatrixB[c][e] = MatrixB[c][e];
		}
	}
	if (Det(TempMatrixB, MatrixBRow) != 0.000) {
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < 2 * n; ++j)
			{
				if (j == (i + n))
				{
					TempMatrixB[i][j] = 1;
				}
			}
		}
		for (i = n; i > 1; --i)
		{
			if (TempMatrixB[i - 1][1] < TempMatrixB[i][1])
			{
				for (j = 0; j < 2 * n; ++j)
				{
					d = TempMatrixB[i][j];
					TempMatrixB[i][j] = TempMatrixB[i - 1][j];
					TempMatrixB[i - 1][j] = d;
				}
			}
		}
		cout << endl;
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < 2 * n; ++j)
			{
				if (j != i)
				{
					d = TempMatrixB[j][i] / TempMatrixB[i][i];
					for (k = 0; k < n * 2; ++k)
					{
						TempMatrixB[j][k] -= TempMatrixB[i][k] * d;
					}
				}
			}
		}
		cout << endl;
		for (i = 0; i < n; ++i)
		{
			d = TempMatrixB[i][i];
			for (j = 0; j < 2 * n; ++j)
			{
				TempMatrixB[i][j] = TempMatrixB[i][j] / d;
			}

		}
		int z = 0, y = 0;
		for (i = 0; i < n; ++i)
		{
			for (j = n; j < 2 * n; ++j)
			{
				Temp_B_Inverse[z][y] = TempMatrixB[i][j];
				y++;
				if (y == n) {
					z++;
					y = 0;
				}

			}
		}
	}
	else {
		cout << "Matrix is not invertable!!";
	}
	
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// 8
void MatrixAminusMatrixB() {
	if (MatrixAColumn == MatrixBColumn && MatrixARow == MatrixBRow) {
		for (int i = 0; i < MatrixARow; i++) {
			for (int k = 0; k < MatrixAColumn; k++) {
				MatrixA[i][k] = MatrixA[i][k] - MatrixB[i][k];
			}
		}
		cout << "--------------------------" << endl;
		cout << "A - B: " << endl;
		for (int i = 0; i < MatrixARow; i++) {
			cout << endl;
			for (int k = 0; k < MatrixAColumn; k++) {
				cout << MatrixA[i][k] << "  ";
			}
		}
		cout << endl;
		cout << "--------------------------" << endl;

	}
	else
	{
		cout << "Your Given Matrices Can Not minus" << endl;
		cout << "Becuse Their Row and Column Are Not Same" << endl;
		cout << "Please Entre Another Matrices" << endl;
	}
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// 9
void MarixAMultiplyByNum() {
	int Number;
	cout << "What Number Do You Want To Multiply In Matrix A ?" << endl;
	cout << "My Number Is :";
	cin >> Number;
	cout << endl;
	for (int i = 0; i < MatrixARow; i++) {
		for (int k = 0; k < MatrixAColumn; k++) {
			MatrixA[i][k] = MatrixA[i][k] * Number;
		}
	}
	cout << "--------------------------" << endl;
	cout << "Matrix A *" << Number  << "is : "<< endl;
	for (int i = 0; i < MatrixARow; i++) {
		cout << endl;
		for (int k = 0; k < MatrixAColumn; k++) {
			cout << MatrixA[i][k] << "  ";
		}
	}
	cout << endl;
	cout << "--------------------------" << endl;

}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// 10 & 11
void Minor(float TempMinorMatrix[100][100], float TempMatrix[100][100], int RowElementPosition, int SizeMatrix) {
	int TempMatrixMinorColumn = 0;
	int TempMatrixMinorRow = 0;
	for (int TempMatrixRow = 1; TempMatrixRow < SizeMatrix; TempMatrixRow++) {
		for (int TempMatrixColumn = 0; TempMatrixColumn < SizeMatrix; TempMatrixColumn++) {
			if (TempMatrixColumn == RowElementPosition) {
				continue;
			}
			TempMinorMatrix[TempMatrixMinorRow][TempMatrixMinorColumn] = TempMatrix[TempMatrixRow][TempMatrixColumn];
			TempMatrixMinorColumn++;
			if (TempMatrixMinorColumn == SizeMatrix - 1) {
				TempMatrixMinorRow++;
				TempMatrixMinorColumn = 0;
			}
		}
	}

}
float Det(float TempMatrix[100][100], int SizeMatrix) {
	float Det_sum = 0;
	float TempMinorMatrix[100][100];
	if (SizeMatrix == 2) {
		Det_sum = TempMatrix[0][0] * TempMatrix[1][1] - TempMatrix[0][1] * TempMatrix[1][0];
		return Det_sum;
	}
	for (int RowElementPosition = 0; RowElementPosition < SizeMatrix; RowElementPosition++) {
		Minor(TempMinorMatrix, TempMatrix, RowElementPosition, SizeMatrix);
		Det_sum += TempMatrix[0][RowElementPosition] * pow(-1, RowElementPosition) * Det(TempMinorMatrix, SizeMatrix - 1);
	}
	return Det_sum;
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// 12
void ShowMatrixA() {
	cout << "--------------------------" << endl;
	cout << "Matrix A: " << endl;
	for (int i = 0; i < MatrixARow; i++) {
		cout << endl;
		for (int k = 0; k < MatrixAColumn; k++) {
			cout << MatrixA[i][k] << "  ";
		}
	}
	cout << endl;
	cout << "--------------------------" << endl;

}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// 13
void ShowMatrixB() {
	cout << "--------------------------" << endl;
	cout << "Matrix B: " << endl;
	for (int i = 0; i < MatrixBRow; i++) {
		cout << endl;
		for (int k = 0; k < MatrixBColumn; k++) {
			cout << MatrixB[i][k] << "  ";
		}
	}
	cout << endl;
	cout << "--------------------------" << endl;

}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// Menu
int menu() {
	while (true) {
		cout << "1.Get Matrix A" << endl;
		cout << "2.Get Matrix B" << endl;
		cout << "3.Matrix A Transfare Matrix B" << endl;
		cout << "4.Matrix B Transfare Matrix A" << endl;
		cout << "5.Matrix A Multiply By Matrix B" << endl;
		cout << "6.Matrix A Plus Matrix B" << endl;
		cout << "7.Matrix A Divided By Matrix B" << endl;
		cout << "8.Matrix A Minus Matrix B" << endl;
		cout << "9.Matrix A Multiply By Number" << endl;
		cout << "10.Calculate Determinant Matrix A" << endl;
		cout << "11.Calculate Determinant Matrix B" << endl;
		cout << "12.Show Matrix A" << endl;
		cout << "13.Show Matrix B" << endl;
		cout << "14.Exit" << endl;
		cout << "Please Enter What You Want" << endl << endl;
		cout << "I Want To Do :";
		cin >> process;
		switch (process) {
		case 1:
			GetMatrixA();
			ShowMatrixA();
			break;
		case 2:
			GetMatrixB();
			ShowMatrixB();
			break;
		case 3:
			MatrixAToMatrixB();
			break;
		case 4:
			MatrixBToMatrixA();
			break;
		case 5:
			MatrixAMultiplyByMatrixB();
			break;
		case 6:
			MatrixAplusMatrixB();
			break;
		case 7:
			if (Det(MatrixB, MatrixBRow) == 0) {
				cout << "Mathmatical Error";
			}
			else {
				MatrixADividedByMatrixB();
				for (int qe = 0; qe < MatrixBRow; qe++) {
					for (int qa = 0; qa < MatrixBRow; qa++) {
						MatrixB[qe][qa] = Temp_B_Inverse[qe][qa];
					}
				}
				if (MatrixAColumn == MatrixBRow) {
					for (int i = 0; i < MatrixARow; ++i)
						for (int j = 0; j < MatrixBColumn; ++j)
							for (int k = 0; k < MatrixAColumn; ++k)
							{
								MultiplyMatrix[i][j] += MatrixA[i][k] * MatrixB[k][j];
							}
					cout << "--------------------------" << endl;
					cout << "A / B :" << endl;
					for (int i = 0; i < MatrixARow; i++) {
						cout << endl;
						for (int k = 0; k < MatrixBColumn; k++) {
							cout << MultiplyMatrix[i][k] << "  ";
						}
					}
					cout << endl;
					cout << "--------------------------" << endl;
				}
				for (int qe = 0; qe < MatrixARow; qe++) {
					for (int qa = 0; qa < MatrixARow; qa++) {
						MatrixA[qe][qa] = MultiplyMatrix[qe][qa];
					}
				}
			}
			break;
		case 8:
			MatrixAminusMatrixB();
			break;
		case 9:
			MatrixAminusMatrixB();
			break;
		case 10:
			if (MatrixAColumn == MatrixARow) {
				cout << "--------------------------" << endl;
				cout << "The Determinant Of Matrix A Is :" << Det(MatrixA, MatrixAColumn) << endl;
				cout << "--------------------------" << endl;
			}
			else {
				cout << "Matrix A Is Not Valid" << endl;
			}
			break;
		case 11:
			cout << "--------------------------" << endl;
			if (MatrixBColumn == MatrixBRow) {
				cout << "The Determinant Of Matrix B Is :" << Det(MatrixB, MatrixBColumn) << endl;
				cout << "--------------------------" << endl;
			}
			else {
				cout << "Matrix B Is Not Valid" << endl;
			}
			break;
		case 12:
			ShowMatrixA();
			break;
		case 13:
			ShowMatrixB();
			break;
		case 14:
			cout << endl;
			cout << "Thanks For Using My Matrix Calculator";
			cout << endl << endl;
			return 0;
			break;
		}

	}



}



