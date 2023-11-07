#include "RenderAPI.h"
#include "PlatformBase.h"

// OpenGL Core profile (desktop) or OpenGL ES (mobile) implementation of RenderAPI.
// Supports several flavors: Core, ES2, ES3


#if SUPPORT_OPENGL_UNIFIED


#include <assert.h>
#if UNITY_IPHONE
#	include <OpenGLES/ES2/gl.h>
#elif UNITY_ANDROID || UNITY_WEBGL
#	include <GLES3/gl3.h>
#elif UNITY_OSX
#	include <OpenGL/gl3.h>
#elif UNITY_WIN
// On Windows, use gl3w to initialize and load OpenGL Core functions. In principle any other
// library (like GLEW, GLFW etc.) can be used; here we use gl3w since it's simple and
// straightforward.
#	include "gl3w/gl3w.h"
#elif UNITY_LINUX
#	define GL_GLEXT_PROTOTYPES
#	include <GL/gl.h>
#else
#	error Unknown platform
#endif

typedef const GLubyte* GLString;

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_Init()
{
#if UNITY_WIN
    gl3wInit();
#endif
}

extern "C" GLString UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_GetString(GLenum name)
{
    return glGetString(name);
}

extern "C" GLenum UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_GetError()
{
    return glGetError();
}

//extern "C" GLint UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API DebugGetFormat()
//{
//	GLint format;
//	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_INTERNAL_FORMAT, &format);
//	return format;
//}

extern "C" unsigned int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_GenTexture()
{
    GLuint texture;
    glGenTextures(1, &texture);
    return texture;
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_DeleteTexture(GLuint texture)
{
    glDeleteTextures(1, &texture);
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_BindTexture(GLenum type, GLuint texture)
{
    glBindTexture(type, texture);
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_TexStorage2D(GLenum target, GLsizei levels, GLenum internalFormat,
    GLsizei width, GLsizei height)
{
    glTexStorage2D(target, levels, internalFormat, width, height);
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_PixelStoreInt(GLenum name, GLint param)
{
    glPixelStorei(name, param);
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_TexImage2D(GLenum target,
    GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type,
    const void* pixels)
{
    glTexImage2D(target, level, internalFormat, width, height, border, format, type, pixels);
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_CompressedTexImage2D(GLenum target,
    GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize,
    const GLvoid* data)
{
    glCompressedTexImage2D(target, level, internalFormat, width, height, border, imageSize, data);
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_TexSubImage2D(GLenum target,
    GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type,
    const void* pixels)
{
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_CompressedTexSubImage2D(GLenum target,
    GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize,
    const void* data)
{
    glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_TexParameterInt(GLenum target, GLenum pname, GLint param)
{
    glTexParameteri(target, pname, param);
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GL_TexParameterFloat(GLenum target, GLenum pname, GLfloat param)
{
    glTexParameterf(target, pname, param);
}

#endif // #if SUPPORT_OPENGL_UNIFIED
