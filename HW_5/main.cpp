#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

float xAwal, yAwal, xEnd, yEnd;

void display(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20, 30, -20, 30);
}

void setPixel(GLint xCoordinate, GLint yCoordinate) {
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void translate(GLint x0, GLint y0, GLint x1, GLint y1) {
    setPixel(x0, y0);
    GLint xEnd = x0 + x1;
    GLint yEnd = y0 + y1;
    GLint xTemp = x0;
    GLint yTemp = y0;
    while (xTemp < xEnd || yTemp < yEnd) {
        if (xTemp < xEnd) {
            xTemp++;
        } else if (yTemp < yEnd) {
            yTemp++;
        }
        setPixel(xTemp, yTemp);
    }
    setPixel(xEnd, yEnd);
}

void scale(GLint x0, GLint y0, GLint sx, GLint sy) {
    setPixel(x0, y0);
    GLint xEnd = x0 * sx;
    GLint yEnd = y0 * sy;
    GLint xTemp = x0;
    GLint yTemp = y0;
    while (xTemp < xEnd || yTemp < yEnd) {
        if (xTemp < xEnd) {
            xTemp++;
        } else if (yTemp < yEnd) {
            yTemp++;
        }
        setPixel(xTemp, yTemp);
    }
    setPixel(xEnd, yEnd);
}

void rotate(GLint x0, GLint y0, GLint xp, GLint yp) {
    setPixel(x0, y0);
    GLint x1, y1;
    x1 = 1 * -xp;
    y1 = 1 * -yp;
    GLint a, b, c, d;
    a = 0;
    b = -1;
    c = 1;
    d = 0;
    GLint xCentered = x0 - xp;
    GLint yCentered = y0 - yp;
    GLint x2 = (a * xCentered) + (c * xCentered);
    GLint y2 = (b * yCentered) + (d * yCentered);

    GLint xEnd, yEnd;
    if (x1 < 0) {
        xEnd = x2 + x1;
    } else if (x1 > 0) {
        xEnd = x2 - x1;
    }
    if (y1 < 0) {
        yEnd = y2 + y1;
    } else if (y1 > 0) {
        yEnd = y2 - y1;
    }

    GLint xTemp = x0;
    GLint yTemp = y0;

    while (xTemp < xEnd || yTemp < yEnd) {
        if (xTemp < xEnd) {
            xTemp++;
        } else if (yTemp < yEnd) {
            yTemp++;
        }
        setPixel(xTemp, yTemp);
    }

    while (xTemp > xEnd || yTemp > yEnd) {
        if (xTemp > xEnd) {
            xTemp--;
        } else if (yTemp > yEnd) {
            yTemp--;
        }
        setPixel(xTemp, yTemp);
    }
    setPixel(xEnd, yEnd);
}

void drawTranslation() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    translate(xAwal, yAwal, xEnd, yEnd);
}

void drawScaling() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    scale(xAwal, yAwal, xEnd, yEnd);
}

void drawRotation() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    rotate(xAwal, yAwal, xEnd, yEnd);
}

int main(int argc, char** argv) {
    int choice;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2D Transformations");
    display();

    cout << "1. Translation\n2. Scaling\n3. Rotation\nPilih salah satu opsi transformasi: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Masukkan koordinat titik awal (x0 y0): " << endl;
            cout << "Masukan x0 :";
            cin >> xAwal;
            cout << "Masukan y0 :";
            cin >> yAwal;
            cout << "Masukkan vektor terjemahan (x1 y1): " << endl;
            cout << "Masukan x1 :";
            cin >> xEnd;
            cout << "Masukan y1 :";
            cin >> yEnd;
            glutDisplayFunc(drawTranslation);
            glutMainLoop();
            break;
        case 2:
            cout << "Masukkan koordinat titik awal (x0 y0): " << endl;
            cout << "Masukan x0 :";
            cin >> xAwal;
            cout << "Masukan y0 :";
            cin >> yAwal;
            cout << "Masukkan vektor terjemahan (x1 y1): " << endl;
            cout << "Masukan x1 :";
            cin >> xEnd;
            cout << "Masukan y1 :";
            cin >> yEnd;
            glutDisplayFunc(drawScaling);
            glutMainLoop();
            break;
        case 3:
            cout << "Masukkan koordinat titik awal (x0 y0): " << endl;
            cout << "Masukan x0 :";
            cin >> xAwal;
            cout << "Masukan y0 :";
            cin >> yAwal;
            cout << "Masukkan vektor terjemahan (x1 y1): " << endl;
            cout << "Masukan x1 :";
            cin >> xEnd;
            cout << "Masukan y1 :";
            cin >> yEnd;
            glutDisplayFunc(drawRotation);
            glutMainLoop();
            break;
        default:
            cout << "Invalid choice.\n";
            return 1;
    }
    return 0;
}
