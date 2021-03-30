# Exam 2
## Context
The quick version of exam 2 is that you are going to create two classes: `poem` and `comic` that are based of the a `book` class that is already created. You will also edit `main.cpp` to add a missing function that prints the contents of a mini library consisting of 3 novels, 3 poems, and 3 comics. I created 3 novels, 2 poems, and 2 comics, you need to find and create a poem, and a comic.

The long version is that you are going to complete a very basic library simulator for printing the inventory of a library. Right now the library has full support for novels (provided by `novel.hpp` and `Novel.cpp`), but need support for poems, and comics. There are functions for printing the titles of novels, poems, and comics, but a function for printing all the info (meaning all of the attributes) of novels, poems, and comics is missing. The function that prints all the info must only print the info of books available (more info on this later). Let's start by looking at the `Book` and `Novel` classes. The data declare have 3 fully fleshed out variables for the `novel` class, but 2 for `poem` and `comic`. The third variable for both classes have placeholder data that you need to replace with a poem and a comic of your choice.

## Book
The book class is provided by two files: `book.hpp` and `Book.cpp`, and is a base class. The class that you will create (`poem` and `comic`) will inherit from `book`. `Book` has the following attributes:

 * title
 * author
 * genre
 * isbn
 * pages

And has a parameterized constructor to take those parameters and initialize them. There is also a copy constructor. There is not an **unparameterized** constructor. There is a whole bunch of setters and getters for each attribute. There is also a `print` method, and the = and << operators are overloaded. This will be pretty much be what you will have to do with `poem` and `comic`. 

### A wild enumerator has appeared
What is unique about the `book` class is that the attribute `_genre` is a `Genre` enumerator (enum). An enumerator is essentially a spicy structure used to indicate a collection of states. Below is an example of using an enumerator for colors:

```cpp
#include <iostream>

enum class Color {
    Red,
    Blue,
    Yellow
};

int main() {
    Color c = Red;
    switch(c) {
        case Color::Yellow:
            std::cout << "Yellow!\n";
            break;
        case Color::Blue:
            std::cout << "Blue!\n";
            break;
        case Color::Red:
            std::cout << "Red!\n";
            break;
    }
    return 0;
}
```

We have the enum `Color` which can represent three things: `Red`, `Blue`, or `Yellow`. So with `Genre` we have:

* Adventure
* Comedy
* Drama
* Lyric
* Romance
* Superhero
* Textbook
* Tragedy

So if we have a variables like this:

```cpp
Genre g;
```

Then g can be anything from `Adventure` to `Tragedy`. However, you must use `Genre::` before each of the states. So initialize g to let's say `Comedy`, this is the way I would do it:

```cpp
Genre g = Genre::Comedy;
```

The method `genre_to_str` takes a genre (like Drama) and returns a string (like "Drama"). To learn more about enumerators, I recommend [this link here](https://en.cppreference.com/w/cpp/language/enum).

Now let's move on to novel.

## Novel
`Novel` is a derived class from `book`, and it is done via public inheritance. It has to following attributes:

* edition
* rating

`Novel` has three constructors, one that has the same parameters as `book` and one to fill out every attribute available for both `book` and `novel`, we also have a copy constructor. After that there are setters and getters for the new attributes, as well as a print method. `Novel` also has the = and << operators overloaded. If you take a look at the `print` method, it calls the parent (`book`) print method, then does its own thing. I recommend this for `poem` and `comic`.

## Poem and Comic
You need to create two classes that will inherit from `book`. Poem should have these additional attributes:

```cpp
unsigned int _stanzas;
std::string _metrical_pattern;
```

Below is the methods you need for Poem:

* A parameterized constructor for initializing every attribute of the `poem` class
* A copy constructor
* Getters and setters for the newly created attributes (stanzas and metrical pattern)
* Print method to print every attribute (from both `book` and `poem`)
* Overload the = operator to copy all attributes
* Overload the << operator to print with std::cout

For the print method should print stanzas and metrical pattern as:

```
x stanzas
y metric
```

Where x is the value of the stanzas and y is the value of the metrical pattern attribute.

Comic should have these attributes:

```cpp
std::string _publisher;
std::string _artist;
```

Below is the methods needed for Comic:

* A parameterized constructor for initializing every attribute of the `comic` class
* A copy constructor
* Getters and setters for the newly created attributes (publisher and artist)
* Print method to print every attribute (from both `book` and `comic`)
* Overload the = operator to copy all attributes
* Overload the << operator to print with std::cout

For the print method for comic you should print the publisher and artist as such:

```
Publisher: x
Artist: y
```

Where x is the value of the publisher attribute and y is the value of the artist attribute.

For both of these classes, it must be a public inheritance.

### Aside (and extra credit) - header guards
Something that you can do with your header files is add something called a header guard, this is to prevent a header file from being included twice. If you use it in `poem` and `comic` you'll get some extra credit. Below is a template:

```cpp
#ifndef FILENAME_H
#define FILENAME_H

// Header file contents

#endif
```

If you want to learn more, [you can click here](https://www.learncpp.com/cpp-tutorial/header-guards/)

## main.cpp
Your task in main begins in line 30 where I started a function called `print_inventory` that will call the `print` methods of each class member of a `Library` data structure. The `Library` stucture is as follows:

```cpp
struct _library {
    // Class members
    std::vector<Novel> novels;
    std::vector<Poem> poems;
    std::vector<Comic> comics;
    
    // Not a class member
    std::vector<bool> availability;
};

typedef struct _library Library;
```

This structure contains four things: vectors of novels, poems, comics, and availability. The vectors will have a size of 3 for novels, poems, and comics. The vector for availablity will have 9 booleans. The initializion begins on line 61 and ends on line 69. 

For `print_inventory` you must print the "available" books. For the availability vector, indices 0 to 2 are the availability for the novels, indices 3 to 5 are the availability for the poems, and indices 6 to 8 are the availability for the comics. 

For example, if availability[0] is false, the novels[0] is not available. If availability[4] is true, then poems[1] is available. **If you have questions or doubts, please come to lab, or email me**.

For examples on how to access the structure, take a look at the three print functions (print_novels, print_poems, print_comics) at the bottom of the file. 

Lastly, you are to change the variables on lines 47/48 and 58/59 to a poem and comic. Right now the data are nothing but place holders and you need to find a poem and comic that you like to populate the data there. Have fun with it.

## Makefile
The file structure here is quite large and I want you to focus on practicing object oriented programming (and the stuff in main) so I am providing the makefile for you.

## Expected results
The results that you should expect from the exam are in a file called `results.txt`. Your results should not be the exact same because the third poem and the third comic will have different data (data that you will create).

# Rubric

|Requirement               |Score  |
| :---:                    | :---: |
| Poem class               | 25    |
| Comic class              | 25    |
| print_inventory function | 20    |
| Custom poem variable     | 5    |
| Custom comic variable    | 5    |
| Clean, readable code     | 10     |
| Header guards            | 15    |
| Total                    | 115   |

