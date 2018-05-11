% file: format.inc
% vim:fileencoding=utf-8:fdm=marker:ft=postscr
% Set ISO 216 page formats.
%
% Copyright © 2018 R.F. Smith <rsmith@xs4all.nl>.
% SPDX-License-Identifier: MIT
% Created: 2018-05-09T22:46:06+0200
% Last modified: 2018-05-11T10:24:10+0200

/format_A5_P { % P = portrait
<< /Pagesize [420 595] >> setpagedevice
} bind def

/format_A5_L { % L = landscape
<< /Pagesize [595 420] >> setpagedevice
} bind def

/format_A4_P {
<< /Pagesize [595 842] >> setpagedevice
} bind def

/format_A4_L {
<< /Pagesize [842 595] >> setpagedevice
} bind def

/format_A3_P {
<< /Pagesize [842 1191] >> setpagedevice
} bind def

/format_A3_L {
<< /Pagesize [1191 842] >> setpagedevice
} bind def

/format_A2_P {
<< /Pagesize [1191 1684] >> setpagedevice
} bind def

/format_A2_L {
<< /Pagesize [1684 1191] >> setpagedevice
} bind def

/format_A1_P {
<< /Pagesize [1684 2384] >> setpagedevice
} bind def

/format_A1_L {
<< /Pagesize [2384 1684] >> setpagedevice
} bind def

/format_A0_P {
<< /Pagesize [2384 3370] >> setpagedevice
} bind def

/format_A0_L {
<< /Pagesize [3370 2384] >> setpagedevice
} bind def
