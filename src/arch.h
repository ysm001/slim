/* Generated by genconfig.  DO NOT EDIT */

#ifndef LMN_ARCH_H
#define LMN_ARCH_H

#define SLIM_DATA_DIR "/usr/local/share/slim"
#define SLIM_LIB_DIR "/usr/local/share/slim/lib"
#define SLIM_EXT_DIR "/usr/local/share/slim/ext"

#if defined __CYGWIN32__ && !defined __CYGWIN__
#  define __CYGWIN__  __CYGWIN32__
#endif

#if defined _WIN32 && !defined __CYGWIN__
#  define DIR_SEPARATOR_CHAR    '\\'
#  define DIR_SEPARATOR_STR	    "\\"
#  define PATH_SEPARATOR_CHAR    ';'
#  define PATH_SEPARATOR_STR     ";"
#endif
#ifndef DIR_SEPARATOR_CHAR
#  define DIR_SEPARATOR_CHAR    '/'
#  define DIR_SEPARATOR_STR	    "/"
#  define PATH_SEPARATOR_CHAR   ':'
#  define PATH_SEPARATOR_STR    ":"
#endif /* !DIR_SEPARATOR_CHAR */

#if defined  _WIN32 || defined __CYGWIN__
#  define DL_FILE_TYPE          "dll"
#else
#  define DL_FILE_TYPE          "so"
#endif

#endif /* LMN_ARCH_H */
