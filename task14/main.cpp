#define CATCH_CONFIG_RUNNER 
#include "catch.hpp"
#include  "MovieRent.h"
#include <iostream>
using namespace std;

void makeOrder();

TEST_CASE("checking")
{
	MovieRent mr;
	mr.download("Movie", "ukr");

	ifstream f("Download/Movie.mov", ios::binary);
	REQUIRE(f.good() == true);
	ifstream f1("Download/Movie_ukr.acc", ios::binary);
	REQUIRE(f1.good() == true);
	ifstream f2("Download/Movie_ukr.sub", ios::binary);
	REQUIRE(f2.good() == true);

	ifstream f3("Download/Movie_eng.sub", ios::binary);
	REQUIRE(f3.good() == false);

	mr.download("Movie", "eng");

	ifstream f4("Download/Movie_eng.sub", ios::binary);
	REQUIRE(f4.good() == true);

	mr.download("Movie", "fr");

	ifstream f5("Download/Movie_fr.sub", ios::binary); //there isn't franch language
	REQUIRE(f5.good() == false);
}

int main(int argc, char* argv[])
{
	int result = Catch::Session().run(argc, argv);
	getchar();
	return result;
}

void makeOrder()
{
	string name, lang;
	cout << "Enter name of the movie\n";
	getline(cin, name);
	cout << "Enter the language\n";
	getline(cin, lang);

	MovieRent mr;
	mr.download(name, lang);

	cout << "Done!\n";
}