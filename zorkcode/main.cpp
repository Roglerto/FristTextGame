// RobertZork.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "World.h"

using namespace std;

int main()
{  
	Map m;
	World world(m);
	
	string val,aux;
	string staf = "use telephone number movile phone";
	string incorrectorder = "use movile phone telephone number";

	cout << endl;
	cout << "    O " << endl;
	
	cout << "   || " << endl;
	cout << "   __                 WELCOME TO YOUR SWEET HOME  " << endl;
	cout << endl;
	cout<< "I'm your teddy bear if you want to survive this night without your parents, you have to do whatever I say to you. First of all, write 'north','south','east','west' to walk in that directions,if you want to see for something write 'watch'if you want to take an object, write 'take', if you want to drop an item write 'drop nameitem', if you want to warch your inventory write 'inventory' if you want to use your items wirte 'use nameitem nameitem'. Your mision is simple get the note and the movil to call to your parents and go thee enter of the house. Please press any botton to continue" <<endl;
	//cin >> val;
	getline(cin, aux);
	aux = "";
	cout << endl;
	cout << endl;
	cout << endl;

	/*
	cout << world.position() << endl;
	cin >> val;
	cout << endl;*/

	while (1) {
		if (world.bossfight() == false) {
			world.go(val);	
		}
		cout << " -> " << world.position() << endl;
		getline(cin, val);
		cout << endl;
		if (world.bossfight()==true) {

			if ((val == "drop magazine")&& (world.playermagazine())) {
				cout << " ->  You throw the magazine to a corner and then you hide. The babysiter sees the magazine, so she takes it, and she sits to read it, your path is clear now. "<<endl;
				world.babysitermove();
				//world.goback();
			}
			else {
				val = "";
				cout << " ->  You come back " << endl;
				world.goback();
			
			}
		}

		if (world.endgame()==true) {
			//cout << " ITTEMMS " << val << " " << staf;
			if ((val==staf)&&(world.playerallitem()) ){
				cout << " ->  You put the movile phone to charge and now you can use it " << endl;
				cout <<" -> Finally you can call to your parents, you finished their romantic dinner, but who care, you are more important than them." <<endl;
				cin >> val;
				return 0;
			}
			else if(val==incorrectorder){
				cout << " -> Incorrect order ." <<endl;
			}
			else if (!world.playerallitem()) {
				cout << " -> You don't have all the items need it to call your parents " << endl;
			}
		}

		if (val=="watch") {
			cout << " -> " << world.watch() <<endl;
			getline(cin, val);
			cout << endl;

			if (val == "take") {
				  world.take();
				  cout << " -> " << " You take it" << endl;
				  cout << endl;
			}
		}

		if (val == "inventory") {
			cout << " -> " << world.playerInventory() <<endl;
			cout << endl;
		}

	}
	cout << endl;
    return 0;
}


