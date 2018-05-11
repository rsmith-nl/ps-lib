% file: units.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
% Handy length units.
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>
% SPDX-License-Identifier: MIT
% Created: 2018-04-30T18:34:55+0200
% Last modified: 2018-05-11T10:27:01+0200

% set unit scale to 1 mm.
/mmscale {2.834645669291339 dup scale} bind def
% Convert numbers to mm. E.g: “2 mm”.
/mm {2.834645669291339 mul} bind def

% Set unit scale to 1 cm.
/cmscale {28.346456692913385 dup scale} bind def
% Convert numbers to cm.
/cm {28.346456692913385 mul} bind def

% Convert numbers to inch.
/in {72 mul} bind def
