#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Book {
public:
    Book(string title, string author, int year) : title(title), author(author), year(year) {}

    void displayInfo() const {
        cout << "Книга: " << title << ", Автор: " << author << ", Рік: " << year << endl << endl;
    }

    bool operator<(const Book& other) const {
        return title < other.title;
    }

    void editBook(string newTitle, string newAuthor, int newYear) {
        title = newTitle;
        author = newAuthor;
        year = newYear;
    }

    const string& getTitle() const {
        return title;
    }

private:
    string title;
    string author;
    int year;
};

void Menu();
void informationAboutBooks(vector<Book>& library);
void sortedBooks(vector<Book>& library);
void editBooks(vector<Book>& library);
void deleteBooks(vector<Book>& library);

int main() {
    setlocale(LC_ALL, "Ukrainian");
    vector<Book> library;

    library.push_back(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.push_back(Book("1984", "George Orwell", 1949));
    library.push_back(Book("The Catcher in the Rye", "J.D. Salinger", 1951));

    char choice;

    do {
        Menu();
        choice = _getch();
        system("cls");

        switch (choice) {
        case '1':
            informationAboutBooks(library);
            break;
        case '2':
            sortedBooks(library);
            break;
        case '3':
            editBooks(library);
            break;
        case '4':
            deleteBooks(library);
            break;
        default:
            break;
        }
    } while (choice != 27);

    return 0;
}

void Menu() {
    cout << "1 - Інформація про книги в бібліотеці" << endl;
    cout << "2 - Бібліотека після сортування за назвою книги" << endl;
    cout << "3 - Редагування книги" << endl;
    cout << "4 - Видалення книги" << endl;
    cout << "Esc - exit" << endl;
}

void informationAboutBooks(vector<Book>& library) {
    for (const auto& book : library) {
        book.displayInfo();
    }
}

void sortedBooks(vector<Book>& library) {
    sort(library.begin(), library.end());

    for (const auto& book : library) {
        book.displayInfo();
    }
}

void editBooks(vector<Book>& library) {
    string searchTitle;
    cout << "Назва книги, яку хочете редагувати: ";
    cin >> searchTitle;
    auto it = find_if(library.begin(), library.end(), [&searchTitle](const Book& book) {
        return book.getTitle() == searchTitle;
        });

    if (it != library.end()) {
        string newTitle, newAuthor;
        int newYear;

        cout << "Введіть нову назву книги: ";
        cin >> newTitle;

        cout << "Введіть нового автора книги: ";
        cin >> newAuthor;

        cout << "Введіть новий рік видання книги: ";
        cin >> newYear;

        it->editBook(newTitle, newAuthor, newYear);
    }
    else {
        cout << "Error" << endl;
    }
}

void deleteBooks(vector<Book>& library) {
    string searchTitle;
    cout << "Назва книги, яку хочете видалити: ";
    getline(cin, searchTitle);
    auto it = find_if(library.begin(), library.end(), [&searchTitle](const Book& book) {
        return book.getTitle() == searchTitle;
        });

    if (it != library.end()) {
        library.erase(it);
        cout << "Книгу видалено" << endl;
    }
    else {
        cout << "Error" << endl;
    }
}




#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void Menu();
void inputFruits(vector<string>& favoriteFruits);
void sortedFruits(vector<string>& favoriteFruits);
void reverseSort(vector<string>& favoriteFruits);

int main() {
    setlocale(LC_ALL, "ru");

    vector<string> favoriteFruits;

   cout << "Ласкаво просимо до гри 'Сортування фруктів'!" << endl;
   char choice;

   do {
       Menu();
       choice = _getch();
       system("cls");
       switch (choice) {
       case '1':
           inputFruits(favoriteFruits);
           break;
       case '2':
           sortedFruits(favoriteFruits);
           break;
       case '3':
           reverseSort(favoriteFruits);
           break;
       default:
           break;
       }
   } while (choice != 27);

   cout << "Гра завершена. Дякуємо за участь!" << endl;

    return 0;
}

void Menu() {
    cout << "\n1 - Введіть свої улюблені фрукти" << endl;
    cout << "2 - Ваші улюблені фрукти в алфавітному порядку" << endl;
    cout << "3 - Ваші улюблені фрукти проти алфавітного порядку" << endl;
    cout << "4 - Esc-вихід" << endl;
}

void inputFruits(vector<string>& favoriteFruits) {
    cout << "Введіть свої улюблені фрукти (введіть 'stop', щоб завершити введення):" << endl;
    string fruit;
    while (true) {
        cout << "Фрукт: ";
        cin >> fruit;

        if (fruit == "stop") {
            break;
        }

        favoriteFruits.push_back(fruit);
    }
}
void sortedFruits(vector<string>& favoriteFruits) {
    sort(favoriteFruits.begin(), favoriteFruits.end());

    cout << "\nВаші улюблені фрукти в алфавітному порядку: ";
    for (const auto& favoriteFruit : favoriteFruits) {
        cout <<endl<< favoriteFruit;
    }
}
void reverseSort(vector<string>& favoriteFruits) {
    sort(favoriteFruits.begin(), favoriteFruits.end());
    reverse(favoriteFruits.begin(), favoriteFruits.end());
    cout << "\nВаші улюблені фрукти проти алфавітного порядку: ";
    for (const auto& favoriteFruit : favoriteFruits) {
        cout <<endl<< favoriteFruit;
    }
}




#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;

class Joke {
public:
    Joke(string text) : text(text), votes(0), totalRating(0) {}

    void tellJoke() const {
        cout << "\nЖарт: " << text << endl;
        cout << "Оцінка: " << fixed << setprecision(2) << getAverageRating() << " (Голосів: " << votes << ")" << endl;
    }

    void rateJoke(int rating, int& numUsers) {
        if (rating >= 1 && rating <= 5) {
            votes++;
            totalRating += rating;
            cout << "Користувач оцінив жарт: " << rating;
        }
        else {
            cout << "Оцінка повинна бути від 1 до 5!" << endl;
        }
    }

    double getAverageRating() const {
        return (votes > 0) ? static_cast<double>(totalRating) / votes : 0.0;
    }

private:
    string text;
    int votes;
    int totalRating;
};

int main() {
    setlocale(LC_ALL, "ru");
    list<Joke> jokeList;

    jokeList.push_back(Joke("Чому програмісти так погано сплять?\nТому що вони давно звикли до багів!"));
    jokeList.push_back(Joke("Що робить програміст після розставання?\nПереходить на інший репозиторій!"));
    jokeList.push_back(Joke("Інтернет – він такий. Читаєш коментарі, думаєш: “Одні ідіоти!” Починаєш з ними сперечатися й не помічаєш, як на одного ідіота стало більше."));

    cout << "Ласкаво просимо до програми для оцінювання жартів!" << endl;

    int numUsers;
    cout << "Введіть кількість користувачів: ";
    cin >> numUsers;

    for (int i = 1; i <= numUsers; i++)
    {
        cout << "\nКористувач " << i << ":" << endl;
        for (auto& joke : jokeList) {
            joke.tellJoke();
            cout << endl;
            int userRating;
            cout << "Оцінка (1-5): ";
            cin >> userRating;

            joke.rateJoke(userRating, numUsers);
            cout << endl;
        }
    }

    cout << "\n\nЖарти з високим рейтингом:" << endl;
    for (const auto& joke : jokeList) {
        if (joke.getAverageRating() >= 4.0) {
            joke.tellJoke();
        }
    }

    return 0;
}





#include <iostream>
#include <map>
#include <string>
#include <conio.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    map<string, double> studentGrades;

      map<string, double> browsingHistory;

    studentGrades["Anna"] = 4.5;
    studentGrades["Boris"] = 3.8;
    studentGrades["Katerina"] = 4.2;
    studentGrades["Dmitro"] = 4.0;

    cout << "Інформація про студентів:" << endl;
    for (const auto& student : studentGrades) {
        cout << student.first << ": " << student.second << endl;
    }

    char choice;
    string searchStudent;
    do {
        cout << "\nВведіть ім'я студента для пошуку середнього балу: ";
        cin >> searchStudent;

        auto it = studentGrades.find(searchStudent);
        if (it != studentGrades.end()) {
            cout << "Середній бал студента " << searchStudent << ": " << it->second << endl;
            browsingHistory[searchStudent] = it->second;
        }
        else {
            cout << "Студент з іменем " << searchStudent << " не знайдений." << endl; 
            browsingHistory[searchStudent] = -1.0;  
        }
        choice = _getch();
    } while (choice != 27);

    cout << "\nЖурнал пошукових запитів користувача:" << endl;
    for (const auto& history : browsingHistory) {
        if (history.second == -1.0)
        {
            cout<< history.first<<": "<<"cтудент з іменем " << history.first << " не знайдений." << endl;
        }
        else
        {
            cout << history.first << ": " << history.second << endl;
        }
    }

    return 0;
}






