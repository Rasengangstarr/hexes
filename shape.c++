#include <iostream>
#include <stdlib.h>

using namespace std;

enum Side { top, top_left, top_right, bottom_left, bottom_right, bottom };


char* DrawHex(int center_x, int center_y, int worldSizeX, int worldSizeY, Side side, char* world)
{
	if (world[center_y * worldSizeX + center_x] == 'x')
		return world;
	
	switch(side)
	{
		case top:
			world[(center_y - 1) * worldSizeX + center_x-1] = '_';
			world[(center_y - 1) * worldSizeX + center_x]   = '_';
			world[(center_y) * worldSizeX + center_x-2] = '/';
			world[(center_y) * worldSizeX + center_x+1]   = '\\';
			world[(center_y + 1) * worldSizeX + center_x-2] = '\\';
			world[(center_y + 1) * worldSizeX + center_x+1]   = '/';
			break;
		case top_left:
			world[(center_y - 1) * worldSizeX + center_x-1] = '_';
			world[(center_y - 1) * worldSizeX + center_x]   = '_';
			world[(center_y) * worldSizeX + center_x+1]   = '\\';
			world[(center_y + 1) * worldSizeX + center_x-2] = '\\';
			world[(center_y + 1) * worldSizeX + center_x+1]   = '/';
			world[(center_y + 1) * worldSizeX + center_x-1] = '_';
			world[(center_y + 1) * worldSizeX + center_x]   = '_';
			break;
		case top_right:
			world[(center_y - 1) * worldSizeX + center_x-1] = '_';
			world[(center_y - 1) * worldSizeX + center_x]   = '_';
			world[(center_y) * worldSizeX + center_x-2] = '/';
			world[(center_y + 1) * worldSizeX + center_x-2] = '\\';
			world[(center_y + 1) * worldSizeX + center_x+1]   = '/';
			world[(center_y + 1) * worldSizeX + center_x-1] = '_';
			world[(center_y + 1) * worldSizeX + center_x]   = '_';
			break;
		case bottom_right:
			world[(center_y - 1) * worldSizeX + center_x-1] = '_';
			world[(center_y - 1) * worldSizeX + center_x]   = '_';
			world[(center_y) * worldSizeX + center_x-2] = '/';
			world[(center_y) * worldSizeX + center_x+1]   = '\\';
			world[(center_y + 1) * worldSizeX + center_x+1]   = '/';
			world[(center_y + 1) * worldSizeX + center_x-1] = '_';
			world[(center_y + 1) * worldSizeX + center_x]   = '_';
			break;
		case bottom_left:
			world[(center_y - 1) * worldSizeX + center_x-1] = '_';
			world[(center_y - 1) * worldSizeX + center_x]   = '_';
			world[(center_y) * worldSizeX + center_x-2] = '/';
			world[(center_y) * worldSizeX + center_x+1]   = '\\';
			world[(center_y + 1) * worldSizeX + center_x-2] = '\\';
			world[(center_y + 1) * worldSizeX + center_x-1] = '_';
			world[(center_y + 1) * worldSizeX + center_x]   = '_';
			break;
		case bottom:
			world[(center_y) * worldSizeX + center_x-2] = '/';
			world[(center_y) * worldSizeX + center_x+1]   = '\\';
			world[(center_y + 1) * worldSizeX + center_x-2] = '\\';
			world[(center_y + 1) * worldSizeX + center_x+1]   = '/';
			world[(center_y + 1) * worldSizeX + center_x-1] = '_';
			world[(center_y + 1) * worldSizeX + center_x]   = '_';
			break;
	}	
	
	world[center_y * worldSizeX + center_x] = 'x';

	if (center_x < 5 || center_y < 5 || center_x > worldSizeX - 5 || center_y > worldSizeY - 5)
	{
		return world;
	}	
	DrawHex(center_x, center_y - 2, worldSizeX, worldSizeY, top, world);
	DrawHex(center_x - 3, center_y - 1, worldSizeX, worldSizeY, top_left, world);
	DrawHex(center_x + 3, center_y - 1, worldSizeX, worldSizeY, top_right, world);
	DrawHex(center_x - 3, center_y + 1, worldSizeX, worldSizeY, bottom_left, world);
	DrawHex(center_x + 3, center_y + 1, worldSizeX, worldSizeY, bottom_right, world);
	DrawHex(center_x, center_y + 2, worldSizeX, worldSizeY, bottom, world);
}	

char* DrawFirstHex(int worldSizeX, int worldSizeY, char* world)
{
	int center_x = (int)(worldSizeX / 2);
	int center_y = (int)(worldSizeY / 2);
	
	world[(center_y - 1) * worldSizeX + center_x-1] = '_';
	world[(center_y - 1) * worldSizeX + center_x]   = '_';
	world[(center_y) * worldSizeX + center_x-2] = '/';
	world[(center_y) * worldSizeX + center_x+1]   = '\\';
	world[(center_y + 1) * worldSizeX + center_x-2] = '\\';
	world[(center_y + 1) * worldSizeX + center_x+1]   = '/';
	world[(center_y + 1) * worldSizeX + center_x-1] = '_';
	world[(center_y + 1) * worldSizeX + center_x]   = '_';
		
	if (center_x < 4 || center_y < 4 || center_x > worldSizeX -4 || center_y > worldSizeY - 4)
	{
		return world;
	}	
	DrawHex(center_x, center_y - 2, worldSizeX, worldSizeY, top, world);
	DrawHex(center_x - 3, center_y - 1, worldSizeX, worldSizeY, top_left, world);
	DrawHex(center_x + 3, center_y - 1, worldSizeX, worldSizeY, top_right, world);
	DrawHex(center_x - 3, center_y + 1, worldSizeX, worldSizeY, bottom_left, world);
	DrawHex(center_x + 3, center_y + 1, worldSizeX, worldSizeY, bottom_right, world);
	DrawHex(center_x, center_y + 2, worldSizeX, worldSizeY, bottom, world);

	return world;
}

int main()
{
	int x;
	int y;	
	
	cout << "Hex grid X dimension? ";
	cin >> x;
	cout << "Hex grid Y dimension? ";
	cin >> y;

	int worldSizeY = y * 3;
	int worldSizeX = x * 4;	

	char world[worldSizeY * worldSizeX] = { };

	for (int i=0; i < worldSizeY * worldSizeX; i++)
	{
		world[i] = ' ';
	}	

	
	DrawFirstHex(worldSizeX, worldSizeY, world);
	
	for (int i=0; i < worldSizeY * worldSizeX; i++)
	{
		if(world[i] == 'x')
			world[i] = ' ';
	}	

	for (int i=0; i < worldSizeY; i++)
	{
		for (int j = 0; j < worldSizeX; j++)
		{
			cout << world[j + i * worldSizeX];
		}
		cout << endl;
	}


	return 0;
}
