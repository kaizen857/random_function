
#include<iostream>
#include<Windows.h>
#include<random>
#include<conio.h>
#include<string>
#include<algorithm>
#include <stdexcept>

#pragma warning(disable:6386)
#pragma warning(disable:6302)

void parse(std::string command);
void generate_one(int para1);
void generate_number(int para1, int para2, int para3);
std::random_device rd;
std::mt19937 mt(rd());
int para1, para2, para3;
std::string command;
std::vector<int> num_used;

int main(void)
{
	using namespace std;
	char currentUser[100] = { 0 };
	DWORD dwSize_currentUser =100;
	GetUserName((LPWSTR)currentUser,&dwSize_currentUser	);
	cout << "随机数生成引擎ver1.02(bug fixed)  create by kaizen-857" << endl << "项目地址：https://github.com/kaizen857/random_function"
		<< endl << "查看输入说明，请使用help" << endl;
	printf("%S>", currentUser);
	getline(cin, command);
	num_used.push_back(0);
	
	while (true)
	{
		parse(command);
		printf("%S>", currentUser);
		getline(cin, command);
	}
}


void parse(std::string command)
{
	using namespace std;
	bool is_one = true;
	if (command == "help")
	{
		cout << "[num1]\t从[1,num2]中抽取1个整数" << endl;
		cout << "[num1] [num2] [num3]\t从[num1,num2]中抽取num3个整数" << endl;
		return;
	}
	else
	{
		try
		{
			auto blank = command.find_first_of(" ");
			para1 = stoi(command);
			if (blank < command.size())//参数不是一位时
			{
				command = command.substr(blank + 1);
				blank = command.find_first_of(" ");
				para2 = stoi(command);

				if (blank > command.size())
				{
					std::cerr << " Invalid_argument in command!" << std::endl;
					return;
				}
				command = command.substr(blank + 1);
				para3 = stoi(command);

				is_one = false;
			}

		}
		catch (std::invalid_argument& e)
		{
			std::cerr << " Invalid_argument: " << e.what() << "!" << std::endl;
			return;//输入数为非数字
		}
		catch (std::out_of_range& e)
		{
			std::cerr << " argument out of range: " << e.what() << "!" << std::endl;
			return;//输入数过大
		}
	}
	

	if (is_one)
	{
		generate_one(para1);//只生成一个数
	}
	else
	{
		generate_number(para1, para2, para3);//生成para3个数
	}

	return;
}

void generate_one(int para1)
{
	using namespace std;
	if (para1 == 1 || para1 == 0)
	{
		std::cerr << " Invalid_argument!" << std::endl;
		return;
	}
	uniform_int_distribution<> dis(1, para1);
	int output;
	auto bo = num_used.begin();
	output = dis(mt);
	bo = find(num_used.begin(), num_used.end(), output);
	while (bo != num_used.end())
	{
		output = dis(mt);
		bo = find(num_used.begin(), num_used.end(), output);
	}
	cout << output << endl;
	num_used.push_back(output);
	if (num_used.size() > 50)
	{
		num_used.clear();
	}
	return;
}

void generate_number(int para1, int para2, int para3)
{
	using namespace std;
	if (para2 < para1)
	{
		std::cerr << " Invalid_argument!" << std::endl;
		return;
	}
	if ((para2 - para1) < para3)
	{
		std::cerr << " Invalid_argument!" << std::endl;
		return;
	}
	uniform_int_distribution<> dis(para1, para2);
	int output;
	auto bo = num_used.begin();
	for (int i = 0; i < para3; ++i)
	{
		output = dis(mt);
		bo = find(num_used.begin(), num_used.end(), output);
		while (bo != num_used.end())
		{
			output = dis(mt);
			bo = find(num_used.begin(), num_used.end(), output);
		}
		cout << output << endl;
		num_used.push_back(output);
		if (num_used.size() > 50)
		{
			num_used.clear();
		}
	}
}