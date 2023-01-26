#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//int a = 0, iResult = 0;					//1 part
	int a = 0, iMax[3] = {0, 0, 0};				//2 part
	std::string sText;

	//std::ifstream ReadFile("C:\\users\\admin\\desktop\\input.txt");
	//std::ifstream ReadFile("D:\\Hobbies\\2.      IT\\2.1      C++\\Программы\\Задачи Adventofcode\\День 1\\input.txt");

	if (ReadFile.is_open())
	{
		while (getline(ReadFile, sText))
		{
			if (sText.empty())		//checking an empty string 
			{
				//iResult = a > iResult ? a : iResult;		//1 part
				//a = 0;
				
				if (a > iMax[0] && a > iMax[1] && a > iMax[2])		//2 part
				{
					iMax[2] = iMax[1];
					iMax[1] = iMax[0];
					iMax[0] = a;							
				}
				else if (a > iMax[1] && a > iMax[2])
				{
					iMax[2] = iMax[1];
					iMax[1] = a;					
				}
				else if (a > iMax[2])
				{
					iMax[2] = a;						
				}
				else
				{							
				}
								
				a = 0;
			}
			else
			{
				a += std::stoi(sText);		//convert string to int
			}
		}
	}

	ReadFile.close();

	//std::cout << iResult << std::endl;		//1 part
	
	int iResult = 0;		//2 part
	for (int i = 0; i < 3; i++)
	{
		iResult += iMax[i];
		std::cout << iMax[i] << std::endl;
	}
	
	std::cout << "-------------------------------" << std::endl;
	std::cout << iResult << std::endl;
	std::cout << "-------------------------------" << std::endl;

	std::cout << "End of program" << std::endl;
}

