/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 01 – Overview of C Language
 *   Hari dan Tanggal    : Rabu, 15 April 2026
 *   Nama (NIM)          : Muhammad Zaki Azzamy Syauqi (13224045)
 *   Nama File           : soal2.c
 *   Deskripsi           : Diberi input:
 *                           T n1 n2 ... nT
 *                         dimana T adalah jumlah bilangan yang ingin diproses, nx adalah bilangan yang ingin diproses
 *                         Untuk setiap bilangan, dihitung banyak langkah sampai menjadi 1 dengan aturan transformasi tertentu:
 *                           n genap    => n = n/2
 *                           n ganjil   => n = 3n + 1
 *                         Output:
 *                           LANGKAH banyak_langkah_n1
 *                           ...
 *                           Langkah banyaK_langkah_nT 
 *                         Perhitungan menggunakan rekursi.
 *                         Asumsi tidak perlu error handling.
 */

#include <stdio.h>

/* Fungsi untuk menghitung langkah (steps) hingga n menjadi 1
    Input:  int n, angka yang ingin diproses
            int steps, inisialisasi dengan 0
    Output: int, hasil langkah         
*/          
int calcSteps(int n, int steps) {
    if (n == 1) {
        return steps;
    }

    if (n % 2 == 0) n /= 2;
    else n = 3*n + 1;
    steps += 1;

    return calcSteps(n, steps);
}

/* Prosedur untuk menghitungan langkah dari semua angka dalam sebuah array dengan size T dan menampilkannya hasilnya pada terminal */
void outputAllSteps(int* numbers_to_process, int T) {
    for (int i = 0; i < T; i += 1) {
        int steps = calcSteps(numbers_to_process[i], 0);
        printf("LANGKAH %d\n", steps);
    }
}

int main() {
    int T; // amount of numbers to process

    // Bagian input, menghasilkan array integer dengan size T berisi input
    scanf("%d", &T);
    int numbers_to_process[T];
    for (int i = 0; i < T; i += 1) {
        scanf("%d", &numbers_to_process[i]);
    }

    // Bagian kalkulasi dan output
    outputAllSteps(numbers_to_process, T);

    return 0;
}