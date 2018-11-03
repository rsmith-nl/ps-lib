% file: dim.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
% Dimensions
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>
% SPDX-License-Identifier: MIT
% Created: 2018-11-03T14:54:56+0100
% Last modified: 2018-11-03T21:19:44+0100

% Distance between dimension point and start of witness line
/dimoffs 6 def
% Distance that the witness line descends past the dimension line.
/dimext 20 def
% Font for dimensions
/dimfont /Alegraya-Regular def
% Font size
/dimscale 12 def
% dimension text offset
/dimtextoffs 12 def
% Dimension color
/dimcol {0 0 1 setrgbcolor} def
% This defines the length of the arrow-head.
/dimhead 30 def

% Usage: x1 y1 x2 y2 arrow_head x3 y3
% Sees a line from x1,y1 to x2,y2 and draws an arrow head on the latter.
% Returns x3 y3, leaving it to the user to draw the line (x1,y1)--(x3,y3).
/_arrow_head {
    9 dict begin
        /y2 exch def /x2 exch def /y1 exch def /x1 exch def
        /dx x2 x1 sub def /dy y2 y1 sub def /ang dy dx atan def
        /len dx dup mul dy dup mul add sqrt def
        /fact dimhead len 0.8 div div def
        gsave
            x2 y2 translate ang rotate
            newpath 0 0 moveto dimhead neg 4 {dup} repeat -.25 mul lineto
            .8 mul 0 lineto .25 mul lineto closepath fill
        grestore
        x2 dx fact mul sub y2 dy fact mul sub % inside of the arrowhead
    end
} bind def

% Usage: (text) _align_middle
/_align_middle {
    dup % (text) (text)
    stringwidth pop % (text) w
    -2 div 0 rmoveto show
} bind def

% Draw a horizontal dimension
% Usage x1 y1 x2 y2 offs (label) horizontal_dim
/horizontal_dim {
    9 dict begin
        /label exch def
        /offs exch def
        /y2 exch def
        /x2 exch def
        /y1 exch def
        /x1 exch def
        /q y1 offs add def
        offs 0 ge {
            /v y1 dimext add def
            /w y1 offs add dimext add def
        } {
            /v y1 dimext sub def
            /w y1 offs add dimext sub def
        } ifelse
        % Left witness line
        x1 v moveto x1 w lineto stroke
        % Right witness line
        x2 v moveto x2 w lineto stroke
        % arrow heads
        x2 q x1 q _arrow_head
        x1 q x2 q _arrow_head
        % Dimension line
        moveto lineto stroke
        x1 x2 add 2 div q dimtextoffs add moveto label _align_middle
    end
} bind def

% Draw a vertical dimension
% Usage x1 y1 x2 y2 offs (label) vertical_dim
/vertical_dim {
    9 dict begin
        /label exch def
        /offs exch def
        /y2 exch def
        /x2 exch def
        /y1 exch def
        /x1 exch def
        /q x1 offs add def
        offs 0 ge {
            /v x1 dimext add def
            /w x1 offs add dimext add def
        } {
            /v x1 dimext sub def
            /w x1 offs add dimext sub def
        } ifelse
        % Bottom witness line
        v y1 moveto w y1 lineto stroke
        % Top witness line
        v y2 moveto w y2 lineto stroke
        % arrow heads
        q y2 q y1 _arrow_head
        q y1 q y2 _arrow_head
        % Dimension line
        moveto lineto stroke
        % Rotated label
        q dimtextoffs sub y1 y2 add 2 div moveto
        gsave 90 rotate label _align_middle grestore
    end
} bind def

