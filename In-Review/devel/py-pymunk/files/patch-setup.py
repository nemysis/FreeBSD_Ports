--- setup.py.orig	2013-10-01 15:14:37.000000000 +0200
+++ setup.py	2013-10-01 15:16:19.000000000 +0200
@@ -59,7 +59,7 @@
             compiler_preargs += ['-m64', '-O3']
         elif arch == 32 and platform.system() == 'Linux':
             compiler_preargs += ['-m32', '-O3']
-        elif platform.system() == 'Darwin':
+        elif platform.system() == ('Darwin', 'FreeBSD'):
             #No -O3 on OSX. There's a bug in the clang compiler when using O3.
             compiler_preargs += ['-arch', 'i386', '-arch', 'x86_64']
         
@@ -87,9 +87,9 @@
         objs = compiler.compile(sources, include_dirs=include_folders, extra_preargs=compiler_preargs)
         
         libname = 'chipmunk'
-        if arch == 64 and platform.system() != 'Darwin':
+        if arch == 64 and platform.system() != ('Darwin', 'FreeBSD'):
             libname += '64'
-        if platform.system() == 'Darwin':
+        if platform.system() == ('Darwin', 'FreeBSD'):
             libname = compiler.library_filename(libname, lib_type='dylib')
             compiler.set_executable('linker_so', ['cc', '-dynamiclib', '-arch', 'i386', '-arch', 'x86_64'])
         else:
