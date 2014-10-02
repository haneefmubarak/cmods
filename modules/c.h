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
