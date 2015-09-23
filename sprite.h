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
#include "graphicobject.h"

namespace graphics
{
	class sprite : public graphicobject
	{
	public:
		sprite() {}
		sprite(animation, vector2d);
		sprite(animation, vector2d, bool, bool);
		~sprite() {}
		void draw(vector2d);
		bool update() { return graphicobject::update(&anim); }
		void setposition(vector2d pos) { position = pos; }
		void togglehide() { visible = !visible; }
		void flip() { flipped = !flipped; }
		animation* getani() { return &anim; }
	private:
		animation anim;
		vector2d position;
		bool visible;
		bool flipped;
	};
}

