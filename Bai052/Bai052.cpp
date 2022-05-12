#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);

int ktCucDai(float[][500], int, int, int, int);
int ktCucTieu(float[][500], int, int, int, int);
float TongCucDai(float[][500], int, int);
float TongCucTieu(float[][500], int, int);
float TongCucTri(float[][500], int, int);

int main()
{
	float b[500][500];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	float kq = TongCucTri(b, k, l);
	cout << "\nTong cuc tri cua ma tran la: " << setw(8) << setprecision(3) << kq;
	
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
int ktCucDai(float a[][500], int m, int n, int d, int c)
{
	int di[8] = { -1,-1,-1,0,+1,+1,+1,0 };
	int dj[8] = { -1,0,+1,+1,+1,0,-1,-1 };
	int flag = 1;
	for (int k = 0;k < 8;k++)
		if (d + di[k] >= 0 && d + di[k] < m &&
			c + dj[k] >= 0 && c + dj[k]<n &&
			a[d + di[k]][c + dj[k]] > a[d][c])
			flag = 0;
	return flag;
}
int ktCucTieu(float a[][500], int m, int n,
	int d, int c)
{
	int flag = 1;
	for (int di = -1; di <= 1; di++)
		for (int dj = -1; dj <= 1; dj++)
			if (d + di >= 0 && d + di < m && c + dj >= 0 && c + dj < n && !(di == 0 && dj == 0) && a[d + di][c + dj] > a[d][c])
				flag = 0;
	return flag;
}
float TongCucDai(float a[][500], int m, int n)
{
	float s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucDai(a, m, n, i, j) == 1)
				s = s + a[i][j];
	return s;
}
float TongCucTieu(float a[][500], int m, int n)
{
	float s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucTieu(a, m, n, i, j) == 1)
				s = s + a[i][j];
	return s;
}

float TongCucTri(float a[][500], int m, int n)
{
	float x = TongCucDai(a, m, n);
	float y = TongCucTieu(a, m, n);
	return x + y;
}
