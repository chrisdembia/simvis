#pragma once

#include "mesh.h"
#include "arrow.h"
#include "path.h"
#include "object.h"
#include "color.h"
#include "light.h"

namespace simvis
{
	class SIMVIS_API scene : public object
	{
	public:
		scene();
		~scene();

		mesh make_mesh( const string& filename );
		mesh make_sphere( float radius, color c, float detail = 0.5f );
		mesh make_cube( vec3f dim, color c );
		mesh make_cylinder( float radius, float height, color c, float detail = 0.5f );
		mesh make_cone( float radius, float height, color c, float detail = 0.5f );
		arrow make_arrow( float radius, color c, float detail = 0.5f );
		path make_path( float radius, color c, float detail = 0.5f );
		light make_light( const vec3f& pos, const color& c );

		void attach( object& o );
		void detach( object& o );

		osg::Group& osg_root() { return *root; }
		virtual osg::Node* osg_node() override { return root; }

	private:
		osg::ref_ptr< osg::Group > root;
	};
}
