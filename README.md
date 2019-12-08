An example project to use Juce with Bela. Currently requires [this](https://github.com/WeAreROLI/JUCE/tree/develop) JUCE branch.

The `.jucer` file comes with all the important flags already set. Here is a breakdown:
Exporters -> LinuxMakefile
- Extra preprocessor definitions:
```
__COBALT__
__COBALT_WRAP__
```
- Extra compiler flags:
```
-mtune=cortex-a8
-mfloat-abi=hard
-mfpu=neon
-ftree-vectorize
-I/root/Bela/include -I/root/Bela/include/legacy -I/root/Bela/ -I/usr/xenomai/include/cobalt -I/usr/xenomai/include
```
- Extra linker flags:
```
-L/root/Bela/lib  -L/usr/xenomai/lib
```
- External libraries to link:
```
bela
belaextra
cobalt
modechk
```

In the `juce_graphics`, `juce_gui_basics`, and `juce_gui_extra` modules (which are for some obscure reason still required) disable most of the disableable voices (not all of them, as some will cause trouble!). Also disable curl in `juce_core`.

## Prerequisites:

Not sure exactly what I had to install. Probably at least:

```
libfreetype6-dev
libxext6-dev
libxinerama1-dev
```

## Usage:

Get a copy of JUCE, open the `.jucer` file in your Projucer, set the appropriate paths for the LinuxMakefile export, and save. Copy all the relevant files to the board, cd to `Builds/LinuxMakefile` and run `make CONFIG=Release`.

## Further notes:

If your Juce app requires a display, then it will be probably fail at runtime. You may find it useful to use a virtual X11 server, such as `xvfb`, although ideally someone that doesn't perform any computation at all would probably be a better option.

The native build process is painfully slow. Using `distcc` helps making that faster, but still the linking stage is fairly slow. When building with `distcc` I recommend:
```
CXX=distcc-clang++ make V=1 TARGET_ARCH=-march=armv7-a CONFIG=Release
```

