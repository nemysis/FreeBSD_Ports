--- ./src/nvidia_subr.c.orig	2014-01-09 03:43:19.000000000 +0100
+++ ./src/nvidia_subr.c	2014-02-17 15:31:03.000000000 +0100
@@ -90,7 +90,7 @@
             if (!sc->BAR_objects[i])
                 goto failed;
 
-            VM_OBJECT_LOCK(sc->BAR_objects[i]);
+            VM_OBJECT_WLOCK(sc->BAR_objects[i]);
             switch (i) {
                 case NV_GPU_BAR_INDEX_FB:
                     vm_object_set_memattr(sc->BAR_objects[i],
@@ -102,7 +102,7 @@
                             VM_MEMATTR_UNCACHEABLE);
                     break;
             }
-            VM_OBJECT_UNLOCK(sc->BAR_objects[i]);
+            VM_OBJECT_WUNLOCK(sc->BAR_objects[i]);
         }
     }
 
@@ -545,9 +545,9 @@
             if (!sc->UD_object)
                 goto failed;
 
-            VM_OBJECT_LOCK(sc->UD_object);
+            VM_OBJECT_WLOCK(sc->UD_object);
             vm_object_set_memattr(sc->UD_object, VM_MEMATTR_UNCACHEABLE);
-            VM_OBJECT_UNLOCK(sc->UD_object);
+            VM_OBJECT_WUNLOCK(sc->UD_object);
         }
 
         nv->flags |= NV_FLAG_OPEN;
@@ -977,9 +977,9 @@
         goto failed;
     }
 
-    VM_OBJECT_LOCK(at->object);
+    VM_OBJECT_WLOCK(at->object);
     vm_object_set_memattr(at->object, attr);
-    VM_OBJECT_UNLOCK(at->object);
+    VM_OBJECT_WUNLOCK(at->object);
 
     *private = at;
     SLIST_INSERT_HEAD(&sc->alloc_list, at, list);
@@ -1120,9 +1120,9 @@
         goto failed;
     }
 
-    VM_OBJECT_LOCK(at->object);
+    VM_OBJECT_WLOCK(at->object);
     vm_object_set_memattr(at->object, attr);
-    VM_OBJECT_UNLOCK(at->object);
+    VM_OBJECT_WUNLOCK(at->object);
 
     *private = at;
     SLIST_INSERT_HEAD(&sc->alloc_list, at, list);