#include <iostream>
#include <stack>
#include <deque>
#include <string>

using namespace std;

bool isBalanced(const string& expression, deque<int>& errorPositions) {
    stack<char> bracketStack;

    for (int i = 0; i < expression.size(); ++i) {
        char currentChar = expression[i];

        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            bracketStack.push(currentChar);
        }
        else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            if (bracketStack.empty()) {
                           errorPositions.push_back(i);
            }
            else {
                char openBracket = bracketStack.top();
                bracketStack.pop();

                if ((currentChar == ')' && openBracket != '(') ||
                    (currentChar == ']' && openBracket != '[') ||
                    (currentChar == '}' && openBracket != '{')) {
                    errorPositions.push_back(i);
                    errorPositions.push_back(expression.find(openBracket));
                }
            }
        }
    }

    while (!bracketStack.empty()) {
        errorPositions.push_back(expression.find(bracketStack.top()));
        bracketStack.pop();
    }

    return errorPositions.empty();
}

int main() {
    setlocale(LC_ALL, "ru");
    string expression;
    cout << "Введіть вираз з дужками: ";
    getline(cin, expression);

    deque<int> errorPositions;

    if (isBalanced(expression, errorPositions)) {
        cout << "Баланс дужок виразу збережений." << endl;
    }
    else {
        cout << "Невірний баланс дужок. Позиції помилок:" << endl;
        for (int position : errorPositions) {
            cout << position << " ";
        }
        cout << endl;
    }

    return 0;
}
