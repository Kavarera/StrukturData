/*
* This program was built on vs2019 and tested on c++11 and above.
* if you face any error please contact the programmer
* Rafli Iskandar Kavarera - 123210131
* 123210131@student.upnyk.ac.id
* Github : https://github.com/Kavarera/StrukturData/blob/Stable/LinkedListTugas.cpp
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
	Mahasiswa* mahasiswaBaru = new Mahasiswa();
	system("cls");

	cout << "Nama mahasiswa : ";
	getline(cin, mahasiswaBaru->Nama);
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
	Node* awal = *headRef;
	Node* nodeBaru = new Node();
	nodeBaru->value = mBaru;
	if (*headRef == NULL) {
		//cout << "headref" << endl; system("pause");
		*headRef = nodeBaru;
		free(awal);
		return;
	}
	else if (awal->next == NULL) {
		if (std::stoi(awal->value->Nim) > std::stoi(nodeBaru->value->Nim)) {
			//cout << "awalnim > nodebarunim" << endl; system("pause");
			nodeBaru->next = awal;
			awal->next = NULL;
			*headRef = nodeBaru;
			return;
		}
		awal->next = nodeBaru;
		//cout << "awalnext=nodebaru" << endl; system("pause");
		return;
	}
	else if (std::stoi(awal->value->Nim) > std::stoi(nodeBaru->value->Nim)) {
		nodeBaru->next = awal;
		*headRef = nodeBaru;
		//cout << "awalnim > nodebarunim next not null" << endl; system("pause");
		return;
	}
	else {
		//cout << "else" << endl; system("pause");
		Node* bantu = awal;
		while (true) {
			//cout << "cBantu=" << bantu->value->Nim << endl;
			if (bantu->next == NULL || bantu->next == nullptr) {
				bantu->next = nodeBaru;
				//cout << "bantunextnull, bantunext nodebaru" << endl; system("pause");
				break;
			}
			else if (std::stoi(bantu->next->value->Nim) >= std::stoi(nodeBaru->value->Nim)) {
				nodeBaru->next = bantu->next;
				bantu->next = nodeBaru;
				//cout << "bantunextnim >= nodebarunim, nodebarunext = bantunext, bantunext=nodebaru" << endl; system("pause");
				break;
			}
			else {
				//cout << bantu->next << endl; system("pause");
				//bantu == NULL ? cout << "bantu= true" : cout << "bantu=false";
				//bantu->next == NULL ? cout << "bantuN=true" : cout << "bantuN=false";
				//cout << endl; system("pause");
				//cout << "cBantu=" << bantu->value->Nim << endl;
				//cout << "cBantuN=" << bantu->next->value->Nim << endl;
				bantu = bantu->next;
				//cout << "cBantu=" << bantu->value->Nim << endl;
				//cout << "cBantuN=" << bantu->next->value->Nim << endl;
				//cout << "bantu=bantunext" << endl << bantu->next << endl; system("pause");
				continue;
			}
		}
	}

}

void cetakData(Node* startPoint) {
	while (startPoint != NULL) {
		cout << "=========================\n";
		cout << "Nama\t: " << startPoint->value->Nama << endl;
		cout << "NIM\t: " << startPoint->value->Nim << endl;
		cout << "Kelas\t: " << startPoint->value->Kelas << endl;
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
			bool deleted = false;
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
			deleted ? cout << "Data dihapus!\n" :
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
		cout << "MENU\n1. Tambah Data\n2. Hapus Data\n3. Lihat Semua Data\n\nesc untuk keluar" << endl;
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
