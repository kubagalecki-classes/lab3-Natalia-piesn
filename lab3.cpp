
#include <iostream>
#include <typeinfo>

using namespace std;

class GeometricThing
{
public:
    virtual void id() = 0;
};

class Figure : public GeometricThing
{
public:
    Figure() {}
    Figure(double p) { area = p; }
    void         set_area(double p) { area = p; }
    int          get_area() { return area; }
    virtual void id() { cout << typeid(this).name() << " " << area << endl; }

    virtual ~Figure() { cout << "Figure destroyed" << endl; }

private:
    double area;
};

class Square : public Figure
{
public:
    Square() {}
    Square(double a) : Figure(a * a) { side = a; }
    void id() override { cout << typeid(this).name() << " " << get_area() << endl; }
    virtual ~Square() { cout << "Square destroyed" << endl; }

private:
    double side;
};

class Circle : public Figure
{
public:
    Circle() {}
    Circle(double r) : Figure(3.14 * r * r) { radius = r; }
    void id() override { cout << typeid(this).name() << " " << get_area() << endl; }
    virtual ~Circle() { cout << "Circle destroyed" << endl; }

private:
    double radius;
};

class FigureVector : public Figure
{
public:
    FigureVector() : counter{0} { fig_vector = new Figure[100]; }
    ~FigureVector()
    {
        delete[] fig_vector;
        cout << "Figurevector deleted" << endl;
    }
    Figure* operator[](int i)
    {
        if (i < counter)
            return &fig_vector[i];
        else
            return nullptr;
    };

    void push(const Figure& f)
    {
        fig_vector[counter] = f;
        counter++;
    }

    void pop()
    {
        fig_vector[counter] = 0;
        // fig_vector[counter - 1] = nullptr;
        counter--;
    }

    void print_counter() { cout << counter << endl; }

private:
    int     counter;
    Figure* fig_vector;
};

void id(Figure* fig)
{
    if (fig == nullptr) {
        cout << "out of range" << endl;
    }
    else {
        fig->id();
    }
}

int main()
{
    FigureVector Figures;

    Square S(4);
    Circle C(10);
    Figure F(5);

    Figures.push(S);
    Figures.print_counter();
    id(Figures[0]);

    Figures.push(C);
    Figures.print_counter();
    Figures.pop();
    Figures.print_counter();

    // id(Figures);

    Figures.push(F);
    Figures.print_counter();
    // id(Figures);

    /*
    id(S);
    Figure F = static_cast< Figure >(S);
    F.id();

   Figure* f = new Square{10};

   Square* sf = dynamic_cast< Square* >(f);
   cout << sf << endl;
   delete sf;
   */
}