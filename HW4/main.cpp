#include <GL/glut.h>
#include <iostream>

int x1, y1, x2, y2;
float pointSize = 5.0;

void plotPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;

    if (x1 < x2) {
        x = x1;
        y = y1;
    } else {
        x = x2;
        y = y2;
        x2 = x1;
        y2 = y1;
    }

    int p = 2 * dy - dx;

    std::cout << "Step\tX\tY\tP\n";
    std::cout << "------------------------\n";

    plotPixel(x, y);

    for (x; x < x2; x++) {
        std::cout << x << "\t" << y << "\t" << p << "\n";

        if (p < 0) {
            p += 2 * dy;
        } else {
            p += 2 * (dy - dx);
            if (y1 < y2) {
                y++;
            } else {
                y--;
            }
        }
        plotPixel(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glPointSize(pointSize); // Atur ukuran titik
    bresenhamLine(x1, y1, x2, y2);
    glPointSize(1.0); // Kembalikan ukuran titik ke default

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 50, 0, 50);
}

int main(int argc, char** argv) {
    std::cout << "Masukkan koordinat titik awal (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Masukkan koordinat titik akhir (x2 y2): ";
    std::cin >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();


    return 0;
}
