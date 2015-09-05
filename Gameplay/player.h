/////////////////////////////////////////////////////////////////////////////
// This file is part of the Journey MMORPG client                           //
// Copyright � 2015 SYJourney                                               //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include "maplechar.h"
#include "playereffects.h"
#include "inventory.h"
#include "footholdtree.h"
#include "laddersropes.h"
#include "moveinfo.h"
#include "skillbook.h"

using namespace std;
using namespace character;

namespace gameplay
{
	const float fallspeed = 7.7f;
	const float gravityAcc = 0.5f;
	const float jumpSpeed = 9.0f;
	const float walkSpeed = 2.25f;

	enum moveinput : char
	{
		min_left,
		min_right,
		min_jump,
		min_crouch,
		min_attack,
		min_up
	};

	enum playerstate : char
	{
		mst_stand,
		mst_walk,
		mst_fall,
		mst_prone,
		mst_dash,
		mst_attack,
		mst_climb
	};

	struct startedquest
	{
		string questdata;
		short infonumber;
		string medaldata;
	};

	class player
	{
	public:
		player() {}
		~player() {}
		player(maplechar*, inventory, int, skillbook, map<int, pair<string, pair<short, string>>>, map<int, int64_t>, pair<vector<int>, vector<int>>, int, map<short, char>, map<short, string>);
		maplestats* getstats() { return &stats; }
		playereffects* geteffects() { return &effects; }
		inventory* getinventory() { return &invent; }
		skillbook* getskills() { return &skills; }
		vector2d getposition() { return position; }
		bool onladderrope() { return state == mst_climb; }
		bool getleft() { return fleft; }
		void setposition(vector2d);
		void setfh(footholdtree*);
		void setlr(ladderrope);
		void sit(bool);
		void key_jump(bool);
		void key_left(bool);
		void key_right(bool);
		void key_down(bool);
		void key_up(bool);
		bool attack(int);
		void setactions(vector<string>);
		void setexpression(char);
		void draw(ID2D1HwndRenderTarget*, vector2d);
		movep_info update();
	private:
		maplestats stats;
		maplelook look;
		inventory invent;
		skillbook skills;
		playereffects effects;
		map<int, pair<string, pair<short, string>>> quests;
		map<int, int64_t> completedquests;
		pair<vector<int>, vector<int>> trockmaps;
		int bookcover;
		map<short, char> bookcards;
		map<short, string> areainfo;
		vector2d position;
		ladderrope ladrrope;
		footholdtree* footholds;
		short speed;
		short jump;
		float hspeed;
		float vspeed;
		float fx;
		float fy;
		float ground;
		bool fleft;
		bool nofriction;
		void recalcstats(bool);
		bool attacking;
		bool candjump;
		playerstate state;
		map<moveinput, bool> keydown;
	};
}

