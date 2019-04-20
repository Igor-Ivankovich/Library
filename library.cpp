#include <iostream>
#include <fstream>
#include <map>
#include "library.hpp"

void library::book_search() {
	system("clear");
	std::string name_b;
	std::string name_a;
	int i ;
	int num;
	bool exit = true;
	while(exit) {
		i = 0;
		std::cout << "Введите название книги: ";
		std::cin.ignore();
		std::getline(std::cin, name_b);
		std::cout << "Введите Автора: " ;
		std::getline(std::cin, name_a);
		system("clear");
		std::multimap <std::string,std::string> :: iterator it_b;
		it_b = name_book.find(name_b);
		if(name_b == it_b->first) {
			std::cout << "Название: " << it_b->first << std::endl;
			std::cout << "Автор: " << it_b->second << std::endl;
			std::cout << "Количество книг: " 
					  << name_book.count(it_b->first) 
					  << std::endl << std::endl;
			i++;
		}
		if(!i) 
			std::cout << "Книга не найдена" <<std::endl;
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
void library::all_books() {
	int num;
	std::string name_repet;
	for(auto &p : name_book) {
		if(name_repet == p.first)
			continue;
		else {
			std::cout << "Название: " << p.first << std::endl;
			std::cout << "Автор: " << p.second << std::endl;
			std::cout << "Количество книг: " << name_book.count(p.first) 
					  << std::endl << std::endl;
			name_repet = p.first;
		}
	}
	do {
		std::cout <<"1-Вернуться назад" << std::endl;
		std::cin >> num;
		system("clear");
	}while(num != 1);
	system("clear");
}
void library::add_book() {
	std::string book;
	std::string author;
	std::ofstream file_book("/home/john/LB2/library/library.txt",
								  std::ios::app);
	std::cout << "Введите название книги: " ;
	std::cin.ignore();
	std::getline(std::cin, book);
	std::cout << "Введите автора: ";
	std::getline(std::cin, author);
	file_book << book << '\n';
	file_book << author << '\n';
	file_book.close();
	name_book.emplace(book, author);
	system("clear");
}
void library::buff_books() {
	std::string word;
	std::string name_b;
	std::ifstream file_books("/home/john/LB2/library/library.txt",
	                       std::ios::in);
	while (getline(file_books,name_b)) {
			getline(file_books,word);
			name_book.emplace(name_b, word);
	}
	file_books.close();
}
