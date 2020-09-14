## Makefile.am -- Process this file with automake to produce Makefile.in

# Include libtool macros
ACLOCAL_AMFLAGS = -I m4

# Additional C compiler flags
AM_CFLAGS = -Wall -Wextra

# Additional C++ compiler flags
AM_CXXFLAGS = -Wall -Wextra

# Additional linker flags
AM_LDFLAGS =

# PACStack full compiler flags
pacstack_full_CFLAGS = -mllvm -pacstack=full
pacstack_full_CXXFLAGS = ${pacstack_full_CFLAGS}

# PACStack nomask compiler flags
pacstack_nomask_CFLAGS = -mllvm -pacstack=nomask
pacstack_nomask_CXXFLAGS = ${pacstack_nomask_CFLAGS}

# PACStack dummy full compiler flags
pacstack_dummy_full_CFLAGS = -mllvm -pacstack=full -mllvm -aarch64-pacstack-dummy-pa
pacstack_dummy_full_CXXFLAGS = ${pacstack_dummy_full_CFLAGS}

# PACStack dummy nomask compiler flags
pacstack_dummy_nomask_CFLAGS = -mllvm -pacstack=nomask -mllvm -aarch64-pacstack-dummy-pa
pacstack_dummy_nomask_CXXFLAGS = ${pacstack_dummy_nomask_CFLAGS}

# Test executables
check_PROGRAMS =

# Include module-specific Makefiles
include tests/Makemodule.am

TESTS = $(check_PROGRAMS)
