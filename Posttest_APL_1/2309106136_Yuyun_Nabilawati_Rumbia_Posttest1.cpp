#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Akun {
    string Nama;
    string NIM;
};

int main() {
    vector<Akun> akunn;
    int gagal = 0;

    while (true) {
        cout << "Halo! selamat datang di Konversi Suhu sederhana" << endl;
        cout << "Silakan pilih 'Daftar akun' jika belum buat akun, dan jika sudah memiliki akun silahkan 'Login'" << endl;
        cout << "1. Daftar akun" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << " " << endl;
        cout << "Pilih opsi: ";
        string opsi;
        getline(cin, opsi);
        cout << endl;

        if (opsi == "1") {
            cout << "Halo Pengguna baru! Ayo buat akun dulu" << endl;
            string Nama;
            cout << "Nama: ";
            getline(cin, Nama);

            bool akuna = false;
            for (Akun akun : akunn) {
                if (akun.Nama == Nama) {
                    akuna = true;
                    break;
                }
            }

            if (akuna) {
                cout << "Nama Sudah Terpakai Untuk Registrasi Silahkan Coba Lagi" << endl;
                cout << " "<< endl;
            } else {
                string NIM;
                cout << "NIM: ";
                getline(cin, NIM);

                akunn.push_back({Nama, NIM,});
                cout << "Akun Anda berhasil terdaftar dengan Nama: " << Nama << endl;
                cout << " " << endl;
            }
        } else if (opsi == "2") {
            cout << "Hi, Silahkan login dulu ya!" << endl;
            string Nama, NIM;
            cout << "Nama: ";
            getline(cin, Nama);
            cout << "NIM: ";
            getline(cin, NIM);            
            
            bool salah_login = false;
            for (Akun akun : akunn) {
                if (akun.Nama == Nama && akun.NIM == NIM) {
                    salah_login = true;
                    cout << "Login berhasil!" << endl;
                    cout << " " << endl;
                    while (true)
                    {
                        cout << "---Silahkan pilih suhu awal untuk di konversi---"<< endl;
                        cout << "1. Celcius"<< endl;
                        cout << "2. Reamur"<< endl;
                        cout << "3. Farenheit"<< endl;
                        cout << "4. Kelvin"<< endl;
                        cout << "5. Menu sebelumnya"<< endl;
                        cout << "Masukan pilihan: ";
                        string suhu;
                        getline(cin, suhu);

                        if (suhu == "1"){
                            cout << "Masukan suhu Celcius: ";
                            float suhu_celcius;
                            cin >> suhu_celcius;
                            cout << "" << endl;
                            cout << "Pilih suhu untuk di konversikan"<< endl;
                            cout << "1. Reamur"<< endl;
                            cout << "2. Farenheit"<< endl;
                            cout << "3. Kelvin" << endl;
                            cout << "Pilih : ";
                            string konversi_celcius;
                            getline(cin, konversi_celcius);

                            if (konversi_celcius == "1"){
                                // R = (4/5)*C
                                float celcius_reamur;
                                celcius_reamur = 0.8 * suhu_celcius;
                                cout << suhu_celcius << " Celcius = " << celcius_reamur << " Reamur" << endl;
                                cout << " " << endl;
                            }
                            else if (konversi_celcius == "2"){
                                // F = (9/5)*C + 32
                                float celcius_farenheit;
                                celcius_farenheit = 1.8 * suhu_celcius + 32;
                                cout << suhu_celcius << " Celcius = " << celcius_farenheit << " Fahrenheit" << endl;
                                cout << " " << endl;
                            }
                            else if (konversi_celcius == "3"){
                                // K = C + 273.25
                                float celcius_kelvin;
                                celcius_kelvin = suhu_celcius + 273.15;
                                cout << suhu_celcius << " Celcius = " << celcius_kelvin << " Kelvin" << endl;
                                cout << " " << endl;
                            }
                            else {
                                cout << "Pilihan tidak Valid";
                            }
                        }
                        else if (suhu == "2"){
                            cout << "Masukan suhu Reamur: ";
                            float suhu_reamur;
                            cin >> suhu_reamur;
                           

                            cout << "" << endl;
                            cout << "Pilih suhu untuk di konversikan"<< endl;
                            cout << "1. Celcius"<< endl;
                            cout << "2. Farenheit"<< endl;
                            cout << "3. Kelvin" << endl;
                            cout << "Pilih : ";
                            string konversi_reamur;
                            cin.ignore();
                            getline(cin,konversi_reamur);

                            if (konversi_reamur == "1"){
                                // C = (4/5) * R
                                float reamur_celcius;
                                reamur_celcius = 1.8 * suhu_reamur;
                                cout << suhu_reamur << " Reamur = " << reamur_celcius << " Celcius" << endl;
                                cout << " " << endl;
                            }
                            else if (konversi_reamur == "2"){
                                // F = (9/4) * R + 32
                                float reamur_farenheit;
                                reamur_farenheit = 2.25 * suhu_reamur + 32;
                                cout << suhu_reamur << " Reamur = " << reamur_farenheit << " Fahrenheit" << endl;
                                cout << " " << endl;
                            }
                            else if (konversi_reamur == "3"){
                                // K = (5/4) * R + 273.15
                                float reamur_kelvin;
                                reamur_kelvin = 1.25 * suhu_reamur + 273.15;
                                cout << suhu_reamur << " Reamur = " << reamur_kelvin << " Kelvin" << endl;
                                cout << " " << endl;
                            }
                            else {
                                cout << "Pilihan tidak Valid";
                            }
                        }  

                        else if (suhu == "3"){
                            cout << "Masukan suhu Fahrenheit: ";
                            float suhu_fahreinheit;
                            cin >> suhu_fahreinheit;
                            cout << "" << endl;
                            cout << "Pilih suhu untuk di konversikan"<< endl;
                            cout << "1. Celcius"<< endl;
                            cout << "2. Reamur"<< endl;
                            cout << "3. Kelvin" << endl;
                            cout << "Pilih : ";
                            string konversi_fahreinheit;
                            cin.ignore();
                            getline(cin,konversi_fahreinheit);
                            

                            if (konversi_fahreinheit == "1"){
                                // C = (F - 32 ) * (5/9)
                                float fahreinheit_celcius;
                                fahreinheit_celcius = (suhu_fahreinheit - 32) * 0.555;
                                cout << suhu_fahreinheit << " Fahreinheit = " << fahreinheit_celcius << " Celcius" << endl;
                                cout << " " << endl;
                            }
                            else if (konversi_fahreinheit == "2"){
                                // R + (F - 32) * (4/9)
                                float fahreinheit_reamur;
                                fahreinheit_reamur = (suhu_fahreinheit - 32) * 0.444;
                                cout << suhu_fahreinheit << " Fahreinheit = " << fahreinheit_reamur << " Reamur" << endl;
                                cout << " " << endl;
                            }
                            else if (konversi_fahreinheit == "3"){
                                // K = (F - 32) * (5/9) + 273.15
                                float fahreinheit_kelvin;
                                fahreinheit_kelvin = (suhu_fahreinheit - 32) * 0.555 + 273.15;
                                cout << suhu_fahreinheit << " Fahreinheit = " << fahreinheit_kelvin << " Kelvin" << endl;
                                cout << " " << endl;
                            }
                            else {
                                cout << "Pilihan tidak Valid";
                            }
                        }  

                        else if (suhu == "4"){
                            cout << "Masukan suhu Kelvin: ";
                            float suhu_kelvin;
                            cin >> suhu_kelvin;
                            cout << "" << endl;
                            cout << "Pilih suhu untuk di konversikan"<< endl;
                            cout << "1. Celcius"<< endl;
                            cout << "2. Reamur"<< endl;
                            cout << "3. Fahreinheit" << endl;
                            cout << "Pilih : ";
                            string konversi_kelvin;
                            cin.ignore();
                            getline(cin,konversi_kelvin);

                            if (konversi_kelvin == "1"){
                                // C = K - 273.15
                                float kelvin_celcius;
                                kelvin_celcius = suhu_kelvin - 273.15;
                                cout << suhu_kelvin << " Kelvin = " << kelvin_celcius << " Celcius" << endl;
                                cout << " " << endl;
                            }
                            else if (konversi_kelvin == "2"){
                                // R = (4/5) * (K - 273.15)
                                float kelvin_reamur;
                                kelvin_reamur = 0.8 * (suhu_kelvin - 273.15);
                                cout << suhu_kelvin << " Kelvin = " << kelvin_reamur << " Reamur" << endl;
                                cout << " " << endl;
                            }
                            else if (konversi_kelvin == "3"){
                                // F = (9/5) * (K - 273.15) + 32
                                float kelvin_fahreinheit;
                                kelvin_fahreinheit = 1.8 * (suhu_kelvin - 273.15) + 32;
                                cout << suhu_kelvin << " Kelvin = " << kelvin_fahreinheit << " Fahrenheit" << endl;
                                cout << " " << endl;
                            }
                            else {
                                cout << "Pilihan tidak Valid";
                            }
                        }    

                        else if (suhu == "5"){
                            cout << " " << endl;
                            break;
                        }

                        else {
                            cout << "pilihan tidak valid" << endl;
                        }
                        
                    }
                    
                    break;
                }

            }

            if (!salah_login) {
                
                gagal++;
                cout << "Login gagal. Silahkan coba lagi." << endl;
                cout << " " << endl;
                
                if (gagal == 3) {
                    cout << "Anda telah gagal login 3 kali. Program akan keluar." << endl;
                    cout << " " << endl;
                    exit (0);
                }
            }
        }   else if (opsi == "3") {
            cout << "Sampai jumpaa!" << endl;
            exit (0);
             }   
        else {
        cout << "Opsi tidak valid. Silahkan coba lagi." << endl;
        }
    }

    return 0;
}