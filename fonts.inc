% file: fonts.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
% Helper for loading fonts.
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>
% SPDX-License-Identifier: MIT
% Created: 2018-05-20T22:15:05+0200
% Last modified: 2018-05-20T23:18:35+0200

% Usage: /name 12 font_set
/font_set {
    exch findfont exch scalefont setfont
} bind def
