/* Лабораторная работа № 4. Задание № 13.
   "Перевернуть" в строке все слова.
   (Например: "Жили были дед и баба" - "илиЖ илиб дед и абаб").*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define SIZE 50

void transposition1(char string[], int size);
void transposition2(char inStr[], int size);

void transposition1(char string[], int size)
{
	int i = 0, j = 0, pos; //инициализируем счетчики тут так как в циклах обнуление не нужно 
	char help;

	for (pos = 0; string[pos] != '\0'; pos++)
	{
		if (string[pos] == ' ' || string[pos + 1] == '\0')// запуск тела цикла при достижении пробела или крайнего символа перед '\0'
		{
			for (; string[j] != ' ' && string[j] != '\0'; j++);//один счетчик в конец строки
			j--;

			for (; i < j; i++, j--)//движение счетчиков друг к другу 
			{//пошаговая замена символов
				help = string[i];
				string[i] = string[j];
				string[j] = help;
			}

			i = pos + 1;//выставляем счетчики 
			j = pos + 1;//на начало следующего слова
		}
	}

	printf("Первый способ: %s\n\n", string);
}

void transposition2(char inStr[], int size)
{
	char outStr[SIZE];
	int i = 0, j = 0, pos;

	for (; inStr[i - 1] != '\0'; i++) //шаг по массиву
	{
		if (inStr[i] == ' ' || inStr[i] == '\0') //если пробел или конец строки
		{
			pos = i;//запомнить позицию в исх.строке

			for (i--; j != pos; i--, j++)//переброска символов в обратном порядке
			{
				outStr[j] = inStr[i];
			}

			outStr[j++] = ' '; //завершили слово в исх. строке пробелом
			i = pos + 1;//начали с нового слова во вх.строке
		}
	}
	outStr[j] = '\0';
	printf("Второй способ: %s\n\n", outStr);
}

void main()
{
	setlocale(LC_ALL, "Rus");

	char myString[SIZE] = "Жили..! были дед да баба";
	printf("Исходная строка. Вывод 1: %s\n\n", myString);
//	transposition1(myString, SIZE);
	transposition2(myString, SIZE);
	printf("Исходная строка. Вывод 2: %s\n\n", myString);

	_getch();
}