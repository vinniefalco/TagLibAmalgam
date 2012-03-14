/*
 * This template is used to produce the amalgamated version of TagLib
 *
 */

#define TAGLIB_NO_CONFIG
#define MAKE_TAGLIB_LIB
#define TAGLIB_STATIC
#define WITH_ASF
#define WITH_MP4


/*** Start of inlined file: tag.h ***/
/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#ifndef TAGLIB_TAG_H
#define TAGLIB_TAG_H


/*** Start of inlined file: taglib_export.h ***/
/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#ifndef TAGLIB_EXPORT_H
#define TAGLIB_EXPORT_H

#if defined(TAGLIB_STATIC)
#define TAGLIB_EXPORT
#elif (defined(_WIN32) || defined(_WIN64))
#ifdef MAKE_TAGLIB_LIB
#define TAGLIB_EXPORT __declspec(dllexport)
#else
#define TAGLIB_EXPORT __declspec(dllimport)
#endif
#elif defined(__GNUC__) && (__GNUC__ > 4 || __GNUC__ == 4 && __GNUC_MINOR__ >= 1)
#define TAGLIB_EXPORT __attribute__ ((visibility("default")))
#else
#define TAGLIB_EXPORT
#endif

#ifndef TAGLIB_NO_CONFIG
#include "taglib_config.h"
#endif

#endif

/*** End of inlined file: taglib_export.h ***/


/*** Start of inlined file: tstring.h ***/
/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#ifndef TAGLIB_STRING_H
#define TAGLIB_STRING_H


/*** Start of inlined file: taglib.h ***/
/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#ifndef TAGLIB_H
#define TAGLIB_H

#define TAGLIB_MAJOR_VERSION 1
#define TAGLIB_MINOR_VERSION 7
#define TAGLIB_PATCH_VERSION 0

#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ > 1))
#define TAGLIB_IGNORE_MISSING_DESTRUCTOR _Pragma("GCC diagnostic ignored \"-Wnon-virtual-dtor\"")
#else
#define TAGLIB_IGNORE_MISSING_DESTRUCTOR
#endif

#if (defined(_MSC_VER) && _MSC_VER >= 1600)
#define TAGLIB_CONSTRUCT_BITSET(x) static_cast<unsigned long long>(x)
#else
#define TAGLIB_CONSTRUCT_BITSET(x) static_cast<unsigned long>(x)
#endif

#include <string>

#ifdef __APPLE__
#  include <libkern/OSAtomic.h>
#  define TAGLIB_ATOMIC_MAC
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#  define NOMINMAX
#  include <windows.h>
#  define TAGLIB_ATOMIC_WIN
#elif defined (__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ >= 401)    \
	  && (defined(__i386__) || defined(__i486__) || defined(__i586__) || \
		  defined(__i686__) || defined(__x86_64) || defined(__ia64)) \
	  && !defined(__INTEL_COMPILER)
#  define TAGLIB_ATOMIC_GCC
#elif defined(__ia64) && defined(__INTEL_COMPILER)
#  include <ia64intrin.h>
#  define TAGLIB_ATOMIC_GCC
#endif

//! A namespace for all TagLib related classes and functions

/*!
 * This namespace contains everything in TagLib.  For projects working with
 * TagLib extensively it may be convenient to add a
 * \code
 * using namespace TagLib;
 * \endcode
 */

namespace TagLib {

  class String;

  typedef wchar_t wchar;
  typedef unsigned char  uchar;
  typedef unsigned short ushort;
  typedef unsigned int   uint;
  typedef unsigned long  ulong;

  /*!
   * Unfortunately std::wstring isn't defined on some systems, (i.e. GCC < 3)
   * so I'm providing something here that should be constant.
   */
  typedef std::basic_string<wchar> wstring;

#ifndef DO_NOT_DOCUMENT // Tell Doxygen to skip this class.
  /*!
   * \internal
   * This is just used as a base class for shared classes in TagLib.
   *
   * \warning This <b>is not</b> part of the TagLib public API!
   */

  class RefCounter
  {
  public:
	RefCounter() : refCount(1) {}

#ifdef TAGLIB_ATOMIC_MAC
	void ref() { OSAtomicIncrement32Barrier(const_cast<int32_t*>(&refCount)); }
	bool deref() { return ! OSAtomicDecrement32Barrier(const_cast<int32_t*>(&refCount)); }
	int32_t count() { return refCount; }
  private:
	volatile int32_t refCount;
#elif defined(TAGLIB_ATOMIC_WIN)
	void ref() { InterlockedIncrement(&refCount); }
	bool deref() { return ! InterlockedDecrement(&refCount); }
	long count() { return refCount; }
  private:
	volatile long refCount;
#elif defined(TAGLIB_ATOMIC_GCC)
	void ref() { __sync_add_and_fetch(&refCount, 1); }
	bool deref() { return ! __sync_sub_and_fetch(&refCount, 1); }
	int count() { return refCount; }
  private:
	volatile int refCount;
#else
	void ref() { refCount++; }
	bool deref() { return ! --refCount; }
	int count() { return refCount; }
  private:
	uint refCount;
#endif

  };

#endif // DO_NOT_DOCUMENT

}

