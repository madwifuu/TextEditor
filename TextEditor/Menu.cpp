#include<string>
#include<iostream>
#include "Menu.h"
#include "File.h"

void Menu::startMenu() {

		int option;
		std::cout << "\n*****************" << std::endl;
		std::cout << "1. Erstellen" << std::endl;
		std::cout << "2. Oeffnen" << std::endl;
		std::cout << "3. Quit" << std::endl;
		std::cout << "*****************\n" << std::endl;

		std::cin >> option;

		if (option == 1) {
			erstellen();
		}
		else if (option == 2) {
			oeffnen();
		}
		else if (option == 3) {
			system("exit");
		}
		else {
			std::cout << "\nUngueltige eingabe\n";
		}

}

void Menu::contentMenu(File file){
	int option;

	do {

		std::cout << "\n*******************" << std::endl;
		std::cout << "** DATEIN OPTIONEN **" << std::endl;
		std::cout << "1. Lesen" << std::endl;
		std::cout << "2. Schreiben" << std::endl;
		std::cout << "3. Loeschen" << std::endl;
		std::cout << "4. Inhalte Optionen" << std::endl;
		std::cout << "5. Zurueck" << std::endl;
		std::cout << "6. Quit" << std::endl;
		std::cout << "********************\n" << std::endl;


		std::cin >> option;

		if (option == 1) {
			file.dateiLesen();
		}
		else if (option == 2) {
			file.dateiSchreiben();
		}
		else if (option == 3) {
			file.dateiLoeschen();
		}
		else if (option == 4) {
			editMenu(file);
		}
		else if (option == 5) {
			startMenu();
		}
		else if (option == 6) {
			system("exit");
		}
		else {
			std::cout << "Ungueltig eingabe";
		}
	} while (option != 6);
}

void Menu::editMenu(File file) {

	int option;

	do {
		std::cout << "\n***********************************" << std::endl;
		std::cout << "****** DATEI INHALT OPTIONEN ******" << std::endl;
		std::cout << "1. Aendern" << std::endl;
		std::cout << "2. Loeschen" << std::endl;
		std::cout << "3. Append" << std::endl;
		std::cout << "4. Etwas an beliebiger Stelle hinzufuegen" << std::endl;
		std::cout << "5. Zurueck" << std::endl;
		std::cout << "6. Quit" << std::endl;
		std::cout << "***********************************\n" << std::endl;

		std::cin >> option;
		switch (option) {

		case 1:break;
		case 2:
			file.inhaltLoeschen(); break;
		case 3:
			file.inhaltAppend(); break;
		case 4: break;
		case 5: contentMenu(file); break;
		case 6: system("exit"); break;

		default: std::cout << "Ungueltige eingabe...";
		}
	
	} while (option != 6);
}

void Menu::erstellen() {

	std::string name, path;
	std::cout << "\nNeu Datei Name eingeben: \n";
	std::cin >> name;
	std::cout << "\nNeu Datei Pfad eingeben: \n";
	std::cin >> path;

	File file(name, path);


}

void Menu::oeffnen() {
	File file;
	std::string name, path;
	std::cout << "Datei Name eingeben: ";
	std::cin >> name;
	std::cout << "Datei Pfad eingeben: ";
	std::cin >> path;
	file.setNameAndPath(name, path);
	contentMenu(file);

}
