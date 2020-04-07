#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MUI_LIB)
#  define MUI_EXPORT Q_DECL_EXPORT
# else
#  define MUI_EXPORT Q_DECL_IMPORT
# endif
#else
# define MUI_EXPORT
#endif
