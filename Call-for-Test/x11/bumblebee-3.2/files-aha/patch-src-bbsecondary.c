--- src/bbsecondary.c.orig	2013-04-23 17:29:23.000000000 +0200
+++ src/bbsecondary.c	2013-04-24 15:03:09.000000000 +0200
@@ -166,7 +166,11 @@
     if (bb_status.x_pipe[0] != -1){close(bb_status.x_pipe[0]); bb_status.x_pipe[0] = -1;}
     if (bb_status.x_pipe[1] != -1){close(bb_status.x_pipe[1]); bb_status.x_pipe[1] = -1;}
     //create a new pipe
+#ifdef __FreeBSD__
+    if (pipe(bb_status.x_pipe)){
+#else
     if (pipe2(bb_status.x_pipe, O_NONBLOCK | O_CLOEXEC)){
+#endif
       set_bb_error("Could not create output pipe for X");
       return false;
     }
