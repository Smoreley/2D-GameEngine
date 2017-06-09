#include "BeserkStd.h"
#include "ResourceCache.h"

namespace Beserk {

	Resource::Resource(const string  &name) {

		m_name = name;
		transform(m_name.begin(), m_name.end(), m_name.begin(), (int(*)(int))tolower);

	}

}