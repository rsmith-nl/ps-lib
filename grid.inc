% file: grid.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
% Draw a grid to assist with composition of drawings.
% Designed to look like graph paper.
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>.
% SPDX-License-Identifier: MIT
% Created: 2018-04-30T18:54:21+0200
% Last modified: 2018-05-11T15:08:33+0200

% Usage: “dx dy grid”
/grid {
    /dy exch def
    /dx exch def
    gsave
    % Get the page sizes, keeping the orientation in mind.
    /orient currentpagedevice /Orientation get def
    orient 3 eq { % landscape
        /w currentpagedevice /PageSize get 1 get def
        /h currentpagedevice /PageSize get 0 get def
    } if
    orient 0 eq { % portrait
        /w currentpagedevice /PageSize get 0 get def
        /h currentpagedevice /PageSize get 1 get def
    } if
    % Set line width and color
    .5 setlinewidth
    .7 1 1 setrgbcolor
    % draw
    newpath
    % vertical lines
    dx dx w {
        0 moveto
        0 h rlineto
    } for
    % horizontal lines
    dy dy h {
        0 exch moveto
        w 0 rlineto
    } for
    stroke
    grestore
} bind def
