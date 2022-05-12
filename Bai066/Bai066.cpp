#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);

int DemDuongBien(float[][500], int, int);

int main()
{
	float b[500][500];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	int kq = DemDuongBien(b, k, l);
	cout << "\nSo luong so duong tren bien cua ma tran la: " << kq;
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
int DemDuongBien(float a[][500], int m, int n)
{
	int dem = 0;
	for (int j = 0;j <= n - 2;j++)
		if ((a[0][j]) > 0)
			dem++;
	for (int i = 0;i <= m - 2;i++)
		if ((a[i][n - 1]) > 0)
			dem++;
	for (int j = n - 1;j >= 1;j--)
		if ((a[m - 1][j]) > 0)
			dem++;
	for (int i = m - 1;i >= 1;i--)
		if ((a[i][0]) > 0)
			dem++;
	return dem;
}

