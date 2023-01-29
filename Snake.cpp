#include <iostream>
#include "windows.h"	//rand()
#include <conio.h>		//getch(), чтение символа с клавиатуры

using namespace std;

int main()
{	
	int iLengthSize = 20;		//длина
	int iHeightSize = 10;		//высота

	int i, j;

	int iFruitLength;
	int	iFruitHeigh;
	int iOneFruitChecking;

	int iTestVal = 500;	//заменить на проверку удара
	int iTest = 0;			//удалить
	cout << iTest << endl;

	int iSnakeHeadX;
	int iSnakeHeadY;
	char Snake[5] = { '@', 0, 0, 0, 0 };
	int iSnakeHeadChecking;
	int iSnakeSize = 0;

	int total = 0;

	iSnakeHeadX = rand() % (iLengthSize - 1) + 1;		//используется для перемещения змеи по стрелкам
	iSnakeHeadY = rand() % (iHeightSize - 2) + 1;		//используется для перемещения змеи по стрелкам

	iFruitLength = rand() % (iLengthSize - 1) + 1;	//случайное место появления фрукта из диапазона
	iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//случайное место появления фрукта из диапазона

	while (iTest != iTestVal)
	{		
		cout << iFruitLength << " _F_ " << iFruitHeigh << endl;

		iOneFruitChecking = 1;
		iSnakeHeadChecking = 1;

		for (i = 0; i < iHeightSize; i++)		//строки
		{
			for (j = 0; j < iLengthSize; j++)		//столбцы
			{
				if (i == 0 || i == iHeightSize - 1)		//для 1 и последней строчки полностью заполняем *
				{
					cout << '*';
				}
				else  //отрисовка на пустом месте
				{
					if (j == 0 || j == iLengthSize - 1)		//для 1 и последнего столбца рисуем *, иначе ничего не рисуем
					{
						cout << '*';
					}
					else if(j == iSnakeHeadX && i == iSnakeHeadY && iSnakeHeadChecking == 1)		//отрисовка головы змеи
					{
						for (int s = 0; s <= total; s++)
						{
							cout << Snake[iSnakeSize];
						}
						iSnakeHeadChecking = 0;
					}
					else if(j == iFruitLength && i == iFruitHeigh && iOneFruitChecking == 1) //появление 1 фрукта в 1 случайном месте
					{						
						cout << 'o';
						iOneFruitChecking = 0;	//появление за цикл только один раз						
					}
					else 
					{
						cout << ' ';
					}									
				}
			}
			cout << '\n';
		}

		cout << iFruitLength << "_Fr_" << iFruitHeigh << endl;
		cout << iSnakeHeadX << "_Sn_" << iSnakeHeadY << endl;

		int iClicking = _getch();		//перемещение змеи
		switch (iClicking)
		{
		case 72: //перемещение змеи вверх
			iSnakeHeadX = iSnakeHeadX;
			iSnakeHeadY = iSnakeHeadY - 1;
			break;

		case 80:	//перемещение змеи вниз
			iSnakeHeadX = iSnakeHeadX;
			iSnakeHeadY = iSnakeHeadY + 1;
			break;

		case 75:	//перемещение змеи влево
			iSnakeHeadX = iSnakeHeadX - 1;
			iSnakeHeadY = iSnakeHeadY;
			break;

		case 77:	//перемещение змеи вправо
			iSnakeHeadX = iSnakeHeadX + 1;
			iSnakeHeadY = iSnakeHeadY;
			break;
		}

		if (iSnakeHeadY == iFruitHeigh && iSnakeHeadX == iFruitLength)
		{
			iFruitLength = rand() % (iLengthSize - 1) + 1;	//новое случайное место появления фрукта из диапазона
			iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//новое случайное место появления фрукта из диапазона

			total++;
			Snake[total] = '@';
		}

		iOneFruitChecking++;
		//Sleep(1000);
				
		system("cls");	//очистка консоли, но запоминание положения змеи
			
		iTest++;			
		cout << iTest << endl;	//приспособить под отображение очков

	}
}









/*

int iClicking = _getch();		//перемещение змеи
					switch (iClicking)
					{
						case 72: //перемещение змеи вверх
							iSnakeHeadX = iSnakeHeadX;
							iSnakeHeadY = iSnakeHeadY - 1;
							break;

						case 80:	//перемещение змеи вниз
							iSnakeHeadX = iSnakeHeadX;
							iSnakeHeadY = iSnakeHeadY + 1;
							break;

						case 75:	//перемещение змеи влево
							iSnakeHeadX = iSnakeHeadX - 1;
							iSnakeHeadY = iSnakeHeadY;
							break;

						case 77:	//перемещение змеи вправо
							iSnakeHeadX = iSnakeHeadX + 1;
							iSnakeHeadY = iSnakeHeadY;
							break;
					}


*/



/*

iOneFruitChecking++;
		//Sleep(1000);

		int i_input;
		i_input = _getch();

		switch (i_input)
		{
			case 13 :
				system("cls");	//очистка консоли, но запоминание положения змеи
				break;
		}

		iTest++;
		cout << iTest << endl;	//приспособить под отображение очков



*/