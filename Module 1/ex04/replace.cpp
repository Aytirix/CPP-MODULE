#include "replace.hpp"

Replace::Replace() {}

Replace::~Replace()
{
	_file.close();
	_new_file.close();
}

int Replace::init_file(const std::string filename, const std::string s1, const std::string s2)
{
	this->_s1 = s1;
	this->_s2 = s2;
	this->_filename = filename;
	this->_file.open(this->_filename.c_str());
	if (!_file.is_open())
	{
		std::cout << "Error: could not open file \033[31m" << this->_filename << "\033[0m" << std::endl;
		return false;
	}
	_new_filename = _filename + ".replace";
	_new_file.open(_new_filename.c_str());
	if (!_new_file.is_open())
	{
		std::cout << "Error: could not create new file \033[31m" << _new_filename << "\033[0m" << std::endl;
		return false;
	}
	return true;
}

const std::string Replace::SearchAndReplace(std::string line)
{
	size_t pos = 0;
	while ((pos = line.find(this->_s1, pos)) != std::string::npos)
	{
		for (size_t i = 0; i < this->_s2.length(); i++)
		{
			if (i < this->_s1.length())
				line[pos + i] = this->_s2[i];
			else
				line.insert(pos + i, 1, this->_s2[i]);
		}
		pos += this->_s2.length();
	}
	return line;
}

int Replace::replace(std::string filename, std::string s1, std::string s2)
{
	if (init_file(filename, s1, s2) == false)
		return false;
	while (std::getline(this->_file, this->line))
		_new_file << SearchAndReplace(this->line) << std::endl;
	return true;
}
