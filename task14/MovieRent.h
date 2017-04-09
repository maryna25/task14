#pragma once
#include <map>
#include <memory>
#include "MovieFactory.h"


class MovieRent
{
	std::map<std::string, std::unique_ptr<MovieFactory>> factory;
public:
	MovieRent();
	~MovieRent(){};

	void download(std::string movieName,std::string language);
};
