// Copyright 2024 osenvesen
#include <iostream>
#include "Automata.h"
Automata::Automata() {
cash = 0;
menu = { "Tea", "Coffee", "Milk" }; 
prices[0] = 10;
prices[1] = 15;
prices[2] = 20;
state = OFF;
}

void Automata::on() {
if (state == OFF) {
state = WAIT;
std::cout << "Automata is turned on.\n";
}
}

void Automata::off() {
if (state == WAIT || state == OFF) {
state = OFF;
std::cout << "Automata is turned off.\n";
}
}

void Automata::coin(int sum) {
if (state == ACCEPT || state == WAIT) {
cash += sum;
state = ACCEPT;
std::cout << "Cash: " << cash << " rubles.\n";
}
}

std::vector<std::string> Automata::getMenu() {
return menu;
}

STATES Automata::getState() {
return state;
}

void Automata::choice(int drink) {
if (state == ACCEPT) {
if (drink >= 1 && drink <= 3) {
int cost = prices[drink-1];
if (check(cost)) {
state = COOK;
cook();
} else {
std::cout << "Not enough cash.\n";
}
}
}
}

bool Automata::check(int cost) {
if (cash >= cost) {
cash -= cost;
return true;
}
return false;
}

void Automata::cancel() {
if (state == ACCEPT) {
cash = 0;
state = WAIT;
std::cout << "Canceled.\n";
}
}

void Automata::cook() {
if (state == COOK) {
std::cout << "Cooking...\n";
std::cout << "Done! Enjoy your drink!\n";
state = WAIT;
}
}

void Automata::finish() {
if (state == WAIT) {
cash = 0;
std::cout << "Finished.\n";
}
}