/*!
 * \mainpage TagLib
 *
 * \section intro Introduction
 *
 * TagLib is a library for reading and editing audio meta data, commonly know as \e tags.
 *
 * Features:
 * - A clean, high level, C++ API to handling audio meta data.
 * - Format specific APIs for advanced API users.
 * - ID3v1, ID3v2, APE, FLAC, Xiph, iTunes-style MP4 and WMA tag formats.
 * - MP3, MPC, FLAC, MP4, ASF, AIFF, WAV, TrueAudio, WavPack, Ogg FLAC, Ogg Vorbis and Speex file formats.
 * - Basic audio file properties such as length, sample rate, etc.
 * - Long term binary and source compatibility.
 * - Extensible design, notably the ability to add other formats or extend current formats as a library user.
 * - Full support for unicode and internationalized tags.
 * - Dual <a href="http://www.mozilla.org/MPL/MPL-1.1.html">MPL</a> and
 *   <a href="http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html">LGPL</a> licenses.
 * - No external toolkit dependancies.
 *
 * \section why Why TagLib?
 *
 * TagLib originally was written to provide an updated and improved ID3v2 implementation in C++ for use
 * in a variety of Open Source projects.  Since development began in 2002 and the 1.0 release in 2004
 * it has expanded to cover a wide variety of tag and file formats and is used in a wide variety of
 * Open Source and proprietary applications.  It now supports a variety of UNIXes, including Apple's OS
 * X, as well as Microsoft Windows.
 *
 * \section commercial Usage in Commercial Applications
 *
 * TagLib's licenses \e do allow usage within propriety (\e closed) applications, however TagLib is \e not
 * public domain.  Please note the requirements of the LGPL or MPL, and adhere to at least one of them.
 * In simple terms, you must at a minimum note your usage of TagLib, note the licensing terms of TagLib and
 * if you make changes to TagLib publish them.  Please review the licenses above before using TagLib in your
 * software.  Note that you may choose either the MPL or the LGPL, you do not have to fulfill the
 * requirements of both.
 *
 * \section installing Installing TagLib
 *
 * Please see the <a href="http://developer.kde.org/~wheeler/taglib.html">TagLib website</a> for the latest
 * downloads.
 *
 * TagLib can be built using the CMake build system. TagLib installs a taglib-config and pkg-config file to
 * make it easier to integrate into various build systems.  Note that TagLib's include install directory \e must
 * be included in the header include path. Simply adding <taglib/tag.h> will \e not work.
 *
 * \section start Getting Started
 *
 * TagLib provides both simple, abstract APIs which make it possible to ignore the differences between tagging
 * formats and format specific APIs which allow programmers to work with the features of specific tagging
 * schemes.  There is a similar abstraction mechanism for AudioProperties.
 *
 * The best place to start is with the <b>Class Hierarchy</b> linked at the top of the page.  The File and
 * AudioProperties classes and their subclasses are the core of TagLib.  The FileRef class is also a convenient
 * way for using a value-based handle.
 *
 * \note When working with FileRef please consider that it has only the most basic (extension-based) file
 * type resolution.  Please see its documentation on how to plug in more advanced file type resolution.  (Such
 * resolution may be part of later TagLib releases by default.)
 *
 * Here's a very simple example with TagLib:
 *
 * \code
 *
 * TagLib::FileRef f("Latex Solar Beef.mp3");
 * TagLib::String artist = f.tag()->artist(); // artist == "Frank Zappa"
 *
 * f.tag()->setAlbum("Fillmore East");
 * f.save();
 *
 * TagLib::FileRef g("Free City Rhymes.ogg");
 * TagLib::String album = g.tag()->album(); // album == "NYC Ghosts & Flowers"
 *
 * g.tag()->setTrack(1);
 * g.save();
 *
 * \endcode
 *
 * More examples can be found in the \e examples directory of the source distribution.
 *
 * \section Contact
 *
 * Questions about TagLib should be directed to the TagLib mailing list, not directly to the author.
 *
 *  - <a href="http://developer.kde.org/~wheeler/taglib/">TagLib Homepage</a>
 *  - <a href="https://mail.kde.org/mailman/listinfo/taglib-devel">TagLib Mailing List (taglib-devel@kde.org)</a>
 *
 * \author Scott Wheeler <wheeler@kde.org> et al.
 *
 */

#endif

/*** End of inlined file: taglib.h ***/


