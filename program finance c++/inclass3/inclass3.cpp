//inclass3.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/09/23
//Example:Tally up the number of votes each candidate received and pronounces a winner.

#include<iostream>;
using namespace std;

int main() {

	//initialize variables in declarations
	int c[5] = { 0 };     //Using arrays to show 5 candidates' vote
	int votenumber;       //votenumber is the number of candidates that voters vote to
	int i;                //integer used in the for loop

	cout << "Please enter the number of candidate you will vote for:\n";

	//Using for loop to enter 20 numbers of vote
	for (i = 1; i <= 20; i++) {
		//guide the voter to enter the number of candidates
		cout << "Enter the No." << i << " candidate's number (1-5): ";
		cin >> votenumber;
		//Using while loop to let the voter modify there wrong number
		while (votenumber > 5 || votenumber < 1) {
			cout << "Please enter the number from 1 to 5. \n";
			cout << "Enter the No." << i << " number: ";
			cin >> votenumber;
		}
		c[votenumber - 1] = c[votenumber - 1] + 1;  //count the number of vote
	}

	//Using for loop to show the result of vote
	for (i = 0; i < 5; i++) {
		cout << "No." << i + 1 << " candidate: " << c[i] << endl;
	}

	//Using for loop to find out who is at the head of the poll
	int max = c[0];    //initialize the maximum number
	int N;             //c[N] is the maximum of c arrays
	for (i = 0; i < 5; i++) {
		if (c[i] > max)
			max = c[i], N = i;
	}

	//Using for loop and "if" to find out if there are more than 1 people who have the same highest vote counts
	int count = 0;     //initialize the count number of repetition
	for (i = 0; i < 5; i++) {
		if (c[i] == max)
			count++;
	}

	//Using "if" to decide which kind of output we will use
	if (count == 1)    //there are only 1 people who have the highest vote count
		cout << "The No." << N + 1 << " candidate have the highest vote count who gets " << max << " votes." << endl;
	else               //there are more than 1 people who have the same highest vote counts

		cout << "There is no winner." << endl;

	system("pause");

	return (0);
}