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

int menu();
void tambahkanPengunjung();
void lihatPengunjung();
void ubahPengunjung(Pengunjung* pengunjung);
void hapusPengunjung(Pengunjung* pengunjung);
void bubbleSort(Pengunjung* pengunjung, int jumlahPengunjung);
void selectionSort(Pengunjung* pengunjung, int jumlahPengunjung);
void shellSort(Pengunjung arr[], int n);
void tampilkanData(Pengunjung* pengunjung, int jumlahPengunjung);
void tampilkanBubbleSort(Pengunjung* pengunjung, int jumlahPengunjung);
void tampilkanselectionSort(Pengunjung* pengunjung, int jumlahPengunjung);
void tampilkanshellSort(Pengunjung* pengunjung, int jumlahPengunjung);
void binarySearch(Pengunjung* pengunjung, int jumlahPengunjung);
void interpolationSearch(Pengunjung* pengunjung, int jumlahPengunjung);

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
        exit ;
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
        cout << "Pilih cara penampilan data: " << endl;
        cout << "1. Tampilan langsung" << endl;
        cout << "2. Sorting data berdasarkan Nomor pengunjung" << endl;
        cout << "3. Sorting data berdasarkan Nama pengunjung" << endl;
        cout << "4. Sorting data berdasarkan Jenis Karcis" << endl;
        cout << "5. Searcing Nama Pengunjung" << endl;
        cout << "6. Searcing Nomor Pengunjung" << endl;
        cout << "Pilihan: ";
        cout << " " << endl;
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            tampilkanData(pengunjung, JumlahPengunjung);
        }
        else if (pilihan == 2) {
            tampilkanBubbleSort(pengunjung, JumlahPengunjung);
        }
        else if (pilihan == 3) {
            tampilkanselectionSort(pengunjung, JumlahPengunjung);
        }
        else if (pilihan == 4){
            tampilkanshellSort (pengunjung, JumlahPengunjung);
        }
        else if (pilihan == 5){
            binarySearch (pengunjung, JumlahPengunjung);
        }
        else if (pilihan == 6){
            interpolationSearch (pengunjung, JumlahPengunjung);
        }
        else {
            cout << "Pilihan tidak valid." << endl;
        }
        
    }
}


void ubahPengunjung(Pengunjung* pengunjung) {
    if (JumlahPengunjung == 0) {
        cout << "Belum ada nama pengunjung yang dimasukkan." << endl;
    }
    else {
        tampilkanData(pengunjung, JumlahPengunjung);
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
        tampilkanData(pengunjung, JumlahPengunjung);
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

void tampilkanData(Pengunjung* pengunjung, int jumlahPengunjung) {
    cout << "Daftar nama pengunjung:" << endl;
    for (int i = 0; i < jumlahPengunjung; i++) {
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

void bubbleSort(Pengunjung* pengunjung, int jumlahPengunjung) {
    for (int i = 0; i < jumlahPengunjung - 1; i++) {
        for (int j = 0; j < jumlahPengunjung - i - 1; j++) {
            if (pengunjung[j].nomor_karcis > pengunjung[j + 1].nomor_karcis) {
                Pengunjung temp = pengunjung[j];
                pengunjung[j] = pengunjung[j + 1];
                pengunjung[j + 1] = temp;
            }
        }
    }
}


void tampilkanBubbleSort(Pengunjung* pengunjung, int jumlahPengunjung){ 
    bubbleSort(pengunjung, jumlahPengunjung);
    cout << "Daftar nama pengunjung setelah diurutkan berdasarkan nomor pengunjung:" << endl;
    for (int i = 0; i < jumlahPengunjung; i++) {
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

void selectionSort(Pengunjung* pengunjung, int jumlahPengunjung) {
    for (int i = 0; i < jumlahPengunjung - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < jumlahPengunjung; j++) {
            if (pengunjung[j].nama > pengunjung[max_idx].nama) {
                max_idx = j;
            }
        }
        Pengunjung temp = pengunjung[max_idx];
        pengunjung[max_idx] = pengunjung[i];
        pengunjung[i] = temp;
    }
    cout << endl;
}

void tampilkanselectionSort(Pengunjung* pengunjung, int jumlahPengunjung){ 
    selectionSort(pengunjung, jumlahPengunjung);
    cout << "Daftar nama pengunjung setelah diurutkan berdasarkan Nama pengunjung:" << endl;
    for (int i = 0; i < jumlahPengunjung; i++) {
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

void shellSort(Pengunjung arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Pengunjung temp = arr[i];
            int j;
            // Membandingkan jenis karcis pengunjung secara ascending
            if (temp.karcis.museum_seni == 1) {
                for (j = i; j >= gap && arr[j - gap].karcis.museum_seni != 1; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            } else if (temp.karcis.museum_arkeolog == 1) {
                for (j = i; j >= gap && arr[j - gap].karcis.museum_arkeolog != 1; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            } else if (temp.karcis.museum_planet == 1) {
                for (j = i; j >= gap && arr[j - gap].karcis.museum_planet != 1; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            }
            arr[j] = temp;
        }
    }
}

void tampilkanshellSort(Pengunjung* pengunjung, int jumlahPengunjung){ 
    shellSort(pengunjung, jumlahPengunjung);
    cout << "Daftar nama pengunjung setelah diurutkan berdasarkan jenis karcis:" << endl;
    for (int i = 0; i < jumlahPengunjung; i++) {
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

void binarySearch(Pengunjung* pengunjung, int jumlahPengunjung){
    bubbleSort(pengunjung, JumlahPengunjung);
    cout << "Masukkan nama yang dicari: ";
    string nama;
    cin.ignore();
    getline(cin, nama);
    int awal = 0;
    int tengah;
    int akhir = JumlahPengunjung - 1;
    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (pengunjung[tengah].nama == nama) {
            cout << "Nama " << nama << " ditemukan pada indeks " << tengah << endl;
            break;
        } else if (pengunjung[tengah].nama < nama) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if (pengunjung[tengah].nama != nama){
        cout << "Nama " << nama << " tidak ditemukan." << endl;
    }
}

void interpolationSearch(Pengunjung* pengunjung, int jumlahPengunjung) {
    selectionSort(pengunjung, jumlahPengunjung);
    cout << "Masukkan nomor pengunjung yang dicari: ";
    int nomor;
    cin >> nomor;

    int awal = 0;
    int akhir = jumlahPengunjung - 1;
    int posisi;

    while (awal <= akhir && nomor >= pengunjung[awal].nomor_karcis && nomor <= pengunjung[akhir].nomor_karcis) {
        posisi = awal + ((nomor - pengunjung[awal].nomor_karcis) * (akhir - awal)) / (pengunjung[akhir].nomor_karcis - pengunjung[awal].nomor_karcis);

        if (pengunjung[posisi].nomor_karcis == nomor) {
            cout << "Nomor pengunjung ditemukan pada indeks " << posisi << endl;
            break;
        }

        if (pengunjung[posisi].nomor_karcis < nomor) {
            awal = posisi + 1;
        } else {
            akhir = posisi - 1;
        }
    }

    if (pengunjung[posisi].nomor_karcis != nomor) {
            cout << "Nomor pengunjung tidak ditemukan pada indeks " << posisi << endl;
        }
}
