# x-ray-attenuation-tool

2017/01/31

This is a library and app that I ave been using for quick reference for x-ray attenuation coeffiecients.
It is written in QT (at least the GUI is) and C++14 - so you need to be able to handle that.  It compiles in Windows and Linux - just run qmake, then make.  I have not set it up to install anywhere (i.e. 'make install' does nothing).

There is a directory of data associated with the different elements - ./Xdat/ directory (it is zipped here).  The files with m-prefix have material data like density, atomic weight, atomic number.  The x-prefix siles have x-ray attenuation coeffcients from J. Hubbell and S.M. Seltzer.  The libraries are kind of a simplified C++ version of John Schweppe's mathematica library (http://library.wolfram.com/infocenter/TechNotes/4267/).  I rely on a simple linear interpolation in log-log space to fill in the curves - this has been most sufficient for my calcs.  The data files cover energy ranges of 1 keV to 20 MeV.  The GUI can parse formulas - and you can either put in a density or you can put -1 in the density field and it will approximate the densities as a mass fraction weighted sum -- this is, of course, not great but heck sometimes it is not bad.

The data files are text and can be edited without recompilation if you wish.

Once you compile you should set an environmental varible:

xmatPath = / the directory that holds the data files /

Again, it works with both windows and linux.

There might be bugs.  If you don't point to the data directory with the environmental variable it will complain.  In linux I keep the data in the /usr/local/share/Xdat/ director.

- Hugh.