/*** Start of inlined file: tbytevector.h ***/
/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#ifndef TAGLIB_BYTEVECTOR_H
#define TAGLIB_BYTEVECTOR_H

#include <vector>
#include <ostream>

namespace TagLib {

  //! A byte vector

  /*!
   * This class provides a byte vector with some methods that are useful for
   * tagging purposes.  Many of the search functions are tailored to what is
   * useful for finding tag related paterns in a data array.
   */

  class TAGLIB_EXPORT ByteVector
  {
  public:
#ifndef DO_NOT_DOCUMENT
	typedef std::vector<char>::iterator Iterator;
	typedef std::vector<char>::const_iterator ConstIterator;
#endif

	/*!
	 * Constructs an empty byte vector.
	 */
	ByteVector();

	/*!
	 * Construct a vector of size \a size with all values set to \a value by
	 * default.
	 */
	ByteVector(uint size, char value = 0);

	/*!
	 * Contructs a byte vector that is a copy of \a v.
	 */
	ByteVector(const ByteVector &v);

	/*!
	 * Contructs a byte vector that contains \a c.
	 */
	ByteVector(char c);

	/*!
	 * Constructs a byte vector that copies \a data for up to \a length bytes.
	 */
	ByteVector(const char *data, uint length);

	/*!
	 * Constructs a byte vector that copies \a data up to the first null
	 * byte.  The behavior is undefined if \a data is not null terminated.
	 * This is particularly useful for constructing byte arrays from string
	 * constants.
	 */
	ByteVector(const char *data);

	/*!
	 * Destroys this ByteVector instance.
	 */
	virtual ~ByteVector();

	/*!
	 * Sets the data for the byte array using the first \a length bytes of \a data
	 */
	ByteVector &setData(const char *data, uint length);

	/*!
	 * Sets the data for the byte array copies \a data up to the first null
	 * byte.  The behavior is undefined if \a data is not null terminated.
	 */
	ByteVector &setData(const char *data);

	/*!
	 * Returns a pointer to the internal data structure.
	 *
	 * \warning Care should be taken when modifying this data structure as it is
	 * easy to corrupt the ByteVector when doing so.  Specifically, while the
	 * data may be changed, its length may not be.
	 */
	char *data();

	/*!
	 * Returns a pointer to the internal data structure which may not be modified.
	 */
	const char *data() const;

	/*!
	 * Returns a byte vector made up of the bytes starting at \a index and
	 * for \a length bytes.  If \a length is not specified it will return the bytes
	 * from \a index to the end of the vector.
	 */
	ByteVector mid(uint index, uint length = 0xffffffff) const;

	/*!
	 * This essentially performs the same as operator[](), but instead of causing
	 * a runtime error if the index is out of bounds, it will return a null byte.
	 */
	char at(uint index) const;

	/*!
	 * Searches the ByteVector for \a pattern starting at \a offset and returns
	 * the offset.  Returns -1 if the pattern was not found.  If \a byteAlign is
	 * specified the pattern will only be matched if it starts on a byte divisible
	 * by \a byteAlign (starting from \a offset).
	 */
	int find(const ByteVector &pattern, uint offset = 0, int byteAlign = 1) const;

	/*!
	 * Searches the ByteVector for \a pattern starting from either the end of the
	 * vector or \a offset and returns the offset.  Returns -1 if the pattern was
	 * not found.  If \a byteAlign is specified the pattern will only be matched
	 * if it starts on a byte divisible by \a byteAlign (starting from \a offset).
	 */
	int rfind(const ByteVector &pattern, uint offset = 0, int byteAlign = 1) const;

	/*!
	 * Checks to see if the vector contains the \a pattern starting at position
	 * \a offset.  Optionally, if you only want to search for part of the pattern
	 * you can specify an offset within the pattern to start from.  Also, you can
	 * specify to only check for the first \a patternLength bytes of \a pattern with
	 * the \a patternLength argument.
	 */
	bool containsAt(const ByteVector &pattern, uint offset, uint patternOffset = 0, uint patternLength = 0xffffffff) const;

	/*!
	 * Returns true if the vector starts with \a pattern.
	 */
	bool startsWith(const ByteVector &pattern) const;

	/*!
	 * Returns true if the vector ends with \a pattern.
	 */
	bool endsWith(const ByteVector &pattern) const;

	/*!
	 * Replaces \a pattern with \a with and returns a reference to the ByteVector
	 * after the operation.  This \e does modify the vector.
	 */
	ByteVector &replace(const ByteVector &pattern, const ByteVector &with);

	/*!
	 * Checks for a partial match of \a pattern at the end of the vector.  It
	 * returns the offset of the partial match within the vector, or -1 if the
	 * pattern is not found.  This method is particularly useful when searching for
	 * patterns that start in one vector and end in another.  When combined with
	 * startsWith() it can be used to find a pattern that overlaps two buffers.
	 *
	 * \note This will not match the complete pattern at the end of the string; use
	 * endsWith() for that.
	 */
	int endsWithPartialMatch(const ByteVector &pattern) const;

