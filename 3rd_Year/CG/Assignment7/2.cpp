#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

// To Compile:-
// g++ -pthread 2.cpp -lglfw3 -lGLEW -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl -lglut

int n = 8;
vector<vector<double>> points = 
{
    {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},
    {1.0,1.0,1.0},
    {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0},
    {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0},
};
int choice;
double angle, tx, ty, tz, sx, sy, sz, shear1, shear2;
int isx;
double axis;
vector<vector<vector<double>>> displayPoints;
void debug(vector<vector<double>> &points)
{
    for (auto i : points)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
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

vector<vector<double>> translateMath(vector<vector<double>> &points, int tX, int tY, int tZ)
{
    vector<vector<double>> translateMatrix = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {(double)tX, (double)tY, (double)tZ, 1}};
    return matrix_mul(points, translateMatrix);
}

vector<vector<double>> rotateMathX(vector<vector<double>> &points, double angle)
{

    vector<vector<double>> rotateMatrix = {{1, 0, 0, 0}, {0, cos(angle), sin(angle), 0}, {0, -sin(angle), cos(angle), 0}, {0, 0, 0, 1}};
    return matrix_mul(points, rotateMatrix);
}

vector<vector<double>> rotateMathY(vector<vector<double>> &points, double angle)
{

    vector<vector<double>> rotateMatrix = {{cos(angle), 0, sin(angle), 0}, {0, 1, 0, 0}, {-sin(angle), 0, cos(angle), 0}, {0, 0, 0, 1}};
    return matrix_mul(points, rotateMatrix);
}

