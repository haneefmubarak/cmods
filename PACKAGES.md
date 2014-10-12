packages
========

Here's a list of `cmods` packages:

 - [libc and libm](#c.h)

c.h
---

`c.h` provides functions from `libc` They are
sorted like so:

```
 - c
  - lib		- <stdlib.h>
  - io		- <stdio.h>
  - str		- <string.h> starting with 'str'
  - mem		- <string.h> starting with 'mem'
  - type	- <ctype.h>
  - locale	- <locale.h>
  - signal	- <signal.h>
  - time	- <time.h>
  - fenv	- <fenv.h>
  - math	- <math.h>

  - wide	- <wchar.h>
   - io
   - lib
   - str
   - mem
   - time
```

When using `c.h`, you will also need to link in
`libm`. This can be done via the `-lm` command line
switch with GCC or Clang.
