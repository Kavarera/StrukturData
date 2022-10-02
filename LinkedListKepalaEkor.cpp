#include <iostream>
#include <conio.h>

using namespace std;

struct Peminjam{
	int urut;
	string nama;
	int lamaPinjam;
};

struct Node{
	Peminjam *info;
	Node* next;
};

Peminjam *createPeminjam(int urut){
	Peminjam *p = new Peminjam;
	cout<<"urut\t: "<<urut<<endl;
	p->urut=urut;
	cout<<"Nama\t: "; ; getline(cin,p->nama);
	cout<<"lamaPinjam\t: ";cin>>p->lamaPinjam;cin.ignore();
	return p;
}

void append(Node **k, Node **e,int urut){
	Node * kepala = *k;
	Node * ekor = *e;
	if(urut==0){
		Node *pbaru = new Node;
		pbaru->info	= createPeminjam(urut+1);
		kepala->next=pbaru;
		pbaru->next=ekor;
		return;
	}
	else{
		Node *bantu = kepala->next;
		Peminjam *p;
		while(bantu->next!=nullptr){
			if(bantu->next==ekor){
				Node *baru = new Node;
				baru->info = createPeminjam(urut+1);
				bantu->next=baru;
				baru->next=ekor;
				break;
			}
			bantu = bantu->next;
		}
	}
}
void cetakData(Node** startPoint) {
	Node *bantu = *startPoint;
	bantu = bantu->next;
	system("cls");
	while(bantu->info!=nullptr){
		cout<<"Urut\t: "<<bantu->info->urut<<endl;
		cout<<"Nama\t: "<<bantu->info->nama<<endl;
		cout<<"lama Pinjam : "<<bantu->info->lamaPinjam<<endl;
		bantu= bantu->next;
	}
	system("pause");
}

void Delete(Node** k, Node **e){
	cout<<"nilai dihapus : "; int uDel;cin>>uDel;cin.ignore();
	Node *kepala	= *k;
	Node *ekor = *e;
	Node *bantu = kepala->next;
	Node *prev=kepala->next;
    bool deleted=false;
	while(bantu->next!=nullptr){
		if(kepala->next->info->urut==uDel){//hapus awal
            kepala->next=bantu->next;
            free(bantu);
            deleted=true;
            break;


			// if(bantu->info->urut==uDel){
			// 	kepala->next=bantu->next;
			// 	free(bantu);
            //     deleted=true;
			// 	break;			
			// }
		}
		//hapus tengah dan strnty
		else{
			//hapus tengah
            if(bantu->info->urut==uDel){
                prev->next=bantu->next;
                free(bantu);
                deleted=true;
                break;
            }
            else if(bantu->next==ekor){
                prev->next=ekor;
                free(bantu);
                deleted=true;
                break;
            }
            else{
                prev=bantu;
                bantu = bantu->next;
            }
		}
	}
    deleted ==true ? cout<<"\nBerhasil hapus data\n" : cout<<"\nGagal hapus data\n";
    system("pause");
    
}


int main(){
	int urut=0;
    Node *kepala = new Node;
    Node *ekor = new Node;
    kepala->next=ekor;
    kepala->info= nullptr;
    ekor->info=nullptr;
    ekor->next=nullptr;

    while(true){
    cout<<"pilih menu\n1. Input\n2. Cetak\n3.Delete "<<endl; int i=getch();
    if(i==49){
        append(&kepala,&ekor,urut);
        urut++;
    }
    else if(i==50){
        cetakData(&kepala);
    }
    else if(i==51){
        Delete(&kepala,&ekor);

    }
    else break;

    }

    return 0;
}
