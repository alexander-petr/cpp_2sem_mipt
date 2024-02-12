#include <iostream>

class Point2D
{
protected:
    double _x;
    double _y;

public:
    // ����������� ����� � ��������� ������������
    Point2D(double x, double y): _x(x), _y(y) {
    }

    // �������� ���������� X �����
    double x() const {
        return _x;
    }

    // �������� ���������� Y �����
    double y() const {
        return _y;
    }
};

template <typename T>
T abs(T x) {
    return x > T(0) ? x : -x;
}

#include <vector>

class Polygone
{
public:
    // �����������, ������ ������� �� ������ �����.
    // ����� ���������� � ������� ������ �������� �� �������.
    Polygone(const std::vector<Point2D>& points){
        vertices = points;
    }

    // ����������, ���� �����

    // ���������� ������� ��������
    double area() const{
        auto s = 0.;
        auto p_0 = vertex(0);
        for (auto i = 1u; i + 1 < this->size(); i++){
            auto p_i = vertex(i);
            auto p_j = vertex(i + 1);
            s += abs((p_i.x() - p_0.x())*(p_j.y()- p_0.y()) - (p_j.x() - p_0.x())*(p_i.y()- p_0.y()));
        }
        return s / 2;
    }

    // ���������� ���������� ������ ��������
    unsigned int size() const{
        return vertices.size();
    }

    // ���������� N-�� ������� ��������
    // (������� ���������� � ��� �� �������, � ������� ���� ��������)
    Point2D vertex(unsigned int N) const{
        return vertices[N];
    }
private:
    std::vector<Point2D> vertices;

};


using namespace std;

int main()
{
    std::vector<Point2D> points = {{-1.0, -1.0}, {-1.0, 1.0}, {1.0, 1.0}, {1.0, -1.0}};
    Polygone p(points);
    cout << "Points:" << endl;
    for(unsigned int i = 0; i < p.size(); i++) {
        cout << p.vertex(i).x() << " " << p.vertex(i).y() << endl;
    }
    cout << "Area: " << p.area() << endl;
    return 0;
}
