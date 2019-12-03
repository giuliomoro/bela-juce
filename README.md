An example project to use Juce with Bela. Currently requires [this](https://github.com/giuliomoro/JUCE/tree/fix/bela-fixes) JUCE branch.

The .projucer file comes with all the important flags already set. Here is a breakdown:
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

In the `juce_graphics`, `juce_gui_basics`, and `juce_gui_extra` modules (which are for some obscure reason still required) disable all disableable voices.

## Prerequisites:

Not sure exactly what I had to install. Probably at least:

```
libfreetype6-dev
libxext6-dev
libxinerama1-dev
libcurl4-openssl-dev
```

## Further notes:

If your Juce app requires a display, then it will be probably fail at runtime. You may find it useful to use a virtual X11 server, such as `xvfb`, although ideally someone that doesn't perform any computation at all would probably be a better option.