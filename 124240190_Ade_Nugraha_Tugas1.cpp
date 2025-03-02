#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Film
{
    string judul;
    string kode;
    float rating;
};

Film films[] = {
    {"Omniscience Reader's Viewpoint", "A001", 9.5},
    {"Eleceed", "B002", 9.8},
    {"Star Embracing Swordmaster", "C003", 9.0},
    {"Lookism", "D004", 8.5},
    {"Solo Leveling", "E005", 8.2},
    {"Jinx", "F006", 2.7},
    {"Lord of The Mysteries", "G007", 9.9},
    {"Noblesse", "H008", 8.1},
    {"Strangers From Hell", "I009", 8.3},
    {"Study Group", "J010", 8.6}};

int N = sizeof(films) / sizeof(films[0]);

void quick_sort(Film array[], int awal, int akhir)
{
    int low = awal, high = akhir;

    float pivot = array[(awal + akhir) / 2].rating;

    float temp;

    do
    {
        while (array[low].rating < pivot)
            low++;

        while (array[high].rating > pivot)
            high--;

        if (low <= high)
        {
            swap(array[low], array[high]);
            low++;
            high--;
        }

    } while (low <= high);

    if (awal < high)
        quick_sort(array, awal, high);

    if (low < akhir)
        quick_sort(array, low, akhir);
}

void garis()
{
    cout << "+--------+--------------------------------+--------+\n";
}

int main()
{

    string username, password;

    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    if (username == "ade" && password == "123")
    {
        cout << "Login berhasil !!\n";
    }
    else
    {
        cout << "Username atau password salah.\n";
        return 0;
    }

    int menu;
    string cari;
    char ulang;

    do
    {
        cout << "\n====================================================\n";
        cout << "|      Sistem Manajemen Data Bioskop Double A      |\n";
        cout << "====================================================\n";
        cout << "Menu : \n";
        cout << "1. Tampilkan semua data film\n";
        cout << "2. Cari Film Berdasarkan Kode\n";
        cout << "3. Cari Film Berdasarkan Judul\n";
        cout << "4. Mengurutkan Film Berdasarkan Rating (Asc)\n";
        cout << "5. Mengurutkan Film Berdasarkan Rating (Desc)\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu : ";
        cin >> menu;
        switch (menu)
        {

        case 1:
        {

            garis();
            cout << "| " << left << setw(6) << "Kode" << " | "
                 << setw(30) << "Judul" << " | "
                 << setw(6) << "Rating" << " |\n";
            garis();

            for (int i = 0; i < N; ++i)
            {
                cout << "| " << left << setw(6) << films[i].kode << " | "
                     << setw(30) << films[i].judul << " | "
                     << setw(6) << films[i].rating << " |\n";
            }

            garis();

            break;
        }

        case 2:
        {
            int c = 0;

            cout << "Masukan kode film yang ingin dicari : ";
            cin >> cari;

            while (c < N && films[c].kode != cari)
            {
                c++;
            }

            if (c == N)
                cout << "Data tidak ditemukan" << endl;
            else
                garis();
            cout << "| " << left << setw(6) << films[c].kode << " | "
                 << setw(30) << films[c].judul << " | "
                 << setw(6) << films[c].rating << " |\n";
            garis();
            break;
        }

        case 3:
        {

            // Sorting judulnya dulu dengan Bubble Sort karena Binary Search datanya wajib terurut
            for (int i = 0; i < N - 1; ++i)
            {
                for (int j = 0; j < N - i - 1; ++j)
                {
                    if (films[j].judul > films[j + 1].judul)
                    {
                        swap(films[j], films[j + 1]);
                    }
                }
            }

            string cari;
            cout << "Masukkan judul film yang ingin dicari: ";
            cin.ignore();
            getline(cin, cari);

            int awal = 0, akhir = N - 1, tengah;
            bool found = false;
            while (awal <= akhir)
            {
                tengah = (awal + akhir) / 2;
                if (films[tengah].judul == cari)
                {
                    found = true;
                    break;
                }
                else if (films[tengah].judul < cari)
                {
                    awal = tengah + 1;
                }
                else
                {
                    akhir = tengah - 1;
                }
            }

            if (found)
            {
                cout << "Film ditemukan:\n";
                garis();
                cout << "| " << left << setw(6) << films[tengah].kode << " | "
                     << setw(30) << films[tengah].judul << " | "
                     << setw(6) << films[tengah].rating << " |\n";
                garis();
            }
            else
                cout << "Data tidak ditemukan.\n";
            break;
        }

        case 4:
        {
            quick_sort(films, 0, N - 1);

            cout << "\nQuick Sort (Ascending):" << endl;

            garis();
            cout << "| " << left << setw(6) << "Kode" << " | "
                 << setw(30) << "Judul" << " | "
                 << setw(6) << "Rating" << " |\n";
            garis();

            for (int i = 0; i < N; ++i)
            {
                cout << "| " << left << setw(6) << films[i].kode << " | "
                     << setw(30) << films[i].judul << " | "
                     << setw(6) << films[i].rating << " |\n";
            }

            garis();
            break;

        case 5:
        {
            for (int i = 0; i < N - 1; i++)
            {
                for (int j = 0; j < N - i - 1; j++)
                {
                    if (films[j].rating < films[j + 1].rating)
                    {
                        swap(films[j], films[j + 1]);
                    }
                }
            }

            cout << "Bubble Sort (Descending) : " << endl;

            garis();
            cout << "| " << left << setw(6) << "Kode" << " | "
                 << setw(30) << "Judul" << " | "
                 << setw(6) << "Rating" << " |\n";
            garis();

            for (int i = 0; i < N; ++i)
            {
                cout << "| " << left << setw(6) << films[i].kode << " | "
                     << setw(30) << films[i].judul << " | "
                     << setw(6) << films[i].rating << " |\n";
            }

            garis();
            break;
        }

        case 0:
        {
            cout << "\nTerima Kasih ^^" << endl;

            system("pause");
            system("cls");

            return 0;
            break;
        }

        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
        }

        cout << "Apakah Anda ingin kembali ke menu? (y/n): ";
        cin >> ulang;

        if (ulang == 'n' || ulang == 'N')
        {
            cout << "\nTerima Kasih ^^" << endl;
            system("pause");
            system("cls");
        }
    } while (ulang == 'y' || ulang == 'Y');
}