	/*!
	 * Appends \a v to the end of the ByteVector.
	 */
	ByteVector &append(const ByteVector &v);

	/*!
	 * Clears the data.
	 */
	ByteVector &clear();

	/*!
	 * Returns the size of the array.
	 */
	uint size() const;

	/*!
	 * Resize the vector to \a size.  If the vector is currently less than
	 * \a size, pad the remaining spaces with \a padding.  Returns a reference
	 * to the resized vector.
	 */
	ByteVector &resize(uint size, char padding = 0);

	/*!
	 * Returns an Iterator that points to the front of the vector.
	 */
	Iterator begin();

	/*!
	 * Returns a ConstIterator that points to the front of the vector.
	 */
	ConstIterator begin() const;

	/*!
	 * Returns an Iterator that points to the back of the vector.
	 */
	Iterator end();

	/*!
	 * Returns a ConstIterator that points to the back of the vector.
	 */
	ConstIterator end() const;

	/*!
	 * Returns true if the vector is null.
	 *
	 * \note A vector may be empty without being null.
	 * \see isEmpty()
	 */
	bool isNull() const;

	/*!
	 * Returns true if the ByteVector is empty.
	 *
	 * \see size()
	 * \see isNull()
	 */
	bool isEmpty() const;

	/*!
	 * Returns a CRC checksum of the byte vector's data.
	 */
	uint checksum() const;

	/*!
	 * Converts the first 4 bytes of the vector to an unsigned integer.
	 *
	 * If \a mostSignificantByteFirst is true this will operate left to right
	 * evaluating the integer.  For example if \a mostSignificantByteFirst is
	 * true then $00 $00 $00 $01 == 0x00000001 == 1, if false, $01 00 00 00 ==
	 * 0x01000000 == 1.
	 *
	 * \see fromUInt()
	 */
	uint toUInt(bool mostSignificantByteFirst = true) const;

	/*!
	 * Converts the first 2 bytes of the vector to a short.
	 *
	 * If \a mostSignificantByteFirst is true this will operate left to right
	 * evaluating the integer.  For example if \a mostSignificantByteFirst is
	 * true then $00 $01 == 0x0001 == 1, if false, $01 00 == 0x01000000 == 1.
	 *
	 * \see fromShort()
	 */
	short toShort(bool mostSignificantByteFirst = true) const;

	/*!
	 * Converts the first 2 bytes of the vector to a unsigned short.
	 *
	 * If \a mostSignificantByteFirst is true this will operate left to right
	 * evaluating the integer.  For example if \a mostSignificantByteFirst is
	 * true then $00 $01 == 0x0001 == 1, if false, $01 00 == 0x01000000 == 1.
	 *
	 * \see fromShort()
	 */
	unsigned short toUShort(bool mostSignificantByteFirst = true) const;

	/*!
	 * Converts the first 8 bytes of the vector to a (signed) long long.
	 *
	 * If \a mostSignificantByteFirst is true this will operate left to right
	 * evaluating the integer.  For example if \a mostSignificantByteFirst is
	 * true then $00 00 00 00 00 00 00 01 == 0x0000000000000001 == 1,
	 * if false, $01 00 00 00 00 00 00 00 == 0x0100000000000000 == 1.
	 *
	 * \see fromUInt()
	 */
	long long toLongLong(bool mostSignificantByteFirst = true) const;

	/*!
	 * Creates a 4 byte ByteVector based on \a value.  If
	 * \a mostSignificantByteFirst is true, then this will operate left to right
	 * in building the ByteVector.  For example if \a mostSignificantByteFirst is
	 * true then $00 00 00 01 == 0x00000001 == 1, if false, $01 00 00 00 ==
	 * 0x01000000 == 1.
	 *
	 * \see toUInt()
	 */
	static ByteVector fromUInt(uint value, bool mostSignificantByteFirst = true);

	/*!
	 * Creates a 2 byte ByteVector based on \a value.  If
	 * \a mostSignificantByteFirst is true, then this will operate left to right
	 * in building the ByteVector.  For example if \a mostSignificantByteFirst is
	 * true then $00 01 == 0x0001 == 1, if false, $01 00 == 0x0100 == 1.
	 *
	 * \see toShort()
	 */
	static ByteVector fromShort(short value, bool mostSignificantByteFirst = true);

	/*!
	 * Creates a 8 byte ByteVector based on \a value.  If
	 * \a mostSignificantByteFirst is true, then this will operate left to right
	 * in building the ByteVector.  For example if \a mostSignificantByteFirst is
	 * true then $00 00 00 01 == 0x0000000000000001 == 1, if false,
	 * $01 00 00 00 00 00 00 00 == 0x0100000000000000 == 1.
	 *
	 * \see toLongLong()
	 */
	static ByteVector fromLongLong(long long value, bool mostSignificantByteFirst = true);

