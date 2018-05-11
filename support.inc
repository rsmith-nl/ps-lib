% file: support.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>.
% SPDX-License-Identifier: MIT
% Created: 2018-05-11T09:19:28+0200
% Last modified: 2018-05-11T10:08:38+0200

(units.inc) runlibfile

% Usage: x y support_clamped
/support_clamped {
    /y exch def /x exch def
    gsave
        newpath x y 10 mm sub moveto 0 20 mm rlineto -10 mm 0 rlineto
        0 -20 mm rlineto closepath
        .75 setgray fill
    grestore
    gsave
        newpath x y 10 mm sub moveto
        .5 mm setlinewidth 0 setgray
        0 20 mm rlineto stroke
    grestore
} bind def


% Usage: x y support_simple_fixed
/support_simple_fixed {
    /y exch def /x exch def
    gsave
        x y translate
        newpath -5 mm -5 mm moveto 10 mm 0 rlineto 0 -6 mm rlineto
        -10 mm 0 rlineto closepath .75 setgray fill
        newpath -5 mm -5 mm moveto 10 mm 0 rlineto -7.5 mm 0 rmoveto
        0 0 lineto 2.5 mm -5 mm lineto .5 mm setlinewidth 0 setgray stroke
    grestore
} bind def

% Usage: x y support_simple_roller
/support_simple_roller {
    /y exch def /x exch def
    gsave
        x y translate
        newpath -5 mm -8 mm moveto 10 mm 0 rlineto 0 -3 mm rlineto
        -10 mm 0 rlineto closepath .75 setgray fill
        newpath -5 mm -5 mm moveto 10 mm 0 rlineto -7.5 mm 0 rmoveto
        0 0 lineto 2.5 mm -5 mm lineto -5 mm -8 mm moveto 10 mm 0 rlineto
        .5 mm setlinewidth 0 setgray stroke
        -2.5 mm -6.5 mm 1.2 mm 0 360 arc closepath stroke
        2.5 mm -6.5 mm 1.2 mm 0 360 arc closepath stroke
    grestore
} bind def
