#include"pch.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<ctime>
#include<cstdlib>
using namespace std;
char Number()//得到一个0到4的随机数分别代表加，减，乘，除运算符
{
	int i = 1 + rand() % 4;
	return i;
}
void solver(int num)
{
	fstream question;//存储题目
	fstream answer;//存储答案
	question.open("question.txt", ios::out);
	answer.open("answer.txt", ios::out);
	question.close();
	answer.close();
	question.open("question.txt", ios::app);
	answer.open("answer.txt", ios::app);
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int c1, c2, c3;//c1,c2,c3表示将要生成的运算符
	int shuzi = 0;//表达式中数字的个数
	srand(time(nullptr));
	for (int i = 1; i <= num; i++)
	{
		shuzi = rand() % 2;//运算题中的数字的个数:2或3
		a = rand() % 100;
		b = rand() % 100;
		c = rand() % 100;
		d = rand() % 100;
		c1 = Number();
		c2 = Number();
		c3 = Number();
		if (shuzi == 1)//判断运算数的个数
		{
			switch (c1)
			{
			case 1:
			case 2:
				switch (c2)
				{
				case 1:
				case 3:
					switch (c3)
					{
					case 1:
						question << a << '+' << b << '+' << c << '+' << d << '=' << endl;
						answer << a + b + c + d << endl;
						break;
					case 2:
						while (c - d < 0)
						{
							c = rand() % 100;
							d = rand() % 100;
						}
						question << a << '+' << b << '+' << c << '-' << d << '=' << endl;
						answer << a + b + c - d << endl;
						break;
					case 3:
						question << a << '+' << b << '+' << c << '*' << d << '=' << endl;
						answer << a + b + c * d << endl;
						break;
					case 4:
						while (d == 0 || c != d * (c / d))
						{
							c = rand() % 100;
							d = rand() % 100;
						}
						question << a << '+' << b << '+' << c << '/' << d << '=' << endl;
						answer << a + b + c / d << endl;
						break;
					default:
						break;
					}
					break;
				case 2:
				case 4:
					switch (c3)
					{
					case 1:
						while (b - c < 0)
						{
							b = rand() % 100;
							c = rand() % 100;
						}
						question << a << '+' << b << '-' << c << '+' << d << '=' << endl;
						answer << a + b - c + d << endl;
						break;
					case 2:
						while (a + b - c - d < 0)
						{
							a = rand() % 100;
							b = rand() % 100;
							c = rand() % 100;
							d = rand() % 100;
						}
						question << a << '+' << b << '-' << c << '-' << d << '=' << endl;
						answer << a + b - c - d << endl;
						break;
					case 3:
						while (a + b - c * d < 0)
						{
							a = rand() % 100;
							b = rand() % 100;
							c = rand() % 100;
							d = rand() % 100;
						}
						question << a << '+' << b << '-' << c << '*' << d << '=' << endl;
						answer << a + b - c * d << endl;
						break;
					case 4:
						while (d == 0 || c != d * (c / d) || a + b - c / d < 0)
						{
							a = rand() % 100;
							b = rand() % 100;
							c = rand() % 100;
							d = rand() % 100;
						}
						question << a << '+' << b << '-' << c << '/' << d << '=' << endl;
						answer << a + b - c / d << endl;
						break;
					default:
						break;
					}break;
				default:
					break;
				}
				break;
			case 3:
			case 4:
				/*				switch (c2)
								{
								case 1:
								case 2:
								case 3:
								case 4: */
				switch (c3)
				{
				case 1:
					question << a << '*' << b << '+' << c << '+' << d << '=' << endl;
					answer << a * b + c + d << endl;
					break;
				case 2:
					while (c - d < 0)
					{
						c = rand() % 100;
						d = rand() % 100;
					}
					question << a << '*' << b << '+' << c << '-' << d << '=' << endl;
					answer << a * b + c - d << endl;
					break;
				case 3:
					question << a << '*' << b << '+' << c << '*' << d << '=' << endl;
					answer << a * b + c * d << endl;
					break;
				case 4:
					while (d == 0 || c != d * (c / d))
					{
						c = rand() % 100;
						d = rand() % 100;
					}
					question << a << '*' << b << '+' << c << '/' << d << '=' << endl;
					answer << a * b + c / d << endl;
					break;
				default:
					break;
				}
				break;
				//}
		//	default:
		//		break;
			}
		}
		else if (shuzi == 0)//三个运算数
		{
			switch (c1)//第一个运算符
			{
			case 1:
				switch (c2)//第二个运算符
				{
				case 1:
					question << a << '+' << b << '+' << c << '=' << endl;
					answer << a + b + c << endl;
					break;
				case 2:
					while (b - c < 0)
					{
						b = rand() % 100;
						c = rand() % 100;
					}
					question << a << '+' << b << '-' << c << '=' << endl;
					answer << a + b - c << endl;
					break;
				case 3:
					question << a << '+' << b << '*' << c << '=' << endl;
					answer << a + b * c << endl;
					break;
				case 4:
					while (c == 0 || b != c * (b / c))//控制结果不出现小数且除数不为0
					{
						b = rand() % 100;
						c = rand() % 100;
					}
					question << a << '+' << b << '/' << c << '=' << endl;
					answer << a + b / c << endl;
					break;
				default:
					break;
				}
				break;
			case 2:
				switch (c2)//第二个运算符
				{
				case 1:
					question << a << '-' << b << '+' << c << '=' << endl;
					answer << a - b + c << endl;
					break;
				case 2:
					while (a - b - c < 0)
					{
						b = rand() % 100;
						c = rand() % 100;
					}
					question << a << '-' << b << '-' << c << '=' << endl;
					answer << a - b - c << endl;
					break;
				case 3:
					while (a - b * c < 0)
					{
						a = rand() % 100;
						b = rand() % 100;
						c = rand() % 100;
					}
					question << a << '-' << b << '*' << c << '=' << endl;
					answer << a - b * c << endl;
					break;
				case 4:
					while (c == 0 || b != c * (b / c))//控制结果不出现小数且除数不为0
					{
						b = rand() % 100;
						c = rand() % 100;
					}
					question << a << '-' << b << '/' << c << '=' << endl;
					answer << a - b / c << endl;
					break;
				default:
					break;
				}
				break;
			case 3:
				switch (c2)//第二个运算符
				{
				case 1:
					question << a << '*' << b << '+' << c << '=' << endl;
					answer << a * b + c << endl;
					break;
				case 2:
					while (b - c < 0)
					{
						b = rand() % 100;
						c = rand() % 100;
					}
					question << a << '*' << b << '-' << c << '=' << endl;
					answer << a * b - c << endl;
					break;
				case 3:
					question << a << '*' << b << '*' << c << '=' << endl;
					answer << a * b * c << endl;
					break;
				case 4:
					while (c == 0 || b != c * (b / c))//控制结果不出现小数且除数不为0
					{
						b = rand() % 100;
						c = rand() % 100;
					}
					question << a << '*' << b << '/' << c << '=' << endl;
					answer << a * b / c << endl;
					break;
				default:
					break;
				}
				break;
			case 4:
				switch (c2)//第二个运算符
				{
				case 1:
					while (b == 0 || a != b * (a / b))
					{
						a = rand() % 100;
						b = rand() % 100;
					}
					question << a << '/' << b << '+' << c << '=' << endl;
					answer << a / b + c << endl;
					break;
				case 2:
					while (b == 0 || a != b * (a / b) || a / b - c < 0)
					{
						a = rand() % 100;
						b = rand() % 100;
						c = rand() % 100;
					}
					question << a << '/' << b << '-' << c << '=' << endl;
					answer << a / b - c << endl;
					break;
				case 3:
					while (b == 0 || a != b * (a / b))
					{
						a = rand() % 100;
						b = rand() % 100;
					}
					question << a << '/' << b << '*' << c << '=' << endl;
					answer << a / b * c << endl;
					break;
				case 4:
					while (b == 0 || a != b * (a / b) || c == 0 || (a / b) != c * ((a / b) / c))//控制结果不出现小数且除数不为0
					{
						a = rand() % 100;
						b = rand() % 100;
						c = rand() % 100;
					}
					question << a << '/' << b << '/' << c << '=' << endl;
					answer << a / b / c << endl;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
	}
	question.close();
	answer.close();
}
int main()
{
	int num = 0;//记录用户想要出的题目的个数
	cout << "请输入需要的题目数：";
	cin >> num;
	solver(num);
	cout << "题目与答案已写入相应文件，请自行进入文件查看！" << endl;
	system("pause");
	return 0;
}