#include <iostream>
#include <iomanip>
#include <cmath>
#include <GL/glut.h>

using namespace std;

double x_before, y_before, z_before; // Koordinat sebelum transformasi
double x_after, y_after, z_after;   // Koordinat setelah transformasi

void multiplyMatrix3D(double matrixA[4][4], double matrixB[4], double resultMatrix[4]) {
    for (int i = 0; i < 4; ++i) {
        resultMatrix[i] = 0;  // Initialize to zero
        for (int j = 0; j < 4; ++j) {
            resultMatrix[i] += matrixA[i][j] * matrixB[j];
        }
    }
}


void translasi3D(double tx, double ty, double tz, double &x, double &y, double &z) {
    double translationMatrix[4][4] = {
        {1, 0, 0, tx},
        {0, 1, 0, ty},
        {0, 0, 1, tz},
        {0, 0, 0, 1}
    };

    double pointMatrix[4] = {x, y, z, 1};
    double resultMatrix[4] = {0};

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << translationMatrix[i][j] << " ";
        }
        cout << "\t";

        if (i == 0) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 1) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 2) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else {
            cout << "   [1]\n";
        }
    }
    multiplyMatrix3D(translationMatrix, pointMatrix, resultMatrix);

    x_before = x;
    y_before = y;
    z_before = z;

    x_after = resultMatrix[0];
    y_after = resultMatrix[1];
    z_after = resultMatrix[2];

    x = x_after;
    y = y_after;
    z = z_after;
    // Tampilkan hasi
    cout << "Hasil Translasi Titik P: (" << x_before << ", " << y_before << ", " << z_before << ") -> (" << x_after << ", " << y_after << ", " << z_after << ")\n";
}

void skala3D(double sx, double sy, double sz, double &x, double &y, double &z) {
    double scaleMatrix[4][4] = {
        {sx, 0, 0, 0},
        {0, sy, 0, 0},
        {0, 0, sz, 0},
        {0, 0, 0, 1}
    };

    double pointMatrix[4] = {x, y, z, 1};
    double resultMatrix[4] = {0};

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << scaleMatrix[i][j] << " ";
        }
        cout << "\t";

        if (i == 0) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 1) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 2) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else {
            cout << "   [1]\n";
        }
    }

    multiplyMatrix3D(scaleMatrix, pointMatrix, resultMatrix);
    x_before = x;
    y_before = y;
    z_before = z;

    x_after = resultMatrix[0];
    y_after = resultMatrix[1];
    z_after = resultMatrix[2];

    x = x_after;
    y = y_after;
    z = z_after;
    // Tampilkan hasi
    cout << "Hasil Translasi Titik P: (" << x_before << ", " << y_before << ", " << z_before << ") -> (" << x_after << ", " << y_after << ", " << z_after << ")\n";
}

void rotasi3D(double angleX, double angleY, double angleZ, double &x, double &y, double &z) {
    double radianAngleX = angleX * M_PI / 180.0;
    double radianAngleY = angleY * M_PI / 180.0;
    double radianAngleZ = angleZ * M_PI / 180.0;

    // Matriks Rotasi X
    double rotationMatrixX[4][4] = {
        {1, 0, 0, 0},
        {0, cos(radianAngleX), -sin(radianAngleX), 0},
        {0, sin(radianAngleX), cos(radianAngleX), 0},
        {0, 0, 0, 1}
    };

    // Matriks Rotasi Y
    double rotationMatrixY[4][4] = {
        {cos(radianAngleY), 0, sin(radianAngleY), 0},
        {0, 1, 0, 0},
        {-sin(radianAngleY), 0, cos(radianAngleY), 0},
        {0, 0, 0, 1}
    };

    // Matriks Rotasi Z
    double rotationMatrixZ[4][4] = {
        {cos(radianAngleZ), -sin(radianAngleZ), 0, 0},
        {sin(radianAngleZ), cos(radianAngleZ), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    double pointMatrix[4] = {x, y, z, 1};
    double resultMatrix[4] = {0};

    cout << fixed << setprecision(2);
    cout << "Matriks Rotasi:\n";

    // Rotasi X
    cout << "Matriks Rotasi X:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << rotationMatrixX[i][j] << " ";
        }
        cout << "\t";

        if (i == 0) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 1) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 2) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else {
            cout << "   [1]\n";
        }
    }

    multiplyMatrix3D(rotationMatrixX, pointMatrix, resultMatrix);
    pointMatrix[0] = resultMatrix[0];
    pointMatrix[1] = resultMatrix[1];
    pointMatrix[2] = resultMatrix[2];

    // Rotasi Y
    cout << "Matriks Rotasi Y:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << rotationMatrixY[i][j] << " ";
        }
        cout << "\t";

        if (i == 0) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 1) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 2) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else {
            cout << "   [1]\n";
        }
    }

    multiplyMatrix3D(rotationMatrixY, pointMatrix, resultMatrix);
    pointMatrix[0] = resultMatrix[0];
    pointMatrix[1] = resultMatrix[1];
    pointMatrix[2] = resultMatrix[2];

    // Rotasi Z
    cout << "Matriks Rotasi Z:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << rotationMatrixZ[i][j] << " ";
        }
        cout << "\t";

        if (i == 0) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 1) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 2) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else {
            cout << "   [1]\n";
        }
    }

    multiplyMatrix3D(rotationMatrixZ, pointMatrix, resultMatrix);

    x_before = x;
    y_before = y;
    z_before = z;

    x_after = resultMatrix[0];
    y_after = resultMatrix[1];
    z_after = resultMatrix[2];

    x = x_after;
    y = y_after;
    z = z_after;
    // Tampilkan hasi
    cout << "Hasil Translasi Titik P: (" << x_before << ", " << y_before << ", " << z_before << ") -> (" << x_after << ", " << y_after << ", " << z_after << ")\n";
}

