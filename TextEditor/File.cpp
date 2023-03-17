#include<string>
#include<iostream>
#include "File.h"
#include <fstream>
#include <cstdio>
#include "Menu.h"

	File::File(std::string name, std::string path){
		Menu menu;
		fileName = name;
		filePath = path;
		std::ofstream MyFile(path+name);
		MyFile << "HI THIS IS THE NEW TEXT FROM FILE ";
		std::cout << name << " datei ist erstellt\n";
		MyFile.close();	
		menu.startMenu();
	}

	File::File() {}

	void File::setNameAndPath(std::string name, std::string path) {
		 fileName = name;
		 filePath = path;
	}
			
	void File::dateiLoeschen() {

		try {
			int status;
			std::string pathname = filePath + fileName;
			char deletedFile[256];
			strcpy_s(deletedFile, pathname.c_str()); // Copy the string contents to the char array
			status = remove(deletedFile);

			if (status == 0)
				std::cout << "\nDatei geloescht!";
			else
				std::cout << "\nFehler!";
			std::cout << std::endl;
		}
		catch (const std::exception& ex) {
			std::cerr << ex.what() << std::endl;

		}
	}

	void File::dateiSchreiben() {
	
		std::string text;
		
		std::cout << "\nSchreiben Sie etwas...\n";
		std::cin >> text;
		std::fstream myFile(filePath + fileName, std::ios::in | std::ios::out | std::ios::app);
		myFile << text;

		myFile.close();


	}

	void File::dateiLesen() {
		std::string line;
		std::ifstream myFile;
		myFile.open(filePath + fileName, std::ios::in);
		if (myFile.is_open()) {
			while (getline(myFile, line)) {
				std::cout << line;
			}
			myFile.close();

		}
	}

	void File::dateiEditieren() {



	}

	void File::inhaltAendern(){}

	void File::inhaltAppend(){
	
		std::string text;

		std::fstream myFile(filePath + fileName, std::ios::in | std::ios::out | std::ios::app);
		std::cout << "\nNeu Text schreiben...\n";
		std::cin >> text;
		myFile << text;

		myFile.close();
	}

	void File::inhaltLoeschen(){
		
		std::fstream myFile(filePath + fileName, std::ios::in | std::ios::out | std::ios::trunc);

		myFile << "";

		myFile.close();
	}

	void File::inhaltEditieren(){}

