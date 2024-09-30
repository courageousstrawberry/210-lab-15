#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Movie class
class Movie{
// Private variables for screenwriter, year, and title.
private:
    string screen_writer;
    int year;
    string title;
public:
    // Default constructor for the class.
    Movie() { screen_writer = "", year = 0, title = ""; }

    // Constructor to assign values to variables.
    Movie(string writer, int y, string t) {
        screen_writer = writer;
        year = y;
        title = t;
    }
    // Setter functions for all variables.
    void setScreenWriter(string writer){
        screen_writer = writer;
    }
    void setYear(int y) {
        year = y;
    }
    void setTitle(string t) {
        title = t;
    }
    // Getter functions for all variables.
    string getScreenWriter() const{
        return screen_writer;
    }
    int getYear() const{
        return year;
    }
    string getTitle() const{
        return title;
    }
    // Function to display class data.
    void print() const{
        cout << "Movie: " << title << endl;
        cout << "\tYear released: " << year << endl;
        cout << "\tScreenwriter: " << screen_writer << endl;
    }
};

int main() {
    ifstream inputFile("input.txt");
    vector<Movie> movies;
    string title;
    int year;
    string screen_writer;
    
    // If the file opens successfully, start reading the data.
    if (inputFile.is_open()) {
        // Store each line into the corresponding variable
        while (getline(inputFile, title) && inputFile >> year && inputFile.ignore() && getline(inputFile, screen_writer)) {
            // Create new movie object based on file data.
            Movie movie(screen_writer, year, title);
            // Add the movie object to the vector.
            movies.push_back(movie);
        }
        inputFile.close(); // Close the file.
    }
    else {
        // Display error message when file doesn't open.
        cout << "Error, failure when trying to open file." << endl;
    }

    // Loop through each object in the vector and display it.
    for (auto & movie: movies) {
        movie.print();
    }

    return 0;
}