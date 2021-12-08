#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void create(double* a, int n, int l, int h, int i);
double sum(double* a, int n, double s, int i);
void print(double* a, int n, int i);
int max_abs(double* a, int n, double max_a, int max_i, int i);
int min_abs(double* a, int n, double min_a, int min_i, int i);
double dob(double* a, int n, double db, int i, int j);
void Min(double* a, const int size, double& min, int& imin, int j);
void Sort(double* a, const int size, int i);


int main() {
	srand((unsigned)time(NULL));

	int n;
	int l = -10;
	int h = 10;
	double s;
	double dob_;
	int k = 0;

	cout << "n = "; cin >> n;

	double* a = new double[n];

	create(a, n, l, h, 0);

	print(a, n, 0);

	s = sum(a, n, 0, 0);

	dob_ = dob(a, n, 1, min_abs(a, n, abs(a[0]), 0, 0), max_abs(a, n, abs(a[0]), 0, 0));

	Sort(a, n, 0);

	print(a, n, 0);

	cout << endl << "| dob = " << dob_ << " |";
	cout << endl << "| s = " << s << " |";

	return 0;
}

void create(double* a, int n, int l, int h, int i) {
	a[i] = ((((double)rand()) / (double)RAND_MAX) * ((double)h - (double)l)) + (double)l;
	if (i < n - 1)
		create(a, n, l, h, i + 1);
}

double sum(double* a, int n, double s, int i) {
	if (a[i] > 0) {
		s += a[i];
	}

	if (i < n - 1) {
		return sum(a, n, s, i + 1);
	}
	else {
		return s;
	}
}

void print(double* a, int n, int i) {
	cout << setw(7) << setprecision(6) << a[i] << " |";

	if (i < n - 1) {
		print(a, n, i + 1);
	}
	else {
		cout << endl;
	}
}


int max_abs(double* a, int n, double max_a, int max_i, int i) {
	if (abs(a[i]) > max_a) {
		max_a = abs(a[i]);
		max_i = i;
	}

	if (i < n - 1) {
		return max_abs(a, n, max_a, max_i, i + 1);
	}
	else {
		cout << "max_i" << max_i << endl;
		return max_i;
	}
}


int min_abs(double* a, int n, double min_a, int min_i, int i) {
	if (abs(a[i]) < min_a) {
		min_a = abs(a[i]);
		min_i = i;
	}

	if (i < n - 1) {
		return min_abs(a, n, min_a, min_i, i + 1);
	}
	else {
		cout << "min_i" << min_i << endl;
		return min_i;
	}
}


double dob(double* a, int n, double db, int i, int j) {
	if (i > j) {
		int tmp = i;
		i = j;
		j = tmp;
	}
	else if (abs(i - j) == 1) {
		return db;
	}

	db *= a[i + 1];

	if (i < j - 2) {
		return dob(a, n, db, i + 1, j);
	}
	else {
		return db;
	}
}

void Min(double* a, const int size, double& min, int& imin, int j) {
	if (min < a[j])
	{
		min = a[j];
		imin = j;
	}
	if (j < size - 1)
		Min(a, size, min, imin, j + 1);
}

void Sort(double* a, const int size, int i) {
	double min = a[i];
	int imin = i;
	Min(a, size, min, imin, i + 1);
	a[imin] = a[i];
	a[i] = min;
	if (i < size - 2)
		Sort(a, size, i + 1);
}
