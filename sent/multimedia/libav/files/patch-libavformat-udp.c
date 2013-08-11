--- libavformat/udp.c.orig	2013-07-06 15:14:38.000000000 +0200
+++ libavformat/udp.c	2013-08-08 14:40:08.000000000 +0200
@@ -40,6 +40,8 @@
 #define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
 #endif
 
+#define IPPROTO_IPV6 41
+
 typedef struct {
     int udp_fd;
     int ttl;
