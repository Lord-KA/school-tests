#include <iostream>

/*
* час - 30 градусов
* минута - 6 градусов
* секунда - 6 градусов
*
*
*/

void func10()
{
	double Q;
	std::cin >> Q;
	int Zhours = Q / 30;
	double Qmin = Q * 12 - Zhours * 360;
	int Zmin = Qmin / 6;
	double Qsec = Qmin * 60 - Zmin * 360;
	int Zsec = Qsec / 6;
	std::cout << Zhours << ' ' << Zmin << ' ' << Zsec << '\n';
}

/*int main()
{
	func10();
}*/