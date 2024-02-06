
#include <iostream>
#include <string>
using namespace std;

// Базовий клас : Графічний Об'єкт
class GraficalObject {
public:
    GraficalObject(const string& title) : title(title) {}

    void play() const {
        cout << "Current object is: " << title << endl;
    }

private:
    string title;
};

// Похідний клас: Коло
class Circle : public GraficalObject {
public:
    Circle(const string& title, int lineLength)
        : GraficalObject(title), lineLength(lineLength) {}

    void displayLineLength() const {
        cout << "line length is: " << lineLength << endl;
    }

private:
    int lineLength; 
};

// Похідний клас: Еліпс
class Ellipse : public Circle {
public:
    Ellipse(const string& title, int lineLength, int largestRadius)
        : Circle(title, lineLength), largestRadius(largestRadius) {}

    void displayLargestRadius() const {
        cout << "Largest Radius is : " << largestRadius << endl;
    }

private:
    int largestRadius;
};

// Похідний клас: Прямокутник
class Rectangle : public GraficalObject {
public:
    Rectangle(const string& title, int perimeter)
        : GraficalObject(title), perimeter(perimeter) {}

    void displayPerimeter() const {
        std::cout << "Perimeter is: " << perimeter << endl;
    }

private:
    int perimeter;
};

// Похідний клас: Квадрат
class Square : public Rectangle {
public:
    Square(const string& title, int perimeter, int side)
        : Rectangle(title, perimeter), side(side) {}

    void displaySide() const {
        cout << "Large of the side is: " << side << endl;
    }

private:
    int side;
};


int main() {
    // Приклад використання:
    Ellipse ellipse1("Ellipse 1", 24, 3);
    ellipse1.play();
    ellipse1.displayLineLength();
    ellipse1.displayLargestRadius();

    Square square1("Square 1", 100, 10);
    square1.play();
    square1.displayPerimeter();
    square1.displaySide();

    return 0;
}
