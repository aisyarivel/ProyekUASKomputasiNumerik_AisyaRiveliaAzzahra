#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <functional>

using namespace std;

class BrentsMethod {
private:
    double tolerance;
    int maxIterations;
    
public:
    BrentsMethod(double tol = 1e-6, int maxIter = 100) : tolerance(tol), maxIterations(maxIter) {}
    
    // Implementasi Brent's Method sesuai algoritma dari Chapman
    double findRoot(function<double(double)> f, double a, double b) {
        double fa = f(a);
        double fb = f(b);
        
        // Pastikan f(a) dan f(b) memiliki tanda berbeda
        if (fa * fb > 0) {
            cout << "Error: f(a) dan f(b) harus memiliki tanda berbeda!" << endl;
            return NAN;
        }
        
        // Inisialisasi variabel
        double c = a;
        double fc = fa;
        double d = b - c;
        double e = d;
        
        cout << "\n=== ITERASI BRENT'S METHOD ===" << endl;
        cout << "Iter\t|\ta\t|\tb\t|\tc\t|\tf(a)\t|\tf(b)\t|\tf(c)\t|\tRoot Est" << endl;
        cout << "----\t|\t----\t|\t----\t|\t----\t|\t----\t|\t----\t|\t----\t|\t----" << endl;
        
        for (int iter = 0; iter < maxIterations; iter++) {
            // Cetak status iterasi
            cout << iter << "\t|\t" << fixed << setprecision(4) 
                 << a << "\t|\t" << b << "\t|\t" << c << "\t|\t"
                 << fa << "\t|\t" << fb << "\t|\t" << fc << "\t|\t";
            
            // Test konvergensi
            if (abs(fb) < tolerance) {
                cout << b << " (Konvergen)" << endl;
                return b;
            }
            
            // Atur ulang jika perlu
            if (abs(fa) < abs(fb)) {
                c = b; fc = fb;
                b = a; fb = fa;
                a = c; fa = fc;
            }
            
            double m = 0.5 * (c - b);
            double tol1 = 2.0 * tolerance * max(abs(b), 1.0);
            
            // Test terminasi
            if (abs(m) <= tol1 || abs(fb) <= tolerance) {
                cout << b << " (Konvergen)" << endl;
                return b;
            }
            
            // Pilih metode: inverse quadratic interpolation, secant, atau bisection
            double p, q, r, s;
            
            if (abs(e) >= tol1 && abs(fc) > abs(fb)) {
                // Inverse quadratic interpolation atau secant method
                s = fb / fc;
                
                if (a == c) {
                    // Secant method
                    p = 2.0 * m * s;
                    q = 1.0 - s;
                } else {
                    // Inverse quadratic interpolation
                    q = fc / fa;
                    r = fb / fa;
                    p = s * (2.0 * m * q * (q - r) - (b - a) * (r - 1.0));
                    q = (q - 1.0) * (r - 1.0) * (s - 1.0);
                }
                
                if (p > 0) q = -q;
                else p = -p;
                
                // Cek apakah interpolasi dapat diterima
                if (2.0 * p < 3.0 * m * q - abs(tol1 * q) && p < abs(0.5 * e * q)) {
                    e = d;
                    d = p / q;
                } else {
                    d = m;
                    e = m;
                }
            } else {
                // Bisection method
                d = m;
                e = m;
            }
            
            a = b;
            fa = fb;
            
            if (abs(d) > tol1) {
                b = b + d;
            } else {
                b = b + (m > 0 ? tol1 : -tol1);
            }
            
            fb = f(b);
            
            cout << b << endl;
            
            // Atur ulang bracket jika diperlukan
            if ((fb > 0 && fc > 0) || (fb < 0 && fc < 0)) {
                c = a;
                fc = fa;
                d = b - c;
                e = d;
            }
        }
        
        cout << "Maximum iterations reached!" << endl;
        return b;
    }
    
    // Fungsi untuk analisis konvergensi
    void analyzeConvergence(function<double(double)> f, double a, double b, double exactRoot) {
        cout << "\n=== ANALISIS KONVERGENSI ===" << endl;
        double root = findRoot(f, a, b);
        double error = abs(root - exactRoot);
        cout << "Root yang ditemukan: " << fixed << setprecision(8) << root << endl;
        cout << "Root eksak: " << exactRoot << endl;
        cout << "Error absolut: " << scientific << error << endl;
        cout << "Error relatif: " << (error / abs(exactRoot)) * 100 << "%" << endl;
    }
};

