// Copyright 2024 osenvesen
// Automata.h
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>

enum STATES {OFF, WAIT, ACCEPT, COOK};

class Automata {
private:

int cash;
std::string menu[3];
int prices[3];
STATES state;

public:

Automata();
void on();
void off();
void coin(int sum);
void getMenu();
STATES getState();
void choice(int drink);
bool check(int cost);
void cancel();
void cook();
void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
