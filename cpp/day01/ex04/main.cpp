#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

void	replace( char **av )
{
	// args : strings 
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	// files : input / output
	std::ofstream	dest_file;
	std::ifstream	source_file;
	// buffers
	std::string		line;
	std::string		dest_filename;
	int				pos;

	// OPEN SOURCE FILE
	source_file.open ( av[1], std::ifstream::in );
	if ( !source_file.is_open() )
	{
		std::cout << "Error, coulnd't open " << av[1] << std::endl;
		return ;
	}
	// OPEN DEST FILE
	dest_filename = av[1] + (std::string)".replace";
	dest_file.open(  dest_filename.c_str(), std::ostream::out );
	if ( !dest_file.is_open() )
	{
		std::cout << "Error, can't create " << av[1] << ".replace" << std::endl;
		return ;
	}

	// REPLACE
	while ( std::getline(source_file, line) )
	{
		pos = 0;
		while (line[pos])
		{
			//	compare line and s1, from start = pos, to end = pos + s1_len
			if ( line.compare(pos, s1.length(), s1) == 0 )
			{
				dest_file << s2;
				pos += s1.length();
			}
			else
				dest_file << line[pos++];
		}
		dest_file << '\n';
	}

	// CLOSE FILES
	source_file.close ();
	dest_file.close ();
	return ;
}

int		parse_error( int ac, char **av )
{
	// ARG NUMBER
	if ( ac != 4)
	{
		std::cout << "Wrong arguments number." << std::endl;
		return (-1);
	}
	// NULL ARGS
	if ( !av[1] || !av[2] || !av[3] )
	{
		std::cout << "Error, NULL arguments." << std::endl;
		return (-1);
	}

	std::string		a = av[1];
	std::string		b = av[2];
	std::string		c = av[3];

	// EMPTY ARGS
	if ( a.length() == 0 || b.length() == 0 || c.length() == 0 )
	{
		std::cout << "Error, empty arguments." << std::endl;
		return (-1);
	}
	return (1);
}

int		main( int ac, char **av )
{
	if ( (parse_error( ac, av )) < 0 )
		return (-1);
	replace( av );
	return (0);
}
