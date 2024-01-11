#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;
int xAwal, yAwal, xAkhir, yAkhir;

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

float skala = 10; // Menentukan faktor skala

void drawPoint(int x, int y) {
    glPointSize(skala); // Ukuran titik
    glBegin(GL_POINTS);
    glVertex2i(x * skala, y * skala);
    glEnd();
}
void tampilkanInformasi(int deltaX, int deltaY, float M) {
    cout << "Delta X: " << deltaX << endl;
    cout << "Delta Y: " << deltaY << endl;
    cout << "Nilai M: " << M << endl;
}

void hitungDeltaDanM(int xAwal, int yAwal, int xAkhir, int yAkhir, int &deltaX, int &deltaY, float &M) {
    deltaX = xAkhir - xAwal;
    deltaY = yAkhir - yAwal;
    M = static_cast<float>(deltaY) / static_cast<float>(deltaX);
}

void tampilkanStep(int deltaX, int deltaY) {
    int step;
    if (abs(deltaX) > abs(deltaY)) {
        step = abs(deltaX);
        cout << "Step: " << step << " (Delta X > Delta Y)" << endl;
    } else {
        step = abs(deltaY);
        cout << "Step: " << step << " (Delta X < Delta Y)" << endl;
    }
}

// Fungsi untuk menampilkan hasil perhitungan dalam bentuk tabel
void tampilkanTabel(int xAwal, int yAwal, int xAkhir, int yAkhir) {
    int deltaX, deltaY;
    float M;
    hitungDeltaDanM(xAwal, yAwal, xAkhir, yAkhir, deltaX, deltaY, M);

    tampilkanInformasi(deltaX, deltaY, M);
    tampilkanStep(deltaX, deltaY);

    int steps;
    if (abs(deltaX) > abs(deltaY)) {
        steps = abs(deltaX);
    } else {
        steps = abs(deltaY);
    }

    float Xp = static_cast<float>(xAwal);
    float Yp = static_cast<float>(yAwal);

    cout << "Rumus yang digunakan: " << endl;
    if (M < 1) {
        cout << "M < 1 (Rumus 1)" << endl;
        cout << left << setw(7) << "X Awal" << setw(7) << "Y Awal" << setw(7) << "Xp+1" << setw(7) << "Yp+1" << setw(14) << "(Xp+1, Yp+1)" << endl;
        for (int i = 0; i < steps; i++) {
            Xp += 1;
            Yp += M;
            cout << left << setw(7) << xAwal << setw(7) << yAwal << setw(7) << int(Xp + 0.5) << setw(7) << int(Yp + 0.5) << setw(15) << "(" << int(Xp + 0.5) << ", " << int(Yp + 0.5) << ")" << endl;
        }
    } else if (M == 1) {
        cout << "M = 1 (Rumus 2)" << endl;
        cout << left << setw(7) << "X Awal" << setw(7) << "Y Awal" << setw(7) << "Xp+1" << setw(7) << "Yp+1" << setw(14) << "(Xp+1, Yp+1)" << endl;
        for (int i = 0; i < steps; i++) {
            Xp += 1;
            Yp += 1;
            cout << left << setw(7) << xAwal << setw(7) << yAwal << setw(7) << int(Xp + 0.5) << setw(7) << int(Yp + 0.5) << setw(15) << "(" << int(Xp + 0.5) << ", " << int(Yp + 0.5) << ")" << endl;
        }
    } else {
        cout << "M > 1 (Rumus 3)" << endl;
        cout << left << setw(7) << "X Awal" << setw(7) << "Y Awal" << setw(7) << "Xp+1" << setw(7) << "Yp+1" << setw(14) << "(Xp+1, Yp+1)" << endl;
        for (int i = 0; i < steps; i++) {
            Xp += 1 / M;
            Yp += 1;
            cout << left << setw(7) << xAwal << setw(7) << yAwal << setw(7) << int(Xp + 0.5) << setw(7) << int(Yp + 0.5) << setw(15) << "(" << int(Xp + 0.5) << ", " << int(Yp + 0.5) << ")" << endl;
        }
    }
}

void DDL(int xAwal, int yAwal, int xAkhir, int yAkhir) {
    int deltaX, deltaY;
    float M;
    hitungDeltaDanM(xAwal, yAwal, xAkhir, yAkhir, deltaX, deltaY, M);

    int steps;
    if (abs(deltaX) > abs(deltaY)) {
        steps = abs(deltaX);
    } else {
        steps = abs(deltaY);
    }

    float Xp = static_cast<float>(xAwal);
    float Yp = static_cast<float>(yAwal);

    for (int i = 0; i < steps; i++) {
        drawPixel(round(Xp) * skala, round(Yp) * skala);
        Xp += 1;
        Yp += M;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Warna putih
    DDL(xAwal, yAwal, xAkhir, yAkhir);

    // Gambar titik A dan B
    glColor3f(1.0, 0.0, 0.0); // Warna merah untuk titik A
    drawPoint(xAwal, yAwal);

    glColor3f(0.0, 1.0, 0.0); // Warna hijau untuk titik B
    drawPoint(xAkhir, yAkhir);

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Warna latar belakang hitam
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480); // Mengatur sistem koordinat
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Grafik Garis dengan Algoritma DDL");
    init();
    cout << "Masukkan Nilai di titik A :";
    cin >> xAwal >> yAwal;
    cout << "Masukkan Nilai di titik B :";
    cin >> xAkhir >> yAkhir;
    cout << "Titik A: (" << xAwal << ", " << yAwal << ")\n";
    cout << "Titik B: (" << xAkhir << ", " << yAkhir << ")\n";
    tampilkanTabel(xAwal, yAwal, xAkhir, yAkhir);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
