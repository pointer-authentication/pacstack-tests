## Makefile.am -- Process this file with automake to produce Makefile.in

# Include libtool macros
ACLOCAL_AMFLAGS = -I m4

# Additional C compiler flags
AM_CFLAGS = -Wall -Wextra

# PACStack full compiler flags
pacstack_full_CFLAGS = -mllvm -pacstack=full

# PACStack nomask compiler flags
pacstack_nomask_CFLAGS = -mllvm -pacstack=nomask

# PACStack dummy full compiler flags
pacstack_dummy_full_CFLAGS = -mllvm -pacstack=full -mllvm -aarch64-pacstack-dummy-pa

# PACStack dummy nomask compiler flags
pacstack_dummy_nomask_CFLAGS = -mllvm -pacstack=nomask -mllvm -aarch64-pacstack-dummy-pa

# Test executables
check_PROGRAMS =

# Include module-specific Makefiles
include tests/Makemodule.am

TESTS = $(check_PROGRAMS)
