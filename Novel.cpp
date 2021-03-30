#include "novel.hpp"

Novel::Novel(std::string title, std::string author, Genre genre,
			std::string isbn, unsigned int pages) :
			Book(title, author, genre, isbn, pages) {}

Novel::Novel(std::string title, std::string author, Genre genre,
			std::string isbn, unsigned int pages, unsigned int edition,
			unsigned int rating) : 
			Book(title, author, genre, isbn, pages),
			_edition{1}, _rating{3} {
	set_edition(edition);
	set_rating(rating);
}

Novel::Novel(const Novel &n) : Book(n._title, n._author, n._genre, n._isbn,
		n._pages), _edition{n._edition}, _rating{n._rating} { }

std::string Novel::get_edition_suffex() {
	unsigned int temp_edition = _edition;
	unsigned int left_most_number;
	while(temp_edition > 0) {
		left_most_number = temp_edition;
		temp_edition = temp_edition/10;
	}

	std::string edition_suffex("th");
	switch(left_most_number) {
		case 1:
			edition_suffex = "st";
			break;
		case 2:
			edition_suffex = "nd";
			break;
		case 3:
			edition_suffex = "rd";
			break;
		default:
			edition_suffex = "th";
			break;
	}
	return edition_suffex;
}

unsigned int Novel::edition() const {
	return _edition;
}

unsigned int Novel::rating() const {
	return _rating;
}

void Novel::set_edition(unsigned int new_edition) {
	if (new_edition < 1) {
		_edition = 1;
	}
	else {
		_edition = new_edition;
	}
}

void Novel::set_rating(unsigned int new_rating) {
	if (new_rating < 6) {
		_rating = 5;
	}
	else {
		_rating = new_rating;
	}
}

void Novel::print() {
	Book::print();
	std::string edition_suffex = get_edition_suffex();
	std::cout << edition() << edition_suffex << " edition\n";
	std::cout << rating() << "/5\n";
}

Novel &Novel::operator=(const Novel &n) {
	_title = n._title;
	_author = n._author;
	set_genre(n._genre);
	_isbn = n._isbn;
	_pages = n._pages;
	_edition = n._edition;
	_rating = n._rating;
	return *this;
}


std::ostream &operator<<(std::ostream &out, const Novel &n) {
	out << n.title() << ", " << n.author() << ", ";
	out << n.genre_str() << ", " << n.isbn() << ", ";
	out << n.pages() << ", " << n.edition() << ", ";
	out << n.rating();
	return out;
}
