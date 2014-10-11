#pragma once
// libcmods - the c modules library
//
// libc

#include "common.h"

// standard library
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

// IO
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

// strings and memory
#include <string.h>

struct cmods_libc_str {
	// general
	union {
		size_t	(*strlen)	(const char *);
		size_t	(*len)		(const char *);
	};
	union {
		char*	(*strcat)	(char *, const char *);
		char*	(*cat)		(char *, const char *);
	};
	union {
		char*	(*strncat)	(char *, const char *, size_t);
		char*	(*ncat)		(char *, const char *, size_t);
	};
	union {
		char*	(*strerror)	(int);
		char*	(*error)	(int);
	};
	union {
		size_t	(*strxfrm)	(char *, const char *, size_t);
		size_t	(*xfrm)		(char *, const char *, size_t);
	};

	// copying
	union {
		char*	(*strcpy)	(char *, const char *);
		char*	(*cpy)		(char *, const char *);
	};
	union {
		char*	(*strncpy)	(char *, const char *, size_t);
		char*	(*ncpy)		(char *, const char *, size_t);
	};

	// comparison
	union {
		int	(*strcmp)	(const char *, const char *);
		int	(*cmp)		(const char *, const char *);
	};
	union {
		int	(*strncmp)	(const char *, const char *, size_t);
		int	(*ncmp)		(const char *, const char *, size_t);
	};
	union {
		int	(*strcoll)	(const char *, const char *);
		int	(*coll)		(const char *, const char *);
	};

	// searching
	union {
		char*	(*strchr)	(const char *, int);
		char*	(*chr)		(const char *, int);
	};
	union {
		char*	(*strrchr)	(const char *, int);
		char*	(*rchr)		(const char *, int);
	};
	union {
		size_t	(*strcspn)	(const char *, const char *);
		size_t	(*cspn)		(const char *, const char *);
	};
	union {
		size_t	(*strspn)	(const char *, const char *);
		size_t	(*spn)		(const char *, const char *);
	};
	union {
		char*	(*strpbrk)	(const char *, const char *);
		char*	(*pbrk)		(const char *, const char *);
	};
	union {
		char*	(*strstr)	(const char *, const char *);
		char*	(*str)		(const char *, const char *);
	};
	union {
		char*	(*strtok)	(char *, const char);
		char*	(*tok)		(char *, const char);
	};
};

struct cmods_libc_mem {
	// general
	union {
		void*	(*memset)	(void *, int, size_t);
		void*	(*set)		(void *, int, size_t);
	};

	// copying
	union {
		void*	(*memcpy)	(void *, const void *, size_t);
		void*	(*cpy)		(void *, const void *, size_t);
	};
	union {
		void*	(*memmove)	(void *, const void *, size_t);
		void*	(*move)		(void *, const void *, size_t);
	};

	// comparison
	union {
		int	(*memcmp)	(const void *, const void *, size_t);
		int	(*cmp)		(const void *, const void *, size_t);
	};

	// searching
	union {
		void*	(*memchr)	(const void *, int, size_t);
		void*	(*chr)		(const void *, int, size_t);
	};
};

// single character type functions
#include <ctype.h>

struct cmods_libc_type {
	// casing
	int	(*tolower)	(int);
	int	(*toupper)	(int);

	// classification
	int	(*isalnum)	(int);
	int	(*isalpha)	(int);
	int	(*isblank)	(int);
	int	(*iscntrl)	(int);
	int	(*isdigit)	(int);
	int	(*isgraph)	(int);
	int	(*islower)	(int);
	int	(*isprint)	(int);
	int	(*ispunct)	(int);
	int	(*isspace)	(int);
	int	(*isupper)	(int);
	int	(*isxdigit)	(int);
};

// locale
#include <locale.h>

struct cmods_libc_locale {
	struct lconv*	(*localeconv)	(void);
	union {
		char*		(*setlocale)	(int, const char *);
		char*		(*set)		(int, const char *);
	};
};

// signal handling
#include <signal.h>

