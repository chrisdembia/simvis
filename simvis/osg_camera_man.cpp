#include "osg_camera_man.h"
#include "xo/system/log_sink.h"

using namespace osg;

namespace vis
{
	osg_camera_man::osg_camera_man() :
	osgGA::OrbitManipulator(),
	orbit_yaw( 0 ),
	orbit_pitch( -5 )
	{
		setAllowThrow( false );
		_distance = 4.5;
		_minimumDistance = 0.001;
		_center = Vec3d( 0, 1.0, 0 );

		updateRotation();

		osg::Vec3d eye, center, up;
		getTransformation( eye, center, up );
		setHomePosition( eye, center, up );
	}

	osg_camera_man::~osg_camera_man() {}

	bool osg_camera_man::performMovementLeftMouseButton( const double eventTimeDelta, const double dx, const double dy )
	{
		orbit_pitch += degree( pitch_scale * dy );
		orbit_yaw -= degree( yaw_scale * dx );

		updateRotation();

		return true;
	}

	void osg_camera_man::updateRotation()
	{
		auto yaw = osg::Quat( orbit_yaw.rad_value(), osg::Vec3d( 0, 1, 0 ) );
		auto pitch = osg::Quat( orbit_pitch.rad_value(), osg::Vec3d( 1, 0, 0 ) );
		_rotation = pitch * yaw;
	}

	bool osg_camera_man::handleKeyDown( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us )
	{
		// filter out space key because we don't want it to reset the camera
		if ( ea.getKey() != osgGA::GUIEventAdapter::KEY_Space )
			return osgGA::OrbitManipulator::handleKeyDown( ea, us );
		else return false;
	}

	bool osg_camera_man::performMovementMiddleMouseButton( const double eventTimeDelta, const double dx, const double dy )
	{
		zoomModel( dy * zoom_scale, false );

		return true;
	}

	bool osg_camera_man::performMovementRightMouseButton( const double eventTimeDelta, const double dx, const double dy )
	{
		// pan model
		float scale = -pan_scale * _distance;
		panModel( dx * scale, dy * scale );

		return true;
	}
}
