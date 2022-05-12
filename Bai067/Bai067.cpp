#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);

bool ktChinhPhuong(int);
int DemChinhPhuongBien(int[][500], int, int);

int main()
{
	int b[500][500];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	int kq = DemChinhPhuongBien(b, k, l);
	cout << "\nSo luong so chinh phuong tren bien cua ma tran: " << kq;
	return 0;
}

void Nhap(int a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (200 + 1) - 100;
}

void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << "\n";
	}
}
bool ktChinhPhuong(int k)
{
	bool flag = false;
	for (int i = 0; i <= k;i++)
		if (i * i == k)
			return true;
	return flag;
}

int DemChinhPhuongBien(int a[][500], int m, int n)
{
	int dem = 0;
	for (int j = 0;j <= n - 2;j++)
		if (ktChinhPhuong(a[0][j]))
			dem++;
	for (int i = 0;i <= m - 2;i++)
		if (ktChinhPhuong(a[i][n - 1]))
			dem++;
	for (int j = n - 1;j >= 1;j--)
		if (ktChinhPhuong(a[m - 1][j]))
			dem++;
	for (int i = m - 1;i >= 1;i--)
		if (ktChinhPhuong(a[i][0]))
			dem++;
	return dem;
}