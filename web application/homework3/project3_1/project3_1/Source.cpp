#include<Eigen/Dense>
#include<iostream>
using namespace std;
using namespace Eigen;
#include<fstream>
#include<cmath>

int main() {
	int const N = 20;
	int const M = 6;

	VectorXd theta(M);
	VectorXd mean(M);
	RowVectorXd xnew(M);
	MatrixXd S(M,M);
	MatrixXd R(M,M);
	double alpha = 0.005, beta = 11.1;
	double m = 0, var = 0;

	

	//the value of x to be predicted
	double x_new = N+1; 
	double x[N];
	double t[N];
	double result[N + 1];

	//read in
	ifstream data_in("GOOG.txt", ios::in);
	int readNumb = 0;
	if (data_in.is_open()) {
		while (!data_in.eof() && readNumb<N) {
			data_in >> x[readNumb] >> t[readNumb];
			readNumb++;
		}
	}


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (i == j)
				S(i, j) = 1;
			else
				S(i, j) = 0;
		}
		mean(i) = 0;
	}

	S = alpha * S;
	for (int i = 0; i < N; i++) {
		theta(0) = 1;
		for (int k = 1; k < M; k++) {
			theta(k) = theta(k - 1)*x[i];
		}
		mean = mean + theta * t[i];
		S = S + beta * theta*theta.transpose();
	}
	R = S.inverse();
	S = R;

	xnew(0) = 1;
	theta(0) = 1;
	for (int i = 1; i < M; i++) {
		xnew(i) = x_new * xnew(i - 1);
		theta(i) = x_new * theta(i - 1);
	}
	
	
	m = beta * xnew * S*mean;
	var = 1 / beta + xnew * S*theta;
	cout << "Mean: " << m << endl;
	cout << "variance: " << var << endl << endl;
	
	int choice;
	cout << "Would you like to calculate the error ?" << endl
		<< "    Yes: 1       No: (else number)" << endl
		<< "choice: ";
	cin >> choice;
	if (choice == 1) {
		double actual_Value;
		cout << "The actual value of next data is: ";
		cin >> actual_Value;
		cout << "Absolute mean error: " << abs(actual_Value - m) << endl
			<< "Average relative error: " << abs(actual_Value - m) / actual_Value << endl;
	}
	
	
	
	//output the data to "out.txt" file.(N+1 elements)
	for (int i = 0; i < N + 1; i++) {
		for (int j = 1; j < M; j++) {
			xnew(j) = (i+1) * xnew(j - 1);
			theta(j) = (i+1) * theta(j - 1);
		}
		result[i] = beta * xnew * S*mean;
	}

	ofstream data_out("out.txt");
	if (data_out.is_open())
	{
		int y = 0;
		while (y < N+1) {
			data_out << result[y] << endl;
			y++;
		}
	}
	

	system("pause");
	return 0;

}
