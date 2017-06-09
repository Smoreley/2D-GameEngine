// The Scene Graph helps manage transformations
// and in rendering only relevant things.

#pragma once

#include "BeserkStd.h"

namespace Beserk {

	// Temp
	class IRender;

	class Scene {
	public:
		Scene(shared_ptr<IRender> renderer);
		virtual ~Scene();



	protected:


	private:

	};

}	// End-of Namespace