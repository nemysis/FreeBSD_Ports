--- ImathTest/testShear.cpp.orig	2013-02-04 19:22:35.000000000 +0100
+++ ImathTest/testShear.cpp	2013-06-08 02:21:40.000000000 +0200
@@ -54,7 +54,6 @@
 
     const float         epsilon = IMATH_INTERNAL_NAMESPACE::limits< float >::epsilon();
 
-    float    	        array[6] = { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F };
     IMATH_INTERNAL_NAMESPACE::Shear6f    	testConstructor1;
     IMATH_INTERNAL_NAMESPACE::Shear6f    	testConstructor2( testConstructor1 );
 
