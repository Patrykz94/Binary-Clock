/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	t(time(0)),
	keyReleased(false)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	t = time(0);
	struct tm timeInfo;
	localtime_s(&timeInfo, &t);
	
	clock.Update(timeInfo.tm_hour, timeInfo.tm_min, timeInfo.tm_sec);

	if (wnd.kbd.KeyIsPressed(VK_LEFT) && keyReleased)
	{
		clock.SetColor(-1);
		keyReleased = false;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT) && keyReleased)
	{
		clock.SetColor(1);
		keyReleased = false;
	}
	else if (!wnd.kbd.KeyIsPressed(VK_LEFT) && !wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		keyReleased = true;
	}

}

void Game::ComposeFrame()
{
	clock.Draw(Vec2(100, 400), gfx);
}
