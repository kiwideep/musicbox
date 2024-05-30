#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class representing common properties
class Entity {
protected:
    string name;

public:
    Entity(string name) : name(name) {}
    string getName(){
         return name; 
         }
};

// Song class inheriting from Entity
class Song : public Entity {
private:
    string artist;
    string youtubeLink;

public:
    Song(string title, string artist, string youtubeLink) : Entity(title), artist(artist), youtubeLink(youtubeLink) {}
    string getArtist(){
         return artist; 
         }
    string getYoutubeLink(){
         return youtubeLink; 
         }
};

// Artist class inheriting from Entity
class Artist : public Entity {
private:
    vector<Song> songs;

public:
    Artist(string name) : Entity(name) {}

    void addSong(string title, string artist, string youtubeLink) {
        songs.push_back(Song(title, artist, youtubeLink));
    }

    void displaySongs(){
        cout << "Songs by " << getName() << ":" << endl;
        for (int i = 0; i < songs.size(); ++i) {
            cout << i + 1 << ". " << songs[i].getName() << " - " << songs[i].getArtist() << endl;
        }
    }

    string getYoutubeLink(int index){
        return songs[index].getYoutubeLink();
    }

    int getNumberOfSongs(){
        return songs.size();
    }
};

// MusicGenre class inheriting from Entity
class MusicGenre : public Entity {
private:
    vector<Artist> artists;

public:
    MusicGenre(string name) : Entity(name) {}

    void addArtist(Artist artist){
        artists.push_back(artist);
    }

    void displayArtists(){
        cout << "Artists in " << getName() << " genre:" << endl;
        for (int i = 0; i < artists.size(); ++i) {
            cout << i + 1 << ". " << artists[i].getName() << endl;
        }
    }

    void displaySongs(int artistIndex){
        artists[artistIndex].displaySongs();
    }

    string getYoutubeLink(int artistIndex, int songIndex){
        return artists[artistIndex].getYoutubeLink(songIndex);
    }

    int getNumberOfArtists(){
        return artists.size();
    }

    int getArtistNumberOfSongs(int artistIndex){
        return artists[artistIndex].getNumberOfSongs();
    }
};

