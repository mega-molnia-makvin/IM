#include "conio.h"
#include "math.h"
#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <time.h>
#include <cmath>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>

using namespace std;

fstream f;

double rundum(long b) {
	long y;
	double r;
	y = b * 1220703125;
	if (y < 0) {
		y += 1073741824;
		y += 1073741824;
	};
	r = y * 0.4656613 / 1000000000;
	return r;
};

void exp() {
	//���������� ������������ ��������� �����
	double x[10];

	//������
	double l = 10;

	//��� �������� � ���������
	double M = 1 / l;
	double D = 1 / l;

	f.open("out_file.xls", ios::out);

	//������ � ���������� �������
	for (int i = 0; i < 10; i++) {
		x[i] = -log(rundum(i + 1)) * M;
		cout << x[i] << "\n";
		f << std::fixed << std::setprecision(3) << x[i] << endl;
	};
};

int main()
{
	cout << "Not library func\n";
	LARGE_INTEGER clockFrequence;

	QueryPerformanceFrequency(&clockFrequence);//���������� ������� ��������
	LARGE_INTEGER startTime;//����� ������ ��������
	LARGE_INTEGER endTime;//����� ��������� ��������
	QueryPerformanceCounter(&startTime);

	exp();

	QueryPerformanceCounter(&endTime);
	LARGE_INTEGER genTime;
	genTime.QuadPart = endTime.QuadPart - startTime.QuadPart;
	float genTimesec = ((float)genTime.QuadPart) / clockFrequence.QuadPart;
	cout << "Time: " << genTimesec;



	//������������ �������

	LARGE_INTEGER clockFrequence2;

	QueryPerformanceFrequency(&clockFrequence2);//���������� ������� ��������
	LARGE_INTEGER startTime2;//����� ������ ��������
	LARGE_INTEGER endTime2;//����� ��������� ��������
	QueryPerformanceCounter(&startTime2);

	cout << "\n\nLibrary func\n";
	random_device rd;
	default_random_engine generator(rd());
	exponential_distribution<double> distribution(1.0); // �������� ��������

	int size = 10; // ���������� ��������������� �����

	for (int i = 0; i < size; i++) {
		double random_number = distribution(generator);
		std::cout << random_number << endl;
	}
	QueryPerformanceCounter(&endTime2);
	LARGE_INTEGER genTime2;
	genTime2.QuadPart = endTime2.QuadPart - startTime2.QuadPart;
	float genTimesec2 = ((float)genTime2.QuadPart) / clockFrequence2.QuadPart;
	cout << "Time: " << genTimesec2;



}
