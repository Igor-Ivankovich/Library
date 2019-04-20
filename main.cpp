#include <map>
#include "library.hpp"
#include "reader.hpp"

int main() {
	setlocale(LC_ALL,"Russian");
	reader obj;
	obj.buff_books();
	obj.buff_login();
	obj.buff_name();
	obj.buff_my_books();
	obj.panel();
	return EXIT_SUCCESS;
}