// Fungsi-fungsi test case
double function1(double x) {
    return x*x*x - 2*x - 5; // Akar sekitar x = 2.094
}

double function2(double x) {
    return exp(x) - 3*x*x; // Akar sekitar x = 0.910 dan x = 3.733
}

double function3(double x) {
    return x*cos(x) - 2*x*x + 3*x - 1; // Akar sekitar x = 0.641
}

// Inverse quadratic interpolation example dari Chapman
double inverseQuadraticExample(double x) {
    return x*x - 4*x + 5; // Tidak memiliki akar real (untuk demonstrasi)
}

// Fungsi dengan akar real untuk demonstrasi
double realRootFunction(double x) {
    return x*x - 4*x + 3; // Akar di x = 1 dan x = 3
}

int main() {
    cout << "====================================================" << endl;
    cout << "    IMPLEMENTASI BRENT'S METHOD UNTUK ROOT FINDING" << endl;
    cout << "====================================================" << endl;
    cout << "Nama: Aisya Rivelia Azzahra" << endl;
    cout << "NPM: 2306161864" << endl;
    cout << "====================================================" << endl;
    
    BrentsMethod solver(1e-6, 50);
    
    cout << "\n1. PENJELASAN METODE BRENT" << endl;
    cout << "============================================" << endl;
    cout << "Brent's Method adalah algoritma hybrid yang menggabinkan:" << endl;
    cout << "- Reliability dari metode bracketing (bisection)" << endl;
    cout << "- Kecepatan dari open methods (secant, inverse quadratic)" << endl;
    cout << "- Menggunakan inverse quadratic interpolation jika memungkinkan" << endl;
    cout << "- Fallback ke secant method atau bisection jika diperlukan" << endl;
    
    cout << "\n2. STUDI KASUS 1: f(x) = x³ - 2x - 5" << endl;
    cout << "============================================" << endl;
    cout << "Mencari akar dalam interval [2, 3]" << endl;
    double root1 = solver.findRoot(function1, 2.0, 3.0);
    cout << "Verifikasi: f(" << root1 << ") = " << function1(root1) << endl;
    
    cout << "\n3. STUDI KASUS 2: f(x) = eˣ - 3x²" << endl;
    cout << "============================================" << endl;
    cout << "Mencari akar dalam interval [0, 1]" << endl;
    double root2 = solver.findRoot(function2, 0.0, 1.0);
    cout << "Verifikasi: f(" << root2 << ") = " << function2(root2) << endl;
    
    cout << "\nMencari akar dalam interval [3, 4]" << endl;
    double root2b = solver.findRoot(function2, 3.0, 4.0);
    cout << "Verifikasi: f(" << root2b << ") = " << function2(root2b) << endl;
    
    cout << "\n4. STUDI KASUS 3: f(x) = x·cos(x) - 2x² + 3x - 1" << endl;
    cout << "===============================================" << endl;
    cout << "Mencari akar dalam interval [0, 1]" << endl;
    double root3 = solver.findRoot(function3, 0.0, 1.0);
    cout << "Verifikasi: f(" << root3 << ") = " << function3(root3) << endl;
    
    cout << "\n5. DEMONSTRASI INVERSE QUADRATIC INTERPOLATION" << endl;
    cout << "===============================================" << endl;
    cout << "f(x) = x² - 4x + 3 (akar di x = 1 dan x = 3)" << endl;
    cout << "Mencari akar dalam interval [0, 2]" << endl;
    double root4 = solver.findRoot(realRootFunction, 0.0, 2.0);
    cout << "Verifikasi: f(" << root4 << ") = " << realRootFunction(root4) << endl;
    
    cout << "\n6. PERBANDINGAN DENGAN METODE LAIN" << endl;
    cout << "====================================" << endl;
    cout << "Keunggulan Brent's Method:" << endl;
    cout << "- Selalu konvergen (guaranteed convergence)" << endl;
    cout << "- Kombinasi optimal antara kecepatan dan reliability" << endl;
    cout << "- Superlinear convergence rate" << endl;
    cout << "- Tidak memerlukan turunan fungsi" << endl;
    
    cout << "\n7. ANALISIS KINERJA" << endl;
    cout << "===================" << endl;
    cout << "Metode Brent menunjukkan konvergensi yang cepat dan stabil" << endl;
    cout << "dengan menggabungkan inverse quadratic interpolation," << endl;
    cout << "secant method, dan bisection method secara adaptif." << endl;
    
    return 0;
}