# TagLib Amalgamation

A distribution of the [TagLib](http://developer.kde.org/~wheeler/taglib.html/) library in amalgamated source
form. The amalgamation is built using the [Amalgamate](http://github.com/vinniefalco/Amalgamate/)
Tool.

## How does this help?

The amalgamated form of TagLib is designed to be added to your existing project or Makefile.
This makes it easier to integrate into your application, and easier to redistribute if you
are providing source code.

The standard distribution of TagLib contains many sources and headers, and arcane
macros that need to be set up in order to function correctly when statically
linked. This amalgamation eliminates those problems.

## How do I use it?

- Add the directory named "Include" to your include paths.
- Add the necessary .cpp files (or .mm files on OS X or iOS) from TagLibAmalgam.
- Use #include "TagLibAmalgam/TagLibAmalgam.h" where you want to use TagLib.
- Edit "TagLibConfig.h" to suit your needs.

### Terms and Conditions
The amalgamation uses the same license as [TagLib](http://developer.kde.org/~wheeler/taglib.html/)<br>
The author hereby releases all his public TagLib changes to the public domain.
