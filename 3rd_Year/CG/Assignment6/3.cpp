#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

// To Compile:-
// g++ -pthread 3.cpp -lglfw3 -lGLEW -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl -lglut

int n;
vector<vector<double>> points;
int choice;
double angle, tx, ty, s, shear;
int isx;

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

vector<vector<double>> translateMath(vector<vector<double>> &points, int tX, int tY)
{
    vector<vector<double>> translateMatrix = {{1, 0, 0}, {0, 1, 0}, {(double)tX, (double)tY, 1}};
    return matrix_mul(points, translateMatrix);
}

vector<vector<double>> rotateMath(vector<vector<double>> &points, double angle)
{
    vector<vector<double>> rotateMatrix = {{cos(angle), sin(angle), 0}, {-sin(angle), cos(angle), 0}, {0, 0, 1}};
    return matrix_mul(points, rotateMatrix);
}

vector<vector<double>> scaleMath(vector<vector<double>> &points, double scale)
{
    vector<vector<double>> scaleMatrix = {{scale, 0, 0}, {0, scale, 0}, {0, 0, 1}};
    return matrix_mul(points, scaleMatrix);
}

vector<vector<double>> shearMath(vector<vector<double>> &points, double shear, bool isX)
{
    vector<vector<double>> scaleMatrix = {{1.0, isX == false ? shear : 0, 0}, {isX == true ? shear : 0, 1, 0}, {0, 0, 1}};
    return matrix_mul(points, scaleMatrix);
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

void translate_util()
{
    vector<vector<double>> translatePoints = getHomogeneousPoints(points);
    points = translateMath(translatePoints, tx, ty);
}

void rotate_util()
{
    vector<vector<double>> rotatePoints = getHomogeneousPoints(points);
    points = rotateMath(rotatePoints, angle);
}

void scale_util()
{
    vector<vector<double>> scalePoints = getHomogeneousPoints(points);
    points = scaleMath(scalePoints, s);
}

void shear_util()
{
    vector<vector<double>> scalePoints = getHomogeneousPoints(points);
    points = shearMath(scalePoints, shear, isx);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.0);
    glColor3f(0, 0, 1);
    plotVector(points);
    glutSwapBuffers();
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
    while (true)
    {
        cout << "Enter Choice:\n1. Translate\n2. Rotate\n3. Scale\n4. Shear\n5. Display\n>>";
        cin >> choice;
        cout<<choice<<endl;
        if (choice == 1)
        {
            cout << "TX: ";
            cin >> tx;
            cout << "TY: ";
            cin >> ty;
            translate_util();
        }
        else if (choice == 2)
        {
            cout << "Angle: ";
            cin >> angle;
            angle *= 180/(3.14159358979);
            rotate_util();
        }
        else if (choice == 3)
        {
            cout << "Scale: ";
            cin >> s;
            scale_util();
        }
        else if (choice == 4)
        {
            cout << "Shear: ";
            cin >> shear;
            cout << "1 if X Shear, 0 otherwise: ";
            cin >> isx;
            shear_util();
        }
        else if (choice == 5)
        {
            break;
        }
        else{
            cout << "Invalid Choice!" << endl;
        }
    }

    glutDisplayFunc(display);

    glutMainLoop();
}