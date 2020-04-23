#pragma once
#include <iostream>
#include <string>
#include <exception>

class HomeWork
{
private:

	/// Модуль числа
	int AbsoluteValue(int number);

	/// Удаляет все пробелы в строке
	std::string RemoveSpaces(std::string  str);

	/// Удаляет нули стоящие перед целым числом
	std::string RemoveZeros(std::string str);

	/// Проверяет является ли символ цифрой
	bool Numeral(char chr);

	/// Проверяет является ли введённая строка числом
	bool CheckIfStringIsNumber(std::string  str);

	/// Преобразует строку в целое число
	bool ConvertToInt(std::string strNumber, int& number);

	/// Проверяет является ли число степенью двойки
	bool DegreeOfTwo(int number);

	/// Разделяет строку в виде дроди на числитель и знаменатель
	bool NumeratorAndDenominator(std::string fraction, int& numerator, int& denominator);

	/// Определяет наибольший общий делитель
	int GreatestCommonFactor(int number1, int number2);

public:

	/// Задание 1
	void Task1();

	/// Задание 2
	void Task2();

	/// Задание 3
	void Task3();

	/// Задание 4
	void Task4();

	/// Задание 5
	void Task5();

	/// Задание 6
	void Task6();

	/// Задание 7
	void Task7();

	/// Задание 8
	void Task8();

	/// Задание 9
	void Task9();

	/// Задание 10
	void Task10();
};

