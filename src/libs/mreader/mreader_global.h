#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MREADER_LIB)
#  define MREADER_EXPORT Q_DECL_EXPORT
# else
#  define MREADER_EXPORT Q_DECL_IMPORT
# endif
#else
# define MREADER_EXPORT
#endif
