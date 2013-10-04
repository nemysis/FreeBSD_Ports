--- src/bbsocket.c.orig	2013-04-23 17:29:23.000000000 +0200
+++ src/bbsocket.c	2013-04-24 13:37:22.000000000 +0200
@@ -48,7 +48,7 @@
 
 int socketConnect(char * address, int nonblock) {
   //create the socket itself
-  int sock = socket(PF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0);
+  int sock = socket(PF_UNIX, SOCK_STREAM, 0);
   if (sock < 0) {
     bb_log(LOG_ERR, "Could not create socket. Error: %s\n", strerror(errno));
     return -1;
@@ -172,7 +172,7 @@
   //delete the file currently there, if any
   unlink(address);
   //create the socket
-  int sock = socket(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0);
+  int sock = socket(AF_UNIX, SOCK_STREAM, 0);
   if (sock < 0) {
     bb_log(LOG_ERR, "Could not create socket! Error: %s\n", strerror(errno));
     return -1;
