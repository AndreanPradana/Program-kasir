#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    string barang;
    int harga;
    int jumlah;
    int total;
    node *next;
};
node *stok_barang;

int isEmpty()
{
    if(stok_barang == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insert(string barang, int jumlah, int harga)
{
    node *baru;
    baru = new node;
    baru->barang=barang;
    baru->jumlah=jumlah;
    baru->harga=harga;
    baru->next=NULL;
    if(isEmpty()==1){
        stok_barang=baru;
        stok_barang->next=NULL;
    }
    else{
        baru->barang = barang;
        baru->jumlah = jumlah;
        baru->harga = harga;
        baru->next = stok_barang->next;
        stok_barang->next =baru;
        }
}

void update(string nama, int jml)
{
    node *bantu;
    bantu=stok_barang;
    int berhasil=0;

    if(isEmpty()==1){
        cout<<"Data Kosong"<<endl;
    }
    else{
        while(bantu != NULL){
            if(bantu->barang==nama){
                bantu->jumlah=bantu->jumlah+jml;
                berhasil=1;
            }
            bantu=bantu->next;
        }
        if(berhasil=1){
            cout<<"Stok Berhasil Ditambah"<<endl;
        }
        else{
            cout<<"Stok Gagal Ditambah"<<endl;
        }
    }
}

void hapus(string barang)
{
    node *bantu, *prev;
    int berhasil=0;
    bantu=stok_barang;

    if(isEmpty()==1){
        cout<<"Barang Kosong"<<endl;
    }
    else{
        while(bantu != NULL && bantu->barang != barang){
            prev = bantu;
            bantu = bantu->next;
            berhasil=1;
        }
        if (bantu != NULL && bantu->barang == barang){
            //hapus tengah
            if(bantu->next != NULL && bantu != stok_barang)
                prev->next = bantu->next;
                //jika hapus di depan dan tinggal 1 simpul
            else if (bantu == stok_barang && stok_barang->next == NULL){
                stok_barang = NULL;}
                //jika hapus di depan tapi masih ada simpul berikutnya
            else if (bantu == stok_barang && stok_barang->next != NULL){
                stok_barang = stok_barang->next;}
                //jika hapus di belakang
            else if (bantu->next == NULL){
                prev->next = NULL;
                }
        }
        if (berhasil==1){
            cout<<"Berhasil dihapus"<<endl;
            }
        else{
            cout<<"Gagal dihapus"<<endl;
            }
    }
}

void view()
{
    node *bantu;
    bantu = new node;
    bantu = stok_barang;

    while(bantu != NULL){
        cout<<"Nama Barang  = "<<bantu->barang<<endl;
        cout<<"Jumlah       = "<<bantu->jumlah<<endl;
        cout<<"Harga Barang = "<<bantu->harga<<" /pcs"<<endl;
        bantu=bantu->next;
    }
}

void login();
void admin()
{
    int pil,jm, hr;
    string nb;
    do{
    system("CLS");
    cout<<"-------Menu Admin-------"<<endl;
    cout<<"1. Insert\n2. Update\n3. Delete\n4. View\n5. LogOut\n6. Exit\nPilih : ";
    cin>>pil;

    switch(pil)
    {
        case 1:{
            cout<<"----Insert----"<<endl;
            cout<<"Nama Barang = ";cin>>nb;
            cout<<"Jumlah      = ";cin>>jm;
            cout<<"Harga       = ";cin>>hr;
            insert(nb,jm,hr);
            cout<<"\nTersimpan"<<endl;
        }
        break;
       case 2:{
            string nb;
            int ts;
            cout<<"----Update----"<<endl;
            cout<<"Masukkan Nama Barang = ";cin>>nb;
            cout<<"Tambah Stok          = ";cin>>ts;
            update(nb,ts);
        }
        break;
        case 3:{
            string hps;
            char yn;
            bagian_hapus:
            cout<<"----Delete----"<<endl;
            cout<<"Masukkan Nama Barang = ";cin>>hps;
            node *bantu;
            bantu=stok_barang;
            int ada=0;
            while(bantu != NULL){
                if(bantu->barang==hps){
                    ada=1;
                }
                bantu=bantu->next;
            }
            if(ada==0){
                cout<<"Nama Barang tidak ada !"<<endl<<"Masukkan Ulang !"<<endl;
                cout<<endl;
                goto bagian_hapus;
            }
            cout<<"Hapus Barang ? [y/n]";cin>>yn;
            if(yn == 'y'){
                hapus(hps);
            }
        }
        break;
        case 4:
            cout<<"----View----"<<endl;
            view();
            break;
        case 5:
            char pil;
            cout<<endl<<"Anda Ingin LogOut ? [y/n]";cin>>pil;
            if(pil == 'y'){
                login();
            }
    }
    system("PAUSE");
    }while(pil != 6);
}

void beli()
{
    node *bantu;
    bantu = new node;
    bantu = stok_barang->next;

    while(bantu->next != NULL){
        bantu->barang=bantu->barang;
        bantu->jumlah=bantu->jumlah;
        bantu->harga=bantu->harga;
        bantu=bantu->next;
    }
}

void kasir()
{
    string nb;
    int jb, i=0, bayar, total, total_semua=0;
    char ulang;

    do{
    node *cari;
    cari = stok_barang;
    cout<<"----Pembelian----"<<endl;
    cout<<"Masukkan nama barang = ";cin>>nb;

    while(nb!=cari->barang){
        cari = cari->next;
    }
        cout<<"Jumlah Barang        = ";cin>>jb;
        if(jb <= cari->jumlah){
        cout<<"Harga Barang         = "<<cari->harga<<endl;
        total=cari->harga*jb;
        cout<<"Total Yang Dibayar   = "<<total<<endl;
        total_semua=total_semua+total;
        cout<<endl;
        cari->jumlah = cari->jumlah - jb;
        }
        else{
            cout<<"Stok Tidak Mencukupi!"<<endl;
        }

    cout<<"Tambah Lagi ? ";cin>>ulang;
    }while(ulang=='y');
     while(true){
        cout<<"Total Semua Barang = "<<total_semua<<endl;
        cout<<"Masukkan Uang = ";cin>>bayar;
        if(bayar >= total_semua){
            cout<<"Kembalian = "<<bayar-total_semua<<endl;
            break;
        }
        else{
            cout<<"Uang Anda kurang !"<<endl;
        }
    }
    system("PAUSE");
    login();
}

void login()
{
    string id_admin="admin";
    string pass_admin="1234";
    string id_kasir="kasir";
    string pass_kasir="1234";

    system("CLS");
    cout<<"LOGIN"<<endl;
    string i, p;
    cout<<"ID       = ";cin>>i;
    cout<<"Password = ";cin>>p;
    cout<<endl;

    if(i==id_kasir && p==pass_kasir){
        cout<<"Berhasil Login"<<endl;
        kasir();
    }
    else if(i==id_admin && p==pass_admin){
        cout<<"Berhasil Login"<<endl;
        admin();
    }
    else{
        cout<<"Id atau Password Salah"<<endl;
        system("PAUSE");
        login();
    }
}

int main()
{
    stok_barang=NULL;
    login();
    return 0;
}
