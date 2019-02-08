#include <iostream>
using namespace std;

struct node {
		int x;	//keeps data
		bool isPrime = true;	//keeps is prime or non prime
		bool isNext = false;	// keeps is next number or not
};
bool is_Prime(int n) {
	bool flag = true;
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}
void orthagonal(node array[3][3]) {
	array[0][0].isNext = true;
	int i = 0, j = 0;
	int k = 0;

	while(k < 3) {
	
		bool checkDown = is_Prime(array[++i][j].x);
	if (checkDown == false)				//first checks downwards
		array[i][j].isNext = true;

	else{								//then checks diagonals
		--i;
		bool checkCross = is_Prime(array[++i][++j].x);
		if(checkCross == false)
		array[i][j].isNext = true;
	}
	k++;
	}
}

int sumfunc(node array[3][3]) {
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		//cout << endl;
		for (int j = 0; j < 3; j++) {
			if (array[i][j].isNext == true) {
				cout << array[i][j].x << " > ";
				sum += array[i][j].x;
				//cout << "SUM:" << sum << endl;
			}
		}
	}
	return sum;
}
int main() {
	node array[3][3];	/*{ {1, true, false}, {0, true, false}, {0, true, false},
							{4, true, false}, {8, true, false}, {0, true, false},
							{2, true, false}, {6, true, false}, {9, true, false} };*/
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << "Enter the variable of array[" << i << "]" << "[" << j << "]" << endl;
				cin >> array[i][j].x;
				//array[i][j].isPrime = isPrime(array[i][j].x);
				//cout<<array[i][j].isPrime<<" ";
			}
		}
		orthagonal(array);

		cout << "The matrix: " << endl;
		for (int i = 0; i < 3; i++) {
			cout << endl;
			for (int j = 0; j < 3; j++) {
				if (array[i][j].x == 0)
					cout << " ";
				else if (array[i][j].isNext == true || (i==0 && j==0)|| array[i][j].x==1)
					cout << "*" << array[i][j].x << " ";
				
				else
					cout << array[i][j].x << " ";
			}
		}
		cout << endl;

		int toplam = sumfunc(array);
		cout << "Sum: " << toplam << endl;



}

