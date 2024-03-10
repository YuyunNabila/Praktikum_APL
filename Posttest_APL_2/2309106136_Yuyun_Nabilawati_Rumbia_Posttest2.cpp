#include <iostream>
#include <string>
using namespace std;

int main () {
    int salah = 0;
    int JumlahPengunjung = 0; 

    while (true) {
        string pengunjung[1000];
        string Nama, NIM, opsi, updatePengunjung;
        int indeks;

        cout << "Selamat datang di sistem admin Pengunjung Museum Nasional Indonesia" << endl;
        cout << "Silahkan login" << endl;
        cout << "Nama: ";
        getline(cin, Nama);
        cout << "NIM: ";
        getline(cin, NIM);
        if (Nama == "Yuyun Nabilawati Rumbia" && NIM == "2309106136") {
            cout << endl;
            cout << "Login berhasil!";

            while (true) {

                cout << endl;
                cout << endl;
                cout << "-----Selamat datang di Menu-----" << endl;
                cout << "1. Tambahkan nama pengunjung" << endl;
                cout << "2. Lihat nama pengunjung" << endl;
                cout << "3. Ubah nama pengunjung" << endl;
                cout << "4. Hapus nama pengunjung" << endl;
                cout << "5. Keluar" << endl;
                cout << endl;
                cout << "Silahkan pilih opsi: ";
                cin >> opsi;
                cout << endl;

                if (opsi == "1") {
                    if (JumlahPengunjung >= 1000) {
                        cout << "Jumlah pengunjung sudah mencapai batas" << endl;
                    }
                    else {
                        cout << "Masukkan nama pengunjung: ";
                        cin.ignore();
                        getline(cin, pengunjung[JumlahPengunjung]);
                        JumlahPengunjung++;
                        cout << "Nama sudah di daftarkan" << endl;
                    }
                }

                else if (opsi == "2") {
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

                else if (opsi == "3") {
                    if (JumlahPengunjung == 0) {
                        cout << "Belum ada nama pengunjung yang dimasukkan." << endl;
                    }
                    else {
                        cout << "Daftar nama pengunjung:" << endl;
                        for (int i = 0; i < JumlahPengunjung; i++) {
                            cout << i + 1 << ". " << pengunjung[i] << endl;
                        }
                        cout << "Pilih Nama yang akan diubah: ";
                        cin >> indeks;
                        if (indeks < 1 || indeks > JumlahPengunjung) {
                            cout << "Pilihan tidak valid!" << endl;
                        }
                        else {
                            cout << "Masukkan nama pengunjung: ";
                            cin.ignore();
                            getline(cin, updatePengunjung);
                            pengunjung[indeks - 1] = updatePengunjung;
                            cout << "Nama di nomor " << indeks << " sudah di ubah" << endl;
                        }
                    }
                }

                else if (opsi == "4") {
                    if (JumlahPengunjung == 0) {
                        cout << "Belum ada nama pengunjung yang dimasukkan." << endl;
                    }
                    else {
                        for (int i = 0; i < JumlahPengunjung; i++) {
                            cout << i + 1 << ". " << pengunjung[i] << endl;
                        }
                        cout << "Pilih nama yang akan dihapus: ";
                        cin >> indeks;
                        for (int i = indeks - 1; i < JumlahPengunjung; i++) {
                            pengunjung[i] = pengunjung[i + 1];
                        }
                        JumlahPengunjung--;
                    }
                }

                else if (opsi == "5") {
                    cout << "Sampai jumpa!" << endl;
                    return 0; 
                }

                else {
                    cout << "Oops! O_o' pilihan opsi tidak valid!" << endl;
                }
            }
            break;

        }
        else if (Nama != "Yuyun Nabilawati Rumbia" && NIM != "2309106136") {
            salah++;
            cout << "Nama dan NIM tidak valid!" << endl;
            cout << "Sisa percobaan login " << 3 - salah << endl;
            cout << " " << endl;
            if (salah == 3) {
                cout << "Anda sudah 3x gagal login. Program akan berhenti paksa" << endl;
                return 1; 
            }
        }
        else {
            cout << "Inputan tidak valid" << endl;
        }

    }
    return 0;
}
