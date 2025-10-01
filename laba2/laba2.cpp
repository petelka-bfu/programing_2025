#include <iostream>
#include <bitset>
int main()
{
	setlocale(LC_ALL, "Russian");
	//Часть 1
	//Принимаю переменную а
	short a;
	std::cout << "Введите А: ";
	std::cin >> a;
	//принимаю переменную i
	short i;
	std::cout << "Введите номер бита: ";
	std::cin >> i;

	if (0 <= i && i <= 8) { //Проверка правильно ли введено i
		std::bitset<8> bit(a);
		std::cout << bit << "=" << a;
		if (bit[i] == 1) { //Если бит под номером i равен единице, то принимается пара чисел и выводится максимальное
			int b;
			int c;
			std::cin >> b;
			std::cin >> c;
			if (b > c) {
				std::cout << b << std::endl;
			}
			else { 
				std::cout << c << std::endl;
			}
		}
		else if (bit[i]==0) { // Иначе выводится число, обратное А
			std::bitset<8> bi(255 - a);
			std::cout << bi << "=" << a;
		}

	}
	else
	{
		std::cout << "Номер бита введён неправильно" << std::endl;
	}
	short n;
	std::cin >> n;
	switch (n)
	{
	case 1:
		std::cout << "Январь";
		break;
	case 2:
		std::cout << "Февраль";
		break;
	case 3:
		std::cout << "Март";
		break;
	case 4:
		std::cout << "Апрель";
		break;
	case 5:
		std::cout << "Май";
		break;
	case 6:
		std::cout << "Июнь";
		break;
	case 7:
		std::cout << "Июль";
		break;
	case 8:
		std::cout << "Август";
		break;
	case 9:
		std::cout << "Сентябрь";
		break;
	case 10:
		std::cout << "Октябрь";
		break;
	case 11:
		std::cout << "Ноябрь";
		break;
	case 12:
		std::cout << "Декабрь";
		break;
	default:
		std::cout << "Месяца под таким номером не существует";
	}
}

