//
//  main.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//
#include "Game.hpp"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    Game* g = new Game();
    try {
        g->setup();
        g->start();
    }catch(exception &e){
        cout << "Exception" << e.what() << endl;
    }
    delete g;
    return 0;
}
