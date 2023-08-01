#include "LevelMaker.h"
#include "ExternDecl.h"

void LevelMaker::make_level(const char* tilemap[]) {
	for (int count = 0; count < 10; count++) {
		for (int index = 0; index < 28; index++) {
			if (tilemap[count][index] == 'X') {
				int x, y;
				x = index * 50;
				y = count * 50;
				group_of_tiles.push_back(new Tile(x, y));
			}
		}
	}
}