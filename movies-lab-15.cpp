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

    Movie(string writer, int y, string t) {
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
    string getScreenWriter() const{
        return screen_writer;
    }
    int getYear() const{
        return year;
    }
    string getTitle() const{
        return title;
    }
    void print() const{
        cout << "Movie: " << title << endl;
        cout << "\tYear released: " << year << endl;
        cout << "\tScreenwriter: " << screen_writer << endl;
    }
};

int main() {
    ifstream inputFile("input.txt");
    vector<Movie> movies;
    string line;
    string title;
    int year;
    string screen_writer;
    
    if (inputFile.is_open()) {
        while (getline(inputFile, title) && inputFile >> year && inputFile.ignore() && getline(inputFile, screen_writer)) {
            Movie movie(screen_writer, year, title);
            movies.push_back(movie);
        }
        inputFile.close();
    }
    else {
        cout << "Error, failure when trying to open file." << endl;
    }

    for (auto & movie: movies) {
        movie.print();
    }

    return 0;
}