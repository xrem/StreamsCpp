#include <iostream>
#include <string>
// Подключаем дополнительные манипуляторы для io-потоков
#include <iomanip>
// Подключим дополнительные функция валидации набора символов
#include <cctype>
// Подключить библиотеку для работы с файловыми потоками.
#include <fstream>
// Подключение stringstream
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
		// Поток - контейнер предоставляющий и/или принимающий набор данных (в текстовом или бинарном виде).
		// 1.789271287
		std::cout << "Enter your age:" << std::endl;

		// Какие бывают потоки?
		std::istream; // Поддерживает оператор чтения >>
		std::ostream; // Поддерживает оператор записи <<
		std::iostream; // Поддерживает как чтение так и запись.

		// Состояние
		// Набор данных.
		
		std::cin >> age;
		if (!std::cin.good())
		{
			std::cout << "Incorrect input. Please try again." << std::endl;
			// Возврат потока в изначальное состояние (сброс состояния)
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
	// Мы можем вручную управлять флагами, вызывая set flag:
	std::cout.setf(std::ios::hex);
	// И отключать:
	std::cout.unsetf(std::ios::dec);
	// std::nouppercase - манипулятор для указания регистра букв которыми представлены данные.
	std::cout << std::nouppercase << "Your age in HEX: " << age << std::endl;

	// std::endl == '\n'
	

	// Манипуляторы. (Специальные объекты которые могут повлиять на поток)
	std::cout << "Your age " << std::endl
		<< " In HEX: " << std::hex << age << std::endl
		<< " In DEC: " << std::dec << age << std::endl
		<< " In OCT: " << std::oct << age << std::endl;

	std::cout.unsetf(std::ios::oct);
	// Установить основание для чисел в потоке:
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

	// Временный поток представляющий собой input-output stream.
	std::stringstream temp_string_stream;
	temp_string_stream << temp;
	int myAge;
	// В помощью временного потока мы легко может конвертировать базовые типы данных.
	temp_string_stream >> myAge;
	std::cout << "Your age " << std::endl
		<< " In HEX: " << std::hex << myAge << std::endl
		<< " In DEC: " << std::dec << myAge << std::endl
		<< " In OCT: " << std::oct << myAge << std::endl;

	// Файловые потоки
	std::fstream; // базовый класс
	std::ofstream; // Поток позволящий писать в файл данные
	std::ifstream; // Поток позволящий читать из файла данные

	std::ifstream input_file;
	input_file.open("C:\\Users\\XAdmin\\source\\repos\\Streams\\Debug\\input_age.txt");
	checkState(input_file);
	int file_age;
	input_file >> file_age;
	checkState(input_file);
	// Закрываем.
	input_file.close();

	std::ofstream output_file;
	// app (append) - дописывание в уже существующий файл
	// ate (at the end) - после открытия перейти в конец файла
	// trunc (truncate) - пересоздание файла если он существует (и создание если него небыло)
	output_file.open("C:\\Users\\XAdmin\\source\\repos\\Streams\\Debug\\output_age.txt", std::ios::app | std::ios::ate);
	output_file << std::hex << file_age << std::endl;
	output_file.close();
}