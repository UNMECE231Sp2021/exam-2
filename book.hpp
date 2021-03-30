#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

enum class Genre {
	Adventure,
	Comedy,
	Drama,
	Lyric,
	Romance,
	Superhero,
	Textbook,
	Tragedy
};

class Book {
	protected:
		std::string _title;
		std::string _author;
		Genre _genre;
		std::string _genre_str;
		std::string _isbn;
		unsigned int _pages;

	public:
		Book(std::string title, std::string author, Genre genre,
			std::string isbn, unsigned int pages);
		Book(const Book &b);
		~Book();

		// Getters
		std::string title() const;
		std::string author() const;
		Genre genre() const;
		std::string genre_str() const;
		std::string isbn() const;
		unsigned int pages() const;

		// Setters
		virtual void set_title(std::string new_title);
		virtual void set_author(std::string new_author);
		virtual void set_genre(Genre new_genre);
		virtual void set_isbn(std::string new_isbn);
		virtual void set_pages(unsigned int pages);

		virtual std::string genre_to_str();
		void print();

		Book &operator=(const Book &b);

		friend std::ostream &operator<<(std::ostream &out, const Book &b);
};
#endif
