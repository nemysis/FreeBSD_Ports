--- addons/audio/pulseaudio.c.orig	2012-06-24 08:13:41.000000000 +0200
+++ addons/audio/pulseaudio.c	2012-10-09 00:54:07.000000000 +0200
@@ -22,7 +22,7 @@
 #include <pulse/error.h>
 #include <pulse/introspect.h>
 #include <pulse/mainloop.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 ALLEGRO_DEBUG_CHANNEL("PulseAudio")
 
