My PostScript modules
#####################

:date: 2018-07-29
:tags: PostScript
:author: Roland Smith

.. Last modified: 2018-07-29T16:43:11+0200

Introduction
============

This repository is where I keep PostScript code that I want to be able to
re-use.

I have given these files the ``.inc`` extension to mark them as include files.

Using “include” files
=====================

The ``GS_LIB`` environment variable is used to make the files in this
directory available to ghostscript_.

.. _ghostscript: https://www.ghostscript.com/

Using these “include” files is simple, e.g:

.. code-block:: postscript

    (units.inc) runlibfile
    (grid.inc) runlibfile

    10 mm 10 mm grid


The modules
===========

align.inc
---------

Place text with different alignments.


arrow.inc
---------

Straight arrows


fonts.inc
---------

Shortcut for loading a font.


grid.inc
--------

Draws a grid. Helpful for interactive drawing.


import.inc
----------

Helps to import e.g. bitmaps and other EPS files.


short.inc
---------

Shortcuts for often used commands


support.inc
-----------

Drawing mechaninal supports. (simple and clamped)


units.inc
---------

Convert different units to PostScript points or set the unit scale to
different units.


x11colors.inc
-------------

A mechanical translation of the standard X11 colors to PostScript.
