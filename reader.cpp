#include <iostream>
#include <fstream>
#include <map>
#include "library.hpp"
#include "reader.hpp"


void reader::change_pas() {
	std::cout << "Введите новый пароль: "<<std::endl;
	std::cin >> password;
	std::multimap <std::string,std::string> :: iterator it;
	it = log.find(username);
	log.erase(it);
	log.emplace(username, password);
	remove("/home/john/LB2/reader/log.txt");
	std::ofstream file_log("/home/john/LB2/reader/log.txt",
	                       std::ios::app);
	for( auto &p : log) {
		file_log << p.first << '\n';
		file_log << p.second << '\n';
	}
	file_log.close();
}
void reader::panel() {
	int num;
	bool exit = true;
	while(exit) {
		std::cout << "1 - Показать все книги"<<std::endl;
		std::cout << "2 - Показать всех пользователей"<<std::endl;
		std::cout << "3 - Найти книгу"<<std::endl;
		std::cout << "4 - Найти читателя"<<std::endl;
		std::cout << "5 - Регистрация читателя"<<std::endl;
		std::cout << "6 - Войти в библиотеку"<<std::endl;
		std::cout << "7 - Выход из программы"<<std::endl;
		std::cin >> num;
		switch(num) {
			case 1:system("clear");all_books();break;
			case 2:system("clear");all_users();break;
			case 3:system("clear");book_search();break;
			case 4:system("clear");reader_search();break;
			case 5:system("clear");registration();break;
			case 6:system("clear");login();break;
			case 7:system("clear");exit = false;break;
			default:system("clear");std::cout<< "Неправильный ввод" 
									<< std::endl;
		}
	}
}
void reader::return_book() {
	system("clear");
	std::string name_b;
	std::string name_a;
	bool exit = true;
	int num;
	while(exit) {
		std::cout << "Введите название книги: ";
		std::cin.ignore();
		std::getline(std::cin, name_b);
		std::cout << "Введите Автора: " ;
		std::getline(std::cin, name_a);
		system("clear");
		std::multimap <std::string,std::string> :: iterator it_b;
		it_b = my_books.find(username);
			if(name_b == it_b->second ) {
				my_books.erase(it_b);
				it_b++;
				my_books.erase(it_b);
				remove("/home/john/LB2/library/mybooks.txt");
				std::ofstream file_books("/home/john/LB2/library/mybooks.txt",std::ios::app);
				std::ofstream file_l("/home/john/LB2/library/library.txt",std::ios::app);
				for(auto &p : my_books) {
					file_books << p.first << '\n';
					file_books << p.second << '\n';
					
				}
				name_book.emplace(name_b, name_a);
				file_l << name_b << '\n';
				file_l << name_a << '\n';
				file_l.close();
				file_books.close();
				exit = false;
			}
			else {
				std::cout << "Книга не найдена" << std::endl;
				std::cout << "Повторить попытку?" <<std::endl;
				std::cout << "1-Да" <<std::endl;
				std::cout << "2-Нет" <<std::endl;
				std::cin >> num;
				switch(num) {
					case 1:system("clear");exit = true; break;
					case 2:system("clear");exit = false; ;break;
					default: std::cout<< "Неправильный ввод" << std::endl;
				}
			}
	}
}
void reader::take_book() {
	system("clear");
	std::string name_b;
	std::string name_a;
	bool exit = true;
	int num;
	while(exit) {
		std::cout << "Введите название книги: ";
		std::cin.ignore();
		std::getline(std::cin, name_b);
		std::cout << "Введите Автора: " ;
		std::getline(std::cin, name_a);
		system("clear");
		std::multimap <std::string,std::string> :: iterator it_b;
		it_b = name_book.find(name_b);
			if(name_b == it_b->first && name_a == it_b->second) {
				std::ofstream file_books("/home/john/LB2/library/mybooks.txt",std::ios::app);
				name_book.erase(it_b);
				remove("/home/john/LB2/library/library.txt");
				std::ofstream file_l("/home/john/LB2/library/library.txt",std::ios::app);
				
				for(auto &p : name_book) {
					file_l << p.first << '\n';
					file_l << p.second << '\n';
				}
				my_books.emplace(username, name_b);
				my_books.emplace(username, name_a);
				file_books <<username << '\n';
				file_books << name_b << '\n';
				file_books <<username << '\n';
				file_books << name_a << '\n';
				file_l.close();
				file_books.close();
				exit = false;
			}
			else {
				std::cout << "Книга не найдена" << std::endl;
				std::cout << "Повторить попытку?" <<std::endl;
				std::cout << "1-Да" <<std::endl;
				std::cout << "2-Нет" <<std::endl;
				std::cin >> num;
				switch(num) {
					case 1:system("clear");exit = true; break;
					case 2:system("clear");exit = false; ;break;
					default: std::cout<< "Неправильный ввод" << std::endl;
				}
			}
	}
}
void reader::yourself_inf() {
	int num;
	do {
		system("clear");
		std::cout << "Имя: " << name << std::endl;
		std::cout << "Фамилия: " << surname << std::endl;
		std::cout << "Username: " << username << std::endl;
		std::cout << "Пароль: " << password <<'\n'<< std::endl;
		std::multimap <std::string,std::string> :: iterator it;
		it = my_books.find(username);
		for (int i = 0; i < my_books.count(username); i++,++it) {
			std::cout << "Название Книги: " << it->second << std::endl;
			it++;
			i++;
			std::cout << "Автор: " << it->second <<'\n'<< std::endl;
		}
		std::cout <<"1-Сменить Пароль" <<std::endl;
		std::cout <<"2-Вернуться назад" << std::endl;
		std::cin >> num;
		switch(num) {
			case 1:system("clear");change_pas();break;
			case 2:system("clear"); break;
			default:system("clear");std::cout<< "Неправильный ввод" 
									<< std::endl;
		}
	}while(num != 2);
	
}
void reader::all_users() {
	int num;
	std::multimap <std::string,std::string> :: iterator it_loging;
	for (auto it = log_reader.begin();
		 it != log_reader.end(); ++it) {
			 std::cout <<"Username: " << it->first <<std::endl;
			 std::cout <<"Имя: " << it->second <<std::endl;
			 it++;
			 std::cout <<"Фамилия: " << it->second <<'\n'<<std::endl;
	}
	do {
		std::cout <<"1-Вернуться назад" << std::endl;
		std::cin >> num;
		system("clear");
	}while(num != 1);
	system("clear");
}
void reader::reader_search() {
	system("clear");
	std::string name_r;
	std::string surname_r;
	int i ;
	int num;
	bool exit = true;
	while(exit) {
		i = 0;
		std::cout << "Введите имя читателя: ";
		std::cin >> name_r;
		std::cout << "Введите фамилию: " ;
		std::cin >> surname_r;
		system("clear");
		for( auto it = log_reader.begin(); it != log_reader.end(); ++it) {
			if(it->second == name_r) {
				it++;
				if(it->second == surname_r) {
					std::cout <<"Username: " << it->first <<std::endl;
					std::cout <<"Имя: " << name_r <<std::endl;
					std::cout <<"Фамилия: " << surname_r <<'\n'<<std::endl;
					i++;
				}
			}
		}
		if(!i) {
			std::cout << "Пользователь не найден" <<std::endl;
		}
			std::cout << "Повторить попытку?" <<std::endl;
			std::cout << "1-Да" <<std::endl;
			std::cout << "2-Нет" <<std::endl;
			std::cin >> num;
			switch(num) {
				case 1:system("clear");exit = true; break;
				case 2:system("clear");exit = false; ;break;
				default: std::cout<< "Неправильный ввод" << std::endl;
			}
	}
}
void reader::panel_reader() {
	int num;
	bool exit = true;
	system("clear");
	while(exit) {
		std::cout << "1-Взять книгу" <<std::endl;
		std::cout << "2-Вернуть книгу" <<std::endl;
		std::cout << "3-Найти книгу" <<std::endl;
		std::cout << "4-Найти читателя" <<std::endl;
		std::cout << "5-Показать все книги" <<std::endl;
		std::cout << "6-Показать всех пользователей" <<std::endl;
		std::cout << "7-информация о читателе" <<std::endl;
		std::cout << "8-добавить книгу" <<std::endl;
		std::cout << "9-выйти из учетной записи" <<std::endl;
		std::cin >> num;
		switch(num) {
			case 1:system("clear");take_book(); break;
			case 2:system("clear");return_book(); break;
			case 3:system("clear");book_search(); break;
			case 4:system("clear");reader_search(); break;
			case 5:system("clear");all_books(); break;
			case 6:system("clear");all_users(); break;
			case 7:system("clear");yourself_inf(); break;
			case 8:system("clear");add_book(); break;
			case 9:system("clear");exit = false; break;
			default: system("clear");std::cout<< "Неправильный ввод"
									 << std::endl;
		}
	}
}
void reader::login() {
	std::string username_r;
	std::string password_r;
	int num;
	bool exit = true;
	std::multimap <std::string,std::string> :: iterator it_loging;
	while(exit) {
		std::cout << "Введите username: ";
		std::cin >> username_r;
		std::cout << "Введите пароль: ";
		std::cin >> password_r;
		it_loging = log.find(username_r);
		if (it_loging == log.end() ||it_loging->second != password_r) {
			system("clear");
			std::cout << "Неправильный username или пароль" << std::endl;
			std::cout << "Повторить попытку?" <<std::endl;
			std::cout << "1-Да" <<std::endl;
			std::cout << "2-Нет" <<std::endl;
			std::cin >> num;
			switch(num) {
				case 1:system("clear");exit = true; break;
				case 2:system("clear");exit = false; break;
				default: std::cout<< "Неправильный ввод" << std::endl;
			}
		}
		else {
			it_loging = log_reader.find(username_r);
			name = it_loging->second;
			it_loging++;
			surname = it_loging->second;
			username = username_r;
			password = password_r;
			exit = false;
			panel_reader();
		}
	}
	name.clear();
	surname.clear();
	username.clear();
	password.clear();
}
void reader::buff_my_books() {
	std::string word;
	std::string username_w;
	std::ifstream file_log("/home/john/LB2/library/mybooks.txt",
	                       std::ios::in);
	while (getline(file_log,username_w)) {
			getline(file_log,word);
			my_books.emplace(username_w, word);
	}
	file_log.close();
}
void reader::buff_name() {
	std::string word;
	std::string name_r;
	std::ifstream file_name("/home/john/LB2/reader/reader.txt",
	                       std::ios::in);
	while (file_name >> name_r >>name_r) {
			file_name >> word;
			name_reader.emplace(name_r, word);
	}
	file_name.close();
}
void reader::buff_login() {
	std::string word;
	std::string username_w;
	std::ifstream file_reader("/home/john/LB2/reader/reader.txt",
	                          std::ios::in);
	std::ifstream file_log("/home/john/LB2/reader/log.txt",
	                       std::ios::in);
	while (file_log >> username_w) {
			file_log >> word;
			log.emplace(username_w, word);
	}
	while (file_reader >> username_w) {
		for(int i = 0; i < 2; i++) {
			file_reader >> word;
			log_reader.emplace(username_w, word);
		}
	}
	file_log.close();
	file_reader.close();
}
void reader::registration() {
	std::string username_r;
	std::string password_r;
	std::string name_r;
	std::string surname_r;
	bool exit = true;
	while(exit) {
		std::ofstream file_regist("/home/john/LB2/reader/log.txt",
								  std::ios::app);
		std::ofstream file_rlog("/home/john/LB2/reader/reader.txt",
								  std::ios::app);
		std::cout << "Введите username: " ;
		std::cin >> username_r ;
		std::cout << "Введите пароль: ";
		std::cin >> password_r;
		std::multimap <std::string,std::string> :: iterator it_user;
		it_user = log.find(username_r);
		if (it_user == log.end()) {
			file_regist << username_r << '\n';
			file_regist << password_r << '\n';
			file_rlog << username_r << '\n';
			std::cout << "Введите имя: " ;
			std::cin >> name_r;
			file_rlog << name_r << '\n';
			std::cout << "Введите фамилию: " ;
			std::cin >> surname_r;
			file_rlog << surname_r << '\n';
			file_regist.close();
			file_rlog.close();
			log.emplace(username_r, password_r);
			log_reader.emplace(username_r, name_r);
			log_reader.emplace(username_r, surname_r);
			name_reader.emplace(username_r,surname_r);
			exit = false;
			system("clear");
		}
		else {
			system("clear");
			std::cout << "Такой username уже существует" <<std::endl;
			file_regist.close();
			file_rlog.close();
			exit = true;
		}
	}
}
