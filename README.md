# PACStack Tests

This repository contains automated tests used for functional and regression
testing of PACStack instrumented binaries.

## Usage

PACStack uses the ARMv8.3-a PAuth extension and supports only AArch64 targets
with PAuth extension (e.g., `-march=armv8.3-a`). Consequently the testcases in
this repository have to be (cross-)compiled for AArch64 using the PACStack LLVM
toolchain available at [https://github.com/pacstack/pacstack-llvm](https://github.com/pacstack/pacstack-llvm).

Note that since LLVM project does not have implementations of all the parts of
toolchain and library dependencies it must be combined with a GCC cross compile
toolchain to provide missing components. The instructions here assume that the
Linaro toolchain (available at [https://www.linaro.org/downloads/](https://www.linaro.org/downloads/)) is installed
on host system.

Test binaries can be use executed using either ARM's [Armv8-A Architecture Fixed
Virtual Platform (FVP)](https://developer.arm.com/tools-and-software/simulation-models/fixed-virtual-platforms) simulation models, or the [QEMU](https://www.qemu.org/) machine emulator version
4.0 or newer. The instructions here assume QEMU and that binary formats for the
Aarch64 binaries have been registered with Linux so that it will be possible to
run foreign binaries directly. On Ubuntu and other Debian-based distributions
this can be achieved by installing the `qemu-user-static` deb package. 

The tests can be built using the PACStack LLVM & Linaro toolchain and ran using QEMU
as follows:
<pre>
$ git clone https://github.com/pointer-authentication/pacstack-tests
$ cd pacstack-tests
$ ./autogen.sh

$ ./configure --host=aarch64-unknown-linux-gnu \
    CC=<i>/path/to/pacstack/llvm/toolchain</i>/bin/clang \
    LDSHARED=<i>/path/to/pacstack/llvm/toolchain</i>/bin/clang \
    CFLAGS="--target=aarch64-linux-gnu --sysroot=<i>/path/to/linaro/sysroot</i> --gcc-toolchain=<i>/path/to/linaro/gcc</i>" \
    LDFLAGS="-Wl,--dynamic-linker=<i>/path/to/linaro/sysroot</i>/lib/ld-linux-aarch64.so.1"
    
$ make check TESTS_ENVIRONMENT=LD_LIBRARY_PATH=<i>/path/to/linaro/sysroot</i>/lib;"
</pre>

## Table of testcases

The following tests are currently implemented:

| Test | Description |
| --- | --- |
| `conftest` | Minimal _"Hello World"_ test for testing build configuration |
| `confirm_callback` | ConFIRM callback test |
| `confirm_convention` | ConFIRM C++ call convention test |
| `confirm_cppeh` | ConFIRM C++ exception handling test |
| `confirm_fptr` | ConFIRM function pointer test |
| `confirm_load_time_dynlnk` | ConFIRM load time dynamic linking test |
| `confirm_longjmp` | ConFIRM `setjmp` / `longjmp` test (from `unmatched_pair`) |
| `confirm_ret` | ConFIRM return branch test |
| `confirm_signal` | ConFIRM signal test |
| `confirm_switch` | ConFIRM switch case test |
| `confirm_tail_call` | ConFIRM tail call test |
| `confirm_vtable_call` | ConFIRM C++ vtable call test |

## Acknowledgements

Several tests included in this repository have been sourced from the [ConFIRM](https://github.com/SoftwareLanguagesSecurityLab/ConFIRM)
microbenchmarking suite for control-flow integrity relevance metrics originally
developed by the Software Languages Security Lab at the University of Texas at
Dallas. Licensed under the MIT license.

## License

> Copyright 2020 Aalto University Secure Systems Group
>
> Permission is hereby granted, free of charge, to any person obtaining a copy
> of this software and associated documentation files (the "Software"), to deal
> in the Software without restriction, including without limitation the rights
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
> copies of the Software, and to permit persons to whom the Software is
> furnished to do so, subject to the following conditions:
>
> The above copyright notice and this permission notice shall be included in all
> copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
> SOFTWARE.

