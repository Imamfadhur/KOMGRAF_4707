#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void multiplyMatrix(double matrixA[3][3], double matrixB[3], double resultMatrix[3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultMatrix[i] += matrixA[i][j] * matrixB[j];
        }
    }
}

void translasi(double tx, double ty, double &x, double &y) {
    double translationMatrix[3][3] = {{1, 0, tx},
                                      {0, 1, ty},
                                      {0, 0, 1}};
    double pointMatrix[3] = {x, y, 1};
    double resultMatrix[3] = {0};

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

void skala(double sx, double sy, double &x, double &y) {
    double scalingMatrix[3][3] = {{sx, 0, 0},
                                  {0, sy, 0},
                                  {0, 0, 1}};
    double pointMatrix[3] = {x, y, 1};
    double resultMatrix[3] = {0};

    cout << "Matriks Skala:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << scalingMatrix[i][j] << " ";
        }
        cout << "\t";

        if (i == 0) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else if ( i == 1) {
            cout << "   [" << pointMatrix[i] << "]\n";
        } else {
            cout << "   [1]\n";
        }
    }
    multiplyMatrix(scalingMatrix, pointMatrix, resultMatrix);

    cout << "Hasil Skala Titik P: (" << x << ", " << y << ") -> (" << resultMatrix[0] << ", " << resultMatrix[1] << ")\n";
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
    multiplyMatrix(rotationMatrix, pointMatrix, resultMatrix);
    cout << "Hasil Rotasi Titik P: (" << x << ", " << y << ") -> (" << resultMatrix[0] << ", " << resultMatrix[1] << ")\n";
    x = resultMatrix[0];
    y = resultMatrix[1];
}

void mirrorX(double &x, double y) {
    cout << "Hasil Refleksi (Mirror) terhadap sumbu X pada Titik P: (" << x << ", " << y << ") -> (" << x << ", " << -y << ")\n";
    y = -y;
}

void mirrorY(double x, double &y) {
    cout << "Hasil Refleksi (Mirror) terhadap sumbu Y pada Titik P: (" << x << ", " << y << ") -> (" << -x << ", " << y << ")\n";
    x = -x;
}

void mirrorOrigin(double &x, double &y) {
    cout << "Hasil Refleksi (Mirror) terhadap titik origin pada Titik P: (" << x << ", " << y << ") -> (" << -x << ", " << -y << ")\n";
    x = -x;
    y = -y;
}

