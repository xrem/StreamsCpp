#include <iostream>
#include <string>
// ���������� �������������� ������������ ��� io-�������
#include <iomanip>
// ��������� �������������� ������� ��������� ������ ��������
#include <cctype>
// ���������� ���������� ��� ������ � ��������� ��������.
#include <fstream>
// ����������� stringstream
#include <sstream>

void checkState(const std::istream& stream)
{
	if (stream.good())
	{
		std::cout << "Everything is good." << std::endl;
	}
	if (stream.bad())
	{
		std::cout << "Fatal error." << std::endl;
	}
	if (stream.fail())
	{
		std::cout << "Non fatal error." << std::endl;
	}
	if (stream.eof())
	{
		std::cout << "End of file." << std::endl;
	}
}

void main()
{
	int age;
	std::string s;

	while (true) {
		// ����� - ��������� ��������������� �/��� ����������� ����� ������ (� ��������� ��� �������� ����).
		// 1.789271287
		std::cout << "Enter your age:" << std::endl;

		// ����� ������ ������?
		std::istream; // ������������ �������� ������ >>
		std::ostream; // ������������ �������� ������ <<
		std::iostream; // ������������ ��� ������ ��� � ������.

		// ���������
		// ����� ������.
		
		std::cin >> age;
		if (!std::cin.good())
		{
			std::cout << "Incorrect input. Please try again." << std::endl;
			// ������� ������ � ����������� ��������� (����� ���������)
			std::cin.clear();
			std::cin.ignore(300, '\n');
			continue;
		}

		if (age < 0)
		{
			std::cout << "Age must be a positive number. Please try again." << std::endl;
			continue;
		}

		if (age < 4)
		{
			std::cout << "You are too young. Please try again" << std::endl;
			continue;
		}

		break;
	}
	// �� ����� ������� ��������� �������, ������� set flag:
	std::cout.setf(std::ios::hex);
	// � ���������:
	std::cout.unsetf(std::ios::dec);
	// std::nouppercase - ����������� ��� �������� �������� ���� �������� ������������ ������.
	std::cout << std::nouppercase << "Your age in HEX: " << age << std::endl;

	// std::endl == '\n'
	

	// ������������. (����������� ������� ������� ����� �������� �� �����)
	std::cout << "Your age " << std::endl
		<< " In HEX: " << std::hex << age << std::endl
		<< " In DEC: " << std::dec << age << std::endl
		<< " In OCT: " << std::oct << age << std::endl;

	std::cout.unsetf(std::ios::oct);
	// ���������� ��������� ��� ����� � ������:
	std::cout << std::setbase(2);
	std::cout << age << std::endl;


	std::string user_input;
	std::cout << "What is your name and what is your age?" << std::endl;
	std::cin.ignore(32222, '\n');
	std::getline(std::cin, user_input);

	std::string temp;
	auto iter = user_input.begin();
	while (iter != user_input.end())
	{
		if (isdigit(*iter))
		{
			temp += *iter;
		}
		++iter;
	}
	std::cout << temp;

	// ��������� ����� �������������� ����� input-output stream.
	std::stringstream temp_string_stream;
	temp_string_stream << temp;
	int myAge;
	// � ������� ���������� ������ �� ����� ����� �������������� ������� ���� ������.
	temp_string_stream >> myAge;
	std::cout << "Your age " << std::endl
		<< " In HEX: " << std::hex << myAge << std::endl
		<< " In DEC: " << std::dec << myAge << std::endl
		<< " In OCT: " << std::oct << myAge << std::endl;

	// �������� ������
	std::fstream; // ������� �����
	std::ofstream; // ����� ���������� ������ � ���� ������
	std::ifstream; // ����� ���������� ������ �� ����� ������

	std::ifstream input_file;
	input_file.open("C:\\Users\\XAdmin\\source\\repos\\Streams\\Debug\\input_age.txt");
	checkState(input_file);
	int file_age;
	input_file >> file_age;
	checkState(input_file);
	// ���������.
	input_file.close();

	std::ofstream output_file;
	// app (append) - ����������� � ��� ������������ ����
	// ate (at the end) - ����� �������� ������� � ����� �����
	// trunc (truncate) - ������������ ����� ���� �� ���������� (� �������� ���� ���� ������)
	output_file.open("C:\\Users\\XAdmin\\source\\repos\\Streams\\Debug\\output_age.txt", std::ios::app | std::ios::ate);
	output_file << std::hex << file_age << std::endl;
	output_file.close();
}