struct cmods_libc_signal {
	void	(*(*signal)	(int, void (*func)(int)))(int);		// not going to even pretend I understand that syntax
	int	(*raise)	(int);
};

// time
#include <time.h>

struct cmods_libc_time {
	// general
	clock_t		(*clock)	(void);
	double		(*difftime)	(time_t, time_t);
	time_t		(*mktime)	(struct tm *);
	time_t		(*time)		(time_t *);

	// type processing / conversion
	size_t		(*strftime)	(char *, size_t, const char *, const struct tm *);
	char*		(*asctime)	(const struct tm *);
	char*		(*ctime)	(const time_t *);
	struct tm*	(*gmtime)	(const time_t *);
	struct tm*	(*localtime)	(const time_t *);
};

// floating point environment
#include <fenv.h>

struct cmods_libc_fenv {
	// general
	union {
		int	(*fegetenv)	(fenv_t *);
		int	(*getenv)	(fenv_t *);
		int	(*get)		(fenv_t *);
	};
	union {
		int	(*fesetenv)	(const fenv_t *);
		int	(*setenv)	(const fenv_t *);
		int	(*set)		(const fenv_t *);
	};
	union {
		int	(*feupdateenv)	(const fenv_t *);
		int	(*updateenv)	(const fenv_t *);
		int	(*update)	(const fenv_t *);
	};

	// rounding
	struct {
		union {
			int	(*fegetround)	(void);
			int	(*getround)	(void);
			int	(*get)		(void);
		};
		union {
			int	(*fesetround)	(int);
			int	(*setround)	(int);
			int	(*set)		(int);
		};
	} round;

	// FP exceptions
	struct {
		union {
			int	(*feholdexcept)		(fenv_t *);
			int	(*holdexcept)		(fenv_t *);
			int	(*hold)			(fenv_t *);
		};
		union {
			int	(*feclearexcept)	(int);
			int	(*clearexcept)		(int);
			int	(*clear)		(int);
		};
		union {
			int	(*feraiseexcept)	(int);
			int	(*raiseexcept)		(int);
			int	(*raise)		(int);
		};
		struct {
			union {
				int	(*fegetexceptflag)	(fexcept_t *, int);
				int	(*getexceptflag)	(fexcept_t *, int);
				int	(*getflag)		(fexcept_t *, int);
				int	(*get)			(fexcept_t *, int);
			};
			union {
				int	(*fesetexceptflag)	(const fexcept_t *, int);
				int	(*setexceptflag)	(const fexcept_t *, int);
				int	(*setflag)		(const fexcept_t *, int);
				int	(*set)			(const fexcept_t *, int);
			};
		} flag;
	} except;
};

// math
#include <math.h>

struct cmods_libc_math {
	// general / misc
	double		(*fabs)		(double);
	float		(*fabsf)	(float);
	long double	(*fabsl)	(long double);
	double		(*fmax)		(double, double);
	float		(*fmaxf)	(float, float);
	long double	(*fmaxl)	(long double, long double);
	double		(*fmin)		(double, double);
	float		(*fminf)	(float, float);
	long double	(*fminl)	(long double, long double);
	double		(*fdim)		(double, double);
	float		(*fdimf)	(float, float);
	long double	(*fdiml)	(long double, long double);
	double		(*fma)		(double, double, double);
	float		(*fmaf)		(float, float, float);
	long double	(*fmal)		(long double, long double, long double);
	double		(*fmod)		(double, double);
	float		(*fmodf)	(float, float);
	long double	(*fmodl)	(long double, long double);
	double		(*copysign)	(double, double);
	float		(*copysignf)	(float, float);
	long double	(*copysignl)	(long double, long double);
	double		(*nan)		(const char *);
	float		(*nanf)		(const char *);
	long double	(*nanl)		(const char *);
	double		(*nextafter)	(double, double);
	float		(*nextafterf)	(float, float);
	long double	(*nextafterl)	(long double, long double);
	double		(*nexttoward)	(double, long double);
	float		(*nexttowardf)	(float, long double);
	long double	(*nexttowardl)	(long double, long double);
	double		(*remainder)	(double, double);
	float		(*remainderf)	(float, float);
	long double	(*remainderl)	(long double, long double);
	double		(*remquo)	(double, double, int *);
	float		(*remquof)	(float, float, int *);
	long double	(*remquol)	(long double, long double, int *);

