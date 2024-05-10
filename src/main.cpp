#include "Automata.h"

int main() {
Automata vendingMachine;
vendingMachine.on();
vendingMachine.coin(20);
vendingMachine.getMenu();
vendingMachine.choice(2);
vendingMachine.finish();
vendingMachine.off();
return 0;
}
