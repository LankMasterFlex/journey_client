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

namespace util
{
	class vector2d
	{
	private:
		int a;
		int b;
	public:
		vector2d();
		vector2d(int);
		vector2d(int, int);
		~vector2d();
		int x();
		int y();
		int length();
		int center();
		bool contains(int);
		bool straight();
		bool overlaps(vector2d);
		bool iswithin(vector2d, vector2d);
		string tostring() { return to_string(a) + "," + to_string(b); }
		vector2d operator + (vector2d);
		vector2d operator - (vector2d);
		vector2d operator * (vector2d);
		vector2d operator / (vector2d);
		bool operator == (vector2d);
		bool operator != (vector2d);
		void setx(int v) { a = v; }
		void sety(int v) { b = v; }
	};
}

