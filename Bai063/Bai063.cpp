#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);

int DemAm(float[][500], int, int, int);

int main()
{
	float b[500][500];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	int c;
	cout << "\nNhap cot: ";
	cin >> c;

	int kq = DemAm(b, k, l, c);
	cout << "\nSo luong so am tren cot " << c << " la: " << kq;
	return 0;
}

void Nhap(float  a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100.0 + (rand() / (RAND_MAX / (100.0 - (-100.0))));
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(3);
			cout << a[i][j];
		}
		cout << "\n";
	}
}

int DemAm(float a[][500], int m, int n, int c)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[i][c] < 0)
			dem++;
	}
	return dem;
}
