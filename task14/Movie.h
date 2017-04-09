#pragma once

#include <string>
#include <fstream>

class MovieFactory;
class Movie
{
	std::ifstream filmFile;
	std::ifstream trackFile;
	std::ifstream subFile;

	std::string name;
	std::string lang;

protected:  
	Movie(std::string name, std::string track, std::string sub, std::string _name, std::string _lang)
		:	filmFile(name, std::fstream::binary), trackFile(track, std::fstream::binary), subFile(sub, std::fstream::binary),
			name(_name),lang(_lang)
	{
		if (!filmFile.good())		throw std::exception("File do not exist");
		if (!trackFile.good())		throw std::exception("File do not exist");
		if (!subFile.good())		throw std::exception("File do not exist");
	};
public:
	virtual ~Movie(){};
	friend void copyTo(Movie*mov, std::string path)
	{
		std::ofstream filmCopy	(path +"\\" + mov->name + ".mov", std::fstream::binary);
		std::ofstream trackCopy	(path +"\\" + mov->name + "_"+mov->lang + ".acc", std::fstream::binary);
		std::ofstream subCopy	(path +"\\" + mov->name + "_"+mov->lang + ".sub", std::fstream::binary);

		filmCopy << mov->filmFile.rdbuf();
		trackCopy << mov->trackFile.rdbuf();
	    subCopy<< mov->subFile.rdbuf();
	};
};


class UkrMovieFactory;
class UkrMovie : public Movie
{
	UkrMovie(std::string name)
		:Movie(name + ".mov", name + "_ukr" + ".acc", name + "_ukr" + ".sub",name,"ukr"){};
	friend class UkrMovieFactory;
};


class EngMoviefactory;
class EngMovie : public Movie
{
	EngMovie(std::string name)
		:Movie(name + ".mov", name + "_eng" + ".acc", name + "_eng" + ".sub",name,"eng"){};
	friend class EngMovieFactory;
};

