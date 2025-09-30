#include <iostream>
#include <bitset>
#include <string>
int main()
{
	setlocale(LC_ALL, "Russian");
	short a;
	std::cout << "Введите А: ";
	std::cin >> a;

	short i;
	std::cout << "Введите номер бита: ";
	std::cin >> i;

	if (0 <= i && i <= 8) {
		std::bitset<8> bit(a);
		if (bit[i] == 1) {
			int b;
			int c;
			std
		}

	}
	else
	{
		std::cout << "Номер бита введён неправильно";
	}
}
