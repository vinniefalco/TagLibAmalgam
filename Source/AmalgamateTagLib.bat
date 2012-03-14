@ECHO OFF
SET TOOL=..\..\..\Solutions\Amalgamate\Release\Amalgamate
SET SRCDIR=..\..\TagLib\taglib
SET DESTDIR=..\Include\TagLibAmalgam
SET OPTIONS=-i %SRCDIR% -w "*.c;*.cpp;*.h;*.hpp;*.tcc" -s ^
  -i %SRCDIR%\toolkit ^
  -i %SRCDIR%\asf ^
  -i %SRCDIR%\mpeg ^
  -i %SRCDIR%\ogg ^
  -i %SRCDIR%\ogg\flac ^
  -i %SRCDIR%\flac ^
  -i %SRCDIR%\mpc ^
  -i %SRCDIR%\mp4 ^
  -i %SRCDIR%\ogg\vorbis ^
  -i %SRCDIR%\ogg\speex ^
  -i %SRCDIR%\mpeg\id3v2 ^
  -i %SRCDIR%\mpeg\id3v2\frames ^
  -i %SRCDIR%\mpeg\id3v1 ^
  -i %SRCDIR%\ape ^
  -i %SRCDIR%\wavpack ^
  -i %SRCDIR%\trueaudio ^
  -i %SRCDIR%\riff ^
  -i %SRCDIR%\riff\aiff ^
  -i %SRCDIR%\riff\wav ^
  -i %SRCDIR%\mod ^
  -i %SRCDIR%\s3m ^
  -i %SRCDIR%\it ^
  -i %SRCDIR%\xm

%TOOL% %OPTIONS% TagLibAmalgamTemplate.h %DESTDIR%\TagLibAmalgam.h
%TOOL% %OPTIONS% TagLibAmalgamTemplate.cpp %DESTDIR%\TagLibAmalgam.cpp

..\..\..\..\TagLib\taglib\toolkit
..\..\..\..\TagLib\taglib\asf
..\..\..\..\TagLib\taglib\mpeg
..\..\..\..\TagLib\taglib\ogg
..\..\..\..\TagLib\taglib\ogg\flac
..\..\..\..\TagLib\taglib\flac
..\..\..\..\TagLib\taglib\mpc
..\..\..\..\TagLib\taglib\mp4
..\..\..\..\TagLib\taglib\ogg\vorbis
..\..\..\..\TagLib\taglib\ogg\speex
..\..\..\..\TagLib\taglib\mpeg\id3v2
..\..\..\..\TagLib\taglib\mpeg\id3v2\frames
..\..\..\..\TagLib\taglib\mpeg\id3v1
..\..\..\..\TagLib\taglib\ape
..\..\..\..\TagLib\taglib\wavpack
..\..\..\..\TagLib\taglib\trueaudio
..\..\..\..\TagLib\taglib\riff
..\..\..\..\TagLib\taglib\riff\aiff
..\..\..\..\TagLib\taglib\riff\wav
..\..\..\..\TagLib\taglib\mod
..\..\..\..\TagLib\taglib\s3m
..\..\..\..\TagLib\taglib\it
..\..\..\..\TagLib\taglib\xm