int main() {
    // Music genres
    MusicGenre rapGenre("Rap");
    MusicGenre popGenre("Pop");
    MusicGenre rockGenre("Rock");

    // Artists and their songs
    // Rap
    Artist eminem("Eminem");
    eminem.addSong("Without Me", "Eminem", "https://www.youtube.com/watch?v=YVkUvmDQ3HY");
    eminem.addSong("Lose Yourself", "Eminem", "https://www.youtube.com/watch?v=_Yhyp-_hX2s");
    eminem.addSong("Mockingbird", "Eminem", "https://www.youtube.com/watch?v=S9bCLPwzSC0");
    rapGenre.addArtist(eminem);

    // Pop
    Artist harryStyles("Harry Styles");
    harryStyles.addSong("Kiwi", "Harry Styles", " https://www.youtube.com/watch?v=9wg3v-01yKQ");
    harryStyles.addSong("Sign of the Times", "Harry Styles", "https://www.youtube.com/watch?v=qN4ooNx77u0");
    harryStyles.addSong("Only Angel", "Harry Styles", "https://www.youtube.com/watch?v=QbShJru2WFc");
    popGenre.addArtist(harryStyles);

    Artist rihanna("Rihanna");
    rihanna.addSong("Diamonds", "Rihanna", "https://www.youtube.com/watch?v=lWA2pjMjpBs");
    rihanna.addSong("Only Girl in the World", "Rihanna", "https://www.youtube.com/watch?v=pa14VNsdSYM");
    rihanna.addSong("Where Have You Been", "Rihanna", "https://www.youtube.com/watch?v=HBxt_v0WF6Y");
    popGenre.addArtist(rihanna);

    // Rock
    Artist nirvana("Nirvana");
    nirvana.addSong("Smells Like Teen Spirit", "Nirvana", "https://www.youtube.com/watch?v=hTWKbfoikeg");
    nirvana.addSong("Lithium", "Nirvana", "https://www.youtube.com/watch?v=pkcJEvMcnEg");
    nirvana.addSong("Something in the Way", "Nirvana", "https://www.youtube.com/watch?v=4VxdufqB9zg");
    rockGenre.addArtist(nirvana);

    Artist linkinPark("Linkin Park");
    linkinPark.addSong("In the End", "Linkin Park", "https://www.youtube.com/watch?v=eVTXPUF4Oz4");
    linkinPark.addSong("Numb", "Linkin Park", "https://www.youtube.com/watch?v=kXYiU_JCYtU");
    linkinPark.addSong("One Step Closer", "Linkin Park", "https://www.youtube.com/watch?v=4qlCC1GOwFw");
    rockGenre.addArtist(linkinPark);

    // Kullanıcıya seçenekler sunuluyor
    cout << "Welcome to the Music Box!" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Search by Music Genre" << endl;
    cout << "2. Search by Artist" << endl;

    int choice;
    cin >> choice;

    // Kullanıcının seçimine göre işlem yapılıyor
    if (choice == 1) {
        cout << "Available Music Genres:" << endl;
        cout << "1. Rap" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Rock" << endl;

        int genreChoice;
        cin >> genreChoice;

        if (genreChoice == 1) {
            rapGenre.displayArtists();
            int artistIndex;
            cin >> artistIndex;
            if (artistIndex >= 1 && artistIndex <= rapGenre.getNumberOfArtists()) {
                rapGenre.displaySongs(artistIndex - 1);
                int songIndex;
                cout << "Choose a song by entering its number: ";
                cin >> songIndex;
                if (songIndex >= 1 && songIndex <= rapGenre.getArtistNumberOfSongs(artistIndex - 1)) {
                    cout << "Here is the YouTube link for the selected song: " << rapGenre.getYoutubeLink(artistIndex - 1, songIndex - 1) << endl;
                } else {
                    cout << "Invalid song choice. Please try again." << endl;
                }
            } else {
                cout << "Invalid artist choice. Please try again." << endl;
            }
        } else if (genreChoice == 2) {
            popGenre.displayArtists();
            int artistIndex;
            cin >> artistIndex;
            if (artistIndex >= 1 && artistIndex <= popGenre.getNumberOfArtists()) {
                popGenre.displaySongs(artistIndex - 1);
                int songIndex;
                cout << "Choose a song by entering its number: ";
                cin >> songIndex;
                if (songIndex >= 1 && songIndex <= popGenre.getArtistNumberOfSongs(artistIndex - 1)) {
                    cout << "Here is the YouTube link for the selected song: " << popGenre.getYoutubeLink(artistIndex - 1, songIndex - 1) << endl;
                } else {
                    cout << "Invalid song choice. Please try again." << endl;
                }
            } else {
                cout << "Invalid artist choice. Please try again." << endl;
            }
        } else if (genreChoice == 3) {
            rockGenre.displayArtists();
            int artistIndex;
            cin >> artistIndex;
            if (artistIndex >= 1 && artistIndex <= rockGenre.getNumberOfArtists()) {
                rockGenre.displaySongs(artistIndex - 1);
                int songIndex;
                cout << "Choose a song by entering its number: ";
                cin >> songIndex;
                if (songIndex >= 1 && songIndex <= rockGenre.getArtistNumberOfSongs(artistIndex - 1)) {
                    cout << "Here is the YouTube link for the selected song: " << rockGenre.getYoutubeLink(artistIndex - 1, songIndex - 1) << endl;
                } else {
                    cout << "Invalid song choice. Please try again." << endl;
                }
            } else {
                cout << "Invalid artist choice. Please try again." << endl;
            }
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } else if (choice == 2) {
        cout << "Available Artists:" << endl;
        cout << "1. Eminem" << endl;
        cout << "2. Harry Styles" << endl;
        cout << "3. Rihanna" << endl;
        cout << "4. Nirvana" << endl;
        cout << "5. Linkin Park" << endl;

        int artistChoice;
        cin >> artistChoice;

        if (artistChoice == 1) {
            eminem.displaySongs();
            int songIndex;
            cout << "Choose a song by entering its number: ";
            cin >> songIndex;
            if (songIndex >= 1 && songIndex <= eminem.getNumberOfSongs()) {
                cout << "Here is the YouTube link for the selected song: " << eminem.getYoutubeLink(songIndex - 1) << endl;
            } else {
                cout << "Invalid song choice. Please try again." << endl;
            }
        } else if (artistChoice == 2) {
            harryStyles.displaySongs();
            int songIndex;
            cout << "Choose a song by entering its number: ";
            cin >> songIndex;
            if (songIndex >= 1 && songIndex <= harryStyles.getNumberOfSongs()) {
                cout << "Here is the YouTube link for the selected song: " << harryStyles.getYoutubeLink(songIndex - 1) << endl;
            } else {
                cout << "Invalid song choice. Please try again." << endl;
            }
        } else if (artistChoice == 3) {
            rihanna.displaySongs();
            int songIndex;
            cout << "Choose a song by entering its number: ";
            cin >> songIndex;
            if (songIndex >= 1 && songIndex <= rihanna.getNumberOfSongs()) {
                cout << "Here is the YouTube link for the selected song: " << rihanna.getYoutubeLink(songIndex - 1) << endl;
            } else {
                cout << "Invalid song choice. Please try again." << endl;
            }
        } else if (artistChoice == 4) {
            nirvana.displaySongs();
            int songIndex;
            cout << "Choose a song by entering its number: ";
            cin >> songIndex;
            if (songIndex >= 1 && songIndex <= nirvana.getNumberOfSongs()) {
                cout << "Here is the YouTube link for the selected song: " << nirvana.getYoutubeLink(songIndex - 1) << endl;
            } else {
                cout << "Invalid song choice. Please try again." << endl;
            }
        } else if (artistChoice == 5) {
            linkinPark.displaySongs();
            int songIndex;
            cout << "Choose a song by entering its number: ";
            cin >> songIndex;
            if (songIndex >= 1 && songIndex <= linkinPark.getNumberOfSongs()) {
                cout << "Here is the YouTube link for the selected song: " << linkinPark.getYoutubeLink(songIndex - 1) << endl;
            } else {
                cout << "Invalid song choice. Please try again." << endl;
            }
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } else {
        cout << "Invalid choice. Please try again." << endl;
    }

    return 0;
}