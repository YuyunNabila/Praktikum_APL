#include <iostream>
#include <string>

using namespace std;

int salah = 0;
int JumlahPengunjung = 0;
string pengunjung[1000];

void tambahkanPengunjung();
void lihatPengunjung();
void ubahPengunjung();
void hapusPengunjung();
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
                main ();
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
            ubahPengunjung();
            menu();
        }
        else if (opsi == "4") {
            hapusPengunjung();
            menu();
        }
        else if (opsi == "5") {
            cout << "Sampai jumpa!" << endl;
            return 0;
        }
        else {
            cout << "Oops! O_o' pilihan opsi tidak valid!" << endl;
            menu ();
        }
    return 0;
}

void tambahkanPengunjung() {
    if (JumlahPengunjung >= 1000) {
        cout << "Jumlah pengunjung sudah mencapai batas" << endl;
    }
    else {
        string nama;
        cout << "Masukkan nama pengunjung: ";
        cin.ignore();
        getline(cin, nama); 
        pengunjung[JumlahPengunjung] = nama;
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
            cout << i + 1 << ". " << pengunjung[i] << endl;
        }
    }
}

void ubahPengunjung() {
    if (JumlahPengunjung == 0) {
        cout << "Belum ada nama pengunjung yang dimasukkan." << endl;
    }
    else {
        cout << "Daftar nama pengunjung:" << endl;
        for (int i = 0; i < JumlahPengunjung; i++) {
            cout << i + 1 << ". " << pengunjung[i] << endl;
        }
        int indeks;
        cout << "Pilih Nama yang akan diubah: ";
        cin >> indeks;
        if (indeks < 1 || indeks > JumlahPengunjung) {
            cout << "Pilihan tidak valid!" << endl;
        }
        else {
            string nama;
            cout << "Masukkan nama pengunjung: ";
            cin.ignore();
            getline(cin, nama);
            pengunjung[indeks - 1] = nama;
            cout << "Nama di nomor " << indeks << " sudah diubah" << endl;
        }
    }
}

void hapusPengunjung() {
    if (JumlahPengunjung == 0) {
        cout << "Belum ada nama pengunjung yang dimasukkan." << endl;
    }
    else {
        for (int i = 0; i < JumlahPengunjung; i++) {
            cout << i + 1 << ". " << pengunjung[i] << endl;
        }
        int indeks;
        cout << "Pilih nama yang akan dihapus: ";
        cin >> indeks;
        if (indeks < 1 || indeks > JumlahPengunjung) {
            cout << "Pilihan tidak valid!" << endl;
        }
        else {
            for (int i = indeks - 1; i < JumlahPengunjung - 1; i++) {
                pengunjung[i] = pengunjung[i + 1];
            }
            JumlahPengunjung--;
            cout << "Nama di nomor " << indeks << " sudah dihapus" << endl;
        }
    }
}
