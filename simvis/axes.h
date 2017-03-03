#pragma once

#include "object.h"
#include "mesh.h"
#include "group.h"
#include "arrow.h"

namespace vis
{
	class SIMVIS_API axes : public group
	{
	public:
		axes() : group() {}
		axes( group& s, vec3f length, float detail ) : axes( s, length, 0.005f, 0.010f, detail ) {}
		axes( group& s, vec3f length, float radius, float head_radius, float detail );
		virtual ~axes();
		
	private:
		mesh x_arrow;
		mesh y_arrow;
		mesh z_arrow;
	};
}
