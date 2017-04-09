#include "MovieRent.h"
#include <iostream>

MovieRent::MovieRent()
{
	factory["ukr"] = std::make_unique<UkrMovieFactory>();
	factory["eng"] = std::make_unique<EngMovieFactory>();
}

void MovieRent::download(std::string movieName, std::string language)
{
	if (!factory.count(language))
	{
		std::cout << "There isn't " << language << " language\n";
		return;
	}
	auto moviePtr = factory.at(language)->make(movieName);

	copyTo(moviePtr.get() , ".\\Download");
}


