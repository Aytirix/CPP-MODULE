#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace
{
	public:
		Replace();
		~Replace();
		int replace(std::string filename, std::string s1, std::string s2);
	private:
		int init_file(std::string filename, std::string s1, std::string s2);
		const std::string SearchAndReplace(std::string line);
		std::string line;
		std::string _s1;
		std::string _s2;
		std::string _filename;
		std::ifstream _file;
		std::string _new_filename;
		std::ofstream _new_file;
};
#endif