vector<vector<double>> rotateMathZ(vector<vector<double>> &points, double angle)
{

    vector<vector<double>> rotateMatrix = {{cos(angle), sin(angle), 0, 0}, {-sin(angle), cos(angle), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    return matrix_mul(points, rotateMatrix);
}

vector<vector<double>> scaleMath(vector<vector<double>> &points, double scaleX, double scaleY, double scaleZ)
{
    vector<vector<double>> scaleMatrix = {{scaleX, 0, 0, 0}, {0, scaleY, 0, 0}, {0, 0, scaleZ, 0}, {0, 0, 0, 1}};
    return matrix_mul(points, scaleMatrix);
}

vector<vector<double>> shearMath(vector<vector<double>> &points, double shear1, double shear2, int shearDir)
{
    vector<vector<double>> scaleMatrix = {{1, shearDir == 1 ? shear1 : 0.0, shearDir == 2 ? shear1 : 0.0, 0}, {shearDir == 0 ? shear1 : 0.0, 1, shearDir == 2 ? shear2 : 0.0, 0}, {shearDir == 0 ? shear2 : 0.0, shearDir == 1 ? shear2 : 0.0, 1, 0}, {0, 0, 0, 1}};
    return matrix_mul(points, scaleMatrix);
}

vector<vector<double>> reflectMath(vector<vector<double>> &points, int axis)
{
    vector<vector<double>> translateMatrix = {{axis == 0 ? -1.0 : 1.0, 0, 0, 0}, {0, axis == 1 ? -1.0 : 1.0, 0, 0}, {0, 0, axis == 2 ? -1.0 : 1.0, 0}, {0, 0, 0, 1}};
    return matrix_mul(points, translateMatrix);
}

vector<vector<double>> getHomogeneousPoints(vector<vector<double>> &points)
{

    vector<vector<double>> homogeneousPoints(n, vector<double>(4, 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            homogeneousPoints[i][j] = points[i][j];
    return homogeneousPoints;
}


float color[8][3] = 
{
    {0.0,0.0,0.0},
    {1.0,0.0,0.0},
    {1.0,1.0,0.0},
    {0.0,1.0,0.0},
    {0.0,0.0,1.0},
    {1.0,0.0,1.0},
    {1.0,1.0,1.0},
    {0.0,1.0,1.0},
};

void quad(int a,int b,int c,int d,vector<vector<double>> &points)
{
    glBegin(GL_QUADS);
    glColor3f(color[a][0],color[a][1],color[a][2]);
    glVertex3f(points[a][0],points[a][1],points[a][2]);

    glColor3f(color[b][0],color[b][1],color[b][2]);
    glVertex3f(points[b][0],points[b][1],points[b][2]);


    glColor3f(color[c][0],color[c][1],color[c][2]);
    glVertex3f(points[c][0],points[c][1],points[c][2]);


    glColor3f(color[d][0],color[d][1],color[d][2]);
    glVertex3f(points[d][0],points[d][1],points[d][2]);

    glEnd();
}

void colorcube(vector<vector<double>>& points)
{
    quad(0,3,2,1,points);
    quad(2,3,7,6,points);
    quad(0,4,7,3,points);
    quad(1,2,6,5,points);
    quad(4,5,6,7,points);
    quad(0,1,5,4,points);
}

void plotVector(vector<vector<double>> &points)
{

    colorcube(points);
}

void normal_util()
{
    plotVector(points);
}

void translate_util()
{
    vector<vector<double>> translatePoints = getHomogeneousPoints(points);
    points = translateMath(translatePoints, tx, ty, tz);
}

void rotate_util()
{
    vector<vector<double>> rotatePoints = getHomogeneousPoints(points);
    if (axis == 0)
    {
        points = rotateMathX(rotatePoints, angle);
    }
    else if (axis == 1)
    {
        points = rotateMathY(rotatePoints, angle);
    }
    else if (axis == 2)
    {
        points = rotateMathY(rotatePoints, angle);
    }
}

void scale_util()
{
    vector<vector<double>> scalePoints = getHomogeneousPoints(points);
    points = scaleMath(scalePoints, sx, sy, sz);
    debug(points);
}

void shear_util()
{
    vector<vector<double>> scalePoints = getHomogeneousPoints(points);
    points = shearMath(scalePoints, shear1, shear2, axis);
}

void reflect_util()
{
    vector<vector<double>> reflectPoints = getHomogeneousPoints(points);
    points = reflectMath(reflectPoints, axis);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.0);
    glColor3f(0, 0, 1);
    for(auto i: displayPoints) plotVector(i);
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    // cout << "Enter Number of Points: ";
    // cin >> n;
    // points = vector<vector<double>>(n, vector<double>(3, 0));
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter point[" << i << "].x: ";
    //     cin >> points[i][0];
    //     cout << "Enter point[" << i << "].y: ";
    //     cin >> points[i][1];
    //     cout << "Enter point[" << i << "].z: ";
    //     cin >> points[i][2];
    // }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Assignment 7");
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(60, w / h, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        3, 3, 3,
        0, 0, 0,
        0, 0, 1);
    while (true)
    {
        displayPoints.push_back(points);
        cout << "Enter Choice:\n1. Translate\n2. Rotate\n3. Scale\n4. Shear\n5. Reflect\n6. Display\n>>";
        cin >> choice;
        cout << choice << endl;
        if (choice == 1)
        {
            cout << "TX: ";
            cin >> tx;
            cout << "TY: ";
            cin >> ty;
            cout << "TZ: ";
            cin >> tz;
            translate_util();
        }
        else if (choice == 2)
        {
            cout << "Axis (X=0,Y=1,Z=2): ";
            cin >> axis;
            cout << "Angle: ";
            cin >> angle;
            angle *= 180 / (3.14159358979);
            rotate_util();
        }
        else if (choice == 3)
        {
            cout << "Scale X: ";
            cin >> sx;
            cout << "Scale Y: ";
            cin >> sy;
            cout << "Scale Z: ";
            cin >> sz;
            scale_util();
        }
        else if (choice == 4)
        {
            cout << "Shear Axis(X=0,Y=1,Z=2): ";
            cin >> axis;
            cout << "Shear 1: ";
            cin >> shear1;
            cout << "Shear 2: ";
            cin >> shear2;
            shear_util();
        }
        else if (choice == 5)
        {
            cout << "Reflecting Axis (X=0,Y=1,Z=2): ";
            cin >> axis;
            reflect_util();
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }
    }

    glutDisplayFunc(display);

    glutMainLoop();
}