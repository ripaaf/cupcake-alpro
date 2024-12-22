#include <iostream>
#include <string>

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define LIGHT_BLUE "\033[36m"
#define WHITE "\033[37m"
#define GREEN "\033[32m"

using namespace std;

struct Absen {
    string nama;
    string status; // "Hadir", "Izin", "Sakit", "Alfa"
};

const int MAX_ABSEN = 100;

void tampilkanAbsen(Absen daftarAbsen[], int jumlahAbsen) {
    if (jumlahAbsen == 0)  {
        return;
    }

    cout << "\n";
    cout << "+===============================+\n";
    cout << YELLOW << "         Daftar Kehadiran       \n" << RESET;
    cout << "+-------------------------------+\n";
    cout << GREEN << " No.\tNama\t\tStatus\n\n" << WHITE;
    for (int i = 0; i < jumlahAbsen; ++i) {
        cout << " " << (i + 1) << "\t" << daftarAbsen[i].nama << "\t\t" << daftarAbsen[i].status << "\n";
    }
    cout << RESET << "+-------------------------------+\n";
}

void updateAbsen(Absen daftarAbsen[], int* jumlahAbsen) {
    int index;
    cout << "Masukkan nomor absen yang ingin diupdate: ";
    cin >> index;
    cin.ignore(); 

    if (index > 0 && index <= *jumlahAbsen) {
        string namaBaru;
        string statusBaru;

        cout << GREEN << "\n*ENTER jika tidak ingin mengubah\n" << RESET;
        cout << "\nMasukkan nama baru: ";
        getline(cin, namaBaru);

        cout << "===============================\n";
        cout << YELLOW <<"        Update status        \n\n" << WHITE;
        cout << "1." << LIGHT_BLUE << " Sakit" << WHITE <<"\t2." << LIGHT_BLUE <<" Izin" << WHITE <<"\n3." <<
            LIGHT_BLUE <<" Hadir\t" << WHITE <<"4."<< LIGHT_BLUE << " Alfa\n" << RESET;
        cout << "\n";
        cout << "Pilihan: ";
        getline(cin, statusBaru);
        if (statusBaru == "1") {
            statusBaru = "Sakit";
        } else if (statusBaru == "2") {
            statusBaru = "Izin";
        } else if (statusBaru == "3") {
            statusBaru = "Hadir";
        } else if (statusBaru == "4") {
            statusBaru = "Alfa";
        }

        if (!namaBaru.empty()) {
            daftarAbsen[index - 1].nama = namaBaru;
        }

        if (!statusBaru.empty()) {
            daftarAbsen[index - 1].status = statusBaru;
        }

        cout << "\nAbsen berhasil diupdate!\n";
    } else {
        cout << "Nomor absen tidak valid.\n";
    }
}

void deleteAbsen(Absen daftarAbsen[], int& jumlahAbsen) {
    int index;
    cout << "\nMasukkan nomor absen yang ingin dihapus : ";
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= jumlahAbsen) {
        for (int i = index - 1; i < jumlahAbsen - 1; ++i) {
            daftarAbsen[i] = daftarAbsen[i + 1];
        }
        --jumlahAbsen;
        cout << "\nAbsen berhasil dihapus!\n";
    } else {
        cout << "\nNomor absen tidak valid.\n";
    }
}

int main() {
    Absen daftarAbsen[MAX_ABSEN];
    int jumlahAbsen = 0;
    int pilihan;

    do {
        cout << WHITE << "\n";
        if (jumlahAbsen == 0){
        cout << "|===============================|\n";
        cout << "|        " << YELLOW << "Program Absensi" << WHITE << "        |\n";
        cout << "|-------------------------------|\n";
        }
        tampilkanAbsen(daftarAbsen, jumlahAbsen);
        cout << "| 1. " << LIGHT_BLUE << "Tambah Absen" << WHITE << "               |\n";
        // cout << "| 2. " << LIGHT_BLUE << "Tampilkan Absen" << WHITE << "            |\n";
        cout << "| 2. " << LIGHT_BLUE << "Update Absen" << WHITE << "               |\n";
        cout << "| 3. " << LIGHT_BLUE << "Hapus Absen" << WHITE << "                |\n";
        cout << "| 4. " << LIGHT_BLUE << "Keluar" << WHITE << "                     |\n";
        cout << "|===============================|\n\n";
        cout << RESET << "Pilihan: " << RESET;
        cin >> pilihan;

        cin.ignore();
        
        switch (pilihan) {
            case 1:
                if (jumlahAbsen < MAX_ABSEN) {
                    cout << "\n";
                    cout << "Masukkan nama: ";
                    getline(cin, daftarAbsen[jumlahAbsen].nama);
                    cout << "===============================\n";
                    cout << YELLOW <<"        Masukkan status        \n\n" << WHITE;
                    cout << "1." << LIGHT_BLUE << " Sakit" << WHITE <<"\t2." << LIGHT_BLUE <<" Izin" << WHITE <<"\n3." <<
                     LIGHT_BLUE <<" Hadir\t" << WHITE <<"4."<< LIGHT_BLUE << " Alfa\n" << RESET;
                    cout << "\n";
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
                    } else {
                        daftarAbsen[jumlahAbsen].status = "-";
                    }

                    ++jumlahAbsen;
                    cout <<"\nAbsen berhasil ditambahkan!\n";
                } else {
                    cout << "Kapasitas absen penuh.\n";
                }
                break;

            // case 2:
            //     if (jumlahAbsen == 0) {
            //         cout << YELLOW << "\nBelum ada data absensi.\n" << RESET;
            //     } else {
            //         tampilkanAbsen(daftarAbsen, jumlahAbsen);
            //     }
            //     break;

            case 2:
                if (jumlahAbsen == 0) {
                    cout << YELLOW << "\nBelum ada data absensi.\n" << RESET;
                } else {
                    updateAbsen(daftarAbsen, &jumlahAbsen);
                }
                break;

            case 3:
                if (jumlahAbsen == 0) {
                    cout << YELLOW << "\nBelum ada data absensi.\n" << RESET;
                } else {
                    deleteAbsen(daftarAbsen, jumlahAbsen);
                }
                break;

            case 4:
                cout << GREEN << "Keluar dari program.\n" << RESET;
                break;

            default:
                cout << YELLOW << "Pilihan tidak valid. Silakan coba lagi.\n" << RESET;
                break;
        }

    } while (pilihan != 4);
}
