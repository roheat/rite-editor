-------------------------------
           ABOUT
-------------------------------
'Mukt Editor' is a minimal text editor which runs on Linux. 
It is implemented using Gtk+2.0 and C programming language.


-------------------------------
           FEATURES
-------------------------------
1.  Save, Open and create a new file.
2.  Change font and search for occurrence of a string
3.  Cut, Copy and Paste text
4.  Display of line number and column number in status bar
5.  Custom Icon of the editor

-------------------------------
          REQUIREMENT
-------------------------------
1. libgtk2.0-dev ( $ sudo apt-get install build-essential libgtk2.0-dev )
2. gcc compiler

-------------------------------
         COMMAND TO RUN
-------------------------------

Compile :
---------
$ gcc editor.c -o editor `pkg-config --libs --cflags gtk+-2.0`

OR

$ make

Execute :
---------
$./editor

-------------------------------
        COPYRIGHT
-------------------------------
MADE BY ROHITH SRIVATHSAV
MIS : 111508059
SY IT S3 BATCH
# missal-pav
