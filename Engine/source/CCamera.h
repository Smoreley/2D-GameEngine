#pragma once
#include "IComponent.h"

namespace Beserk {
	class CCamera : public IComponent
	{
	public:
		static unsigned int camera_count;	// The number of cameras in the scene
		static CCamera active_camera;		// Currently active camera

		int window_width;
		int window_height;

		float fov;
		float near_clip_plane;
		float far_clip_plane;

		CCamera();
		~CCamera();

		bool SetAsActiveCamera();	// Sets this camera as the active camera to render out of


	private:

	};
}