	/*!
	 * Returns a ByteVector based on the CString \a s.
	 */
	static ByteVector fromCString(const char *s, uint length = 0xffffffff);

	/*!
	 * Returns a const refernence to the byte at \a index.
	 */
	const char &operator[](int index) const;

	/*!
	 * Returns a reference to the byte at \a index.
	 */
	char &operator[](int index);

	/*!
	 * Returns true if this ByteVector and \a v are equal.
	 */
	bool operator==(const ByteVector &v) const;

	/*!
	 * Returns true if this ByteVector and \a v are not equal.
	 */
	bool operator!=(const ByteVector &v) const;

	/*!
	 * Returns true if this ByteVector and the null terminated C string \a s
	 * contain the same data.
	 */
	bool operator==(const char *s) const;

	/*!
	 * Returns true if this ByteVector and the null terminated C string \a s
	 * do not contain the same data.
	 */
	bool operator!=(const char *s) const;

	/*!
	 * Returns true if this ByteVector is less than \a v.  The value of the
	 * vectors is determined by evaluating the character from left to right, and
	 * in the event one vector is a superset of the other, the size is used.
	 */
	bool operator<(const ByteVector &v) const;

	/*!
	 * Returns true if this ByteVector is greater than \a v.
	 */
	bool operator>(const ByteVector &v) const;

	/*!
	 * Returns a vector that is \a v appended to this vector.
	 */
	ByteVector operator+(const ByteVector &v) const;

	/*!
	 * Copies ByteVector \a v.
	 */
	ByteVector &operator=(const ByteVector &v);

	/*!
	 * Copies ByteVector \a v.
	 */
	ByteVector &operator=(char c);

	/*!
	 * Copies ByteVector \a v.
	 */
	ByteVector &operator=(const char *data);

	/*!
	 * A static, empty ByteVector which is convenient and fast (since returning
	 * an empty or "null" value does not require instantiating a new ByteVector).
	 */
	static ByteVector null;

	/*!
	 * Returns a hex-encoded copy of the byte vector.
	 */
	ByteVector toHex() const;

  protected:
	/*
	 * If this ByteVector is being shared via implicit sharing, do a deep copy
	 * of the data and separate from the shared members.  This should be called
	 * by all non-const subclass members.
	 */
	void detach();

  private:
	class ByteVectorPrivate;
	ByteVectorPrivate *d;
  };

}

/*!
 * \relates TagLib::ByteVector
 * Streams the ByteVector \a v to the output stream \a s.
 */
TAGLIB_EXPORT std::ostream &operator<<(std::ostream &s, const TagLib::ByteVector &v);

#endif

/*** End of inlined file: tbytevector.h ***/

#include <string>
#include <ostream>

/*!
 * \relates TagLib::String
 *
 * Converts a QString to a TagLib::String without a requirement to link to Qt.
 *
 * \note consider conversion via usual char-by-char for loop to avoid UTF16->UTF8->UTF16
 * conversion happening in the background
 */
#define QStringToTString(s) TagLib::String(s.utf8().data(), TagLib::String::UTF8)

/*!
 * \relates TagLib::String
 *
 * Converts a TagLib::String to a QString without a requirement to link to Qt.
 *
 * \note consider conversion via usual char-by-char for loop to avoid UTF16->UTF8->UTF16
 * conversion happening in the background
 *
 */
#define TStringToQString(s) QString::fromUtf8(s.toCString(true))

namespace TagLib {

  class StringList;

  //! A \e wide string class suitable for unicode.

  /*!
   * This is an implicitly shared \e wide string.  For storage it uses
   * TagLib::wstring, but as this is an <i>implementation detail</i> this of
   * course could change.  Strings are stored internally as UTF-16BE.  (Without
   * the BOM (Byte Order Mark)
   *
   * The use of implicit sharing means that copying a string is cheap, the only
   * \e cost comes into play when the copy is modified.  Prior to that the string
   * just has a pointer to the data of the \e parent String.  This also makes
   * this class suitable as a function return type.
   *
   * In addition to adding implicit sharing, this class keeps track of four
   * possible encodings, which are the four supported by the ID3v2 standard.
   */

  class TAGLIB_EXPORT String
  {
  public:

#ifndef DO_NOT_DOCUMENT
	typedef std::basic_string<wchar>::iterator Iterator;
	typedef std::basic_string<wchar>::const_iterator ConstIterator;
#endif

