#pragma once
#include<string>
#include<iostream>
#include "File.h"

class Menu {
public:
	void startMenu();

	void contentMenu(File file);

	void editMenu(File file);

	void erstellen();

	void oeffnen();
};