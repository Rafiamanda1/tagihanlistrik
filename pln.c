#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Pelanggan
{
    int id;
    char nama[50];
    int golongan;
    float va;
    float pemakaianKwh;
    float Harga;
};

#define MAX_PELANGGAN 1000
struct Pelanggan pelanggan[MAX_PELANGGAN];
int jumlahPelanggan = 0;


// Rendi
void InputPelanggan()
{
    if (jumlahPelanggan >= MAX_PELANGGAN)
    {
        printf("Kapasitas pelanggan telah mencapai batas maksimum.\n");
        return;
    }
    pelanggan[jumlahPelanggan].id = jumlahPelanggan + 1;

    printf("ID Pelanggan: %d\n", pelanggan[jumlahPelanggan].id);
    getchar();

    do
    {
        printf("Masukkan Nama Pelanggan: ");
        fgets(pelanggan[jumlahPelanggan].nama, sizeof(pelanggan[jumlahPelanggan].nama), stdin);
        pelanggan[jumlahPelanggan].nama[strcspn(pelanggan[jumlahPelanggan].nama, "\n")] = '\0';
        if (strlen(pelanggan[jumlahPelanggan].nama) == 0)
        {
            printf("Nama Tidak Boleh Kosong, Masukkan Kembali\n");
        }

    } while (strlen(pelanggan[jumlahPelanggan].nama) == 0);

    printf("Masukkan golongan (1,2,3): ");
    scanf("%d", &pelanggan[jumlahPelanggan].golongan);

    printf("Pilih Daya (VA): \n\n");
    int angka;

    switch (pelanggan[jumlahPelanggan].golongan)
    {
    case 1:
        printf("Ketik 1 untuk paket Va 450, Rp 415 per 1 kwh\n");
        printf("Ketik 2 untuk paket Va 900, Rp 605 per 1 kwh\n");
        printf("Pilih Paket VA untuk golongan R1: ");
        scanf("%d", &angka);

        if (angka == 1)
        {
            pelanggan[jumlahPelanggan].va = 450;
        }
        else if (angka == 2)
        {
            pelanggan[jumlahPelanggan].va = 900;
        }
        else
        {
            printf("Pilihan tidak vali, Default ke 900 VA\n");
            pelanggan[jumlahPelanggan].va = 900;
        }
        break;

    case 2:
        printf("Ketik 1 paket Va 3500, Rp 1699 per 1 kwh\n");
        printf("Ketik 2 paket Va 5500, Rp 1699 per 1 kwh\n");
        printf("Pilih Paket VA untuk golongan R2: ");
        scanf("%d", &angka);

        if (angka == 1)
        {
            pelanggan[jumlahPelanggan].va = 3500;
        }
        else if (angka == 2)
        {
            pelanggan[jumlahPelanggan].va = 5500;
        }
        else
        {
            printf("Pilihan tidak valid, Default ke 3500 VA\n");
            pelanggan[jumlahPelanggan].va = 3500;
        }
        break;

    case 3:
        printf("paket golongan R3 hanya ada paket Va 6600, 1699 per 1 kwh\n");
        pelanggan[jumlahPelanggan].va = 6600;
        break;

    default:
        printf("Golongan tidak valid.\n");
        return;
    }

    do
    {

        printf("Masukkan Pemakaian (kWh): ");
        scanf("%f", &pelanggan[jumlahPelanggan].pemakaianKwh);
        if (pelanggan[jumlahPelanggan].pemakaianKwh < 0)
        {
            printf("Kwh tidak boleh negatif, Masukkan Kembali\n");
        }

    } while (pelanggan[jumlahPelanggan].pemakaianKwh < 0);

    jumlahPelanggan++;
    printf("\n");
    printf("Pelanggan berhasil ditambahkan.\n\n");
}


//Shavira
void HitungTagihan()
{
    for (int i = 0; i < jumlahPelanggan; i++)
    {
        float harga = 0;

        if (pelanggan[i].va == 0)
        {
            printf("Va tidak boleh 0 \n");
            return;
        }

        switch (pelanggan[i].golongan)
        {
        case 1:
            if (pelanggan[i].va == 450)
                harga = pelanggan[i].pemakaianKwh * 415;
            else if (pelanggan[i].va == 900)
                harga = pelanggan[i].pemakaianKwh * 605;
            break;
        case 2:
            if (pelanggan[i].va == 3500 || pelanggan[i].va == 5500)
                harga = pelanggan[i].pemakaianKwh * 1699;
            break;
        case 3:
            if (pelanggan[i].va >= 6600)
                harga = pelanggan[i].pemakaianKwh * 1699;
            break;
        }

        pelanggan[i].Harga = harga;
        
    }
                printf("Berhasil Menghitung Total\n");

}


//Rendi
void tampilkanPelanggan()
{
    if (jumlahPelanggan == 0)
    {
        printf("Belum ada data pelanggan\n");

        return;
    }

    for (int i = 0; i < jumlahPelanggan; i++)
    {
        printf("\n=== Data Pelanggan ke-%d ===\n", i + 1);
        printf("ID Pelanggan: %d\n", pelanggan[i].id);
        printf("Nama Pelanggan: %s\n", pelanggan[i].nama);
        printf("Golongan: %d\n", pelanggan[i].golongan);
        printf("Daya (VA): %.0f\n", pelanggan[i].va);
        printf("Pemakaian (kWh): %.2f\n", pelanggan[i].pemakaianKwh);
        if (pelanggan[i].Harga == 0)
        {
            printf("Total Tagihan  Belum di Hitung\n");
        }
        else
        {

            printf("Total Tagihan: Rp %.2f\n", pelanggan[i].Harga);
        }
    }
}


