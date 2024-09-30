#include <iostream>
#include <fstream>
#include <array>

using namespace std;

class Movie{
private:
    string screen_writer;
    int year;
    string title;
public:
    Movie() { screen_writer = "", year = 0, title = ""; }

    Movie::Movie(string writer, int y, string t) {
        screen_writer = writer;
        year = y;
        title = t;
    }
    void setScreenWriter(string writer){
        screen_writer = writer;
    }
    void setYear(int y) {
        year = y;
    }
    void setTitle(string t) {
        title = t;
    }
    string getScreenWriter(){
        return screen_writer;
    }
    int getYear() {
        return year;
    }
    string getTitle() {
        return title;
    }
};

int main() {
    ifstream inputFile("movies.txt");
    array<Movie, 5> movies;
    string title;
    int year;
    string screen_writer;
    
    if (inputFile.is_open()) {
        while (inputFile >> title >> year >> screen_writer) {
            Movie movie(screen_writer, year, title);
        }
    }
    return 0;
}