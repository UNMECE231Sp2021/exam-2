#include "book.hpp"

Book::Book(std::string title, std::string author, Genre genre, 
		std::string isbn, unsigned int pages) : 
		_title{title}, _author{author}, _genre{genre}, _isbn{isbn}, 
		_pages{pages} {
	_genre_str = genre_to_str();
}
	
Book::Book(const Book &b) :
		_title{b._title}, _author{b._author}, _genre{b._genre},
		_isbn{b._isbn}, _pages{b._pages} {
	_genre_str = genre_to_str();
}

Book::~Book() {}

std::string Book::title() const {
	return _title;
}

std::string Book::author() const {
	return _author;
}

Genre Book::genre() const {
	return _genre;
}

std::string Book::genre_str() const {
	return _genre_str;
}

std::string Book::isbn() const {
	return _isbn;
}

unsigned int Book::pages() const {
	return _pages;
}

void Book::set_title(std::string new_title) {
	_title = new_title;
}

void Book::set_author(std::string new_author) {
	_author = new_author;
}

void Book::set_genre(Genre new_genre) {
	_genre = new_genre;
	_genre_str = genre_to_str();
}

void Book::set_isbn(std::string new_isbn) {
	_isbn = new_isbn;
}

void Book::set_pages(unsigned int pages) {
	_pages = pages;
}

std::string Book::genre_to_str() {
	std::string genre_string;

	switch(_genre) {
		case Genre::Adventure:
			genre_string = "Adventure";
			break;
		case Genre::Comedy:
			genre_string = "Comedy";
			break;
		case Genre::Drama:
			genre_string = "Drama";
			break;
		case Genre::Lyric:
			genre_string = "Lyric";
			break;
		case Genre::Romance:
			genre_string = "Romance";
			break;
		case: Genre::Superhero:
			genre_string = "Superhero";
			break;
		case Genre::Textbook:
			genre_string = "Textbook";
			break;
		case Genre::Tragedy:
			genre_string = "Tragedy";
			break;
		default:
			genre_string = "Adventure";
			break;
	}
	return genre_string;
}

void Book::print() {
	std::cout << "Title: " << title() << '\n';
	std::cout << "Author: " << author() << '\n';
	std::cout << "Genre: " << genre_str() << '\n';
	std::cout << "ISBN: " << isbn() << '\n';
	std::cout << "Pages: " << pages() << '\n';
}

Book &Book::operator=(const Book &b) {
	_title = b._title;
	_author = b._author;
	set_genre(b._genre);
	_isbn = b._isbn;
	_pages = b._pages;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Book &b) {
	out << b.title() << ", " << b.author() << ", ";
	out << b.genre_str() << ", " << b.isbn() << ", ";
	out << b.pages();
	return out;
}
