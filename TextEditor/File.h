#pragma once
#include<string>
#include<iostream>

class File {

public:
	std::string fileName;
	std::string filePath;

	File(std::string fileName, std::string filePath);

	File();

	void dateiEditieren();

	void dateiLoeschen();

	void dateiSchreiben();

	void dateiLesen();

	void setNameAndPath(std::string name, std::string path);

	void inhaltAendern();

	void inhaltAppend();

	void inhaltLoeschen();

	void inhaltEditieren();
};
