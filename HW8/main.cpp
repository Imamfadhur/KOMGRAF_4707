#include <iostream>
#include <GL/glut.h>

float x1, y1, x2, y2, x_min, y_min, x_max, y_max;
float m;

void garis() {
    // Hitung gradien garis
    m = (y2 - y1) / (x2 - x1);

    // Hitung titik potong
    float xp1 = x1 + (y_min - y1) / m;
    float yp1 = y1 + m * (x_min - x1);
    float xp2 = x1 + (y_max - y1) / m;
    float yp2 = y1 + m * (x_max - x1);

    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    // Output hasil perhitungan
    std::cout << "\nPenjumlahan" << std::endl;
    std::cout << "m = (" << y2 << "-" << y1 << ") / (" << x2 << "-" << x1 << ") = " << m << std::endl;
    std::cout << "xp1 = " << x1 << "+" << "(" << y_min << "-" << y1 << ") /" << m << " = " << xp1 << std::endl;
    std::cout << "yp1 = " << y1 << "+" << m << "* (" << x_min << "-" << x1 << ") = " << yp1 << std::endl;
    std::cout << "xp2 = " << x1 << "+" << "(" << y_max << "-" << y1 << ") /" << m << " = " << xp2 << std::endl;
    std::cout << "yp2 = " << y1 << "+" << m << "* (" << x_max << "-" << x1 << ") = " << yp2 << std::endl;

    std::cout << "\nHasil penjumlahan" << std::endl;
    std::cout << "(x_min , yp1) = (" << x_min << ", " << yp1 << ")" << std::endl;
    std::cout << "(x_max , yp2) = (" << x_max << ", " << yp2 << ")" << std::endl;
    std::cout << "(xp1 , y_min) = (" << xp1 << ", " << y_min << ")" << std::endl;
    std::cout << "(xp2 , y_max) = (" << xp2 << ", " << y_max << ")" << std::endl;
}


void clippingWindow() {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x_min, y_min);
    glVertex2f(x_max, y_min);
    glVertex2f(x_max, y_max);
    glVertex2f(x_min, y_max);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0); // Set line color to white
    garis();

    glColor3f(0.0, 1.0, 0.0); // Set clipping window color to green
    clippingWindow();

    glFlush();
}

int main(int argc, char** argv) {
    // Input data
    std::cout << "Masukkan koordinat ujung kiri garis (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Masukkan koordinat ujung kanan garis (x2, y2): ";
    std::cin >> x2 >> y2;
    std::cout << "Masukkan koordinat batas gambar (x_min, y_min, x_max, y_max): ";
    std::cin >> x_min >> y_min >> x_max >> y_max;

    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Line and Clipping Window");
    glutInitWindowSize(50, 50);
    gluOrtho2D(0, 50, 0, 50);
    glutDisplayFunc(display);

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutMainLoop();

    return 0;
}
