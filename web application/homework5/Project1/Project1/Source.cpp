//name:Tian Zhou
//course:software engineering web application
//data:2018/03/23

#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

double f(double);
void getRandom(double*);

int main()
{
	double x1, x2;
	double f1[4], f2[4];
	double E;
	double n;
	double e;
	double delta_f1, delta_f2;
	double z[4];
	double w[9];  //double w11, w12, w21, w22, w1, w2,w1f1,w1f2,w1z
	double batch[4][3] = { {0,0,0},{0,1,1},{1,0,1},{1,1,0} };

	//create random wij
	getRandom(w);

	//introduction:
	cout << "Introduction:" << endl
		<< "input layer: 1, x1, x2" << endl
		<< "hidden layer: f1, f2" << endl
		<< "output layer: z" << endl
		<< "weight:" << endl
		<< "  w[0]:x1--f1" << endl
		<< "  w[1]:x1--f2" << endl
		<< "  w[2]:x2--f1" << endl
		<< "  w[3]:x2--f2" << endl
		<< "  w[4]:f1--z" << endl
		<< "  w[5]:f2--z" << endl
		<< "  w[6]:1--f1" << endl
		<< "  w[7]:1--f2" << endl
		<< "  w[8]:1--z" << endl << endl;

	//enter the learning rate and target error
	cout << "Please enter the learning rate n: ";
	cin >> n;
	cout << "Please enter the target error: ";
	cin >> e;

	//first run
	E = 0.0;
	for (int i = 0; i < 4; i++) {
		x1 = batch[i][0];
		x2 = batch[i][1];
		f1[i] = f(w[0] * x1 + w[2] * x2 + w[6]);
		f2[i] = f(w[1] * x1 + w[3] * x2 + w[7]);
		z[i] = f(w[4] * f1[i] + w[5] * f2[i] + w[8]);
		E = E + (1.0 / 2.0)*(z[i] - batch[i][2])*(z[i] - batch[i][2]);		
	}
	cout << "the initial weights are: " << endl;
	for (int i = 0; i < 9; i++) {
		cout << "  w[" << i << "]: " << w[i] << endl;
	}
	cout << "the first batch error is : " << E << endl;
	
	//learning
	int count = 0;
	while (E > e) {
		count++;
		E = 0.0;
		for (int j = 0; j < 4; j++) {
			delta_f1 = w[4] * (batch[j][2] - z[j])*z[j] * (1.0 - z[j])*f1[j] * (1.0 - f1[j]);
			delta_f2 = w[5] * (batch[j][2] - z[j])*z[j] * (1.0 - z[j])*f2[j] * (1.0 - f2[j]);
			
			w[0] = w[0] + n * delta_f1*batch[j][0];
			w[1] = w[1] + n * delta_f2*batch[j][0];
			w[2] = w[2] + n * delta_f1*batch[j][1];
			w[3] = w[3] + n * delta_f2*batch[j][1];

			w[4] = w[4] + n * (batch[j][2] - z[j])*z[j] * (1.0 - z[j])*f1[j];
			w[5] = w[5] + n * (batch[j][2] - z[j])*z[j] * (1.0 - z[j])*f2[j];

			w[6] = w[6] + n * delta_f1;
			w[7] = w[7] + n * delta_f2;
			w[8] = w[8] + n * (batch[j][2] - z[j])*z[j] * (1.0 - z[j]);

			x1 = batch[j][0];
			x2 = batch[j][1];
			f1[j] = f(w[0] * x1 + w[2] * x2 + w[6]);
			f2[j] = f(w[1] * x1 + w[3] * x2 + w[7]);
			z[j] = f(w[4] * f1[j] + w[5] * f2[j] + w[8]);
			E = E + (1.0 / 2.0)*(z[j] - batch[j][2])*(z[j] - batch[j][2]);
		}
		//cout << E << "   " << count << endl;

	}

	cout << "the final weights are: " << endl;
	for (int i = 0; i < 9; i++) {
		cout << "  w[" << i << "]: " << w[i] << endl;
	}
	cout << "the final error is : " << E << endl
		<< "the total number of batches: " << count << endl;

	cout << "final result for the batch: {0,0,0},{0,1,1},{1,0,1},{1,1,0} is:" << endl;
	for (int k = 0; k < 4; k++)
	{
		cout << z[k] << endl;
	}
	
	system("pause");
	return 0;
}

double f(double x) 
{
	return 1 / (1 + exp(-x));
}

void getRandom(double* a)
{
	srand(time(NULL));
	for (int i = 0; i < 9; i++) {
		a[i] = rand() % 100 / (double)51 - 1;
	}
}




