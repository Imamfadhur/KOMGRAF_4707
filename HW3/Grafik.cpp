#include <GL/glut.h>
#include <iostream>


int xAwal, yAwal, xAkhir, yAkhir;

void drawPoint() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // Warna titik (merah)
    glVertex2i(xAwal, yAwal);    // Gambar titik awal
    glVertex2i(xAkhir, yAkhir);  // Gambar titik akhir
    glEnd();
    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Warna background (putih)
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480); // Mengatur sistem koordinat
}

int main(int argc, char** argv) {
    // Input koordinat titik awal dan titik akhir
    printf("Masukkan Nilai di titik A: ");
    scanf("%d %d", &xAwal, &yAwal);
    printf("Masukkan Nilai di titik B: ");
    scanf("%d %d", &xAkhir, &yAkhir);

    // Inisialisasi GLUT
    glutInit(&argc, argv);
    glutCreateWindow("Titik Koordinat");
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    init();
    glutDisplayFunc(drawPoint);
    glutMainLoop();
    return 0;
}
