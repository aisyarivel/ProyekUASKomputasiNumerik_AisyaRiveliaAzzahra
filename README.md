# Brent's Method for Root Finding - Numerical Computation

**Implementasi Brent's Method untuk Pencarian Akar Fungsi Nonlinear**

---

## 👨‍💻 Author Information

**Nama:** Aisya Rivelia Azzahra  
**NPM:** 2306161864  
**Jurusan:** Teknik Komputer  
**Universitas:** Universitas Indonesia  

---

## 📖 Deskripsi Program

Program ini merupakan implementasi **Brent's Method** dalam bahasa **C++** untuk menyelesaikan masalah pencarian akar (root finding) pada fungsi nonlinear. Brent's Method adalah algoritma hybrid yang cerdas dan efisien, menggabungkan keunggulan dari tiga metode berbeda untuk mencapai konvergensi yang optimal.

### 🔍 Apa itu Brent's Method?

Brent's Method, yang dikembangkan oleh Richard Brent pada tahun 1973, adalah algoritma pencarian akar yang secara adaptif memilih strategi terbaik berdasarkan kondisi iterasi saat ini. Metode ini menggabinkan:

1. **Inverse Quadratic Interpolation** - Menggunakan tiga titik untuk membentuk parabola terbalik
2. **Secant Method** - Menggunakan dua titik untuk aproksimasi linear
3. **Bisection Method** - Sebagai fallback untuk menjamin konvergensi

### 🎯 Keunggulan Utama

- **Konvergensi Dijamin**: Selalu menemukan akar jika interval awal valid
- **Tidak Memerlukan Turunan**: Hanya membutuhkan evaluasi fungsi
- **Adaptif**: Secara otomatis memilih metode terbaik di setiap iterasi
- **Superlinear Convergence**: Konvergensi lebih cepat daripada bisection
- **Robust**: Stabil untuk berbagai jenis fungsi matematika

### 🧮 Fungsi Yang Diuji

Program ini telah diuji pada berbagai jenis fungsi untuk memvalidasi performanya:

1. **f₁(x) = x³ - 2x - 5**
   - Fungsi polinomial kubik
   - Akar sekitar x ≈ 2.094

2. **f₂(x) = eˣ - 3x²**
   - Fungsi transcendental eksponensial
   - Dua akar: x ≈ 0.910 dan x ≈ 3.733

3. **f₃(x) = x·cos(x) - 2x² + 3x - 1**
   - Fungsi trigonometri campuran
   - Akar sekitar x ≈ 0.641

4. **f₄(x) = x² - 4x + 3**
   - Fungsi kuadrat sederhana
   - Akar eksak: x = 1 dan x = 3

### ⚙️ Spesifikasi Teknis

- **Bahasa Pemrograman**: C++
- **Toleransi**: 1×10⁻⁶
- **Maksimum Iterasi**: 50
- **Metode Interpolasi**: Inverse Quadratic Interpolation
- **Fallback Methods**: Secant Method dan Bisection Method

### 📊 Hasil Performa

Berdasarkan pengujian yang dilakukan:
- **Konvergensi**: Superlinear rate (6-9 iterasi rata-rata)
- **Akurasi**: Tinggi dengan toleransi 10⁻⁶
- **Stabilitas**: Sangat stabil untuk berbagai jenis fungsi
- **Efisiensi**: Optimal dibandingkan metode tradisional

### 🔬 Algoritma Kerja

1. **Inisialisasi**: Menentukan interval [a,b] dengan f(a)·f(b) < 0
2. **Evaluasi Kondisi**: Mengecek kriteria untuk pemilihan metode
3. **Pemilihan Adaptif**:
   - Gunakan Inverse Quadratic jika kondisi optimal
   - Gunakan Secant Method jika hanya dua titik tersedia
   - Gunakan Bisection sebagai fallback
4. **Iterasi**: Update titik dan bracket hingga konvergensi tercapai
5. **Terminasi**: Berhenti ketika toleransi tercapai atau iterasi maksimum

### 🎓 Konteks Akademik

Program ini dikembangkan sebagai bagian dari **Proyek UAS Komputasi Numerik** untuk memahami dan mengimplementasikan metode numerik advanced dalam pencarian akar fungsi nonlinear. Implementasi ini menunjukkan penerapan praktis dari teori komputasi numerik dalam menyelesaikan masalah matematika kompleks.

### 🔧 Penggunaan

Program ini dapat digunakan untuk:
- Penelitian komputasi numerik
- Pembelajaran metode root finding
- Penyelesaian persamaan nonlinear dalam engineering
- Basis pengembangan solver numerik yang lebih kompleks

---

## 📈 Kesimpulan

Brent's Method terbukti sebagai algoritma yang sangat efektif untuk pencarian akar fungsi nonlinear, menawarkan kombinasi optimal antara kecepatan konvergensi dan stabilitas numerik. Implementasi ini berhasil mendemonstrasikan keunggulan metode hybrid dalam komputasi numerik modern.

---

*Proyek ini merupakan bagian dari mata kuliah Komputasi Numerik, Departemen Teknik Elektro, Universitas Indonesia.*