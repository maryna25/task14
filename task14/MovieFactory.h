#pragma once
#include "Movie.h"
#include <memory>

class MovieFactory
{
public:
	virtual ~MovieFactory()
	{
	}

	virtual std::unique_ptr<Movie> make(std::string name) = 0;
};

class UkrMovieFactory :public MovieFactory
{
public:
	std::unique_ptr<Movie> make(std::string name) override
	{
		return std::unique_ptr<UkrMovie>(new UkrMovie(name));
	}
};

class EngMovieFactory :public MovieFactory
{
public:
	std::unique_ptr<Movie> make(std::string name) override
	{
		return std::unique_ptr<EngMovie>(new EngMovie(name));
	}
};


