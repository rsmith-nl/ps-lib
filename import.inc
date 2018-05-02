% file: import.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
%
% From appendix 7 of “Mathematical Illustrations”
% http://www.math.ubc.ca/~cass/graphics/manual/
%
% Created: 2018-04-30T18:16:58+0200
% Last modified: 2018-05-02T21:28:52+0200

% Usage example:
% begin_import
% x y moveto
% w y scale
% (bla) run
% end_import

/begin_import {
    % Save the current state
    save /savedstate exch def
    % Save the sizes of the two stacks
    count /opstacksize exch def
    /dictstacksize countdictstack def
    % Turn showpage off
    /showpage {} def
    % Set default graphics state
    0 setgray 0 setlinecap
    1 setlinewidth 0 setlinejoin
    10 setmiterlimit [] 0 setdash newpath
    /languagelevel where
    {pop languagelevel 1 ne
        {false setstrokeadjust false setoverprint} if
    } if
} bind def

/end_import {
    count opstacksize sub
    dup 0 gt { {pop} repeat } {pop} ifelse
    countdictstack dictstacksize sub
    dup 0 gt { {end} repeat } {pop} ifelse
    savedstate restore
} bind def
