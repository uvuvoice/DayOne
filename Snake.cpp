#include <iostream>
#include "windows.h"	//rand()
#include <conio.h>		//getch(), ������ ������� � ����������

using namespace std;

int main()
{	
	int iLengthSize = 20;		//�����
	int iHeightSize = 10;		//������

	int i, j;

	int iFruitLength;
	int	iFruitHeigh;
	int iOneFruitChecking;

	int iTestVal = 500;	//�������� �� �������� �����
	int iTest = 0;			//�������
	cout << iTest << endl;

	int iSnakeHeadX;
	int iSnakeHeadY;
	char Snake[5] = { '@', 0, 0, 0, 0 };
	int iSnakeHeadChecking;
	int iSnakeSize = 0;

	int total = 0;

	iSnakeHeadX = rand() % (iLengthSize - 1) + 1;		//������������ ��� ����������� ���� �� ��������
	iSnakeHeadY = rand() % (iHeightSize - 2) + 1;		//������������ ��� ����������� ���� �� ��������

	iFruitLength = rand() % (iLengthSize - 1) + 1;	//��������� ����� ��������� ������ �� ���������
	iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//��������� ����� ��������� ������ �� ���������

	while (iTest != iTestVal)
	{		
		cout << iFruitLength << " _F_ " << iFruitHeigh << endl;

		iOneFruitChecking = 1;
		iSnakeHeadChecking = 1;

		for (i = 0; i < iHeightSize; i++)		//������
		{
			for (j = 0; j < iLengthSize; j++)		//�������
			{
				if (i == 0 || i == iHeightSize - 1)		//��� 1 � ��������� ������� ��������� ��������� *
				{
					cout << '*';
				}
				else  //��������� �� ������ �����
				{
					if (j == 0 || j == iLengthSize - 1)		//��� 1 � ���������� ������� ������ *, ����� ������ �� ������
					{
						cout << '*';
					}
					else if(j == iSnakeHeadX && i == iSnakeHeadY && iSnakeHeadChecking == 1)		//��������� ������ ����
					{
						for (int s = 0; s <= total; s++)
						{
							cout << Snake[iSnakeSize];
						}
						iSnakeHeadChecking = 0;
					}
					else if(j == iFruitLength && i == iFruitHeigh && iOneFruitChecking == 1) //��������� 1 ������ � 1 ��������� �����
					{						
						cout << 'o';
						iOneFruitChecking = 0;	//��������� �� ���� ������ ���� ���						
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

		int iClicking = _getch();		//����������� ����
		switch (iClicking)
		{
		case 72: //����������� ���� �����
			iSnakeHeadX = iSnakeHeadX;
			iSnakeHeadY = iSnakeHeadY - 1;
			break;

		case 80:	//����������� ���� ����
			iSnakeHeadX = iSnakeHeadX;
			iSnakeHeadY = iSnakeHeadY + 1;
			break;

		case 75:	//����������� ���� �����
			iSnakeHeadX = iSnakeHeadX - 1;
			iSnakeHeadY = iSnakeHeadY;
			break;

		case 77:	//����������� ���� ������
			iSnakeHeadX = iSnakeHeadX + 1;
			iSnakeHeadY = iSnakeHeadY;
			break;
		}

		if (iSnakeHeadY == iFruitHeigh && iSnakeHeadX == iFruitLength)
		{
			iFruitLength = rand() % (iLengthSize - 1) + 1;	//����� ��������� ����� ��������� ������ �� ���������
			iFruitHeigh = rand() % (iHeightSize - 2) + 1;		//����� ��������� ����� ��������� ������ �� ���������

			total++;
			Snake[total] = '@';
		}

		iOneFruitChecking++;
		//Sleep(1000);
				
		system("cls");	//������� �������, �� ����������� ��������� ����
			
		iTest++;			
		cout << iTest << endl;	//������������ ��� ����������� �����

	}
}









/*

int iClicking = _getch();		//����������� ����
					switch (iClicking)
					{
						case 72: //����������� ���� �����
							iSnakeHeadX = iSnakeHeadX;
							iSnakeHeadY = iSnakeHeadY - 1;
							break;

						case 80:	//����������� ���� ����
							iSnakeHeadX = iSnakeHeadX;
							iSnakeHeadY = iSnakeHeadY + 1;
							break;

						case 75:	//����������� ���� �����
							iSnakeHeadX = iSnakeHeadX - 1;
							iSnakeHeadY = iSnakeHeadY;
							break;

						case 77:	//����������� ���� ������
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
				system("cls");	//������� �������, �� ����������� ��������� ����
				break;
		}

		iTest++;
		cout << iTest << endl;	//������������ ��� ����������� �����



*/