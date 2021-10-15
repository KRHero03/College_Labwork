#include <bits/stdc++.h>

using namespace std;

class Student
{
private:
    int id;
    vector<double> grades_obtained;
    double spi;

public:
    Student(int id)
    {
        this->id = id;
        grades_obtained = {0, 0, 0, 0, 0, 0};
        spi = 0;
    }
    Student(int id, vector<double> g_o)
    {
        if (g_o.size() != 6)
        {
            throw "Invalid Grades Obtained Size! It should be 6!";
        }
        for (auto i : g_o)
            if (i < 0 || i > 5)
                throw "Invalid Grade! Grade should be between 0.0 and 5.0 inclusive.";
        this->id = id;
        grades_obtained = g_o;
        this->calculate_spi();
    }

    void calculate_spi()
    {
        this->spi = accumulate(this->grades_obtained.begin(), this->grades_obtained.end(), 0.0) / 6.0;
    }

    void display()
    {
        cout << "Student ID : " << this->id << endl;
        cout << "Scores in Subjects : ";
        for (auto i : this->grades_obtained)
            cout << i << " ";
        cout << endl;
        cout << "SPI : " << this->spi << endl;
        cout << endl;
    }
};

int main()
{
    int n = 6;
    vector<Student*> s;
    for (int i = 0; i < n; i++)
    {
        vector<double> g;
        for (int j = 0; j < 6; j++)
            g.push_back((double)(rand() % 5));
        s.push_back(new Student(i, g));
    }
    for (auto i : s)
        i->display();
}