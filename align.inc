% file: align.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
% Text with specified alignments.
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>.
% SPDX-License-Identifier: MIT
% Created: 2018-05-08T23:53:58+0200
% Last modified: 2018-05-11T10:23:16+0200

% Usage: (text) align_center
% Shows the text with the centre of the bounding box on the current position.
/align_center {
    /text exch def
    gsave newpath 0 0 moveto text false charpath pathbbox grestore
    /ury exch def /urx exch def /lly exch def /llx exch def
    % Place minus half the width on the stack
    llx urx sub 2 div
    % Place minus half the height on the stack
    lly ury sub 2 div
    % go to that point, show the text.
    rmoveto text show
} bind def

% Usage: (text) align_middle
% Shows the text with middle aligned on the current position.
/align_middle {
    /text exch def
    gsave newpath 0 0 moveto text false charpath pathbbox grestore
    /ury exch def /urx exch def /lly exch def /llx exch def
    % Place minus half the width on the stack
    llx urx sub 2 div
    % Place minus half the height on the stack
    0
    % go to that point, show the text.
    rmoveto text show
} bind def

% Usage: (text) align_right
% Shows the text right aligned on the current position.
/align_right {
    /text exch def
    gsave newpath 0 0 moveto text false charpath pathbbox grestore
    /ury exch def /urx exch def /lly exch def /llx exch def
    % Place minus the width on the stack as the x offset
    llx urx sub
    % Place 0 on the stack as the y offset
    0
    % Draw the text.
    rmoveto text show
} bind def
