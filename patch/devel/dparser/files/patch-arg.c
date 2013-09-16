--- arg.c.orig	2013-01-23 03:14:58.000000000 +0100
+++ arg.c	2013-09-12 19:38:48.000000000 +0200
@@ -40,7 +40,7 @@
           *(double *)desc[i].location = atof(arg);
           break;
         case 'L':
-          *(int64 *)desc[i].location = atoll(arg);
+          *(int64 *)desc[i].location = strtoll(arg,NULL,10);
           break;
         case 'S': strncpy((char *)desc[i].location,arg, atoi(desc[i].type+1));
           break;
