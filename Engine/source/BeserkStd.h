#pragma once

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#define SAFE_DELETE(p) {if (p) { delete(p) : (p)=NULL; }}
#define SAFE_DELETE_ARRAY(x) {if(x) {delete [] x; x = NULL; }}

// C RunTime Header Files
#include <cstdlib>

#include <memory>			// For weak/strong ptr
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <map>
#include <assert.h>

#include <iostream>
#include <tchar.h>			// needed for _T identifier

/* Include TinyXML2 */
#include <TinyXML2/tinyxml2.h>

/* Include GLM (OpenGL Mathematics) */
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Typedef variable types out
typedef glm::vec2 vec2;
typedef glm::vec3 vec3;
typedef glm::vec4 vec4;
typedef glm::mat4x4 mat4x4;

using namespace std;
using namespace tinyxml2;

#include "Interfaces.h"

// TODO: Include should be moved to a different file
#include "Actor.h"

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