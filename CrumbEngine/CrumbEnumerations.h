
// CrumbEnumerations.h
// Enumerations to be used by rest of Engine
// Bribz - 3/4/2017

#ifndef CRUMB_ENUMERATIONS_H
#define CRUMB_ENUMERATIONS_H


// GLShaderType
// Easier readability by shader program input
// May be removed if necessary
enum class GLShaderType : char
{
	COMPUTE				= 'c',
	FRAGMENT			= 'f',
	GEOMETRY			= 'g',
	TESSELLATION		= 't',
	VERTEX				= 'v',
	NULL_TYPE			= 256
};


#endif // CRUMB_ENUMERATIONS_H
