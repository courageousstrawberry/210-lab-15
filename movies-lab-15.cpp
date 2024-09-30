#include <iostream>

using namespace std;

class Movie{
public:
    string screen_writer;
    int year;
    string title;
private:
    Movie(string writer, int y, string t) {
        screen_writer = writer;
        year = y;
        title = t;
    }
    
};