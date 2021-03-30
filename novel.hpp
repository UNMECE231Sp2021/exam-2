#ifndef NOVEL_H
#define NOVEL_H

#include "book.hpp"

class Novel : public Book {
	private:
		unsigned int _edition;
		unsigned int _rating;

		std::string get_edition_suffex();
	public:
		Novel(std::string title, std::string author, Genre genre,
			std::string isbn, unsigned int pages);
		Novel(std::string title, std::string author, Genre genre,
			std::string isbn, unsigned int pages, unsigned int edition,
			unsigned int rating);
		Novel(const Novel &n);

		// Getters
		unsigned int edition() const;
		unsigned int rating() const;

		// Setters
		void set_edition(unsigned int new_edition);
		void set_rating(unsigned int new_rating);

		void print();

		Novel &operator=(const Novel &n);

		friend std::ostream &operator<<(std::ostream &out, const Novel &n);
};
#endif
