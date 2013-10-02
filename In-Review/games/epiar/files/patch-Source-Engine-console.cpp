--- Source/Engine/console.cpp.orig	2012-10-27 10:18:51.000000000 +0200
+++ Source/Engine/console.cpp	2013-09-14 21:18:05.000000000 +0200
@@ -79,7 +79,6 @@
 					break;
 					case SDLK_RETURN:
 					case SDLK_KP_ENTER:
-					case '\n': // this shouldn't be necessary but on os x the two above it don't seem to catch
 						RunCommand();
 					break;
 					case SDLK_BACKSPACE:
