#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "book.h"

/*
*	Merge book list files without creating duplicate entries
*	@param argc Number of supplied command-line arguments
*	@param argv Names of files containing book entries
*/
int main(int argc, char** argv)
{
	std::vector<Book> books;
	std::ofstream mergedBookFile{ "mergedBookFile.txt" };
	for (int i = 1; i < argc; i++)
	{
		std::ifstream inBookFile{ argv[i] };
		while (!inBookFile.eof())
		{
			std::string bookInformation;
			getline(inBookFile, bookInformation);
			size_t const tab1{ bookInformation.find('\t') };
			size_t const authorInformationTab{ tab1 + 1 };
			size_t const tab2{ bookInformation.find('\t', authorInformationTab) };
			Book const newBook
			{
				Book(
					bookInformation.substr(0, tab1),
					bookInformation.substr(authorInformationTab, tab2 - tab1 - 1),
					bookInformation.substr(tab2 + 1)
				)
			};
			if (std::find(books.begin(), books.end(), newBook) == std::end(books))
			{
				books.push_back(newBook);
				mergedBookFile << newBook.toString() << '\n';
			}
		}
	}
	std::cout << "The merged book list contains " << books.size() - 1 << " books\n";
}
