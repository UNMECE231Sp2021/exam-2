GPP=g++ -std=c++17
all: LibraryUtils.o Comic.o Poem.o Novel.o Book.o main.o
	$(GPP) LibraryUtils.o Comic.o Poem.o Novel.o Book.o main.o -o exam2

LibraryUtils.o: LibraryUtils.cpp library_utils.hpp
	$(GPP) -c LibraryUtils.cpp

Comic.o: Comic.cpp comic.hpp
	$(GPP) -c Comic.cpp

Poem.o: Poem.cpp poem.hpp
	$(GPP) -c Poem.cpp

Novel.o: Novel.cpp novel.hpp
	$(GPP) -c Novel.cpp

Book.o: Book.cpp book.hpp
	$(GPP) -c Book.cpp

main.o: main.cpp book.hpp novel.hpp poem.hpp comic.hpp library_utils.hpp
	$(GPP) -c main.cpp

clean:
	rm *.o
	rm exam2
