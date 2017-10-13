//
//  main.cpp
//  lab6_2
//
//  Created by  Aleksandr Chernyi on 13/10/2017.
//  Copyright © 2017  Aleksandr Chernyi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Point
{
    int x;
    int y;
};

struct Shape
{
    int num_of_vertices;
    vector<Point> vertices;
    
    friend ostream& operator<<(ostream &os, const Shape &shape) {
        os << "Вершин в фигуре: " << shape.num_of_vertices << endl;
        
        for (auto vertex : shape.vertices) {
            os << "x: " << vertex.x << setw(5) <<  "y: " << vertex.y << endl;
        }
        
        return os;
    }
    
    
    bool operator<(const Shape& other) const {
        return num_of_vertices < other.num_of_vertices;
    }
};

class ShapeGenerator {
public:
    Shape generateShape() {
        Shape shape;
        shape.num_of_vertices = rand() % 3 + 3;
        for (int i = 0; i < shape.num_of_vertices; i++) {
            int x = rand() % 100;
            int y = rand() % 100;
            Point point {x, y};
            shape.vertices.push_back(point);
        }
        
        return shape;
    }
};

int number_of_all_vertices(const vector<Shape> shapes) {
    int counter = 0;
    
    for (const auto &shape : shapes) {
        counter += shape.num_of_vertices;
    }
    
    return counter;
}

bool shape_equal_5(const Shape& shape) {
    return shape.num_of_vertices == 5;
}

void remove_all_pentagons(vector<Shape>& shapes) {
    shapes.erase(remove_if(shapes.begin(), shapes.end(), shape_equal_5), shapes.end());
}

void show_number_of_diffrent_shapes(const vector<Shape> shapes) {
    int number_of_triangles, number_of_squares, number_of_pentagons;
    number_of_triangles = number_of_squares = number_of_pentagons = 0;
    
    for (auto shape : shapes) {
        int vertices = shape.num_of_vertices;
        
        switch (vertices) {
            case 3 : number_of_triangles++; break;
            case 4 : number_of_squares++; break;
            case 5 : number_of_pentagons++; break;
            default: break;
        }
    }
    
    cout << "Количество треугольников "  << number_of_triangles << endl;
    cout << "Количество четырехугольников " << number_of_squares << endl;
    cout << "Количество пятиугольников " << number_of_pentagons << endl;
}

vector<Point> get_vertices_from_shapes(const vector<Shape> shapes) {
    vector<Point> vertices;
    
    for (const auto &shape : shapes)
        vertices.push_back(*shape.vertices.begin());
    
    return vertices;
}

int main(int argc, const char * argv[]) {
    
    vector<Shape> shapes;
    
    // Создание Фигур
    auto generator = ShapeGenerator();
    for (int i = 0; i < 10; i++) {
        auto shape = generator.generateShape();
        shapes.push_back(shape);
    }
    
    // Вывод фигур
    for (auto shape : shapes) {
        cout << shape << endl;
    }
    
    // Подсчет всех вершин
    cout << "Количество вершин: " << number_of_all_vertices(shapes) << endl;
    show_number_of_diffrent_shapes(shapes);
    
    remove_all_pentagons(shapes);
    
    // Вывод фигур
    for (auto shape : shapes) {
        cout << shape << endl;
    }
    
    auto vertices = get_vertices_from_shapes(shapes);
    cout << "Список координат:" << endl;
    for (auto vertex : vertices) {
        cout << "x: " << vertex.x << setw(5) <<  "y: " << vertex.y << endl;
    }
    cout << endl;
    
    sort(shapes.begin(), shapes.end());
    
    // Вывод фигур
    for (auto shape : shapes) {
        cout << shape << endl;
    }
    
    return 0;
}
