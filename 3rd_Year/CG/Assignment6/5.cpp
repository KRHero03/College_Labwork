#include <bits/stdc++.h>
#include <GL/glut.h>
#include <chrono>
#include <thread>

using namespace std;

// To Compile:-
// g++ -pthread 5.cpp -lglfw3 -lGLEW -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl -lglut

int n;
vector<vector<double>> points;
double cx = 0,cy = 0;
double cosVal = cos(0.01256637061);
double sinVal = sin(0.01256637061);

void debug(){
    for(auto i: points){
        for(auto j: i) cout<<j<<" ";
        cout<<endl;
    }
}

vector<vector<double>> matrix_mul(vector<vector<double>> &mat1, vector<vector<double>> &mat2)
{
    int p = mat1.size();
    int q = mat1[0].size();
    int r = mat2[0].size();
    vector<vector<double>> mat3(p, vector<double>(q, 0));
    for (int i = 0; i < p; i++)
    {
        for (int k = 0; k < r; k++)
        {
            for (int j = 0; j < q; j++)
            {
                mat3[i][k] += mat1[i][j] * mat2[j][k];
            }
        }
    }
    return mat3;
}

vector<vector<double>> translateMath(vector<vector<double>> &points,double tx,double ty)
{
    vector<vector<double>> translateMatrix = {{1, 0, 0}, {0, 1, 0}, {(double)tx, (double)tx, 1}};
    return matrix_mul(points, translateMatrix);
}

vector<vector<double>> rotateMath(vector<vector<double>> &points)
{
    vector<vector<double>> rotateMatrix = {{cosVal, sinVal, 0}, {-sinVal, cosVal, 0}, {0, 0, 1}};
    return matrix_mul(points, rotateMatrix);
}

vector<vector<double>> getHomogeneousPoints(vector<vector<double>> &points)
{

    vector<vector<double>> homogeneousPoints(n, vector<double>(3, 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            homogeneousPoints[i][j] = points[i][j];
    return homogeneousPoints;
}

void plotVector(vector<vector<double>> &points)
{

    glColor3f(0, 0, 1);
    for (int i = 0; i < n; i++)
    {
        glBegin(GL_LINES);
        glVertex2f(points[i][0], points[i][1]);
        glVertex2f(points[(i + 1) % n][0], points[(i + 1) % n][1]);
        glEnd();
    }
}

void normal_util()
{
    plotVector(points);
}

void translate_util(double tx,double ty)
{
    vector<vector<double>> translatePoints = getHomogeneousPoints(points);
    points = translateMath(translatePoints,tx,ty);
}

void rotate_util()
{
    vector<vector<double>> rotatePoints = getHomogeneousPoints(points);
    points = rotateMath(rotatePoints);
}


void transform(vector<vector<double>>& points){
    translate_util(-cx,-cy);
    rotate_util();
    translate_util(cx,cy);
}

void display()
{

    points = getHomogeneousPoints(points);
    for(auto i: points){
        cx += i[0];
        cy += i[1];
    }
    cx /= n;
    cy /= n;
    while(true){
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(1.0);
        glColor3f(0, 0, 1);
        plotVector(points);
        glutSwapBuffers();
        transform(points);
        this_thread::sleep_for(chrono::milliseconds(60) );
        glFlush();
    }
}


int main(int argc, char *argv[])
{
    cout << "Enter Number of Points: ";
    cin >> n;
    points = vector<vector<double>>(n, vector<double>(2, 0));
    for (int i = 0; i < n; i++)
    {
        cout << "Enter point[" << i << "].x: ";
        cin >> points[i][0];
        cout << "Enter point[" << i << "].y: ";
        cin >> points[i][1];
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Assignment 6");
    glShadeModel(GLU_FLAT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);

    glutDisplayFunc(display);
    glutMainLoop();
}