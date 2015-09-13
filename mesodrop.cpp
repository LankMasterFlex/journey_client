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
#include "mesodrop.h"
#include "nxfile.h"

namespace maplemap
{
	mesodrop::mesodrop(short o, int id, int own, vector2d pos, vector2d dst, char type, bool pld, footholdtree* fht)
	{
		oid = o;

		nl::node mesonode;
		if (id > 999)
		{
			mesonode = nx::nodes["Item"]["Special"]["0900.img"]["09000003"]["iconRaw"];
		}
		else if (id > 99)
		{
			mesonode = nx::nodes["Item"]["Special"]["0900.img"]["09000002"]["iconRaw"];
		}
		else if (id > 9)
		{
			mesonode = nx::nodes["Item"]["Special"]["0900.img"]["09000001"]["iconRaw"];
		}
		else
		{
			mesonode = nx::nodes["Item"]["Special"]["0900.img"]["09000000"]["iconRaw"];
		}
		anim = animation(mesonode);

		owner = own;
		pickuptype = type;
		playerdrop = pld;

		footholds = fht;
		fh = footholds->getbelow(pos);
		fx = static_cast<float>(pos.x());
		fy = static_cast<float>(pos.y());
		alpha = 1.0f;
		moved = 0.0f;

		if (pos == dst)
		{
			state = DST_FLOATING;
			vspeed = 0;
			hspeed = 0;
			basey = fy;
		}
		else
		{
			state = DST_DROPPED;
			vspeed = -6.0f;
			hspeed = static_cast<float>(dst.x() - pos.x()) / 16;
		}
	}

	void mesodrop::draw(ID2D1HwndRenderTarget* target, vector2d viewpos)
	{
		if (state != DST_INACTIVE)
		{
			anim.draw(target, viewpos + getposition(), alpha);
		}
	}

	bool mesodrop::update()
	{
		if (state != DST_INACTIVE)
		{
			anim.update(8);
		}

		return drop::update();
	}
}