	// rounding and truncation
	double		(*ceil)		(double);
	float		(*ceilf)	(float);
	long double	(*ceill)	(long double);
	double		(*floor)	(double);
	float		(*floorf)	(float);
	long double	(*floorl)	(long double);
	double		(*trunc)	(double);
	float		(*truncf)	(float);
	long double	(*truncl)	(long double);
	double		(*round)	(double);
	float		(*roundf)	(float);
	long double	(*roundl)	(long double);
	long		(*lround)	(double);
	long		(*lroundf)	(float);
	long		(*lroundl)	(long double);
	long long	(*llround)	(double);
	long long	(*llroundf)	(float);
	long long	(*llroundl)	(long double);
	double		(*rint)		(double);
	float		(*rintf)	(float);
	long double	(*rintl)	(long double);
	long		(*lrint)	(double);
	long		(*lrintf)	(float);
	long		(*lrintl)	(long double);
	long long	(*llrint)	(double);
	long long	(*llrintf)	(float);
	long long	(*llrintl)	(long double);
	double		(*nearbyint)	(double);
	float		(*nearbyintf)	(float);
	long double	(*nearbyintl)	(long double);

	// error, gamma, and power functions
	double		(*erf)		(double);
	float		(*erff)		(float);
	long double	(*erfl)		(long double);
	double		(*erfc)		(double);
	float		(*erfcf)	(float);
	long double	(*erfcl)	(long double);
	double		(*lgamma)	(double);
	float		(*lgammaf)	(float);
	long double	(*lgammal)	(long double);
	double		(*tgamma)	(double);
	float		(*tgammaf)	(float);
	long double	(*tgammal)	(long double);
	double		(*pow)		(double, double);
	float		(*powf)		(float, float);
	long double	(*powl)		(long double, long double);
	double		(*sqrt)		(double);
	float		(*sqrtf)	(float);
	long double	(*sqrtl)	(long double);
	double		(*cbrt)		(double);
	float		(*cbrtf)	(float);
	long double	(*cbrtl)	(long double);
	double		(*hypo)		(double, double);
	float		(*hypof)	(float, float);
	long double	(*hypol)	(long double, long double);

	// trig and hyp functions
	double		(*sin)		(double);
	float		(*sinf)		(float);
	long double	(*sinl)		(long double);
	double		(*cos)		(double);
	float		(*cosf)		(float);
	long double	(*cosl)		(long double);
	double		(*tan)		(double);
	float		(*tanf)		(float);
	long double	(*tanl)		(long double);
	double		(*asin)		(double);
	float		(*asinf)	(float);
	long double	(*asinl)	(long double);
	double		(*acos)		(double);
	float		(*acosf)	(float);
	long double	(*acosl)	(long double);
	double		(*atan)		(double);
	float		(*atanf)	(float);
	long double	(*atanl)	(long double);
	double		(*atan2)	(double, double);
	float		(*atan2f)	(float, float);
	long double	(*atan2l)	(long double, long double);
	double		(*sinh)		(double);
	float		(*sinhf)	(float);
	long double	(*sinhl)	(long double);
	double		(*cosh)		(double);
	float		(*coshf)	(float);
	long double	(*coshl)	(long double);
	double		(*tanh)		(double);
	float		(*tanhf)	(float);
	long double	(*tanhl)	(long double);
	double		(*asinh)	(double);
	float		(*asinhf)	(float);
	long double	(*asinhl)	(long double);
	double		(*acosh)	(double);
	float		(*acoshf)	(float);
	long double	(*acoshl)	(long double);
	double		(*atanh)	(double);
	float		(*atanhf)	(float);
	long double	(*atanhl)	(long double);

