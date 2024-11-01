/*
 * TicketMachine.cpp
 *
 *  Created on: 2024年11月2日
 *      Author: tracy
 */

#include "TicketMachine.h"
#include <iostream>
using namespace std;

//TicketMachine::TicketMachine : PRICE (0){
//	// TODO Auto-generated constructor stub
//
//}

TicketMachine::~TicketMachine() {
	// TODO Auto-generated destructor stub
}

void TicketMachine::showPrompt(){
    cout << "something";
}
void TicketMachine::insertMoney(int money){
    balance += money;
}

void TicketMachine::showBalance(){
    cout << balance;
}
