#pragma once

namespace Beserk {

	struct GameOptions {

		// Render Options
		unsigned int m_windowSizeX;
		unsigned int m_windowSizeY;
		bool m_fullScreen;
		bool m_vsync;
		float m_brightness;
		float m_gamma;


		// Sound Options
		float m_masterVol;
		float m_effectVol;
		float m_musicVol;

	};

}	// End-of Namespace