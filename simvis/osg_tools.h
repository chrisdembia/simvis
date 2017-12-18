#pragma once

#include "prerequisites.h"
#include "color.h"
#include "xo/filesystem/path.h"

#include <osg/Vec3f>
#include <osg/Vec4f>
#include <osg/Quat>
#include <osg/Geode>

namespace vis
{
	const int OsgReceiveShadowMask = 0x1;
	const int OsgCastShadowMask = 0x2;

	inline osg::Vec3f make_osg( const vec3f& v ) { return osg::Vec3f( v.x, v.y, v.z ); }
	inline osg::Vec4f make_osg( const vec4f& v ) { return osg::Vec4f( v.x, v.y, v.z, v.w ); }
	inline osg::Quat make_osg( const quatf& v ) { return osg::Quat( v.x, v.y, v.z, v.w ); }
	inline osg::Vec4f make_osg( const color& v ) { return osg::Vec4f( v.r, v.g, v.b, v.a ); }

	SIMVIS_API osg::Geode* create_tile_floor( int x_tiles, int z_tiles, float tile_width = 1.0f );
	SIMVIS_API osg::ref_ptr< osg::Geode > read_vtp( const xo::path& filename );

	SIMVIS_API void set_shadow_mask( osg::Node* n, bool receive, bool cast );
}