	/**
	 * The four types of string encodings supported by the ID3v2 specification.
	 * ID3v1 is assumed to be Latin1 and Ogg Vorbis comments use UTF8.
	 */
	enum Type {
	  /*!
	   * IS08859-1, or <i>Latin1</i> encoding.  8 bit characters.
	   */
	  Latin1 = 0,
	  /*!
	   * UTF16 with a <i>byte order mark</i>.  16 bit characters.
	   */
	  UTF16 = 1,
	  /*!
	   * UTF16 <i>big endian</i>.  16 bit characters.  This is the encoding used
	   * internally by TagLib.
	   */
	  UTF16BE = 2,
	  /*!
	   * UTF8 encoding.  Characters are usually 8 bits but can be up to 32.
	   */
	  UTF8 = 3,
	  /*!
	   * UTF16 <i>little endian</i>.  16 bit characters.
	   */
	  UTF16LE = 4
	};

	/*!
	 * Constructs an empty String.
	 */
	String();

	/*!
	 * Make a shallow, implicitly shared, copy of \a s.  Because this is
	 * implicitly shared, this method is lightweight and suitable for
	 * pass-by-value usage.
	 */
	String(const String &s);

	/*!
	 * Makes a deep copy of the data in \a s.
	 *
	 * \note This should only be used with the 8-bit codecs Latin1 and UTF8, when
	 * used with other codecs it will simply print a warning and exit.
	 */
	String(const std::string &s, Type t = Latin1);

	/*!
	 * Makes a deep copy of the data in \a s.
	 */
	String(const wstring &s, Type t = UTF16BE);

	/*!
	 * Makes a deep copy of the data in \a s.
	 */
	String(const wchar_t *s, Type t = UTF16BE);

	/*!
	 * Makes a deep copy of the data in \a c.
	 *
	 * \note This should only be used with the 8-bit codecs Latin1 and UTF8, when
	 * used with other codecs it will simply print a warning and exit.
	 */
	String(char c, Type t = Latin1);

	/*!
	 * Makes a deep copy of the data in \a c.
	 */
	String(wchar_t c, Type t = Latin1);

	/*!
	 * Makes a deep copy of the data in \a s.
	 *
	 * \note This should only be used with the 8-bit codecs Latin1 and UTF8, when
	 * used with other codecs it will simply print a warning and exit.
	 */
	String(const char *s, Type t = Latin1);

	/*!
	 * Makes a deep copy of the data in \a s.
	 *
	 * \note This should only be used with the 8-bit codecs Latin1 and UTF8, when
	 * used with other codecs it will simply print a warning and exit.
	 */
	String(const ByteVector &v, Type t = Latin1);

	/*!
	 * Destroys this String instance.
	 */
	virtual ~String();

	/*!
	 * If \a unicode if false (the default) this will return a \e Latin1 encoded
	 * std::string.  If it is true the returned std::wstring will be UTF-8
	 * encoded.
	 */
	std::string to8Bit(bool unicode = false) const;

	/*!
	 * Returns a wstring version of the TagLib string as a wide string.
	 */
	wstring toWString() const;

	/*!
	 * Creates and returns a C-String based on the data.  This string is still
	 * owned by the String (class) and as such should not be deleted by the user.
	 *
	 * If \a unicode if false (the default) this string will be encoded in
	 * \e Latin1.  If it is true the returned C-String will be UTF-8 encoded.
	 *
	 * This string remains valid until the String instance is destroyed or
	 * another export method is called.
	 *
	 * \warning This however has the side effect that this C-String will remain
	 * in memory <b>in addition to</b> other memory that is consumed by the
	 * String instance.  So, this method should not be used on large strings or
	 * where memory is critical.
	 */
	const char *toCString(bool unicode = false) const;

	/*!
	 * Returns an iterator pointing to the beginning of the string.
	 */
	Iterator begin();

	/*!
	 * Returns a const iterator pointing to the beginning of the string.
	 */
	ConstIterator begin() const;

	/*!
	 * Returns an iterator pointing to the end of the string (the position
	 * after the last character).
	 */
	Iterator end();

	/*!
	 * Returns a const iterator pointing to the end of the string (the position
	 * after the last character).
	 */
	ConstIterator end() const;

	/*!
	 * Finds the first occurrence of pattern \a s in this string starting from
	 * \a offset.  If the pattern is not found, -1 is returned.
	 */
	int find(const String &s, int offset = 0) const;

	/*!
	 * Finds the last occurrence of pattern \a s in this string, searched backwards,
	 * either from the end of the string or starting from \a offset. If the pattern
	 * is not found, -1 is returned.
	 */
	int rfind(const String &s, int offset = -1) const;

	/*!
	 * Splits the string on each occurrence of \a separator.
	 */
	StringList split(const String &separator = " ") const;

	/*!
	 * Returns true if the strings starts with the substring \a s.
	 */
	bool startsWith(const String &s) const;

	/*!
	 * Extract a substring from this string starting at \a position and
	 * continuing for \a n characters.
	 */
	String substr(uint position, uint n = 0xffffffff) const;