	// log and antilog function
	double		(*exp)		(double);
	float		(*expf)		(float);
	long double	(*expl)		(long double);
	double		(*exp2)		(double);
	float		(*exp2f)	(float);
	long double	(*exp2l)	(long double);
	double		(*expm1)	(double);
	float		(*expm1f)	(float);
	long double	(*expm1l)	(long double);
	double		(*frexp)	(double, int *);
	float		(*frexpf)	(float, int *);
	long double	(*frexpl)	(long double, int *);
	double		(*ldexp)	(double, int);
	float		(*ldexpf)	(float, int);
	long double	(*ldexpl)	(long double, int);
	double		(*log)		(double);
	float		(*logf)		(float);
	long double	(*logl)		(long double);
	double		(*log2)		(double);
	float		(*log2f)	(float);
	long double	(*log2l)	(long double);
	double		(*logb)		(double);
	float		(*logbf)	(float);
	long double	(*logbl)	(long double);
	int		(*ilogb)	(double);
	int		(*ilogbf)	(float);
	int		(*ilogbl)	(long double);
	double		(*log10)	(double);
	float		(*log10f)	(float);
	long double	(*log10l)	(long double);
	double		(*log1p)	(double);
	float		(*log1pf)	(float);
	long double	(*log1pl)	(long double);
	double		(*modf)		(double, double *);
	float		(*modff)	(float, float *);
	long double	(*modfl)	(long double, long double *);
	double		(*scalbn)	(double, int);
	float		(*scalbnf)	(float, int);
	long double	(*scalbnl)	(long double, int);
	double		(*scalbln)	(double, long);
	float		(*scalblnf)	(float, long);
	long double	(*scalblnl)	(long double, long);
};

// wide character type functions
#include <wctype.h>

struct cmods_libc_wtype {
	// casing
	union {
		wint_t	(*towlower)	(wint_t);
		wint_t	(*tolower)	(wint_t);
	};
	union {
		wint_t	(*towupper)	(wint_t);
		wint_t	(*toupper)	(wint_t);
	};

	// classification
	union {
		int	(*iswalnum)	(wint_t);
		int	(*isalnum)	(wint_t);
	};
	union {
		int	(*iswalpha)	(wint_t);
		int	(*isalpha)	(wint_t);
	};
	union {
		int	(*iswblank)	(wint_t);
		int	(*isblank)	(wint_t);
	};
	union {
		int	(*iswcntrl)	(wint_t);
		int	(*iscntrl)	(wint_t);
	};
	union {
		int	(*iswdigit)	(wint_t);
		int	(*isdigit)	(wint_t);
	};
	union {
		int	(*iswgraph)	(wint_t);
		int	(*isgraph)	(wint_t);
	};
	union {
		int	(*iswlower)	(wint_t);
		int	(*islower)	(wint_t);
	};
	union {
		int	(*iswprint)	(wint_t);
		int	(*isprint)	(wint_t);
	};
	union {
		int	(*iswpunct)	(wint_t);
		int	(*ispunct)	(wint_t);
	};
	union {
		int	(*iswspace)	(wint_t);
		int	(*isspace)	(wint_t);
	};
	union {
		int	(*iswupper)	(wint_t);
		int	(*isupper)	(wint_t);
	};
	union {
		int	(*iswxdigit)	(wint_t);
		int	(*isxdigit)	(wint_t);
	};

	// misc
	int		(*iswctype)	(wint_t, wctype_t);
	wint_t		(*towctrans)	(wint_t, wctrans_t);
	wctrans_t	(*wctrans)	(const char *);
	wctype_t	(*wctype)	(const char *);
};

// sets for wide chars
#include <wchar.h>

struct cmods_libc_wide_io {
	// general
	int	(*fwide)	(FILE *, int);

