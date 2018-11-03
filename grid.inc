% file: grid.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
% Draw a grid to assist with composition of drawings.
% Designed to look like graph paper.
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>.
% SPDX-License-Identifier: MIT
% Created: 2018-04-30T18:54:21+0200
% Last modified: 2018-11-03T23:44:39+0100

% This is the color that the grid is drawn in.
/grid_major_color {1 .6 .6} def
/grid_color {.7 1 1} def
% The line width used for the grid.
/grid_major_lw 1.5 def
/grid_lw .5 def

% Every major-th line is drawn in a different color and thickness.
/major 10 def

% Usage: dx dy grid
% Draws a grid over the whole width and height of the page.
% Distances between vertical lines is dx, dy for horizontal lines.
/grid {
    5 dict begin
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
            grid_lw setlinewidth
            grid_color setrgbcolor
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
            newpath
            grid_major_lw setlinewidth
            grid_major_color setrgbcolor
            % every 10th line
            0 dx major mul w {
                0 moveto
                0 h rlineto
            } for
            0 dy major mul h {
                0 exch moveto
                w 0 rlineto
            } for
            stroke
        grestore
    end
} bind def

% Usage: dx dy w h gridwh
% Draw a grid over a supplied width and height
/gridwh {
  4 dict begin
    /h exch def
    /w exch def
    /dy exch def
    /dx exch def
    gsave
        % Set line width and color
        grid_lw setlinewidth
        grid_color setrgbcolor
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
        newpath
        grid_major_lw setlinewidth
        grid_major_color setrgbcolor
        % every 10th line
        0 dx major mul w {
            0 moveto
            0 h rlineto
        } for
        0 dy major mul h {
            0 exch moveto
            w 0 rlineto
        } for
        stroke
    grestore
  end
} bind def
