#include <iostream>
#include <string>
using namespace std;

struct Buku
{
    string judul;
    string penulis;
    int tahunTerbit;
    string penerbit;
    bool tersedia;
};

void menu(Buku[], int);
void tampilkanDaftarBuku(Buku[], int);
void cariBuku(Buku[], int, string);
void pinjamBuku(Buku[], int);
void kembalikanBuku(Buku[], int);
void biodataKelompok();
void closeProgam();

int main()
{
    const int MAX_BUKU = 10;
    Buku perpustakaan[MAX_BUKU] = {
        {"Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 2011, "Harper", true},
        {"Becoming", "Michelle Obama", 2018, "Crown", true},
        {"The Power of Habit", "Charles Duhigg", 2012, "Random House", true},
        {"Educated", "Tara Westover", 2018, "Random House", true},
        {"The Subtle Art of Not Giving a F*ck", "Mark Manson", 2016, "HarperOne", true},
        {"Atomic Habits", "James Clear", 2018, "Avery", true},
        {"The Alchemist", "Paulo Coelho", 1988, "HarperOne", true},
        {"The Four Agreements", "Don Miguel Ruiz", 1997, "Amber-Allen Publishing", true},
        {"Thinking, Fast and Slow", "Daniel Kahneman", 2011, "Farrar, Straus and Giroux", true},
        {"The Catcher in the Rye", "J.D. Salinger", 1951, "Little, Brown and Company", true},
    };

    menu(perpustakaan, MAX_BUKU);

    return 0;
}

void menu(Buku buku[], int jumlahBuku)
{
    int pilihan;
    string judulCari;

    do
    {
        cout << "~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~" << endl;
        cout << "1. Daftar Buku                  " << endl;
        cout << "2. Cari Buku berdasarkan Judul  " << endl;
        cout << "3. Pinjam Buku                  " << endl;
        cout << "4. Kembalikan Buku              " << endl;
        cout << "5. Jumlah Total Buku            " << endl;
        cout << "6. biodata kelommpok            " << endl;
        cout << "7. Keluar                       " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Pilih Menu (1-6): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tampilkanDaftarBuku(buku, jumlahBuku);
            break;
        case 2:
            cout << "Masukkan judul buku yang ingin dicari: ";
            cin.ignore();
            getline(cin, judulCari);
            cariBuku(buku, jumlahBuku, judulCari);
            break;
        case 3:
            pinjamBuku(buku, jumlahBuku);
            break;
        case 4:
            kembalikanBuku(buku, jumlahBuku);
            break;
        case 5:
            cout << "Jumlah total buku dalam perpustakaan: " << jumlahBuku << endl;
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 6:
            biodataKelompok();
            break;
        case 7:
            closeProgam();
            break;
        default:
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "~~~                                             ~~~" << endl;
            cout << "~~~ Pilihan tidak valid. Silakan pilih kembali  ~~~" << endl;
            cout << "~~~                                             ~~~" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        }

    } while (pilihan != 6);
}

void tampilkanDaftarBuku(Buku buku[], int jumlahBuku)
{
    cout << "===== DAFTAR BUKU =====" << endl;
    for (int i = 0; i < jumlahBuku; ++i)
    {
        cout << "Buku ke-" << i + 1 << endl;
        cout << "Judul   : " << buku[i].judul << endl;
        cout << "Penulis : " << buku[i].penulis << endl;
        cout << "Penerbit: " << buku[i].penerbit << endl;
        cout << "Tahun   : " << buku[i].tahunTerbit << endl;
        if (buku[i].tersedia)
            cout << "Status  : Tersedia" << endl;
        else
            cout << "Status  : Dipinjam" << endl;
        cout << "-----------------------" << endl;
    }

    cout << "Tekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
    cout << endl;
    cout << endl;
    cout << endl;
}

void cariBuku(Buku buku[], int jumlahBuku, string judulCari)
{
    bool ditemukan = false;

    for (int i = 0; i < jumlahBuku; ++i)
    {
        if (buku[i].judul == judulCari)
        {
            cout << "Buku ditemukan:" << endl;
            cout << "Judul   : " << buku[i].judul << endl;
            cout << "Penulis : " << buku[i].penulis << endl;
            cout << "Penerbit: " << buku[i].penerbit << endl;
            cout << "Tahun   : " << buku[i].tahunTerbit << endl;
            if (buku[i].tersedia)
                cout << "Status  : Tersedia" << endl;
            else
                cout << "Status  : Dipinjam" << endl;
            ditemukan = true;

            cout << "Tekan Enter untuk kembali ke menu...";
            cin.ignore();
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        }
    }

    if (!ditemukan)
    {
        cout << "Buku dengan judul '" << judulCari << "' tidak ditemukan." << endl;
    }
}

void pinjamBuku(Buku buku[], int jumlahBuku)
{
    int nomorBuku;
    cout << "Masukkan nomor buku yang ingin dipinjam (1-" << jumlahBuku << "): ";
    cin >> nomorBuku;

    if (nomorBuku < 1 || nomorBuku > jumlahBuku)
    {
        cout << "Nomor buku tidak valid." << endl;
        return;
    }

    int index = nomorBuku - 1;

    if (!buku[index].tersedia)
    {
        cout << "Buku dengan judul '" << buku[index].judul << "' sedang tidak tersedia untuk dipinjam." << endl;
    }
    else
    {
        buku[index].tersedia = false;

        cout << "Anda berhasil meminjam buku dengan judul '" << buku[index].judul << "'." << endl;
        cout << "Detail Peminjaman:" << endl;
        cout << "Judul   : " << buku[index].judul << endl;
        cout << "Penulis : " << buku[index].penulis << endl;
        cout << "Penerbit: " << buku[index].penerbit << endl;
        cout << "Tahun   : " << buku[index].tahunTerbit << endl;
        cout << "Silakan kembalikan dalam 5 hari." << endl;
    }

    cout << "Tekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
    cout << endl;
    cout << endl;
    cout << endl;
}

void kembalikanBuku(Buku buku[], int jumlahBuku)
{
    int nomorBuku;
    cout << "Masukkan nomor buku yang ingin dikembalikan (1-" << jumlahBuku << "): ";
    cin >> nomorBuku;

    if (nomorBuku < 1 || nomorBuku > jumlahBuku)
    {
        cout << "Nomor buku tidak valid." << endl;
        return;
    }

    int index = nomorBuku - 1;

    if (buku[index].tersedia)
    {
        cout << "Buku dengan judul '" << buku[index].judul << "' sudah tersedia di perpustakaan." << endl;
    }
    else
    {
        buku[index].tersedia = true;

        cout << "Anda berhasil mengembalikan buku dengan judul '" << buku[index].judul << "'." << endl;
    }

    cout << "Tekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
    cout << endl;
    cout << endl;
    cout << endl;
}

void biodataKelompok()
{

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~ BIODATA KELOMPOK 6 ~~~~~~~~~" << endl;
    cout << "1.NAZAR FADILAH                " << endl;
    cout << "2.BUDIANNOR                    " << endl;
    cout << "3.SATRIO WICASKONO             " << endl;
    cout << "4.ISMATUL HAWA                 " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Tekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
    cout << endl;
    cout << endl;
    cout << endl;

    main();
}

void closeProgam()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~                                             ~~~" << endl;
    cout << "~~~ Terima kasih telah menggunakan aplikasi ini ~~~" << endl;
    cout << "~~~                                             ~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    exit(0);
}