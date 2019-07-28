#include<iostream>
using namespace std;

int main() {
	int u[15] = {4,5,4,5,7,5,0,0,7,1,2,6,3,6,6};
	int v[15] = {5,4,7,7,5,1,4,2,3,3,7,2,6,0,4};

	//a
	//double w[15] = {0.35,0.35,0.37,0.28,0.28,0.32,0.38,0.26,0.39,0.29,0.34,-1.2,0.52,-1.4,-1.25};
	
	//b
	double w[15] = {0.35,-0.66,0.37,0.28,0.28,0.32,0.38,0.26,0.39,0.29,0.34,0.40,0.52,0.58,0.93};



	
	double dis[8];

	for (int i = 0; i < 8; i++) {
		dis[i] = 100.0;
	}
	dis[5] = 0.0;

	for (int j = 0; j < 8; j++) {
		for (int k = 0; k < 15; k++) {
			if (dis[u[k]] + w[k] < dis[v[k]])
				dis[v[k]] = dis[u[k]] + w[k];
		}
		
		cout << "Loop " << j + 1 << ": " << endl;
		for (int l = 0; l < 8; l++) {
			cout << l << "  " << dis[l] << endl;
		}
		cout << endl;
	}

	system("pause");
	return 0;


}



