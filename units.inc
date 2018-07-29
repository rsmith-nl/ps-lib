% file: units.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
% Handy length units.
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>
% SPDX-License-Identifier: MIT
% Created: 2018-04-30T18:34:55+0200
% Last modified: 2018-07-29T14:18:40+0200

% Usage: s mmscale
% Scales everything so that 1 unit equals 1 mm.
/mmscale {72 25.4 div dup scale} bind def

% Usage: x mm
% Converts the number x in mm to postscript points.
/mm {72 mul 25.4 div} bind def

% Usage: s cmscale
% Scales everything so that 1 unit equals 1 cm.
/cmscale {72 2.54 div dup scale} bind def

% Usage: x cm
% Converts the number x in cm to postscript points.
/cm {72 mul 2.54 div} bind def

% Usage: x in
% Convert the number x in inches to postscript points.
/in {72 mul} bind def
