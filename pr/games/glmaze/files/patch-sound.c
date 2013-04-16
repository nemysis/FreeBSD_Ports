--- sound.c.orig	2001-11-16 13:22:36.000000000 +0100
+++ sound.c	2012-11-05 01:11:35.000000000 +0100
@@ -18,7 +18,7 @@
 #include "maze.h"
 
 #ifdef SOUND
-#include <SDL/SDL_mixer.h>
+#include <SDL_mixer.h>
 Mix_Chunk *sound[5];
 Mix_Music *music; 
 #endif
