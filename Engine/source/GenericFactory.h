#pragma once

namespace Beserk {

	template <class BaseType, class SubType>
	BaseType* GenericObjectCreationFunction(void) { return new SubType; }

	/* Generic Factory */
	template <class BaseClass, class IdType>
	class GenericObjectFactory
	{
	public:

		template<class SubClass>
		bool Register(IdType id) {
			auto findIt = m_creationFunctions.find(id);
			if (findIt == m_creationFunctions.end()) {
				m_creationFunctions[id] = &GenericObjectCreationFunction<BaseClass, SubClass>;
				return true;
			}
			return false;
		}

		BaseClass* Create(IdType id) {
			auto findIt = m_creationFunctions.find(id);
			if (findIt != m_creationFunctions.end()) {
				ObjectCreationFunction pFunc = findIt->second;
				return pFunc();
			}
			return NULL;
		}


	private:
		typedef BaseClass* (*ObjectCreationFunction)(void);
		map<IdType, ObjectCreationFunction> m_creationFunctions;

	};

}	// End-of Namespace