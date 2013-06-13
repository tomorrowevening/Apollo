//
//  ApolloGLEnum.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once
#include "ApolloCore.h"

#ifdef APOLLO_MAC
#include <OpenGL/gl.h>
#endif

#ifdef APOLLO_MSW
#include <windows.h>
#include "GL\glew.h"
#include "GL\wglew.h"
#include "glu.h"
#endif

#ifdef APOLLO_LINUX
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glx.h>
#endif

#ifdef APOLLO_COCOA_TOUCH
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#endif

#ifdef APOLL_ANDROID
#include <GLES/gl.h>
#include <GLES/glext.h>
#endif

#include "ApolloFBO.h"
#include "ApolloShader.h"
#include "ApolloTexture.h"

namespace Apollo {
	namespace gl {
		
		
		
	}
}
