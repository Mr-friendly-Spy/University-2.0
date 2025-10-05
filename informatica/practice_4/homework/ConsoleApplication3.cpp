#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float C;
	float number = 1.0;
	float x;
	float y;
	float R;
	float S;
	cin >> x;
	cin >> y;
	R = sqrt(pow(x, 2) + pow(y, 2)) * sin(x);
	S = pow(exp(number), x / y);
	cout << R << " " << S << endl;
	C = max(R, S);
	cout << C << endl;
	system("pause");
	return 0;
}


