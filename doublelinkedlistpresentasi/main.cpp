#include <iostream>
#include <conio.h>
#include <thread> 
#include <chrono>

//custom lib
#include "include/DoubleLinkedList.h"

static std::string menus[]={
    "Delete Depan",
    "Delete Tengah",
    "Delete Belakang",
    "Exit"
};

void displayMenu(int selectedOption) {
    system("cls");
    std::cout << "Menu:\n";
    for (int i = 0; i < sizeof(menus) / sizeof(menus[0]); i++) {
        if (i + 1 == selectedOption) {
            std::cout << "\033[42m" << menus[i] << "\033[0m" << std::endl;
        } else {
            std::cout << menus[i] << std::endl;
        }
    }
}

void doDeleteDepan(){
    system("cls");
    DoubleLinkedList list; //init
    std::cout<<"INISIALISASI NODES \n:"<<std::endl;
    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.insertFront(40);
    list.insertFront(50);
    list.displayNodes();

    std::cout<<std::endl<<std::endl;
    const char loadingChars[] = { '/', '-', '\\', '-', '|' };
    int loadingIndex = 0;

    std::cout<<"Tekan Enter Untuk Melanjutkan \t\t"<< "\e[?25l";
    while (!_kbhit()) {
        std::cout << loadingChars[loadingIndex]<<"\b";
        loadingIndex = (loadingIndex + 1) % (sizeof(loadingChars) / sizeof(loadingChars[0]));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout <<"\r"<<std::endl<<"\e[?25h";

    std::cout<<"\n\nHAPUS DEPAN NODES\n:"<<std::endl;
    list.removeFront();
    list.displayNodes();
}

void doDeleteBelakang(){
    system("cls");
    DoubleLinkedList list; //init
    std::cout<<"INISIALISASI NODES \n:"<<std::endl;
    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.insertFront(40);
    list.insertFront(50);
    list.displayNodes();

    std::cout<<std::endl<<std::endl;
    const char loadingChars[] = { '/', '-', '\\', '-', '|' };
    int loadingIndex = 0;

    std::cout<<"Tekan Enter Untuk Melanjutkan \t\t"<< "\e[?25l";
    while (!_kbhit()) {
        std::cout << loadingChars[loadingIndex]<<"\b";
        loadingIndex = (loadingIndex + 1) % (sizeof(loadingChars) / sizeof(loadingChars[0]));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout <<"\r"<<std::endl<<"\e[?25h";

    std::cout<<"\n\nHAPUS BELAKANG NODES\n:"<<std::endl;
    list.removeBack(); 
    list.displayNodes();
}

void doDeleteMiddle(){
    system("cls");
    DoubleLinkedList list; //init
    std::cout<<"INISIALISASI NODES \n:"<<std::endl;
    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.insertFront(40);
    list.insertFront(50);
    list.displayNodes();

    std::cout<<std::endl<<std::endl;
    const char loadingChars[] = { '/', '-', '\\', '-', '|' };
    int loadingIndex = 0;

    std::cout<<"Tekan Enter Untuk Melanjutkan \t\t"<< "\e[?25l";
    while (!_kbhit()) {
        std::cout << loadingChars[loadingIndex]<<"\b";
        loadingIndex = (loadingIndex + 1) % (sizeof(loadingChars) / sizeof(loadingChars[0]));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cin.ignore(1,'\n');
    std::cout <<"\r"<<std::endl<<"\e[?25h";

    std::cout<<"\n\nSIMULASI PENGAHUPUSAN TENGAH NODES\n:"<<std::endl;
    list.specialDisplayNodes(30);
    std::cout<<"Tekan Enter Untuk Melanjutkan \t\t"<< "\e[?25l";
    while (!_kbhit()) {
        std::cout << loadingChars[loadingIndex]<<"\b";
        loadingIndex = (loadingIndex + 1) % (sizeof(loadingChars) / sizeof(loadingChars[0]));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }std::cout <<"\r"<<std::endl<<"\e[?25h";
    std::cin.ignore(1,'\n');
    
    list.removeMiddle(30); 
    std::cout<<"\n\n HASIL PENGAHUPUSAN TENGAH NODES\n:"<<std::endl;
    list.displayNodes();
}

int main() {
    int selectedOption = 1;
    char key;

    while(selectedOption!=4){
            do {
            displayMenu(selectedOption);

            key = _getch();
            switch (key) {
                case 72: //key atas
                    if (selectedOption > 1) {
                        selectedOption--;
                    }
                    break;
                case 80: //key bawah
                    if (selectedOption < 4) {
                        selectedOption++;
                    }
                    break;
                default:
                    break;
            }
        } while (key != 13);//enter
        switch (selectedOption) {
            case 1:
                doDeleteDepan();
                system("pause");
                break;
            case 2:
                doDeleteMiddle();
                system("pause");
                break;
            case 3:
                doDeleteBelakang();
                system("pause");
                break;
            case 4:
                return 0;
                break;
            default:
                break;
        }
        key=' ';
    }

    return 0;
}