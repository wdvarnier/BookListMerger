#include "book.h"

Book::Book(
	std::string const& inID,
	std::string const& inAuthorInformation,
	std::string const& inTitle) :
	ID(inID),
	authorInformation(inAuthorInformation),
	title(inTitle)
{
}

bool Book::operator==(Book const& book) const
{
	return ID == book.ID;
}

std::string Book::toString() const
{
	return ID + '\t' + authorInformation + '\t' + title;
}
