/* ������������ ������ � 4. ������� � 13.
   "�����������" � ������ ��� �����.
   (��������: "���� ���� ��� � ����" - "���� ���� ��� � ����").*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define SIZE 50

void transposition1(char string[], int size);
void transposition2(char inStr[], int size);

void transposition1(char string[], int size)
{
	int i = 0, j = 0, pos; //�������������� �������� ��� ��� ��� � ������ ��������� �� ����� 
	char help;

	for (pos = 0; string[pos] != '\0'; pos++)
	{
		if (string[pos] == ' ' || string[pos + 1] == '\0')// ������ ���� ����� ��� ���������� ������� ��� �������� ������� ����� '\0'
		{
			for (; string[j] != ' ' && string[j] != '\0'; j++);//���� ������� � ����� ������
			j--;

			for (; i < j; i++, j--)//�������� ��������� ���� � ����� 
			{//��������� ������ ��������
				help = string[i];
				string[i] = string[j];
				string[j] = help;
			}

			i = pos + 1;//���������� �������� 
			j = pos + 1;//�� ������ ���������� �����
		}
	}

	printf("������ ������: %s\n\n", string);
}

void transposition2(char inStr[], int size)
{
	char outStr[SIZE];
	int i = 0, j = 0, pos;

	for (; inStr[i - 1] != '\0'; i++) //��� �� �������
	{
		if (inStr[i] == ' ' || inStr[i] == '\0') //���� ������ ��� ����� ������
		{
			pos = i;//��������� ������� � ���.������

			for (i--; j != pos; i--, j++)//���������� �������� � �������� �������
			{
				outStr[j] = inStr[i];
			}

			outStr[j++] = ' '; //��������� ����� � ���. ������ ��������
			i = pos + 1;//������ � ������ ����� �� ��.������
		}
	}
	outStr[j] = '\0';
	printf("������ ������: %s\n\n", outStr);
}

void main()
{
	setlocale(LC_ALL, "Rus");

	char myString[SIZE] = "����..! ���� ��� �� ����";
	printf("�������� ������. ����� 1: %s\n\n", myString);
//	transposition1(myString, SIZE);
	transposition2(myString, SIZE);
	printf("�������� ������. ����� 2: %s\n\n", myString);

	_getch();
}