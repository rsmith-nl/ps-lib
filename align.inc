% file: align.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
% Text with specified alignments.
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>.
% SPDX-License-Identifier: MIT
% Created: 2018-05-08T23:53:58+0200
% Last modified: 2018-05-12T21:07:03+0200

% Usage: (text) align_center
% Shows the text with the centre of the bounding box on the current position.
/align_center {
    dup % (text) (text)
    gsave newpath 0 0 moveto
    false charpath pathbbox grestore % (text) llx lly urx ury
    4 -1 roll % (text) lly urx ury llx
    3 -1 roll % (text) lly ury llx urx
    sub 2 div % (text) lly ury (llx-urx)/2
    3 1 roll % (text) (llx-urx)/2 lly ury
    sub 2 div % (text) (llx-urx)/2 (lly-ury)/2
    rmoveto show
} bind def

% Usage: (text) align_middle
% Shows the text with middle aligned on the current position.
/align_middle {
    dup % (text) (text)
    stringwidth pop % (text) w
    -2 div 0 rmoveto show
} bind def

% Usage: (text) align_right
% Shows the text right aligned on the current position.
/align_right {
    dup % (text) (text)
    stringwidth pop % (text) w
    neg 0 rmoveto show
} bind def
