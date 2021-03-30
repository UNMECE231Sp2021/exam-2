#include <iostream>
#include <vector>

// Custom functions for 'simulating' a library
#include "library_utils.hpp"

// Book base class
#include "book.hpp"
// Novel base class
#include "novel.hpp"

//#include "poem.hpp"
//#include "comic.hpp"

struct _library {
	std::vector<Novel> novels;
	std::vector<Poem> poems;
	std::vector<Comic> comics;
	std::vector<bool> availability;
};

typedef struct _library Library;

// Function prototypes, look at the bottom of main to see what they do
void print_novels(Library &lib);
void print_poems(Library &lib);
void print_comics(Library &lib);

// TODO: Implement printing the available contents of lib
void print_inventory(Library &lib) {
}

int main() {
	Novel open_gl_book("Computer Graphics Programming in Open GL with C++", 
		"V. Scott Gordon", Genre::Textbook, "978-1-68392-672-6", 733u,
		2u, 2u);
	Novel the_trial("The Trial", "Franz Kafka", Genre::Drama, 
		"9780805209990", 304u, 1u, 4u);
	Novel dune("Dune", "Frank Herbert", Genre::Adventure, 
		"9780441013593", 687u, 1u, 5u);

	// Two poems are created, you must change the last one for an existing poem
	Poem lokasenna("Lokasenna", "Snorri Sturluson", Genre::Lyric, 
		"x", 21u, 65u, "Ljooahattr");
	Poem diomedes_fights("Diomedes Fights the Gods", "Homer", Genre::Lyric,
		"x", 31u, 905u, "Dactylic hexameter");
	Poem p("poem_title", "poem_author", Genre::Drama, "poem_isbn", 9u, 
		12u, "Iambic pentameter");


	// Two comics are created, you must change the last one for an existing comic
	Comic brzrkr("BRZRKR", "Keanu Reeves", Genre::Superhero, 
		"1684156858", 122u, "BOOM! Studios", "Ron Garney");

	Comic thor("Thor", "Donny Cates", Genre::Superhero,
		"1302920863", 144u, "Marvel", "Nic Klein");

	Comic c("Comic_title", "Comic_author", Genre::Adventure, "Comic_isbn",
		45u, "Comic_publisher", "Comic_artist");

	Library mini_library =	{
		{open_gl_book, the_trial, dune},
		{lokasenna, diomedes_fights, p},
		{brzrkr, thor, c},
		{false, true, true,
		 true, false, true,
		 true, true, true
		}
	};

	
	int user_input;
	welcome_message();
	user_input = read_input();
	while(validate_input(user_input)) {
		switch(user_input) {
			case 1:
				print_inventory(mini_library);
				break;
			case 2:
				print_novels(mini_library);
				print_poems(mini_library);
				print_comics(mini_library);
				break;
			default:
				break;
		}
		user_input = read_input();
	}

	return 0;
}

// Accesses the library structure to print the contents of novels
void print_novels(Library &lib) {
	for(int i = 0; i < lib.novels.size(); ++i) {
		std::cout << lib.novels[i].title();
		if(lib.availability[i]) {
			std::cout << " - available\n";
		}
		else {
			std::cout << " - not available\n";
		}
	}
}

// Accesses the library structure to print the contents of poems
void print_poems(Library &lib) {
	for(int i = 0; i < lib.poems.size(); ++i) {
		std::cout << lib.poems[i].title();
		if(lib.availability[i+3]) {
			std::cout << " - available\n";
		}
		else {
			std::cout << " - not available\n";
		}
	}
}

// Accesses the library structure to print the contents of comics
void print_comics(Library &lib) {
	for(int i = 0; i < lib.comics.size(); ++i) {
		std::cout << lib.comics[i].title();
		if(lib.availability[i+6]) {
			std::cout << " - available\n";
		}
		else {
			std::cout << " - not available\n";
		}
	}
}
