#pragma once

#include "prerequisites.h"
#include "object.h"

#include <osg/LightSource>

namespace simvis
{
	class SIMVIS_API light : public object
	{
	public:
		light() : light_source( nullptr ) {}
		light( const light& other ) : light_source( other.light_source ) {}
		light( const vec3f& pos, const color& col );
		virtual ~light() {}

		int get_number() { return light_source->getLight()->getLightNum(); }

		virtual osg::Node* osg_node() override { return light_source; }

	private:
		osg::ref_ptr< osg::LightSource > light_source;
		static int unique_light_number;
	};
}