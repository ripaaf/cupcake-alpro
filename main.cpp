#include <iostream>
#include <string>

using namespace std;

struct Absen {
    string nama;
    string status; // "Hadir", "Izin", "Sakit", "Alfa"
};

const int MAX_ABSEN = 100;


void tampilkanAbsen(Absen daftarAbsen[], int jumlahAbsen) {
    cout << "\nDaftar Kehadiran:\n";
    cout << "--------------------------------\n";
    cout << "No.\tNama\t\tStatus\n";
    for (int i = 0; i < jumlahAbsen; ++i) {
        cout << (i + 1) << "\t" << daftarAbsen[i].nama << "\t\t" << daftarAbsen[i].status << "\n";
    }
    cout << "--------------------------------\n";
}

void updateAbsen(Absen daftarAbsen[], int jumlahAbsen) {
    int index;
    cout << "Masukkan nomor absen yang ingin diupdate: ";
    cin >> index;
    cin.ignore(); // Membersihkan buffer input

    if (index > 0 && index <= jumlahAbsen) {
        cout << "Masukkan nama baru: ";
        getline(cin, daftarAbsen[index - 1].nama);
        cout << "Masukkan status baru (Hadir/Izin/Sakit/Alfa): ";
        getline(cin, daftarAbsen[index - 1].status);
        cout << "Absen berhasil diupdate!\n";
    } else {
        cout << "Nomor absen tidak valid.\n";
    }
}

void deleteAbsen(Absen daftarAbsen[], int& jumlahAbsen) {
    int index;
    cout << "\nMasukkan nomor absen yang ingin dihapus\n";
    cout << "===============================\n";

    cin >> index;
    cin.ignore(); // Membersihkan buffer input

    if (index > 0 && index <= jumlahAbsen) {
        for (int i = index - 1; i < jumlahAbsen - 1; ++i) {
            daftarAbsen[i] = daftarAbsen[i + 1];
        }
        --jumlahAbsen;
        cout << "Absen berhasil dihapus!\n";
    } else {
        cout << "Nomor absen tidak valid.\n";
    }
}

int main() {
    Absen daftarAbsen[MAX_ABSEN];
    int jumlahAbsen = 0;
    int pilihan;

    do {
        cout << "\n";
        cout << "|===============================|\n";
        cout << "|   Program Absensi Sederhana   |\n";
        cout << "|-------------------------------|\n";
        cout << "| 1. Tambah Absen               |\n";
        cout << "| 2. Tampilkan Absen            |\n";
        cout << "| 3. Update Absen               |\n";
        cout << "| 4. Hapus Absen                |\n";
        cout << "| 5. Keluar                     |\n";
        cout << "|===============================|\n\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            if (jumlahAbsen < MAX_ABSEN) {
                cout << "\n";
                cout << "Masukkan nama: ";
                getline(cin, daftarAbsen[jumlahAbsen].nama);
                cout << "===============================\n";
                cout << "Masukkan status\n";
                cout << "1. Sakit\n2. Izin\n3. Hadir\n4. Alfa\n";
                cout << "===============================\n";
                cout << "Pilihan: ";
                getline(cin, daftarAbsen[jumlahAbsen].status);
                if (daftarAbsen[jumlahAbsen].status == "1") {
                    daftarAbsen[jumlahAbsen].status = "Sakit";
                } else if (daftarAbsen[jumlahAbsen].status == "2") {
                    daftarAbsen[jumlahAbsen].status = "Izin";
                } else if (daftarAbsen[jumlahAbsen].status == "3") {
                    daftarAbsen[jumlahAbsen].status = "Hadir";
                } else if (daftarAbsen[jumlahAbsen].status == "4") {
                    daftarAbsen[jumlahAbsen].status = "Alfa";
                } else{
                    daftarAbsen[jumlahAbsen].status = "-";
                }
                
                ++jumlahAbsen;
                cout << "\nAbsen berhasil ditambahkan!\n";
            } else {
                cout << "Kapasitas absen penuh.\n";
            }
        } else if (pilihan == 2) {
            if (jumlahAbsen == 0) {
                cout << "\nBelum ada data absensi.\n";
            } else {
                tampilkanAbsen(daftarAbsen, jumlahAbsen);
            }
        } else if (pilihan == 3) {
            if (jumlahAbsen == 0) {
                cout << "\nBelum ada data absensi.\n";
            } else {
                updateAbsen(daftarAbsen, jumlahAbsen);
            }
        } else if (pilihan == 4) {
            if (jumlahAbsen == 0) {
                cout << "\nBelum ada data absensi.\n";
            } else {
                deleteAbsen(daftarAbsen, jumlahAbsen);
            }
        } else if (pilihan == 5) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan != 5);

}
