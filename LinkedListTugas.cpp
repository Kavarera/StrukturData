/*
* This program was built on vs2019 and tested on c++11 and above.
* if you face any error please contact the programmer
* Rafli Iskandar Kavarera - 123210131
* 123210131@student.upnyk.ac.id
*/

#include <iostream>
#include <string>
#include <conio.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Mahasiswa {
public:
	string Nama, Nim;
	char Kelas;
	float Nilai;
};
class Node {
public:
	Mahasiswa* value;
	Node* next;
};

Mahasiswa* createMahasiswa() {
	Mahasiswa *mahasiswaBaru = new Mahasiswa();
	system("cls");

	cout << "Nama mahasiswa : ";
	getline(cin,mahasiswaBaru->Nama);
	cout << "Nim Mahasiswa : ";
	getline(cin, mahasiswaBaru->Nim);
	cin.clear();
	cout << "Kelas\t\t: "; cin >> mahasiswaBaru->Kelas;
	mahasiswaBaru->Kelas = mahasiswaBaru->Kelas >= 97 ? (int)mahasiswaBaru->Kelas - 32 : mahasiswaBaru->Kelas;
	//mahasiswaBaru->Kelas = (char)mahasiswaBaru->Kelas;
	cout << "Nilai\t\t: "; cin >> mahasiswaBaru->Nilai;
	cin.ignore();
	return mahasiswaBaru;
}

void append(Node** headRef, Mahasiswa* mBaru) {
	Node* nodeBaru = new Node();
	Node* akhir = *headRef;
	nodeBaru->value = mBaru;
	nodeBaru->next = NULL;
	if (*headRef == NULL) {
		*headRef = nodeBaru;
		return;
	}
	while (akhir->next != NULL) {
		akhir = akhir->next;
	}
	akhir->next = nodeBaru;
}

void cetakData(Node* startPoint) {
	while (startPoint != NULL) {
		cout << "=========================\n";
		cout << "Nama\t: " << startPoint->value->Nama<<endl;
		cout << "NIM\t: " << startPoint->value->Nim<<endl;
		cout << "Kelas\t: " << startPoint->value->Kelas<<endl;
		cout << "Nilai\t: " << startPoint->value->Nilai << endl;
		startPoint = startPoint->next;
	}
	cout << endl; system("pause");
}
void Delete(Node** headRef) {
	Node* current = *headRef;
	if (current != NULL) {
		Node* after = current->next;
		std::string deletedNim;
		cout << "Masukan Nim yg ingin dihapus : ";
		std::getline(std::cin, deletedNim);
		if (current->value->Nim == deletedNim) {
			if (current->next != NULL) {
				*headRef = after;
				free(current);
				cout << "Data dihapus!\n";
				system("pause");
			}
			else {
				free(current);
				*headRef = NULL;
				cout << "Data dihapus!\n";
				system("pause");
			}
		}
		else {
			bool deleted=false;
			while (current->next != NULL) {
				after = current->next;
				if (after->value->Nim == deletedNim) {
					current->next = after->next;
					free(after);
					deleted = true;
					break;
				}
				else {
					current = after;
					deleted = false;
				}
			}
			deleted ? cout << "Data dihapus!\n":
				cout << "Nim tidak ditemukan\n Hapus data gagal!\n";
			system("pause");
		}
	}
	else {
		cout << "Data kosong, input data terlebih dahulu!\n";
		system("pause");
	}
}

int main() {
	Node* head = NULL;
	while (true)
	{
		system("cls");
		cout << "MENU\n1. Tambah Data\n2. Hapus Data\n3. Lihat Semua Data" << endl;
		int answer = _getch();
		switch (answer)
		{
		case 49:
			append(&head, createMahasiswa());
			system("pause");
			break;
		case 50:
			Delete(&head);
			break;
		case 51:
			cetakData(head);
			break;
		case 27:
			return 0;
			break;
		default:
			break;
		}
	}
}
