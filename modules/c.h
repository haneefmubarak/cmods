// libcmods - the c modules library
//
// libc

#include "common.h"

//	Standard Library
#include <stdlib.h>

struct cmods_libc_lib {
	// memory management
	void* 	(*malloc)	(size_t);
	void*	(*calloc)	(size_t, size_t);
	void*	(*realloc)	(void *, size_t);
	void	(*free)		(void *);

	// string conversion
	double			(*atof)		(const char *);
	int			(*atoi)		(const char *);
	long			(*atol)		(const char *);
	long long		(*atoll)	(const char *);
	double			(*strtod)	(const char *, char **);
	float			(*strtof)	(const char *, char **);
	long			(*strtol)	(const char *, char **, int);
	long double		(*strtold)	(const char *, char **);
	long long		(*strtoll)	(const char *, char **, int);
	unsigned long		(*strtoul)	(const char *, char **, int);
	unsigned long long	(*strtoull)	(const char *, char **, int);

	// predictable testing pseudorandom numbers
	void	(*srand)	(unsigned);
	int	(*rand)		(void);

	// search and sort
	void*	(*bsearch)	(const void *, const void *, size_t, size_t,	\
					int (*compar) (const void *, const void *));
	void	(*qsort)	(void *, size_t, size_t, int (*compar) (const void *, const void *));

	// environment
	void	(*abort)		(void);
	int	(*atexit)		(void (*func) (void));
	int	(*at_quick_exit)	(void (*func) (void));
	void	(*exit)			(int);
	char*	(*getenv)		(const char *);
	void	(*quick_exit)		(int);
	int	(*system)		(const char *);
	void	(*_exit)		(int);

	// multibyte
	int	(*mblen)	(const char *, size_t);
	size_t	(*mbstowcs)	(wchar_t *, const char *, size_t);
	int	(*mbtowc)	(wchar_t *, const char *, size_t);
	size_t	(*wcstombs)	(char *, const wchar_t *, size_t);
	int	(*wctomb)	(char *, wchar_t);

	// integer special functions
	int		(*abs)		(int);
	div_t		(*div)		(int, int);
	long		(*labs)		(long);
	ldiv_t		(*ldiv)		(long, long);
	long long	(*llabs)	(long long);
	lldiv_t		(*lldiv)	(long long, long long);
};

//	IO
#include <stdio.h>

struct cmods_libc_io {
	// open / close etc.
	union {
		FILE*	(*fopen)	(const char *, const char *);
		FILE*	(*open)		(const char *, const char *);
	};
	union {
		FILE*	(*freopen)	(const char *, const char *, FILE *);
		FILE*	(*reopen)	(const char *, const char *, FILE *);
	};
	union {
		int	(*fflush)	(FILE *);
		int	(*flush)	(FILE *);
	};
	union {
		int	(*fclose)	(FILE *);
		int	(*close)	(FILE *);
	};
	void	(*setbuf)	(FILE *, char *);
	int	(*setvbuf)	(FILE *, char *, int, size_t);

	// FS ops
	union {
		int	(*remove)	(const char *);
		int	(*rm)		(const char *);
	};
	union {
		int	(*rename)	(const char *);
		int	(*mv)		(const char *);
	};
	FILE*	(*tmpfile)	(void);
	char*	(*tmpname)	(char *);

	// error handling
	union {
		int	(*feof)		(FILE *);
		int	(*eof)		(FILE *);
	};
	int	(*ferror)	(FILE *);
	void	(*perror)	(const char *);
	void	(*clearerr)	(FILE *);

	// positioning
	void	(*rewind)	(FILE *);
	union {
		long	(*ftell)	(FILE *);
		long	(*tell)		(FILE *);
	};
	union {
		int	(*fseek)	(FILE *, long, int);
		int	(*seek)		(FILE *, long, int);
	};
	union {
		int	(*fgetpos)	(FILE *, fpos_t *);
		int	(*getpos)	(FILE *, fpos_t *);
	};
	union {
		int	(*fsetpos)	(FILE *, const fpos_t *);
		int	(*setpos)	(FILE *, const fpos_t *);
	};

	// character IO
	int	(*fgetc)	(FILE *);
	char*	(*fgets)	(char *, int, FILE *);
	int	(*fputc)	(int, FILE *);
	int	(*fputs)	(const char *, FILE *);
	int	(*getc)		(FILE *);
	int	(*getchar)	(void);
	char*	(*gets)		(char *);
	int	(*putc)		(int, FILE *);
	int	(*putchar)	(int);
	int	(*puts)		(const char *);
	int	(*ungetc)	(int, FILE *);

	// printf
	int	(*printf)	(const char *, ...);
	int	(*fprintf)	(FILE *, const char *, ...);
	int	(*sprintf)	(char *, const char *, ...);
	int	(*snprintf)	(char *, size_t, const char *, ...);
	int	(*asprintf)	(char **, const char *, ...);
	int	(*dprintf)	(int, const char *, ...);
	int	(*vprintf)	(const char *, va_list);
	int	(*vfprintf)	(FILE *, const char *, va_list);
	int	(*vsprintf)	(char *, const char *, va_list);
	int	(*vsnprintf)	(char *, size_t, const char *, va_list);
	int	(*vasprintf)	(char **, const char *, va_list);
	int	(*vdprintf)	(int, const char *, va_list);

	// scanf
	int	(*scanf)	(const char *, ...);
	int	(*fscanf)	(FILE *, const char *, ...);
	int	(*sscanf)	(const char *, const char *, ...);
	int	(*vscanf)	(const char *, va_list);
	int	(*vfscanf)	(FILE *, const char *, va_list);
	int	(*vsscanf)	(const char *, const char *, va_list);
};

//	strings
#include <string.h>

struct cmod_libc_string {
	// general
	size_t	(*strlen)	(const char *);
	void*	(*memset)	(void *, int, size_t);
	char*	(*strcat)	(char *, const char *);
	char*	(*strncat)	(char *, const char *, size_t);
	char*	(*strerror)	(int);
	size_t	(*strxfrm)	(char *, const char *, size_t);

	// copying
	void*	(*memcpy)	(void *, const void *, size_t);
	char*	(*strcpy)	(char *, const char *);
	char*	(*strncpy)	(char *, const char *, size_t);
	void*	(*memmove)	(void *, const void *, size_t);

	// comparison
	int	(*memcmp)	(const void *, const void *, size_t);
	int	(*strcmp)	(const char *, const char *);
	int	(*strncmp)	(const char *, const char *, size_t);
	int	(*strcoll)	(const char *, const char *);

	// searching
	void*	(*memchr)	(const void *, int, size_t);
	char*	(*strchr)	(const char *, int);
	char*	(*strrchr)	(const char *, int);
	size_t	(*strcspn)	(const char *, const char *);
	size_t	(*strspn)	(const char *, const char *);
	char*	(*strpbrk)	(const char *, const char *);
	char*	(*strstr)	(const char *, const char *);
	char*	(*strtok)	(char *, const char);
};
