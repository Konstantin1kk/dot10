#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_ALBUMS = 20;
const int MAX_TRACKS = 20;

enum Genre {
    Rock,
    IndieRock,
    Pop,
    Rap,
    Jazz,
    Classical
};

struct Track {
    char name[100];
    int duration;
};

struct Album {
    char title[100];
    char artist[100];
    Genre genre;
    int releaseYear;
    int totalDuration;
    double price;
    Track tracks[MAX_TRACKS];
    int trackCount;
};

const char* genreToString(Genre genre) {
    switch (genre) {
    case Rock:      return "Rock";
    case IndieRock: return "IndieRock";
    case Pop:       return "Pop";
    case Rap:       return "Rap";
    case Jazz:      return "Jazz";
    case Classical: return "Classical";
    default:        return "Unknown";
    }
}

void addTrack(Album& album, int index, const char name[], int duration) {
    strcpy_s(album.tracks[index].name, name);
    album.tracks[index].duration = duration;
}

void printTrack(const Track& track) {
    cout << "Track: " << track.name << " (" << track.duration / 60 << ":";
    if (track.duration % 60 < 10) {
        cout << "0";
    }
    cout << track.duration % 60 << ")" << endl;
}

void printAlbum(const Album& album) {
    cout << "\n===================================" << endl;
    cout << "Album: " << album.title << endl;
    cout << "Artist: " << album.artist << endl;
    cout << "Genre: " << genreToString(album.genre) << endl;
    cout << "Release year: " << album.releaseYear << endl;
    cout << "Duration: " << album.totalDuration / 60 << ":";
    if (album.totalDuration % 60 < 10) {
        cout << "0";
    }
    cout << album.totalDuration % 60 << endl;
    cout << "Price: $" << album.price << endl;
    cout << "Tracks:" << endl;
    for (int i = 0; i < album.trackCount; i++) {
        printTrack(album.tracks[i]);
    }
    cout << "===================================" << endl;
}

