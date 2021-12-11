#pragma once
#include "error.h"
#include "myArray.h"
#include <iomanip>
// 3 vlt besser als globale oder struct schreiben 
template<class T, int N>
void parkplatz(myArray<T, N>* myArr)
{
	myArr->fill("frei");
	for (unsigned i{}; i < 3; ++i)
		myArr->at(i) = "noName";
}

void printMenu()
{
	std::cout << "   Menu\n" << "(1)Buchung\n" << "(2)Kundigung\n" << "(3)Belegen\n" << "(4)freigeben\n" << "(5)Print\n" << "(6)quite\n";
}

template<class T, int N>
void buchung(myArray<T, N>* myArr)
{
	int menge{};
	for (int i{}; i < 3; ++i)
		if (myArr->at(i) == "noName")
			menge++;
	if (menge == 0)
	{
		std::cout << "keine Pleatze fuer Buchung\n";
	}
	else if (menge == 1)
	{
		std::cout << "Folgende Platz ist frei: ";
		for (int i{}; i < 3; ++i)
			if (myArr->at(i) == "noName")
			{
				std::cout << i + 1 << "Fuer Buchung enter Sie den namen fuer Identifitierung: ";
				std::string name;
				std::cin >> name;
				if (!std::cin)
					error("kein input");
				myArr->at(i) = name;
			}
	}
	else
	{
		std::cout << "Folgende Plaetze sind frei: ";
		for (int i{}; i < 3; ++i)
			if (myArr->at(i) == "noName")
				std::cout << i + 1 << " ";
		int num{};
		std::cout << "Enter, welcher Platz soll gebucht sein: ";
		std::cin >> num;
		if (!std::cin)
			error("kein input");
		num--;
		if (myArr->at(num) != "noName")
			error("dies Platz war gebucht");

		std::cout << "Fuer Buchung enter Sie den namen fuer Identifitierung: ";
		std::string name;
		std::cin >> name;
		if (!std::cin)
			error("kein input");
		myArr->at(num) = name;
	}
	menu(myArr);
}

template<class T, int N>
void kundigung(myArray<T, N>* myArr)
{
	std::cout << "Schreiben Sie bitte den Identifitierungsnamen fuer Kundigung oder noName fuer exit: ";
	std::string name;
	std::cin >> name;
	if (!std::cin)
		error("kein input");
	if (name == "noName")
		menu(myArr);
	for (int i{}; i < 3; ++i)
		if (myArr->at(i) == name)
		{
			myArr->at(i) = "noName";
			break;
		}
	menu(myArr);
}

template<class T, int N>
void pBelegen(myArray<T, N>* myArr)
{
	bool frei{ false };
	for (unsigned i{ 3 }; i < N; ++i)
		if (myArr->at(i) == "frei")
			frei = true;
	if (frei == false)
		std::cout << "kein Platz fuer Belegen\n";
	else
	{
		myArr->printAll();
		std::cout << "Folgende Pleatze sinf zu verfugung: ";
		for (unsigned i{ 3 }; i < N; ++i)
			if (myArr->at(i) == "frei")
				std::cout << i + 1 << " ";
		int num{};
		std::cout << "Enter nummer fuer Belegung (0 fuer exit): ";
		std::cin >> num;
		if (!std::cin)
			error("kein input");
		if (num == 0)
			menu(myArr);
		num--;
		if (myArr->at(num) == "belegt")
			error("platz ist belegt");
		myArr->at(num) = "belegt";
	}
	menu(myArr);
}

template<class T, int N>
void pFrei(myArray<T, N>* myArr)
{
	myArr->printAll();
	bool belegt{ false };
	for (unsigned i{ 3 }; i < N; ++i)
		if (myArr->at(i) == "belegt")
			belegt = true;
	if (belegt == false)
	{
		std::cout << "es gibt keinen belegten Platz\n";
		menu(myArr);
	}
	std::cout << "Folgende Pleatze konnen frei sein: ";
	for (unsigned i{ 3 }; i < N; ++i)
		if (myArr->at(i) == "belegt")
			std::cout << i + 1 << " ";
	int num{};
	std::cout << "Enter nummer, um frei zu machen (0 fuer exit): ";
	std::cin >> num;
	if (!std::cin)
		error("kein input");
	if (num == 0)
		menu(myArr);
	num--;
	if (myArr->at(num) == "frei")
		error("platz ist schon frei");
	myArr->at(num) = "frei";
	menu(myArr);
}

template<class T, int N>
void menu(myArray<T, N>* myArr)
{
	int wahl{};
	printMenu();
	std::cin >> wahl;
	if (!std::cin)
		error("kein input");
	switch (wahl)
	{
	case 1:
		buchung(myArr);
		break;
	case 2:
		kundigung(myArr);
		break;
	case 3:
		pBelegen(myArr);
		break;
	case 4:
		pFrei(myArr);
		break;
	case 5:
		myArr->printAll();
		menu(myArr);
		break;
	case 6:
		std::cout << "chao";
		break;
	default:
		break;
	}
}

