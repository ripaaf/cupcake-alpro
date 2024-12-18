#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Absen {
    string nama;
    string status; // "Hadir", "Izin", "Sakit", "Alfa"
};

string tampilkanAbsen(const vector<Absen>& daftarAbsen) {
    string output = "\nDaftar Kehadiran:\n";
    output += "--------------------------------\n";
    output += "No.\tNama\t\tStatus\n";
    for (size_t i = 0; i < daftarAbsen.size(); ++i) {
        output += to_string(i + 1) + "\t" + daftarAbsen[i].nama + "\t\t" + daftarAbsen[i].status + "\n";
    }
    output += "--------------------------------\n";
    return output;
}

int main() {
    vector<Absen> daftarAbsen;
    int pilihan;

    do {
        cout << "\nProgram Absensi Sederhana\n";
        cout << "1. Tambah Absen\n";
        cout << "2. Tampilkan Absen\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer input

        if (pilihan == 1) {
            Absen absenBaru;
            cout << "Masukkan nama: ";
            getline(cin, absenBaru.nama);
            cout << "Masukkan status (Hadir/Izin/Sakit/Alfa): ";
            getline(cin, absenBaru.status);
            daftarAbsen.push_back(absenBaru);
            cout << "Absen berhasil ditambahkan!\n";
        } else if (pilihan == 2) {
            if (daftarAbsen.empty()) {
                cout << "\nBelum ada data absensi.\n";
            } else {
                cout << tampilkanAbsen(daftarAbsen);
            }
        } else if (pilihan == 3) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan != 3);

    return 0;
}
