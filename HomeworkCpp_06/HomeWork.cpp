#include "HomeWork.h"

int HomeWork::Random(int min, int max)
{
	std::random_device rd;
	std::mt19937 mersenne(rd());

	return min + mersenne() % (max - min);
}

int HomeWork::AbsoluteValue(int number)
{
	return (number >= 0) ? number : -number;
}

std::string HomeWork::RemoveSpaces(std::string str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

	return str;
}

std::string HomeWork::RemoveZeros(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0')
		{
			str.erase(i, 1);
			i--;
		}
		else
		{
			break;
		}
	}
	return str;
}

bool HomeWork::Numeral(char chr)
{
	return (chr == '0') ||
		   (chr == '1') ||
		   (chr == '2') ||
		   (chr == '3') ||
		   (chr == '4') ||
		   (chr == '5') ||
		   (chr == '6') ||
		   (chr == '7') ||
		   (chr == '8') ||
		   (chr == '9');
}

bool HomeWork::CheckIfStringIsNumber(std::string str)
{
	str = RemoveSpaces(str);

	if ((str[0] == '-') || (str[0] == '+'))
	{
		str.erase(0, 1);		
	}
	
	bool key = true;

	for (int i = 0; i < str.length(); i++)
	{
		key = key && Numeral(str[i]);

		if (!key)
		{
			break;
		}
	}

	return key;
}

bool HomeWork::ConvertToInt(std::string strNumber, int& number)
{
	int sign = 1;
	long long temp = 0;
		
	strNumber = RemoveSpaces(strNumber);

	if (strNumber[0] == '-')
	{
		strNumber.erase(0, 1);
		sign = -1;
	}
	else
	{
		if (strNumber[0] == '+')
		{
			strNumber.erase(0, 1);
			sign = 1;
		}
	}

	strNumber = RemoveZeros(strNumber);

	bool key = true;

	for (int i = 0; i < strNumber.length(); i++)
	{
		key = key && Numeral(strNumber[i]);		
	}

	if (key)
	{
		int numeral = 0;
		
		for (int i = 0; i < strNumber.length(); i++)
		{
			numeral = strNumber[i] & 0x0F;
			temp += numeral * ((long long)pow(10, strNumber.length() - 1 - i));
		}

		temp = sign * temp;

		if (-2147483648 <= temp && temp <= 2147483647)
		{
			number = temp;
			return true;
		}		
	}	

	return false;
}

std::string HomeWork::ConvertToString(int number)
{
	std::string outString;
		
	if (number != 0)
	{		
		int sign = 1;

		if (number < 0)
		{
			number = -number;
			sign = -1;
		}

		int numberOfDigits = floor(log10(number)); // Разрядность числа

		int k = numberOfDigits;
		int n = 0;

		while (0 <= k)
		{
			n = (number / pow(10, k));
			outString += n | 0x30;
			number -= n * pow(10, k);
			k--;			
		}

		if (sign == -1)
		{
			outString = "-" + outString;
		}
	}
	else
	{
		outString = "0";
	}	

	return outString;
}

bool HomeWork::DegreeOfTwo(int number)
{
	if (number > 0)
	{
		if ((number & (number - 1)) == 0)
		{
			return true;
		}
	}

	return false;
}

bool HomeWork::NumeratorAndDenominator(std::string fraction, int& numerator, int& denominator)
{
	fraction = RemoveSpaces(fraction);

	std::string strNumerator;    // числитель в виде строки
	std::string strDenominator;  // знаменатель в виде строки
	bool key = false;

	for (int i = 0; i < fraction.length(); i++)
	{
		if (fraction[i] != '/')
		{
			strNumerator += fraction[i];
		}
		else
		{
			fraction.erase(0,i + 1);
			key = true;
			break;
		}
	}

	if (key)
	{
		strDenominator = fraction;

		if (ConvertToInt(strNumerator, numerator) && ConvertToInt(strDenominator, denominator))
		{
			return true;
		}
	}

	return false;
}

int HomeWork::GreatestCommonFactor(int number1, int number2)
{
	if (number1 < 0 || number2 < 0)
	{
		number1 = AbsoluteValue(number1);
		number2 = AbsoluteValue(number2);
	}

	if (number1 != 0 && number2 != 0)
	{
		while (number1 != 0 && number2 != 0)
		{
			if (number1 > number2)
			{
				number1 %= number2;
			}
			else
			{
				number2 %= number1;
			}
		}		
	}

	return number1 + number2;
}

void HomeWork::RepeatingCharacters(std::string str, int number)
{
	int i = 0;

	while (i != number)
	{
		std::cout << str;
		i++;
	}

	std::cout << std::endl;
}