void createAlbums(Album albums[], int& count) {
    count = 20;

    // 1
    strcpy_s(albums[0].title, "Abbey Road");
    strcpy_s(albums[0].artist, "The Beatles");
    albums[0].genre = Rock;
    albums[0].releaseYear = 1969;
    albums[0].totalDuration = 998;
    albums[0].price = 14.99;
    albums[0].trackCount = 5;
    addTrack(albums[0], 0, "Come Together", 259);
    addTrack(albums[0], 1, "Something", 182);
    addTrack(albums[0], 2, "Maxwell's Silver Hammer", 207);
    addTrack(albums[0], 3, "Here Comes the Sun", 185);
    addTrack(albums[0], 4, "Because", 165);

    // 2
    strcpy_s(albums[1].title, "Nevermind");
    strcpy_s(albums[1].artist, "Nirvana");
    albums[1].genre = Rock;
    albums[1].releaseYear = 1991;
    albums[1].totalDuration = 1259;
    albums[1].price = 15.99;
    albums[1].trackCount = 8;
    addTrack(albums[1], 0, "Smells Like Teen Spirit", 301);
    addTrack(albums[1], 1, "In Bloom", 254);
    addTrack(albums[1], 2, "Come as You Are", 218);
    addTrack(albums[1], 3, "Lithium", 256);
    addTrack(albums[1], 4, "Polly", 177);
    addTrack(albums[1], 5, "Territorial Pissings", 143);
    addTrack(albums[1], 6, "Drain You", 223);
    addTrack(albums[1], 7, "Stay Away", 211);

    // 3
    strcpy_s(albums[2].title, "1989");
    strcpy_s(albums[2].artist, "Taylor Swift");
    albums[2].genre = Pop;
    albums[2].releaseYear = 2014;
    albums[2].totalDuration = 1324;
    albums[2].price = 13.49;
    albums[2].trackCount = 5;
    addTrack(albums[2], 0, "Blank Space", 231);
    addTrack(albums[2], 1, "Style", 231);
    addTrack(albums[2], 2, "Shake It Off", 219);
    addTrack(albums[2], 3, "Bad Blood", 211);
    addTrack(albums[2], 4, "Wildest Dreams", 220);

    // 4
    strcpy_s(albums[3].title, "Back in Black");
    strcpy_s(albums[3].artist, "AC/DC");
    albums[3].genre = Rock;
    albums[3].releaseYear = 1980;
    albums[3].totalDuration = 1565;
    albums[3].price = 16.99;
    albums[3].trackCount = 6;
    addTrack(albums[3], 0, "Hells Bells", 312);
    addTrack(albums[3], 1, "Shoot to Thrill", 317);
    addTrack(albums[3], 2, "Back in Black", 255);
    addTrack(albums[3], 3, "You Shook Me All Night Long", 210);
    addTrack(albums[3], 4, "Rock and Roll Ain't Noise Pollution", 256);
    addTrack(albums[3], 5, "What Do You Do for Money Honey", 215);

    // 5
    strcpy_s(albums[4].title, "Indie Rock Collection");
    strcpy_s(albums[4].artist, "Various Artists");
    albums[4].genre = IndieRock;
    albums[4].releaseYear = 2020;
    albums[4].totalDuration = 1172;
    albums[4].price = 11.99;
    albums[4].trackCount = 8;
    addTrack(albums[4], 0, "Electric Feel", 229);
    addTrack(albums[4], 1, "Little Talks", 266);
    addTrack(albums[4], 2, "Dog Days Are Over", 251);
    addTrack(albums[4], 3, "Float On", 208);
    addTrack(albums[4], 4, "The Cave", 218);
    addTrack(albums[4], 5, "Pumped Up Kicks", 240);
    addTrack(albums[4], 6, "Take Me Out", 230);
    addTrack(albums[4], 7, "Mountain Sound", 215);

    // Остальные альбомы
    for (int i = 5; i < count; i++) {
        strcpy_s(albums[i].title, "Demo Album");
        strcpy_s(albums[i].artist, "Unknown Artist");
        albums[i].genre = Pop;
        albums[i].releaseYear = 2000 + i;
        albums[i].totalDuration = 1000 + i * 10;
        albums[i].price = 9.99 + i;
        albums[i].trackCount = 3;
        addTrack(albums[i], 0, "Track 1", 200);
        addTrack(albums[i], 1, "Track 2", 210);
        addTrack(albums[i], 2, "Track 3", 220);
    }
}

void filterRockAlbums(Album source[], int sourceCount, Album result[], int& resultCount) {
    resultCount = 0;
    for (int i = 0; i < sourceCount; i++) {
        if (source[i].genre == Rock || source[i].genre == IndieRock) {
            result[resultCount] = source[i];
            resultCount++;
        }
    }
}

void bubbleSortByArtist(Album albums[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(albums[j].artist, albums[j + 1].artist) > 0) {
                Album temp = albums[j];
                albums[j] = albums[j + 1];
                albums[j + 1] = temp;
            }
        }
    }
}

void printSpecificAlbum(Album albums[], int count, const char title[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(albums[i].title, title) == 0) {
            printAlbum(albums[i]);
            return;
        }
    }
    cout << "Album not found." << endl;
}

void printTop5Albums(Album albums[], int count) {
    Album sorted[MAX_ALBUMS];
    for (int i = 0; i < count; i++) {
        sorted[i] = albums[i];
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (sorted[j].releaseYear < sorted[j + 1].releaseYear) {
                Album temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    cout << "\nTOP 5 ALBUMS:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << sorted[i].title << " - " << sorted[i].artist << " (" << sorted[i].releaseYear << ")" << endl;
    }
}

void modifyAlbum(Album& album, const char newTitle[], const char newArtist[], Genre newGenre, int newYear, double newPrice) {
    strcpy_s(album.title, newTitle);
    strcpy_s(album.artist, newArtist);
    album.genre = newGenre;
    album.releaseYear = newYear;
    album.price = newPrice;
}

void filterAlbumsMoreThan7Tracks(Album source[], int sourceCount, Album result[], int& resultCount) {
    resultCount = 0;
    for (int i = 0; i < sourceCount; i++) {
        if (source[i].trackCount > 7) {
            result[resultCount] = source[i];
            resultCount++;
        }
    }
}

void printFilteredAlbums(Album albums[], int count, const char title[]) {
    cout << "\n========== " << title << " ==========" << endl;
    for (int i = 0; i < count; i++) {
        cout << albums[i].title << " | " << albums[i].artist << " | " << genreToString(albums[i].genre) << endl;
    }
    cout << "Total albums: " << count << endl;
}

void writePricesToTextFile(Album albums[], int count, const char filename[]) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cout << "Ошибка открытия текстового файла!" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        fout << albums[i].title << " " << albums[i].price << endl;
    }
    fout.close();
}

