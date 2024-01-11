#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void multiplyMatrix(int matrixA[3][3], int matrixB[3], int resultMatrix[3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultMatrix[i] += matrixA[i][j] * matrixB[j];
        }
    }
}

void multiplyMatrixRotasi(double matrixA[3][3], double matrixB[3], double resultMatrix[3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultMatrix[i] += matrixA[i][j] * matrixB[j];
        }
    }
}

void translasi(int tx, int ty, int &x, int &y) {
    int translationMatrix[3][3] = {{1, 0, tx},
                                   {0, 1, ty},
                                   {0, 0, 1}};
    int pointMatrix[3] = {x, y, 1};
    int resultMatrix[3] = {0};

    cout << "Matriks Translasi:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << translationMatrix[i][j] << " ";
        }
        cout << "\t";

        if (i == 0) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 1) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else {
            cout << "   [1]\n";
        }
    }
    multiplyMatrix(translationMatrix, pointMatrix, resultMatrix);
    cout << "Hasil Translasi Titik P: (" << x << ", " << y << ") -> (" << resultMatrix[0] << ", " << resultMatrix[1] << ")\n";
    x = resultMatrix[0];
    y = resultMatrix[1];
}

void skala(int sx, int sy, int &x, int &y) {
    int translationMatrix[3][3] = {{sx, 0, },
                                   {0, sy, 0},
                                   {0, 0, 1}};
    int pointMatrix[3] = {x, y, 1};
    int resultMatrix[3] = {0};

    cout << "Matriks Translasi:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << translationMatrix[i][j] << " ";
        }
        cout << "\t";

        if (i == 0) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 1) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else {
            cout << "   [1]\n";
        }
    }
    multiplyMatrix(translationMatrix, pointMatrix, resultMatrix);

    cout << "Hasil Translasi Titik P: (" << x << ", " << y << ") -> (" << resultMatrix[0] << ", " << resultMatrix[1] << ")\n";
    x = resultMatrix[0];
    y = resultMatrix[1];
}

void rotasi(double angle, double &x, double &y) {
    double radianAngle = angle * M_PI / 180.0;
    double rotationMatrix[3][3] = {
        {cos(radianAngle), -sin(radianAngle), 0},
        {sin(radianAngle), cos(radianAngle), 0},
        {0, 0, 1}};

    double pointMatrix[3] = {x, y, 1};
    double resultMatrix[3] = {0};
    cout << fixed << setprecision(2);
    cout << "Matriks Rotasi:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << rotationMatrix[i][j] << " ";
        }
        cout << "\t";

        if (i == 0) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if (i == 1) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else {
            cout << "   [ 1 ]\n";
        }
    }
    multiplyMatrixRotasi(rotationMatrix, pointMatrix, resultMatrix);
    cout << "Hasil Rotasi Titik P: (" << x << ", " << y << ") -> (" << resultMatrix[0] << ", " << resultMatrix[1] << ")\n";
    x = resultMatrix[0];
    y = resultMatrix[1];
}



int main() {
    int pilihan;
    int x, y;

    cout << "Pilih program yang ingin dijalankan:" << endl;
    cout << "1. Translasi" << endl;
    cout << "2. Skala" << endl;
    cout << "3. Rotasi" << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            int tx, ty;
            cout << "Masukkan nilai translasi tx: ";
            cin >> tx;
            cout << "Masukkan nilai translasi ty: ";
            cin >> ty;
            cout << "Masukkan nilai x dari titik P: ";
            cin >> x;
            cout << "Masukkan nilai y dari titik P: ";
            cin >> y;
            cout << "Nilai awal Titik P: (" << x << ", " << y << ")\n";
            translasi(tx, ty, x, y);
            break;
        case 2:
            int sx, sy;
            cout << "Masukkan nilai skala sx: ";
            cin >> sx;
            cout << "Masukkan nilai skala sy: ";
            cin >> sy;
            cout << "Masukkan nilai x dari titik P: ";
            cin >> x;
            cout << "Masukkan nilai y dari titik P: ";
            cin >> y;
            cout << "Nilai awal Titik P: (" << x << ", " << y << ")\n";
            skala(sx, sy, x, y);
            break;
        case 3:
            double angle;
            double x, y;
            cout << "Masukkan sudut rotasi (derajat): ";
            cin >> angle;
            cout << "Masukkan nilai x dari titik P: ";
            cin >> x;
            cout << "Masukkan nilai y dari titik P: ";
            cin >> y;
            cout << "Nilai awal Titik P: (" << x << ", " << y << ")\n";
            rotasi(angle, x, y);
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            return 1;
    }
    return 0;
}
