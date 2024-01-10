
#include <iostream>
using namespace std;

class stringg
{

public:
	char* text;

	stringg(): text{nullptr} {}//коструктор без параметрів

	stringg(const char* texting) : text{new char[strlen(texting)+1]}//конструктор з параметром
	{
		for (int i = 0; i < strlen(texting)+1; i++)
		{
			text[i] = texting[i];
		}
	}

	stringg(stringg& element) : text{ new char[strlen(element.text)+1] }//конструктор копіювання
	{
		for (int i = 0; i < strlen(element.text)+1; i++)
		{
			text[i] = element.text[i];
		}
	}

	~stringg()//деструктор
	{
		delete[]text;
	}

	
	
	void print()// метод виведення значення стрінга на екран
	{
		cout << endl;
		for (int i = 0; i < strlen(text)+1; i++)
		{
			
			cout << text[i];
		}
		cout << endl;
	}

	void return_line(int start_i, int end_i)//метод, що вертає частину рядка в заданому діапазоні, де start_i елемент з якого починатимемо, end_i - закінчувати 	
	{
		if (start_i < 0)
		{
			cout << "\n початковий індекс не може бути меншим за 0";
			
		}
		if (end_i == strlen(text))
		{
			cout << "\n кінцевий індекс не може бути більшим та рівним  за  довжину рядка";
		}

		else {

			for (int i = start_i; i <= end_i; i++)
			{
				cout << text[i];
			}
			cout << endl;
		}
	}

	int kilkist_sliv()//метод для пошуку кількості слів
	{
		int count = 0;
		for (int i = 0; i < strlen(text)+1; i++)
		{
			if (strlen(text) == 0)
			{
				return 0;
				break;
			}
		    if (text[i] == ' ' || text[i] == '\0')
			{
				count++;
			}
		}
		return count;
	}

	void strchanger(const char* changer) 
	{
		text = new char[strlen(changer) + 1];
		for (int i = 0; i < strlen(changer)+1; i++)
		{
			text[i] = changer[i];
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ukr");// підключив українську мову
	
	stringg first("Sasha killer");
	first.print();
	first.return_line(0, 4);
	cout << first.kilkist_sliv();
	first.strchanger("sergiy");
	first.print();
}

