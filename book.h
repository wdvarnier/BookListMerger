#pragma once
#include <iostream>

/* A written work */
class Book
{
public:
	Book(
		std::string const& inID,
		std::string const& inAuthorInformation,
		std::string const& inTitle
	);
	
	/* Books are compared based on ID */
	bool operator==(Book const& book) const;

	std::string toString() const;
private:
	/* Unique identifier */
	std::string ID;

	/* Author's name and years lived */
	std::string authorInformation;

	/* Name of the book */
	std::string title;
};
