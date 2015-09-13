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
#include "stdfax.h"

using namespace std;

namespace io
{
	enum keyaction : char
	{
		KA_EQUIPS = 0,
		KA_INVENTORY = 1,
		KA_CHARSTATS = 2,
		KA_SKILL = 3,
		KA_BUDDY = 4,
		KA_WORLDMAP = 5,
		KA_MESSAGE = 6,
		KA_MINIMAP = 7,
		KA_QUEST = 8,
		KA_KEYCONFIG = 9,
		KA_CHATALL = 10,
		KA_WHISPER = 11,
		KA_CHATPT = 12,
		KA_CHATBUDDY = 13,
		KA_MAINMENU = 14,
		KA_TOGGLEQS = 15,
		KA_CHATWND = 16,
		KA_GUILD = 17,
		KA_CHATGUILD = 18,
		KA_PARTY = 19,
		KA_HELPER = 20,
		KA_CHATSPOUSE = 21,
		KA_MONSTERBOOK = 22,
		KA_CASHSHOP = 23,
		KA_CHATALLIANCE = 24,
		KA_PARTYSEARCH = 25,
		KA_FAMILY = 26,
		KA_GMSMEDALS = 27,
		KA_BOSS = 28,
		KA_CHATSQUAD = 29,
		KA_PROFESSION = 30,
		KA_ITEMPOT = 31,
		KA_EVENT = 32,
		KA_WHEEL = 33,
		KA_LEVELGUIDE = 34,
		KA_CRUSADE = 35,
		KA_BITS = 36,
		KA_KNOWHOW = 37,
		KA_EPISODE = 38,
		KA_GUIDE = 39,
		KA_EQUIPENHANCE = 40,
		KA_EQUIPENHANCE2 = 41,
		KA_PICKUP = 50,
		KA_SIT = 51,
		KA_ATTACK = 52,
		KA_NPCCHAT = 53, //these are switched 
		KA_JUMP = 54,	// ^
		KA_FACE1 = 100,
		KA_FACE7 = 106
	};

	enum keytype : char
	{
		KT_NONE = 0,
		KT_SKILL = 1,
		KT_ITEM = 2,
		KT_CASH = 3,
		KT_MENU = 4,
		KT_ACTION = 5,
		KT_FACE = 6,
		KT_MACRO = 8
	};

	class keyboard
	{
	public:
		keyboard() {}
		~keyboard() {}
		void init(map<char, pair<char, int>>);
		void addmacros(map<string, pair<char, vector<int>>>);
		pair<keytype, int> getaction(char);
		map<char, pair<keytype, int>> getkeys() { return maplekeys; }
	private:
		map<char, pair<keytype, int>> keymap;
		map<char, pair<keytype, int>> maplekeys;
	};
}

