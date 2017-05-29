#pragma once

// C RunTime Header Files
#include <cstdlib>

#include <memory>		// For weak/strong ptr
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <map>
#include <assert.h>

#include <iostream>
//#include <stdio.h>
//#include <tchar.h>
//#include <utility>
//#include "String.h"

#include <TinyXML2\tinyxml2.h>

using std::shared_ptr;
using std::weak_ptr;
using std::static_pointer_cast;
using std::dynamic_pointer_cast;

using namespace std;
using namespace tinyxml2;

#include "Interfaces.h"



// TODO: Moved to 
#include "Actor.h"


struct Options {
	std::string m_name;

	// Rendering
	std::string m_Renderer;
	bool m_FullScreen;

	// Sound
	float m_Volume;
};


// ue4 type stuff
struct FGenericPlatformTypes {

	// Unsigned base types
	typedef unsigned char				uint8;
	typedef unsigned short int			uint16;
	typedef unsigned int				uint32;
	typedef unsigned long long			uint64;

	// Signed base types
	typedef signed char					int8;
	typedef signed short int			int16;
	typedef signed int					int32;
	typedef signed long long			int64;

	// Character types
	typedef char						ANSICHAR;
	typedef wchar_t						WIDECHAR;
	typedef uint8						CHAR8;
	typedef uint16						CHAR16;
	typedef uint32						CHAR32;		// 32-bit character type
	typedef WIDECHAR					TCHAR;		// switchable character

	typedef int32						TYPE_OF_NULL;
	typedef	decltype(nullptr)			TYPE_OF_NULLPTR;
};