int HomeWork::Answer(std::string text)
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string items[2] = { "Да", "Нет" };
	MenuController menu(items, 2);
	
	return menu.selectedMenuItem(text);
}

void HomeWork::Task1()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	int hour = 0;

	std::cout << "Введите количество часов (0 - 23): ";
	std::cin >> hour;

	if (0 <= hour && hour <= 23)
	{
		if (1 <= hour && hour <= 12)
		{
			RepeatingCharacters("Ку ", hour);
		}

		if (hour == 0)
		{
			RepeatingCharacters("Ку ", 12);
		}

		if (13 <= hour && hour <= 23)
		{
			RepeatingCharacters("Ку ", hour - 12);
		}
	}
	else
	{
		std::cout << "Такого часа не существует!";
	}
}

void HomeWork::Task2()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string name;
	int amountOfDebt = 0;

	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Введите сумму долга: ";
	std::cin >> amountOfDebt;
	std::cout << "-------------------------------------" << std::endl;

	if (name != "" && amountOfDebt > 0)
	{
		while (amountOfDebt > 0)
		{
			int k = 0;

			std::cout << "Ваш долг " << name << " составляет: " << amountOfDebt << std::endl;
			std::cout << "Введите сумму для погашения долга: ";
			std::cin >> k;

			if (k > 0)
			{
				amountOfDebt -= k;
			}
			else
			{
				std::cout << "Ошибка ввода данных!" << std::endl;
			}

			std::cout << "-------------------------------------" << std::endl;
		}

		std::cout << "Ваш долг " << name << " погашен!" << std::endl;		
	}
	else
	{
		std::cout << "Ошибка ввода данных!" << std::endl;
	}

}

void HomeWork::Task3()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strNumber;
	
	std::cout << "Введите число: ";
	std::getline(std::cin, strNumber);

	strNumber = RemoveSpaces(strNumber);
	
	if (CheckIfStringIsNumber(strNumber))
	{
		if ((strNumber[0] == '-') || (strNumber[0] == '+'))
		{
			strNumber.erase(0, 1);
		}

		strNumber = RemoveZeros(strNumber);

		std::cout << "Количество цифр во введённом числе: " << strNumber.length() << std::endl;
	}
	else
	{
		std::cout << "Ошибка ввода данных!!!" << std::endl;
	}		
}

void HomeWork::Task4()
{	
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string name;
	int amountOfDebt = 0;

	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Введите сумму долга: ";
	std::cin >> amountOfDebt;
	std::cout << "-------------------------------------" << std::endl;

	if (name != "/0" && amountOfDebt > 0)
	{
		while (amountOfDebt > 0)
		{
			int k = 0;

			std::cout << "Ваш долг " << name << " составляет: " << amountOfDebt << std::endl;
			std::cout << "Введите сумму для погашения долга: ";
			std::cin >> k;

			if (k > 0)
			{
				amountOfDebt -= k;
			}
			else
			{
				std::cout << "Ошибка ввода данных!" << std::endl;
			}

			std::cout << "-------------------------------------" << std::endl;
		}

		if (amountOfDebt == 0)
		{
			std::cout << "Ваш долг " << name << " погашен!" << std::endl;
		}
		else
		{
			std::cout << "Ваш долг " << name << " погашен!" << std::endl;
			std::cout << "Ваша сдача: " << -amountOfDebt << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!" << std::endl;
	}
}

void HomeWork::Task5()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");
	
	std::string strNumber;

	std::cout << "Введите шестизначный номер билетика: ";
	std::getline(std::cin, strNumber);
	int number = 0;
		
	if (ConvertToInt(strNumber, number))
	{
		if (100000 <= number && number <= 999999)
		{
			int i = 1;
			int sum1 = 0;
			int sum2 = 0;

			while(i != 7)
			{
				if (i <= 3)
				{
					sum1 += number % 10;
					number = number / 10;
				}
				else
				{
					sum2 += number % 10;
					number = number / 10;
				}

				i++;
			}

			if (sum1 == sum2)
			{
				std::cout << "Ура! Счастливый билетик." << std::endl;
			}
			else
			{
				std::cout << "Неповезло." << std::endl;
			}
		}
		else
		{
			std::cout << "Несоответствие диапазону!" << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!" << std::endl;
	}	
}

void HomeWork::Task6()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strNumber;

	std::cout << "Введите целое число: ";
	std::getline(std::cin, strNumber);
	int number = 0;

	if (ConvertToInt(strNumber, number))
	{
		if (DegreeOfTwo(number))
		{
			std::cout << "Число является степенью двойки!" << std::endl;
		}
		else
		{
			std::cout << "Число НЕ является степенью двойки!" << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!" << std::endl;
	}
}

void HomeWork::Task7()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strNumber;

	std::cout << "Введите целое число (0 до 45): ";
	std::getline(std::cin, strNumber);
	int number = 0;
	int result = 0;

	if (ConvertToInt(strNumber, number))
	{
		if (0 <= number && number <= 45)
		{
			if (number > 2)
			{
				int num1 = 1;
				int num2 = 1;
				int num3 = 1;
				int i = 2;

				while (i != number)
				{
					num3 = num2 + num1;

					result = num3;

					std::swap(num1, num2);
					std::swap(num2, num3);
					i++;
				}
			}
			else
			{
				if (number == 2)
				{
					result = 1;
				}
				else
				{
					result = number;
				}
			}

			std::cout << "Число Фибоначчи: " << result << std::endl;
		}
		else
		{
			std::cout << "Выход за границы!" << std::endl;
		}		
	}
	else
	{
		std::cout << "Ошибка ввода данных!" << std::endl;
	}
}

