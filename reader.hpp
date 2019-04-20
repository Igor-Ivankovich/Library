class reader : public library {
	std::string name;
	std::string surname;
	std::string username;
	std::string password;
	std::multimap<std::string,std::string> log_reader;
	std::multimap<std::string,std::string> log;
	std::multimap<std::string,std::string> name_reader;
public:
	void change_pas();
	void panel();
	void return_book();
	void take_book() ;
	void yourself_inf();
	void all_users();
	void reader_search();
	void panel_reader();
	void login();
	void registration();
	void buff_my_books();
	void buff_name();
	void buff_login();
};