	/*!
	 * Append \a s to the current string and return a reference to the current
	 * string.
	 */
	String &append(const String &s);

	/*!
	 * Returns an upper case version of the string.
	 *
	 * \warning This only works for the characters in US-ASCII, i.e. A-Z.
	 */
	String upper() const;

	/*!
	 * Returns the size of the string.
	 */
	uint size() const;

	/*!
	 * Returns the length of the string.  Equivalent to size().
	 */
	uint length() const;

	/*!
	 * Returns true if the string is empty.
	 *
	 * \see isNull()
	 */
	bool isEmpty() const;

	/*!
	 * Returns true if this string is null -- i.e. it is a copy of the
	 * String::null string.
	 *
	 * \note A string can be empty and not null.
	 * \see isEmpty()
	 */
	bool isNull() const;

	/*!
	 * Returns a ByteVector containing the string's data.  If \a t is Latin1 or
	 * UTF8, this will return a vector of 8 bit characters, otherwise it will use
	 * 16 bit characters.
	 */
	ByteVector data(Type t) const;

	/*!
	 * Convert the string to an integer.
	 *
	 * Returns the integer if the conversion was successfull or 0 if the
	 * string does not represent a number.
	 */
	// BIC: merge with the method below
	int toInt() const;

	/*!
	 * Convert the string to an integer.
	 *
	 * If the conversion was successfull, it sets the value of \a *ok to
	 * true and returns the integer. Otherwise it sets \a *ok to false
	 * and the result is undefined.
	 */
	int toInt(bool *ok) const;

	/*!
	 * Returns a string with the leading and trailing whitespace stripped.
	 */
	String stripWhiteSpace() const;

	/*!
	 * Returns true if the file only uses characters required by Latin1.
	 */
	bool isLatin1() const;

	/*!
	 * Returns true if the file only uses characters required by (7-bit) ASCII.
	 */
	bool isAscii() const;

	/*!
	 * Converts the base-10 integer \a n to a string.
	 */
	static String number(int n);

	/*!
	 * Returns a reference to the character at position \a i.
	 */
	wchar &operator[](int i);

	/*!
	 * Returns a const reference to the character at position \a i.
	 */
	const wchar &operator[](int i) const;

	/*!
	 * Compares each character of the String with each character of \a s and
	 * returns true if the strings match.
	 */
	bool operator==(const String &s) const;

	/*!
	 * Compares each character of the String with each character of \a s and
	 * returns false if the strings match.
	 */
	bool operator!=(const String &s) const;

	/*!
	 * Appends \a s to the end of the String.
	 */
	String &operator+=(const String &s);

	/*!
	 * Appends \a s to the end of the String.
	 */
	String &operator+=(const wchar_t* s);

	/*!
	 * Appends \a s to the end of the String.
	 */
	String &operator+=(const char* s);

	/*!
	 * Appends \a s to the end of the String.
	 */
	String &operator+=(wchar_t c);

	/*!
	 * Appends \a c to the end of the String.
	 */
	String &operator+=(char c);

	/*!
	 * Performs a shallow, implicitly shared, copy of \a s, overwriting the
	 * String's current data.
	 */
	String &operator=(const String &s);

	/*!
	 * Performs a deep copy of the data in \a s.
	 */
	String &operator=(const std::string &s);

	/*!
	 * Performs a deep copy of the data in \a s.
	 */
	String &operator=(const wstring &s);

	/*!
	 * Performs a deep copy of the data in \a s.
	 */
	String &operator=(const wchar_t *s);

	/*!
	 * Performs a deep copy of the data in \a s.
	 */
	String &operator=(char c);

	/*!
	 * Performs a deep copy of the data in \a s.
	 */
	String &operator=(wchar_t c);

	/*!
	 * Performs a deep copy of the data in \a s.
	 */
	String &operator=(const char *s);

	/*!
	 * Performs a deep copy of the data in \a v.
	 */
	String &operator=(const ByteVector &v);

	/*!
	 * To be able to use this class in a Map, this operator needed to be
	 * implemented.  Returns true if \a s is less than this string in a bytewise
	 * comparison.
	 */
	bool operator<(const String &s) const;

	/*!
	 * A null string provided for convenience.
	 */
	static String null;

  protected:
	/*!
	 * If this String is being shared via implicit sharing, do a deep copy of the
	 * data and separate from the shared members.  This should be called by all
	 * non-const subclass members.
	 */
	void detach();

  private:
	/*!
	 * This checks to see if the string is in \e UTF-16 (with BOM) or \e UTF-8
	 * format and if so converts it to \e UTF-16BE for internal use.  \e Latin1
	 * does not require conversion since it is a subset of \e UTF-16BE and
	 * \e UTF16-BE requires no conversion since it is used internally.
	 */
	void prepare(Type t);

	class StringPrivate;
	StringPrivate *d;
  };

}