void Composite_translasi(double tx1, double ty1, double tx2, double ty2, double &x, double &y) {
    double tx = tx1 + tx2;
    double ty = ty1 + ty2;

    double translationMatrix[3][3] = {{1, 0, tx},
                                      {0, 1, ty},
                                      {0, 0, 1}};
    double pointMatrix[3] = {x, y, 1};
    double resultMatrix[3] = {0};
    cout << "Matriks Translasi:\n";
    cout << "Nilai tx (tx1+tx2)=(" << tx1 << "+" << tx2 << "=" << tx << ")\n";
    cout << "Nilai ty (ty1+ty2)=(" << ty1 << "+" << ty2 << "=" << ty << ")\n";
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

void Composite_skala(double sx1, double sy1, double sx2, double sy2, double &x, double &y) {
    double sx = sx1 * sx2;
    double sy = sy1 * sy2;

    double translationMatrix[3][3] = {{sx, 0, 0},
                                      {0, sy, 0},
                                      {0, 0, 1}};
    double pointMatrix[3] = {x, y, 1};
    double resultMatrix[3] = {0};
    cout << "Matriks Skala:\n";
    cout << "Nilai sx (sx1*sx2)=(" << sx1 << "*" << sx2 << "=" << sx << ")\n";
    cout << "Nilai sy (sy1*sy2)=(" << sy1 << "*" << sy2 << "=" << sy << ")\n";
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

void Composite_rotasi(double angle1, double angle2, double &x, double &y) {
    double angle = angle1+angle2;
    double radianAngle1 = angle1 * M_PI / 180.0;
    double radianAngle2 = angle2 * M_PI / 180.0;
    double radianAngle = radianAngle1+radianAngle2;
    double rotationMatrix[3][3] = {
        {cos(radianAngle), -sin(radianAngle), 0},
        {sin(radianAngle), cos(radianAngle), 0},
        {0, 0, 1}};

    double pointMatrix[3] = {x, y, 1};
    double resultMatrix[3] = {0};
    cout << fixed << setprecision(2);
    cout << "Matriks Rotasi:\n";
    cout << "Nilai composite(rad1+rad2)=(" << angle1 << "+" << angle2 << "=" << angle << ")\n";
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
    multiplyMatrix(rotationMatrix, pointMatrix, resultMatrix);
    cout << "Hasil Rotasi Titik P: (" << x << ", " << y << ") -> (" << resultMatrix[0] << ", " << resultMatrix[1] << ")\n";
    x = resultMatrix[0];
    y = resultMatrix[1];
}

int main() {
    int pilihan;
    double x, y;
    double tx, ty, tx2, ty2;
    double sx, sy, sx2, sy2;
    double angle, angle2;

    cout << "Pilih program yang ingin dijalankan:\n";
    cout << "1. Translasi -> Skala -> Rotasi -> Mirror\n";
    cout << "2. Composite\n";
    cin >> pilihan;
    switch (pilihan) {
        case 1:
            cout << "Masukkan nilai x dari titik P: ";
            cin >> x;
            cout << "Masukkan nilai y dari titik P: ";
            cin >> y;
            cout << "Nilai awal Titik P: (" << x << ", " << y << ")\n";

            cout << "-Translasi\n";
            cout << "Masukkan nilai translasi tx: ";
            cin >> tx;
            cout << "Masukkan nilai translasi ty: ";
            cin >> ty;
            translasi(tx, ty, x, y);

            cout << "-Skala\n";
            cout << "Masukkan nilai skala sx: ";
            cin >> sx;
            cout << "Masukkan nilai skala sy: ";
            cin >> sy;
            skala(sx, sy, x, y);

            cout << "-Rotasi\n";
            cout << "Masukkan sudut rotasi (derajat): ";
            cin >> angle;
            rotasi(angle, x, y);

            cout << "-Mirror/Refleksi\n";
            int pilihanTransformasi;
            cout << "Pilih transformasi tambahan:\n";
            cout << "1. Refleksi terhadap sumbu X\n";
            cout << "2. Refleksi terhadap sumbu Y\n";
            cout << "3. Refleksi terhadap titik origin\n";
            cout << "Pilih: ";
            cin >> pilihanTransformasi;

            switch (pilihanTransformasi) {
                case 1:
                    mirrorX(x, y);
                    break;
                case 2:
                    mirrorY(x, y);
                    break;
                case 3:
                    mirrorOrigin(x, y);
                    break;
                default:
                    cout << "Pilihan refleksi tidak valid.\n";
                    return 1;
            }
            break;
        case 2:
            int composite;
            cout << "Pilih Composite tambahan:\n";
            cout << "1. Composite Translasi\n";
            cout << "2. Composite Skala\n";
            cout << "3. Composite Rotasi\n";
            cin >> composite;
            if (composite == 1){
                cout << "Masukkan nilai x dari titik P: ";
                cin >> x;
                cout << "Masukkan nilai y dari titik P: ";
                cin >> y;
                cout << "Nilai awal Titik P: (" << x << ", " << y << ")\n";
                cout << "Masukkan nilai translasi tx: ";
                cin >> tx;
                cout << "Masukkan nilai translasi ty: ";
                cin >> ty;
                cout << "Masukkan nilai translasi tx2: ";
                cin >> tx2;
                cout << "Masukkan nilai translasi ty2: ";
                cin >> ty2;
                Composite_translasi(tx, ty, tx2, ty2, x, y);
                break;
            }
            else if (composite == 2){
                cout << "Masukkan nilai x dari titik P: ";
                cin >> x;
                cout << "Masukkan nilai y dari titik P: ";
                cin >> y;
                cout << "Nilai awal Titik P: (" << x << ", " << y << ")\n";
                cout << "Masukkan nilai skala sx: ";
                cin >> sx;
                cout << "Masukkan nilai skala sy: ";
                cin >> sy;
                cout << "Masukkan nilai skala sx2: ";
                cin >> sx2;
                cout << "Masukkan nilai skala sy2: ";
                cin >> sy2;
                Composite_skala(sx, sy, sx2, sy2, x, y);
                break;
            }
            else if (composite == 3){
                cout << "Masukkan nilai x dari titik P: ";
                cin >> x;
                cout << "Masukkan nilai y dari titik P: ";
                cin >> y;
                cout << "Nilai awal Titik P: (" << x << ", " << y << ")\n";
                cout << "Masukkan sudut rotasi1 (derajat): ";
                cin >> angle;
                cout << "Masukkan sudut rotasi2 (derajat): ";
                cin >> angle2;
                Composite_rotasi(angle, angle2, x, y);
                break;
            }
            else{
                cout << "PIlihan Tidak Valid\n";
            }
        default:
            cout << "Pilihan tidak valid.\n";
            break;
    }

    return 0;
}
