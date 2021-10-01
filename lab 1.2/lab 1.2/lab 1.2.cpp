// Написать функцию, которая определяет, есть ли в тексте слова, начинающиеся с буквы а, и сколько таких слов. С помощью этой функции проверить несколько строк.
// Программа должна содержать функцию пользователя с переменным числом параметров и не менее трех обращений к ней с различным количеством параметров.

#include <iostream>
#include <stdio.h>
#define MAXSTRLEN 200 //максимальное количество символов в строке
#define MAXSTR 5 //максимальное число строк для ввода пользователем
using namespace std;
int searchletter(char*);
int procstrings(char*, ...);
int main()
{
	setlocale(LC_CTYPE, "866");
	cout << "Enter the text (no more than 5 lines, CTRL+Z-end the input): ";
	char** A = new char* [MAXSTR];
	for (int i = 0; i < MAXSTR; i++) A[i] = new char[MAXSTRLEN];
	int rowcount = 0;
	while (!cin.eof())
	{
		cin.getline(A[rowcount++], MAXSTRLEN);
		if (rowcount == MAXSTR)
		{
			cout << "The allowed number of rows has been reached.";
			break;
		}
	}
	for (int i = 0; i < rowcount; i++) cout << A[i] << endl;
	int result = 0;
	if (rowcount == 1) result = procstrings(A[0], NULL);
	else if (rowcount == 2) result = procstrings(A[0], A[1], NULL);
	else if (rowcount == 3) result = procstrings(A[0], A[1], A[2], NULL);
	else if (rowcount == 4) result = procstrings(A[0], A[1], A[2], A[3], NULL);
	else if (rowcount == 5) result = procstrings(A[0], A[1], A[2], A[3], A[4], NULL);
	cout << "The number of words starting with the letter a: " << result << endl;
	//высвобождаем динамическую память
	for (int i = 0; i < MAXSTR; i++) delete[] A[i];
	delete[] A;
	return 0;
}
int searchletter(char* yourstr)
{
	//параметром принимает адрес строки символов, возвращает число слов, начинающихся с буквы а
	int count_a = 0;
	for (int i = 0; i < strlen(yourstr); i++)
	{
		if ((i == 0 && yourstr[i] == '\xA0') || (i > 0 && yourstr[i] == '\xA0' && (yourstr[i - 1] == ' ' || yourstr[i - 1] == '\t'))) count_a++;
	}
	return count_a;
}

int procstrings(char* s, ...)
{
	/* параметрами принимает адреса обрабатываемых строк; NULL - завершение ряда параметров.
	возвращает количество слов, начинающихся с буквы "а" суммарно во всех передаваемых строках */
	char** pch = &s;
	int sum_a = 0;
	while (*pch != NULL)
	{
		sum_a += searchletter(*pch);
		pch++;
	}
	return sum_a;
}
