% file: offset.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>.
% SPDX-License-Identifier: MIT
% Created: 2018-05-08T23:53:58+0200
% Last modified: 2018-05-09T00:17:52+0200

% Usage: (text) atmidpoint
% Shows the text with the centre of the bounding box on the current position.
/atmidpoint {
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
