#include <iostream>
#include <string>

using namespace std;

struct JenisKarcis {
    int museum_seni;
    int museum_planet;
    int museum_arkeolog;
};

struct Pengunjung {
    int nomor_karcis;
    string nama;
    JenisKarcis karcis;
};

int salah = 0;
int JumlahPengunjung = 0;
Pengunjung pengunjung[1000];

void tambahkanPengunjung();
void lihatPengunjung();
void ubahPengunjung(Pengunjung* pengunjung);
void hapusPengunjung(Pengunjung* pengunjung);
int menu();

int main() {
    string Nama, NIM;
    while (true) {
        cout << "----------------------------------------------" << endl;
        cout << "|       Selamat datang di sistem admin       |" << endl;
        cout << "|    Pengunjung Museum Nasional Indonesia    |" << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << "------------------" << endl;
        cout << "| Silahkan login |" << endl;
        cout << "------------------" << endl;
        cout << "Nama: ";
        getline(cin, Nama);
        cout << "NIM: ";
        getline(cin, NIM);
        if (Nama == "Yuyun Nabilawati Rumbia" && NIM == "2309106136") {
            cout << endl;
            cout << "Login berhasil!" << endl;
            menu();
            break;
        }
        else {
            salah++;
            cout << "Nama dan NIM tidak valid!" << endl;
            cout << "Sisa percobaan login " << 3 - salah << endl;
            cout << endl;
            if (salah < 3) {
                main();
            }
            else {
                cout << "Anda sudah 3x gagal login. Program akan berhenti paksa" << endl;
                return 1;
            }
        }
    }
    return 0;
}

int menu() {
    string opsi;
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "|       Selamat datang di sistem admin       |" << endl;
    cout << "|    Pengunjung Museum Nasional Indonesia    |" << endl;
    cout << "|--------------------------------------------|" << endl;
    cout << "|                   -MENU-                   |" << endl;
    cout << "|--------------------------------------------|" << endl;
    cout << "| 1.| Tambahkan nama pengunjung              |" << endl;
    cout << "| 2.| Lihat nama pengunjung                  |" << endl;
    cout << "| 3.| Ubah nama pengunjung                   |" << endl;
    cout << "| 4.| Hapus nama pengunjung                  |" << endl;
    cout << "| 5.| Keluar                                 |" << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "Silahkan pilih opsi: ";
    cin >> opsi;
    cout << endl;

    if (opsi == "1") {
        tambahkanPengunjung();
        menu();
    }
    else if (opsi == "2") {
        lihatPengunjung();
        menu();
    }
    else if (opsi == "3") {
        ubahPengunjung(&pengunjung[0]);
        menu();
    }
    else if (opsi == "4") {
        hapusPengunjung(&pengunjung[0]);
        menu();
    }
    else if (opsi == "5") {
        cout << "Sampai jumpa!" << endl;
        return 0;
    }
    else {
        cout << "Oops! O_o' pilihan opsi tidak valid!" << endl;
        menu();
    }
    return 0;
}

void tambahkanPengunjung() {
    if (JumlahPengunjung >= 1000) {
        cout << "Jumlah pengunjung sudah mencapai batas" << endl;
    }
    else {
        Pengunjung peng;
        peng.nomor_karcis = JumlahPengunjung + 1;

        cout << "Masukkan nama pengunjung: ";
        cin.ignore();
        getline(cin, peng.nama);
        for (int i = 0; i < JumlahPengunjung; ++i) {
            if (peng.nama == pengunjung[i].nama) {
                cout << "Nama pengunjung sudah terdaftar. Silakan masukkan nama yang berbeda." << endl;
                return;
            }
        }

        string pilihan_karcis;
        cout << "----------------------------------------------" << endl;
        cout << "|       Selamat datang di sistem admin       |" << endl;
        cout << "|       Pilih jenis karcis yang dibeli       |" << endl;
        cout << "|--------------------------------------------|" << endl;
        cout << "|                   -MENU-                   |" << endl;
        cout << "|--------------------------------------------|" << endl;
        cout << "| 1.| Karcis Museum Seni                     |" << endl;
        cout << "| 2.| Karcis Museum Arkeolog                 |" << endl;
        cout << "| 3.| Karcis Museum Planet                   |" << endl;
        cout << "| 5.| Keluar                                 |" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Pilihan: ";
        cin >> pilihan_karcis;

        if (pilihan_karcis == "1") {
            peng.karcis.museum_seni = 1;
            peng.karcis.museum_arkeolog = 0;
            peng.karcis.museum_planet = 0;
        }
        else if (pilihan_karcis == "2") {
            peng.karcis.museum_seni = 0;
            peng.karcis.museum_arkeolog = 1;
            peng.karcis.museum_planet = 0;
        }
        else if (pilihan_karcis == "3") {
            peng.karcis.museum_seni = 0;
            peng.karcis.museum_arkeolog = 0;
            peng.karcis.museum_planet = 1;
        }
        else {
            cout << "Pilihan tidak valid." << endl;
            return;
        }

        pengunjung[JumlahPengunjung] = peng;
        JumlahPengunjung++;
        cout << "Nama sudah didaftarkan" << endl;
    }
}

