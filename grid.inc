% file: grid.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
% Draw a grid to assist with composition of drawings.
% Designed to look like graph paper.
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>.
% SPDX-License-Identifier: MIT
% Created: 2018-04-30T18:54:21+0200
% Last modified: 2018-05-11T13:58:03+0200

% Usage: “dx dy grid”
/grid {
    /dy exch def
    /dx exch def
    gsave
    % Get the page sizes
    /width  currentpagedevice /PageSize get 0 get def
    /height currentpagedevice /PageSize get 1 get def
    % Set line width and color
    .5 setlinewidth
    .7 1 1 setrgbcolor
    % draw
    newpath
    % vertical lines
    0 dx width {
        0 moveto
        0 height rlineto
    } for
    % horizontal lines
    0 dy height {
        0 exch moveto
        width 0 rlineto
    } for
    stroke
    grestore
} bind def