void drawAxes() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 10, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 10);
    glEnd();
}

void drawObject(double x, double y, double z) {
    glColor3f(1.0, 0.0, 0.0);
    glutWireCube(1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 15.0, 5.0, 5.0, 0.0, 0.0, 1.0, 0.0);

    drawAxes();

    // Gambar objek sebelum transformasi
    glPushMatrix();
    drawObject(x_before, y_before, z_before);
    glPopMatrix();

    // Gambar objek setelah transformasi
    glPushMatrix();
    drawObject(x_after, y_after, z_after);
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Transformasi 3D");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);

    int pilihan;
    double x, y, z;

    cout << "Pilih program yang ingin dijalankan:" << endl;
    cout << "1. Translasi" << endl;
    cout << "2. Skala" << endl;
    cout << "3. Rotasi" << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            double tx, ty, tz;
            cout << "Masukkan nilai translasi tx: ";
            cin >> tx;
            cout << "Masukkan nilai translasi ty: ";
            cin >> ty;
            cout << "Masukkan nilai translasi tz: ";
            cin >> tz;
            cout << "Masukkan nilai x dari titik P: ";
            cin >> x;
            cout << "Masukkan nilai y dari titik P: ";
            cin >> y;
            cout << "Masukkan nilai z dari titik P: ";
            cin >> z;
            cout << "Nilai awal Titik P: (" << x << ", " << y << ", " << z << ")\n";
            translasi3D(tx, ty, tz, x, y, z);
            break;
        case 2:
            double sx, sy, sz;
            cout << "Masukkan nilai skala sx: ";
            cin >> sx;
            cout << "Masukkan nilai skala sy: ";
            cin >> sy;
            cout << "Masukkan nilai skala sz: ";
            cin >> sz;
            cout << "Masukkan nilai x dari titik P: ";
            cin >> x;
            cout << "Masukkan nilai y dari titik P: ";
            cin >> y;
            cout << "Masukkan nilai z dari titik P: ";
            cin >> z;
            cout << "Nilai awal Titik P: (" << x << ", " << y << ", " << z << ")\n";
            skala3D(sx, sy, sz, x, y, z);
            break;
        case 3:
            double angleX, angleY, angleZ;
            cout << "Masukkan sudut rotasi X (derajat): ";
            cin >> angleX;
            cout << "Masukkan sudut rotasi Y (derajat): ";
            cin >> angleY;
            cout << "Masukkan sudut rotasi Z (derajat): ";
            cin >> angleZ;
            cout << "Masukkan nilai x dari titik P: ";
            cin >> x;
            cout << "Masukkan nilai y dari titik P: ";
            cin >> y;
            cout << "Masukkan nilai z dari titik P: ";
            cin >> z;
            cout << "Nilai awal Titik P: (" << x << ", " << y << ", " << z << ")\n";
            rotasi3D(angleX, angleY, angleZ, x, y, z);
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            return 1;
    }

    glutMainLoop();

    return 0;
}
