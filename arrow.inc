% file: arrow.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>.
% SPDX-License-Identifier: MIT
% Created: 2018-05-11T20:24:17+0200
% Last modified: 2018-05-20T22:03:30+0200

% Inspired by edged.pds by Peter Kleiwweg from
% http://odur.let.rug.nl/kleiweg/postscript/postscript.html.
% However this a much simpler in that it only deals with straight arrows.

% This defines the length of the arrow-head.
/arrow_headsize 30 def

% Usage: x1 y1 x2 y2 arrow
% Draws a line from x1,y1 to x2,y2 and puts an arrow head on the latter.
/arrow {
    8 dict begin
        /y2 exch def /x2 exch def /y1 exch def /x1 exch def
        /dx x2 x1 sub def /dy y2 y1 sub def /ang dy dx atan def
        /len dx dup mul dy dup mul add sqrt def
        gsave
            x2 y2 translate ang rotate
            newpath len neg 0 moveto -0.8 arrow_headsize mul 0 lineto stroke
            newpath 0 0 moveto arrow_headsize neg 4 {dup} repeat -.25 mul lineto
            .8 mul 0 lineto .25 mul lineto closepath fill
        grestore
    end
} bind def

% Usage: x y len downarrow
% Create arrow pointing down of length len with point at x,y
/downarrow {
    1 index add % x y len+y
    2 index exch % x y x len+y
    4 2 roll % x len+y x y
    arrow
} bind def

% Usage: x y len uparrow
% Create arrow pointing up of length len with point at x,y
/uparrow {
    1 index exch sub % x y y-len
    2 index exch % x y x y-len
    4 2 roll % x y-len x y
    arrow
} bind def

% Usage: x y len leftarrow
% Create arrow pointing left of length len with point at x,y
/leftarrow {
    2 index add % x y len+x
    1 index % x y len+x y
    4 2 roll % x len+y x y
    arrow
} bind def

% Usage: x y len rightarrow
% Create arrow pointing right of length len with point at x,y
/rightarrow {
    2 index exch sub % x y x-len
    1 index % x y x-len y
    4 2 roll % x-len y x y
    arrow
} bind def
