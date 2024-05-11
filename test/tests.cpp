// Copyright 2024 osenvesen

#include <gtest/gtest.h>
#include "Automata.h"
#include "Automata.h"
#include <cassert>

void testAutomata() {
Automata vendingMachine;

// Test on() and off() methods
vendingMachine.on();
assert(vendingMachine.getState() == WAIT);
vendingMachine.off();
assert(vendingMachine.getState() == OFF);

// Test coin() method
vendingMachine.on();
vendingMachine.coin(10);
assert(vendingMachine.getState() == ACCEPT);

// Test getMenu() method
vendingMachine.getMenu();
assert(vendingMachine.getState() == WAIT);

// Test choice() method
vendingMachine.on();
vendingMachine.coin(20);
vendingMachine.choice(3);
assert(vendingMachine.getState() == COOK);

// Test check() method
assert(vendingMachine.check(10) == true);
assert(vendingMachine.check(30) == false);

// Test cancel() method
vendingMachine.cancel();
assert(vendingMachine.getState() == WAIT);

// Test cook() method
vendingMachine.on();
vendingMachine.coin(20);
vendingMachine.choice(1);
vendingMachine.cook();
assert(vendingMachine.getState() == WAIT);

// Test finish() method
vendingMachine.finish();
assert(vendingMachine.getState() == WAIT);
}

void main() {
testAutomata();
}
