--- src/core/osspec.c.orig	2013-08-11 12:39:35.000000000 +0200
+++ src/core/osspec.c	2013-09-28 18:58:38.000000000 +0200
@@ -615,7 +615,7 @@
     strcat(ilovesurge, "*"); /* example: "/home/alexandre/.opensurge/sprites/ *" */
 
     /* list the files matching the wildcard */
-    if(al_findfirst(wildcard, &info, FA_ALL & ~FA_LABEL & ~FA_DIREC) == 0) {
+    if(al_findfirst(wildcard, &info, FA_ALL/* & ~FA_LABEL & ~FA_DIREC*/) == 0) {
         do {
             if(!(info.attrib & FA_DIREC) && !(info.attrib & FA_LABEL)) { /* why do I need to check this? can't trust Allegro on this one? */
                 char *file = mallocx((strlen(current_dir) + strlen(info.name) + 1) * sizeof(*file));
@@ -629,7 +629,7 @@
     }
 
     /* look inside the directories, recursively */
-    if(al_findfirst(ilovesurge, &info, FA_DIREC) == 0) {
+    if(al_findfirst(ilovesurge, &info, FA_ALL/*FA_DIREC*/) == 0) { /* FA_DIREC doesn't work on BSD?? */
         do {
             if((info.attrib & FA_DIREC) && strcmp(info.name, "") != 0 && strcmp(info.name, ".") != 0 && strcmp(info.name, "..") != 0) {
                 char *new_wildcard = mallocx((strlen(current_dir) + strlen(info.name) + strlen(curinga) + 2) * sizeof(*new_wildcard));