	// character IO
	union {
		wint_t	(*fgetwc)	(FILE *);
		wint_t	(*fgetc)	(FILE *);
	};
	union {
		wchar_t*	(*fgetws)	(wchar_t *, int, FILE *);
		wchar_t*	(*fgets)	(wchar_t *, int, FILE *);
	};
	union {
		wint_t	(*fputwc)	(wchar_t, FILE *);
		wint_t	(*fputc)	(wchar_t, FILE *);
	};
	union {
		int	(*fputws)	(const wchar_t *, FILE *);
		int	(*fputs)	(const wchar_t *, FILE *);
	};
	union {
		int	(*getwc)	(FILE *);
		int	(*getc)		(FILE *);
	};
	union {
		wint_t	(*getwchar)	(void);
		wint_t	(*getchar)	(void);
	};
	union {
		wint_t	(*putwc)	(wchar_t, FILE *);
		wint_t	(*putc)		(wchar_t, FILE *);
	};
	union {
		wint_t	(*putwchar)	(wchar_t);
		wint_t	(*putchar)	(wchar_t);
	};
	union {
		wint_t	(*ungetwc)	(wint_t, FILE *);
		wint_t	(*ungetc)	(wint_t, FILE *);
	};

	// printf
	union {
		int	(*wprintf)	(const wchar_t *, ...);
		int	(*printf)	(const wchar_t *, ...);
	};
	union {
		int	(*fwprintf)	(FILE *, const wchar_t *, ...);
		int	(*fprintf)	(FILE *, const wchar_t *, ...);
	};
	union {
		int	(*swprintf)	(wchar_t *, size_t, const wchar_t *, ...);
		int	(*sprintf)	(wchar_t *, size_t, const wchar_t *, ...);
	};
	union {
		int	(*vwprintf)	(const wchar_t *, va_list);
		int	(*vprintf)	(const wchar_t *, va_list);
	};
	union {
		int	(*vfwprintf)	(FILE *, const wchar_t *, va_list);
		int	(*vfprintf)	(FILE *, const wchar_t *, va_list);
	};
	union {
		int	(*vswprintf)	(wchar_t *, size_t, const wchar_t *, va_list);
		int	(*vsprintf)	(wchar_t *, size_t, const wchar_t *, va_list);
	};

	//scanf
	union {
		int	(*wscanf)	(const wchar_t *, ...);
		int	(*scanf)	(const wchar_t *, ...);
	};
	union {
		int	(*fwscanf)	(FILE *, const wchar_t *, ...);
		int	(*fscanf)	(FILE *, const wchar_t *, ...);
	};
	union {
		int	(*swscanf)	(const wchar_t *, const wchar_t *, ...);
		int	(*sscanf)	(const wchar_t *, const wchar_t *, ...);
	};
	union {
		int	(*vwscanf)	(const wchar_t *, va_list);
		int	(*vscanf)	(const wchar_t *, va_list);
	};
	union {
		int	(*vswscanf)	(const wchar_t *, const wchar_t *, va_list);
		int	(*vsscanf)	(const wchar_t *, const wchar_t *, va_list);
	};
};

struct cmods_libc_wide_lib {
	// string conversion
	double			(*wcstod)	(const wchar_t *, wchar_t **);
	float			(*wcstof)	(const wchar_t *, wchar_t **);
	long			(*wcstol)	(const wchar_t *, wchar_t **, int);
	long double		(*wcstold)	(const wchar_t *, wchar_t **);
	long long		(*wcstoll)	(const wchar_t *, wchar_t **, int);
	unsigned long		(*wcstoul)	(const wchar_t *, wchar_t **, int);
	unsigned long long	(*wcstoull)	(const wchar_t *, wchar_t **, int);

	// monobyte (ironic, I know)
	int	(*mbsinit)	(const mbstate_t *);
	size_t	(*mbrlen)	(const char *, size_t, mbstate_t *);
	size_t	(*mbrtowc)	(wchar_t *, const char *, size_t, mbstate_t *);
	size_t	(*mbsrtowcs)	(wchar_t *, const char **, size_t, mbstate_t *);
	int	(*wctob)	(wint_t);
	wint_t	(*btowc)	(int);
	size_t	(*wcsrtombs)	(char *, const wchar_t **, size_t, mbstate_t *);
	size_t	(*wcrtomb)	(char *, wchar_t, mbstate_t *);
};