void writeAlbumsToBinaryFile(const Album albums[], int count, const char filename[]) {
    ofstream fout(filename, ios::binary | ios::out);
    if (!fout.is_open()) {
        cout << "Ошибка открытия бинарного файла для записи!" << endl;
        return;
    }
    // Записываем количество элементов в самом начале файла
    fout.write((char*)&count, sizeof(count));
    // Записываем сам блок памяти с массивом структур
    fout.write((char*)albums, sizeof(Album) * count);
    fout.close();
    cout << "Данные успешно сохранены в бинарный файл: " << filename << endl;
}

void readAlbumsFromBinaryFile(Album albums[], int& count, const char filename[]) {
    ifstream fin(filename, ios::binary | ios::in);
    if (!fin.is_open()) {
        cout << "Ошибка открытия бинарного файла для чтения!" << endl;
        return;
    }
    // Считываем сохраненное количество записей
    fin.read((char*)&count, sizeof(count));
    // Считываем весь блок структур обратно в массив
    fin.read((char*)albums, sizeof(Album) * count);
    fin.close();
    cout << "Данные успешно прочитаны из бинарного файла: " << filename << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Album allAlbums[MAX_ALBUMS];
    int albumCount;

    createAlbums(allAlbums, albumCount);
    cout << "Created albums: " << albumCount << endl;

    // фильтрация
    Album rockAlbums[MAX_ALBUMS];
    int rockCount;
    filterRockAlbums(allAlbums, albumCount, rockAlbums, rockCount);
    bubbleSortByArtist(rockAlbums, rockCount);
    printFilteredAlbums(rockAlbums, rockCount, "ROCK & INDIE ROCK");

    // вывод альбома
    printSpecificAlbum(allAlbums, albumCount, "Abbey Road");

    // топ 5
    printTop5Albums(allAlbums, albumCount);

    // > 7 треков
    Album manyTracks[MAX_ALBUMS];
    int manyTracksCount;
    filterAlbumsMoreThan7Tracks(allAlbums, albumCount, manyTracks, manyTracksCount);
    printFilteredAlbums(manyTracks, manyTracksCount, "MORE THAN 7 TRACKS");

    // изменение
    modifyAlbum(allAlbums[0], "Abbey Road Remastered", "The Beatles", Rock, 2025, 19.99);
    cout << "\nModified album:" << endl;
    printAlbum(allAlbums[0]);

    // запись в текстовый файл
    writePricesToTextFile(allAlbums, albumCount, "prices.txt");

    // Запись и Чтение структуры из бинарного файла
    cout << "\n================ БИНАРНЫЕ ФАЙЛЫ ================" << endl;

    // 1. Записываем текущие данные в бинарный файл
    writeAlbumsToBinaryFile(allAlbums, albumCount, "albums.bin");

    // 2. Создаем чистый массив структур и переменную для демонстрации честной загрузки
    Album loadedAlbums[MAX_ALBUMS];
    int loadedCount = 0;

    // 3. Вызываем подпрограмму чтения из бинарного файла
    readAlbumsFromBinaryFile(loadedAlbums, loadedCount, "albums.bin");
    cout << "Количество успешно загруженных структур: " << loadedCount << endl;

    // 4. Восстановленные из файла данные на примере измененного ранее альбома
    cout << "\nПроверка восстановленных данных из файла (Альбом 1):";
    printAlbum(loadedAlbums[0]);

    return 0;
}