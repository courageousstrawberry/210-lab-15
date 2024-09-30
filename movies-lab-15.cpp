#include <iostream>
#include <fstream>
#include <vector>

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
    void print() {
        cout << "Movie: " << title << endl;
        cout << "\tYear released: " << year << endl;
        cout << "\tScreenwriter: " << screen_writer << endl;
    }
};

int main() {
    ifstream inputFile("movies.txt");
    vector<Movie> movies;
    string title;
    int year;
    string screen_writer;
    
    if (inputFile.is_open()) {
        while (inputFile >> title >> year >> screen_writer) {
            Movie movie(screen_writer, year, title);
            movies.push_back(movie);
        }
        inputFile.close();
    }
    else {
        cout << "Error, failure when trying to open file." << endl;
    }

    for ()
    return 0;
}