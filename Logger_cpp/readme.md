Description:
class log has three main functions:
LogE (errors) / LogW (warnings) / logV (verbosity)
Can output either using TCP/Console/file
Project need to follow this structure:
1/ Each class in a seperate file
2/ folder structure are as follow:
-Src
-header
-Main
-Makefile.sh
-----------------------

Class structure:

class Logger

Attributes:
error_color
warning_color
verbosity_color

constructor (Console by default )

methods
virtual printE
virtual printW
virtual printV
--------------------

class LoggerC :: Logger

methods
printE
printW
printV

------------


