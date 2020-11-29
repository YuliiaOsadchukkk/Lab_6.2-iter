#include <iostream>
#include <iomanip>
using namespace std;

void draw_line(int size, const char& c = '-') {
	for (--size; size >= 0; size--)
		cout << c;
	cout << endl;
}

int myrand(const int& min, const int& max) {
	return min > 0 ?
		rand() % (max - min + 1) + min :
		rand() % (abs(min) + max + 1) + min;
}

void full_mass(int* mass, int size, const int* dia) {
	for (--size; size >= 0; size--)
		mass[size] = myrand(dia[0], dia[1]);
}

void draw_mass(const int* mass, const int& size, const int& c_space) {
	draw_line(size * c_space + 2);
	for (int i = 0; i < size; i++)
		cout << "|" << setw(c_space - 1) << mass[i];
	cout << " |" << endl;
	draw_line(size * c_space + 2);
}

double do_stuff(int* mass, int size) {
	unsigned int sum = 0, count = 0;
	for (--size; size >= 0; size--)
		if (mass[size] % 2 != 0) {
			sum += size;
			count++;
		}
	return sum;
}

void main() {
	srand(time(NULL));
	const int c_space = 4; // ������� ���� ��� ���������� �� ���� ������ �������, ��� ����� � �������
	int dia[2]{}, n; // �������, n

	cout << "n = "; cin >> n;
	cout << "dia start = "; cin >> dia[0];
	cout << "dia end = "; cin >> dia[1];

	int* mass = new int[n];

	full_mass(mass, n, dia);
	draw_mass(mass, n, c_space);
	cout << "sum = " << do_stuff(mass, n) << endl;

	delete[] mass;
}
