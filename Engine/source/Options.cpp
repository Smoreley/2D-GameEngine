#include "BeserkStd.h"
#include "Options.h"

namespace Beserk {

	/* Defaults */
	GameOptions::GameOptions() {

		// Render Options
		m_windowSizeX = 960;
		m_windowSizeY = 540;
		m_fullScreen = false;
		m_vsync = true;
		m_brightness = 1.0f;
		m_gamma = 1.0f;

		// Sound Options
		m_masterVol = 100.0f;
		m_effectVol = 100.0f;
		m_musicVol = 100.0f;
	}

	// Load options from xml file
	void GameOptions::Init(const char* xmlFilePath) {
		XMLDocument doc;
		doc.LoadFile(xmlFilePath);

		XMLElement *pRoot = doc.RootElement();		// Grab the root of the XML

		if (!pRoot) {
			cout << "Unable to get root element" << endl;
			return;
		}
		else {
			// Graphics Data
			XMLElement* pGraphicsElement = pRoot->FirstChildElement("Graphics");
			if (pGraphicsElement) {
				m_windowSizeX = pGraphicsElement->IntAttribute("width");
				m_windowSizeY = pGraphicsElement->IntAttribute("height");
				m_fullScreen = pGraphicsElement->BoolAttribute("fullscreen");
			}

			// Sound
			XMLElement* pSoundElement = pRoot->FirstChildElement("Sound");
			if (pSoundElement) {
				m_masterVol = pSoundElement->FloatAttribute("masterVolume");
				m_effectVol = pSoundElement->FloatAttribute("effectVolume");
				m_musicVol = pSoundElement->FloatAttribute("musicVolume");
			}

		}
	}

}	// End-of Namespace