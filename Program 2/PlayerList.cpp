#include "PlayerList.h"
#include <iostream>

PlayerList::PlayerList() {
	for (int i = 0; i < 8; i++) {
		players[i] = 0;
	}
}