void lihatPengunjung() {
    if (JumlahPengunjung == 0) {
        cout << "Belum ada nama pengunjung yang dimasukkan." << endl;
    }
    else {
        cout << "Daftar nama pengunjung:" << endl;
        for (int i = 0; i < JumlahPengunjung; i++) {
            cout << "Nama Pengunjung: " << pengunjung[i].nama << endl;
            cout << "Nomor Pengunjung: " << pengunjung[i].nomor_karcis << endl;
            if (pengunjung[i].karcis.museum_seni == 1) {
                cout << "Jenis Karcis: Karcis Museum Seni" << endl;
            }
            if (pengunjung[i].karcis.museum_arkeolog == 1) {
                cout << "Jenis Karcis: Karcis Museum Arkeolog" << endl;
            }
            if (pengunjung[i].karcis.museum_planet == 1) {
                cout << "Jenis Karcis: Karcis Museum Planet" << endl;
            }
            cout << endl;
        }
    }
}

void ubahPengunjung(Pengunjung* pengunjung) {
    if (JumlahPengunjung == 0) {
        cout << "Belum ada nama pengunjung yang dimasukkan." << endl;
    }
    else {
        lihatPengunjung();
        string nama_pengunjung;
        cout << "Masukkan nama pengunjung yang akan diubah: ";
        cin.ignore();
        getline(cin, nama_pengunjung);
        bool found = false;
        for (int i = 0; i < JumlahPengunjung; i++) {
            if (pengunjung[i].nama == nama_pengunjung) {
                found = true;
                string nama;
                cout << "Masukkan nama pengunjung: ";
                getline(cin, nama);

                string pilihan_karcis;
                cout << "----------------------------------------------" << endl;
                cout << "|       Selamat datang di sistem admin       |" << endl;
                cout << "|       Pilih jenis karcis yang dibeli       |" << endl;
                cout << "|--------------------------------------------|" << endl;
                cout << "|                   -MENU-                   |" << endl;
                cout << "|--------------------------------------------|" << endl;
                cout << "| 1.| Karcis Museum Seni                     |" << endl;
                cout << "| 2.| Karcis Museum Arkeolog                 |" << endl;
                cout << "| 3.| Karcis Museum Planet                   |" << endl;
                cout << "| 5.| Keluar                                 |" << endl;
                cout << "----------------------------------------------" << endl;
                cout << "Pilihan: ";
                getline(cin, pilihan_karcis);

                if (pilihan_karcis == "1") {
                    pengunjung[i].karcis.museum_seni = 1;
                    pengunjung[i].karcis.museum_arkeolog = 0;
                    pengunjung[i].karcis.museum_planet = 0;
                }
                else if (pilihan_karcis == "2") {
                    pengunjung[i].karcis.museum_seni = 0;
                    pengunjung[i].karcis.museum_arkeolog = 1;
                    pengunjung[i].karcis.museum_planet = 0;
                }
                else if (pilihan_karcis == "3") {
                    pengunjung[i].karcis.museum_seni = 0;
                    pengunjung[i].karcis.museum_arkeolog = 0;
                    pengunjung[i].karcis.museum_planet = 1;
                }
                else {
                    cout << "Pilihan tidak valid." << endl;
                    return;
                }

                pengunjung[i].nama = nama;
                cout << "Data pengunjung dengan nama " << nama_pengunjung << " sudah diubah" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Nama pengunjung tidak ditemukan!" << endl;
        }
    }
}

void hapusPengunjung(Pengunjung* pengunjung) {
    if (JumlahPengunjung == 0) {
        cout << "Belum ada nama pengunjung yang dimasukkan." << endl;
    }
    else {
        lihatPengunjung();
        string nama_pengunjung;
        cout << "Masukkan nama pengunjung yang akan dihapus: ";
        cin.ignore();
        getline(cin, nama_pengunjung);
        bool found = false;
        for (int i = 0; i < JumlahPengunjung; i++) {
            if (pengunjung[i].nama == nama_pengunjung) {
                found = true;
                for (int j = i; j < JumlahPengunjung - 1; j++) {
                    pengunjung[j] = pengunjung[j + 1];
                }
                JumlahPengunjung--;
                cout << "Pengunjung dengan nama " << nama_pengunjung << " telah dihapus" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Nama pengunjung tidak ditemukan!" << endl;
        }
    }
}