struct cmods_libc_wide_string {
	// general
	union {
		size_t		(*wcslen)	(const wchar_t *);
		size_t		(*len)		(const wchar_t *);
	};
	union {
		wchar_t*	(*wcscat)	(wchar_t *, const wchar_t *);
		wchar_t*	(*cat)		(wchar_t *, const wchar_t *);
	};
	union {
		wchar_t*	(*wcsncat)	(wchar_t *, const wchar_t *, size_t);
		wchar_t*	(*ncat)		(wchar_t *, const wchar_t *, size_t);
	};
	union {
		size_t		(*wcsxfrm)	(wchar_t *, const wchar_t *, size_t);
		size_t		(*xfrm)		(wchar_t *, const wchar_t *, size_t);
	};

	// copying
	union {
		wchar_t*	(*wcscpy)	(wchar_t *, const wchar_t *);
		wchar_t*	(*cpy)		(wchar_t *, const wchar_t *);
	};
	union {
		wchar_t*	(*wcsncpy)	(wchar_t *, const wchar_t *, size_t);
		wchar_t*	(*ncpy)		(wchar_t *, const wchar_t *, size_t);
	};

	// comparison
	union {
		int	(*wcscmp)	(const wchar_t *, const wchar_t *);
		int	(*cmp)		(const wchar_t *, const wchar_t *);
	};
	union {
		int	(*wcsncmp)	(const wchar_t *, const wchar_t *, size_t);
		int	(*ncmp)		(const wchar_t *, const wchar_t *, size_t);
	};
	union {
		int	(*wcscoll)	(const wchar_t *, const wchar_t *);
		int	(*coll)		(const wchar_t *, const wchar_t *);
	};

	// searching
	union {
		wchar_t*	(*wcschr)	(const wchar_t *, wchar_t);
		wchar_t*	(*chr)		(const wchar_t *, wchar_t);
	};
	union {
		wchar_t*	(*wcsrchr)	(const wchar_t *, wchar_t);
		wchar_t*	(*rchr)		(const wchar_t *, wchar_t);
	};
	union {
		size_t		(*wcscspn)	(const wchar_t *, const wchar_t *);
		size_t		(*cspn)		(const wchar_t *, const wchar_t *);
	};
	union {
		size_t		(*wcsspn)	(const wchar_t *, const wchar_t *);
		size_t		(*spn)		(const wchar_t *, const wchar_t *);
	};
	union {
		wchar_t*	(*wcspbrk)	(const wchar_t *, const wchar_t *);
		wchar_t*	(*pbrk)		(const wchar_t *, const wchar_t *);
	};
	union {
		wchar_t*	(*wcsstr)	(const wchar_t *, const wchar_t *);
		wchar_t*	(*str)		(const wchar_t *, const wchar_t *);
	};
	union {
		wchar_t*	(*wcstok)	(wchar_t *, const wchar_t *);
		wchar_t*	(*tok)		(wchar_t *, const wchar_t *);
	};
};

struct cmods_libc_wide_mem {
	// general
	union {
		wchar_t*	(*wmemset)	(wchar_t *, wchar_t, size_t);
		wchar_t*	(*set)		(wchar_t *, wchar_t, size_t);
	};

	// copying
	union {
		wchar_t*	(*wmemcpy)	(wchar_t *, const wchar_t *, size_t);
		wchar_t*	(*cpy)		(wchar_t *, const wchar_t *, size_t);
	};
	union {
		wchar_t*	(*wmemmove)	(wchar_t *, const wchar_t *, size_t);
		wchar_t*	(*move)		(wchar_t *, const wchar_t *, size_t);
	};

	// comparison
	union {
		int	(*wmemcmp)	(const wchar_t *, const wchar_t *, size_t);
		int	(*cmp)		(const wchar_t *, const wchar_t *, size_t);
	};

	// searching
	union {
		wchar_t*	(*wmemchr)	(const wchar_t *, wchar_t, size_t);
		wchar_t*	(*wchr)		(const wchar_t *, wchar_t, size_t);
	};
};

struct cmods_libc_wide_time {
	size_t	(*wcsftime)	(wchar_t *, size_t, const wchar_t *, const struct tm *);
};
