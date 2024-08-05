
#include <iostream>
#include <fstream>

std::string	readfile(std::ifstream &in)
{
	std::string str;
	int size;

	in.seekg(0, std::ios::end);
	size = in.tellg();
	str.resize(size);
	in.seekg(0, std::ios::beg);
	in.read(&str[0], size);
	return (str);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Input Error" << std::endl;;
		return (1);
	}
	std::string filename = argv[1];
	std::string f_str = argv[2];
	std::string s_str = argv[3];
	if (f_str.length() == 0)
	{
		std::cout << "first string error" << std::endl;
		return (1);
	}

	std::ifstream in(filename.c_str());
	if (in.is_open() == false)
	{
		std::cout << "File open is error" << std::endl;
		return (1);
	}

	std::ofstream out((filename.append(".replace")).c_str());
	if (out.is_open() == false)
	{
		std::cout << "File open is error" << std::endl;
		return (1);
	}
	
	std::string contents = readfile(in);
	std::size_t pos = 0;
	std::size_t offset = 0;

	while (1)
	{
		pos = contents.find(f_str, offset);
		if (pos != std::string::npos)
		{
			contents.erase(pos, f_str.length());
			contents.insert(pos, s_str);
			offset += s_str.length();
		}
		else
			break ;
	}

	out << contents;
	in.close();
	out.close();

	return (0);
}
