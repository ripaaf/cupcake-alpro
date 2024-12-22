#include <iostream>
#include <string>

using namespace std;

struct Absensi {
    int id;
    string nama;
    string tanggal;
    string status;
};

const int MAX_ABSENSI = 100;
Absensi daftarAbsensi[MAX_ABSENSI];
int jumlahAbsensi = 0;

int tampilkanAbsensi() {
    if (jumlahAbsensi == 0) {
        cout << "Belum ada data absensi.\n";
    } else {
        cout << "\nDaftar Absensi:\n";
        cout << "-------------------------------------------------------------\n";
        cout << "| ID  | Nama          | Tanggal      | Status (Hadir/Izin/Sakit/Alpha) |\n";
        cout << "-------------------------------------------------------------\n";
        for (int i = 0; i < jumlahAbsensi; i++) {
            cout << "| " << daftarAbsensi[i].id << "   | " 
                 << daftarAbsensi[i].nama << "\t\t| " 
                 << daftarAbsensi[i].tanggal << "\t| " 
                 << daftarAbsensi[i].status << " |\n";
        }
        cout << "-------------------------------------------------------------\n";
    }
    return 0;
}

int tambahAbsensi() {
    if (jumlahAbsensi >= MAX_ABSENSI) {
        cout << "Data absensi penuh!\n";
        return 0;
    }

    Absensi absensiBaru;
    absensiBaru.id = jumlahAbsensi + 1;

    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, absensiBaru.nama);

    cout << "Masukkan tanggal (DD-MM-YYYY): ";
    getline(cin, absensiBaru.tanggal);

    cout << "Masukkan status (Hadir/Izin/Sakit/Alpha): ";
    getline(cin, absensiBaru.status);

    daftarAbsensi[jumlahAbsensi] = absensiBaru;
    jumlahAbsensi++;
    cout << "Data absensi berhasil ditambahkan.\n";

    return 0;
}

int updateAbsensi() {
    int id;
    cout << "Masukkan ID absensi yang ingin diperbarui: ";
    cin >> id;

    bool ditemukan = false;
    for (int i = 0; i < jumlahAbsensi; i++) {
        if (daftarAbsensi[i].id == id) {
            cout << "Data saat ini: \n";
            cout << "Nama: " << daftarAbsensi[i].nama 
                 << ", Tanggal: " << daftarAbsensi[i].tanggal 
                 << ", Status: " << daftarAbsensi[i].status << endl;

            cin.ignore();
            cout << "Masukkan nama baru: ";
            getline(cin, daftarAbsensi[i].nama);

            cout << "Masukkan tanggal baru (DD-MM-YYYY): ";
            getline(cin, daftarAbsensi[i].tanggal);

            cout << "Masukkan status baru (Hadir/Izin/Sakit/Alpha): ";
            getline(cin, daftarAbsensi[i].status);

            cout << "Data absensi berhasil diperbarui.\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data absensi dengan ID " << id << " tidak ditemukan.\n";
    }

    return 0;
}

int hapusAbsensi() {
    int id;
    cout << "Masukkan ID absensi yang ingin dihapus: ";
    cin >> id;

    bool ditemukan = false;
    for (int i = 0; i < jumlahAbsensi; i++) {
        if (daftarAbsensi[i].id == id) {
            for (int j = i; j < jumlahAbsensi - 1; j++) {
                daftarAbsensi[j] = daftarAbsensi[j + 1];
            }
            jumlahAbsensi--;
            cout << "Data absensi dengan ID " << id << " berhasil dihapus.\n";

            for (int j = 0; j < jumlahAbsensi; j++) {
                daftarAbsensi[j].id = j + 1;
            }

            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data absensi dengan ID " << id << " tidak ditemukan.\n";
    }

    return 0;
}

int menu() {
    int pilihan;
    do {
        cout << "\n=== Sistem Absensi ===\n";
        cout << "1. Tambah Absensi\n";
        cout << "2. Tampilkan Absensi\n";
        cout << "3. Update Absensi\n";
        cout << "4. Hapus Absensi\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        if (pilihan == 1) {
            tambahAbsensi();
        } else if (pilihan == 2) {
            tampilkanAbsensi();
        } else if (pilihan == 3) {
            updateAbsensi();
        } else if (pilihan == 4) {
            hapusAbsensi();
        } else if (pilihan == 5) {
            cout << "Keluar dari sistem absensi.\n";
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan != 5);
    return 0;
}

int main() {
    menu();
    return 0;
}