% file: units.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
% Handy length units.
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>
% SPDX-License-Identifier: MIT
% Created: 2018-04-30T18:34:55+0200
% Last modified: 2018-05-20T14:11:08+0200

% set unit scale to 1 mm.
/mmscale {72 25.4 div dup scale} bind def
% Convert numbers to mm. E.g: “2 mm”.
/mm {72 mul 25.4 div} bind def

% Set unit scale to 1 cm.
/cmscale {72 2.54 div dup scale} bind def
% Convert numbers to cm.
/cm {72 mul 2.54 div} bind def

% Convert numbers to inch.
/in {72 mul} bind def