// Rafi amanda
void cariPelangganByID()
{
    if (jumlahPelanggan == 0)
    {
        printf("Belum ada data pelanggan!\n");
        return;
    }

    int idCari;
    int ditemukan = 0;
    printf("Masukkan ID Pelanggan yang dicari: ");
    scanf("%d", &idCari);

    for (int i = 0; i < jumlahPelanggan; i++)
    {
        if (pelanggan[i].id == idCari)
        {
            ditemukan = 1;
            printf("\n PELANGGAN DITEMUKAN \n");
            printf("ID Pelanggan: %d\n", pelanggan[i].id);
            printf("Nama Pelanggan: %s\n", pelanggan[i].nama);
            printf("Golongan : %d\n", pelanggan[i].golongan);
            printf("Daya (VA): %.0f\n", pelanggan[i].va);
            printf("Pemakaian (kWh): %.2f\n", pelanggan[i].pemakaianKwh);
            printf("Total Tagihan: Rp %.2f\n", pelanggan[i].Harga);
            break;
        }
    }

    if (!ditemukan)
    {
        printf("Pelanggan dengan ID %d tidak ditemukan\n", idCari);
    }
}


// Raafi Adlu
void simpanFile()
{
    char fileName[] = "tagihan_pelanggan.txt";
    FILE *fp = fopen(fileName, "w");
    for (int i = 0; i < jumlahPelanggan; i++)
    {
        fprintf(fp, "ID Pelanggan: %d\n", pelanggan[i].id);
        fprintf(fp, "Nama Pelanggan: %s\n", pelanggan[i].nama);
        fprintf(fp, "Golongan: %d\n", pelanggan[i].golongan);
        fprintf(fp, "Daya (VA): %.0f\n", pelanggan[i].va);
        fprintf(fp, "Pemakaian (kWh): %.2f\n", pelanggan[i].pemakaianKwh);
        fprintf(fp, "Total Tagihan: Rp %.2f\n\n", pelanggan[i].Harga);
    }

    printf("Data sudah tersimpan di file %s", fileName);
    fclose(fp);
}


// Farrel
void sortingDenganInsertion()
{
    for (int i = 0; i < jumlahPelanggan; i++)
    {

        struct Pelanggan key = pelanggan[i];
        int j = i - 1;
        while (j >= 0 && pelanggan[j].Harga < key.Harga)
        {

            pelanggan[j + 1] = pelanggan[j];
            j--;
        }
        pelanggan[j + 1] = key;
    }
    for (int i = 0; i < jumlahPelanggan; i++)
    {
        printf("ID Pelanggan: %d\n", pelanggan[i].id);
        printf("Nama Pelanggan: %s\n", pelanggan[i].nama);
        printf("Golongan: %d\n", pelanggan[i].golongan);
        printf("Daya (VA): %.0f\n", pelanggan[i].va);
        printf("Pemakaian (kWh): %.2f\n", pelanggan[i].pemakaianKwh);
        if (pelanggan[i].Harga == 0)
        {

            printf("Total Tagihan Belum di Bayar\n\n");
        }
        else
        {
            printf("Total Tagihan: Rp %.2f\n\n", pelanggan[i].Harga);
        }
    }
}


//Faisal
void statistik()
{
    if (jumlahPelanggan == 0)
    {
        printf("Belum ada data!\n");
        return;
    }

    float totalPemakaian = 0;
    float totalTagihan = 0;

    for (int i = 0; i < jumlahPelanggan; i++)
    {
        totalPemakaian += pelanggan[i].pemakaianKwh;
        totalTagihan += pelanggan[i].Harga;
    }

    printf("\n STATISTIK \n");
    printf("Jumlah Data  \t: %d\n", jumlahPelanggan);
    printf("Total kWh    \t: %.2f\n", totalPemakaian);
    printf("Total Rp     \t: %.2f\n", totalTagihan);
    printf("Rata Rata kWh\t: %.2f\n", totalPemakaian / jumlahPelanggan);
    printf("Rata Rata Rp \t: %.2f\n", totalTagihan / jumlahPelanggan);
}

void tampilkanMenu()
{
    printf("\n\n");
    printf("\n=== MENU UTAMA ===\n");
    printf("1. Input Data Pelanggan\n");
    printf("2. Hitung total tagihan berdasarkan golongan tarif (if/switch)\n");
    printf("3. Cari pelanggan berdasarkan ID\n");
    printf("4. Sorting pelanggan berdasarkan tagihan tertinggi\n");
    printf("5. Simpan data tagihan ke file\n");
    printf("6. Statistik total pemakaian listrik pelanggan\n");
    printf("7. Tampilkan pelanggan\n");
    printf("8. Keluar\n");
    printf("Masukkan Pilihan Menu: ");
}

int main()
{
    int angka;

    do
    {

        tampilkanMenu();

        scanf("%d", &angka);
        switch (angka)
        {
        case 1:

            InputPelanggan();

            break;
        case 2:
            HitungTagihan();

            break;
        case 3:
            cariPelangganByID();

            break;
        case 4:
            sortingDenganInsertion();

            break;
        case 5:
            simpanFile();

            break;
        case 6:
            statistik();

            break;
        case 7:
            tampilkanPelanggan();

            break;
        case 8:

            printf("Anda Telah Keluar");

            break;

        default:
            printf("Pilihan tidak valid.\n");
            break;
        }

    } while (angka != 8);

    return 0;
}