void HomeWork::Task8()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string fraction;
	int numerator;   // числитель
	int denominator; // знаменатель

	std::cout << "Введите дробь в виде A/B: ";
	std::getline(std::cin, fraction);

	if (NumeratorAndDenominator(fraction, numerator, denominator))
	{
		if (denominator != 0)
		{			
			int d = GreatestCommonFactor(numerator, denominator);

			if (d != 1)
			{
				numerator /= d;
				denominator /= d;

				if (denominator != 1)
				{
					std::cout << "После сокращения: " << numerator << "/" << denominator << std::endl;
				}
				else
				{
					std::cout << "После сокращения: " << numerator << std::endl;
				}				
			}
			else
			{
				std::cout << "Данная дробь не сократима!" << std::endl;
			}
		}
		else
		{
			std::cout << "Деление на ноль!" << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!" << std::endl;
	}
}

void HomeWork::Task9()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strInitialDepositAmount; // Начальная сумма вклада
	std::string strInterestRate;         // Процентная ставка
	std::string strFinalAmountOfDeposit; // Конечная сумма вклада

	std::cout << "Введите начальную сумму вклада: ";
	std::getline(std::cin, strInitialDepositAmount);
	std::cout << "Введите процентную ставку: ";
	std::getline(std::cin, strInterestRate);
	std::cout << "Введите конечную сумму вклада: ";
	std::getline(std::cin, strFinalAmountOfDeposit);

	int initialDepositAmount = 0;
	int interestRate = 0;
	int finalAmountOfDeposit = 0;

	if (ConvertToInt(strInitialDepositAmount, initialDepositAmount) && 
		ConvertToInt(strInterestRate, interestRate) && 
		ConvertToInt(strFinalAmountOfDeposit, finalAmountOfDeposit))
	{
		if (initialDepositAmount > 0 && interestRate > 0 && finalAmountOfDeposit > 0)
		{
			if (initialDepositAmount < finalAmountOfDeposit)
			{
				float growth = initialDepositAmount;
				int numberOfYears = 0;

				while (growth < finalAmountOfDeposit)
				{
					growth = growth * (1 + (float)interestRate / 100);
					growth = floor(growth);
					numberOfYears++;
				}

				std::cout << "------------------------------------------------" << std::endl;
				std::cout << "Начальная сумма вклада: " << initialDepositAmount << std::endl;
				std::cout << "Конечная сумма вклада: " << growth << std::endl;
				std::cout << "Количество лет: " << numberOfYears << std::endl;
			}
			else
			{
				std::cout << "Начальная сумма вклада не может быть больше конечной!" << std::endl;
			}
		}
		else
		{
			std::cout << "Ошибка ввода данных!" << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!" << std::endl;
	}
}

void HomeWork::Task10()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	int const minNumber = 1;
	int const maxNumber = 63;

	std::string strNumber;
	int number;

	std::cout << "Введите число (" << minNumber << " - " << maxNumber << ") : ";
	std::getline(std::cin, strNumber);

	if (ConvertToInt(strNumber, number))
	{
		if (minNumber <= number && number <= maxNumber)
		{
			int min = minNumber;
			int max = maxNumber + 1;			
			int k = Random(minNumber, maxNumber + 1);
			
			std::string text;
			
			while (k != number)
			{			
				text = "Загаданное число больше " + ConvertToString(k) + "?";
								
				if (Answer(text) == 0)
				{
					min = k;														
				}
				else
				{					
					max = k;							
				}
				
				k = min + AbsoluteValue(max - min) / 2;
			}

			std::cout << "Вы загдали число: " << k << std::endl;
		}
		else
		{
			std::cout << "Выход за границы диапазона!" << std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка ввода данных!" << std::endl;
	}
}