/*!
 * \relates TagLib::String
 *
 * Concatenates \a s1 and \a s2 and returns the result as a string.
 */
TAGLIB_EXPORT const TagLib::String operator+(const TagLib::String &s1, const TagLib::String &s2);

/*!
 * \relates TagLib::String
 *
 * Concatenates \a s1 and \a s2 and returns the result as a string.
 */
TAGLIB_EXPORT const TagLib::String operator+(const char *s1, const TagLib::String &s2);

/*!
 * \relates TagLib::String
 *
 * Concatenates \a s1 and \a s2 and returns the result as a string.
 */
TAGLIB_EXPORT const TagLib::String operator+(const TagLib::String &s1, const char *s2);

/*!
 * \relates TagLib::String
 *
 * Send the string to an output stream.
 */
TAGLIB_EXPORT std::ostream &operator<<(std::ostream &s, const TagLib::String &str);

#endif

/*** End of inlined file: tstring.h ***/

namespace TagLib {

  //! A simple, generic interface to common audio meta data fields

  /*!
   * This is an attempt to abstract away the difference in the meta data formats
   * of various audio codecs and tagging schemes.  As such it is generally a
   * subset of what is available in the specific formats but should be suitable
   * for most applications.  This is meant to compliment the generic APIs found
   * in TagLib::AudioProperties, TagLib::File and TagLib::FileRef.
   */

  class TAGLIB_EXPORT Tag
  {
  public:

	/*!
	 * Detroys this Tag instance.
	 */
	virtual ~Tag();

	/*!
	 * Returns the track name; if no track name is present in the tag
	 * String::null will be returned.
	 */
	virtual String title() const = 0;

	/*!
	 * Returns the artist name; if no artist name is present in the tag
	 * String::null will be returned.
	 */
	virtual String artist() const = 0;

	/*!
	 * Returns the album name; if no album name is present in the tag
	 * String::null will be returned.
	 */
	virtual String album() const = 0;

	/*!
	 * Returns the track comment; if no comment is present in the tag
	 * String::null will be returned.
	 */
	virtual String comment() const = 0;

	/*!
	 * Returns the genre name; if no genre is present in the tag String::null
	 * will be returned.
	 */
	virtual String genre() const = 0;

	/*!
	 * Returns the year; if there is no year set, this will return 0.
	 */
	virtual uint year() const = 0;

	/*!
	 * Returns the track number; if there is no track number set, this will
	 * return 0.
	 */
	virtual uint track() const = 0;

	/*!
	 * Sets the title to \a s.  If \a s is String::null then this value will be
	 * cleared.
	 */
	virtual void setTitle(const String &s) = 0;

	/*!
	 * Sets the artist to \a s.  If \a s is String::null then this value will be
	 * cleared.
	 */
	virtual void setArtist(const String &s) = 0;

	/*!
	 * Sets the album to \a s.  If \a s is String::null then this value will be
	 * cleared.
	 */
	virtual void setAlbum(const String &s) = 0;

	/*!
	 * Sets the comment to \a s.  If \a s is String::null then this value will be
	 * cleared.
	 */
	virtual void setComment(const String &s) = 0;

	/*!
	 * Sets the genre to \a s.  If \a s is String::null then this value will be
	 * cleared.  For tag formats that use a fixed set of genres, the appropriate
	 * value will be selected based on a string comparison.  A list of available
	 * genres for those formats should be available in that type's
	 * implementation.
	 */
	virtual void setGenre(const String &s) = 0;

	/*!
	 * Sets the year to \a i.  If \a s is 0 then this value will be cleared.
	 */
	virtual void setYear(uint i) = 0;

	/*!
	 * Sets the track to \a i.  If \a s is 0 then this value will be cleared.
	 */
	virtual void setTrack(uint i) = 0;

	/*!
	 * Returns true if the tag does not contain any data.  This should be
	 * reimplemented in subclasses that provide more than the basic tagging
	 * abilities in this class.
	 */
	virtual bool isEmpty() const;

	/*!
	 * Copies the generic data from one tag to another.
	 *
	 * \note This will no affect any of the lower level details of the tag.  For
	 * instance if any of the tag type specific data (maybe a URL for a band) is
	 * set, this will not modify or copy that.  This just copies using the API
	 * in this class.
	 *
	 * If \a overwrite is true then the values will be unconditionally copied.
	 * If false only empty values will be overwritten.
	 */
	static void duplicate(const Tag *source, Tag *target, bool overwrite = true);

  protected:
	/*!
	 * Construct a Tag.  This is protected since tags should only be instantiated
	 * through subclasses.
	 */
	Tag();

  private:
	Tag(const Tag &);
	Tag &operator=(const Tag &);

	class TagPrivate;
	TagPrivate *d;
  };
}

#endif

/*** End of inlined file: tag.h ***/

