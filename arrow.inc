% file: arrow.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>.
% SPDX-License-Identifier: MIT
% Created: 2018-05-11T20:24:17+0200
% Last modified: 2018-05-21T14:22:04+0200

% Inspired by edged.pds by Peter Kleiwweg from
% http://odur.let.rug.nl/kleiweg/postscript/postscript.html.
% However this a much simpler in that it only deals with straight arrows.

% This defines the length of the arrow-head.
/arrow_headsize 30 def

% Usage: x1 y1 x2 y2 arrow_head x3 y3
% Sees a line from x1,y1 to x2,y2 and draws an arrow head on the latter.
% Returns x3 y3, leaving it to the user to draw the line (x1,y1)--(x3,y3).
/arrow_head {
    9 dict begin
        /y2 exch def /x2 exch def /y1 exch def /x1 exch def
        /dx x2 x1 sub def /dy y2 y1 sub def /ang dy dx atan def
        /len dx dup mul dy dup mul add sqrt def
        /fact arrow_headsize len 0.8 div div def
        gsave
            x2 y2 translate ang rotate
            newpath 0 0 moveto arrow_headsize neg 4 {dup} repeat -.25 mul lineto
            .8 mul 0 lineto .25 mul lineto closepath fill
        grestore
        x2 dx fact mul sub y2 dy fact mul sub % inside of the arrowhead
    end
} bind def

% Usage: x1 y1 x2 y2 arrow
/arrow {
    2 dict begin
        /x1 4 index def /y1 3 index def
        arrow_head
        newpath moveto x1 y1 lineto stroke
    end
} bind def


% Usage: x y len downarrow
% Create arrow pointing down of length len with point at x,y
/downarrow {
    4 dict begin
        /len exch def /y exch def /x exch def
        /y2 y len add def
        x y2 x y arrow_head
        newpath moveto x y2 lineto stroke
    end
} bind def

% Usage: x y len uparrow
% Create arrow pointing up of length len with point at x,y
/uparrow {
    4 dict begin
        /len exch def /y exch def /x exch def
        /y2 y len sub def
        x y2 x y arrow_head
        newpath moveto x y2 lineto stroke
    end
} bind def

% Usage: x y len leftarrow
% Create arrow pointing left of length len with point at x,y
/leftarrow {
    4 dict begin
        /len exch def /y exch def /x exch def
        /x2 x len add def
        x2 y x y arrow_head
        newpath moveto x2 y lineto stroke
    end} bind def

% Usage: x y len rightarrow
% Create arrow pointing right of length len with point at x,y
/rightarrow {
    4 dict begin
        /len exch def /y exch def /x exch def
        /x2 x len sub def
        x2 y x y arrow_head
        newpath moveto x2 y lineto stroke
} bind def
