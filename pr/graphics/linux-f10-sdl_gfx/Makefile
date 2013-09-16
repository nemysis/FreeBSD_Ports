# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_gfx
PORTVERSION=	2.0.16
CATEGORIES=	graphics linux
MASTER_SITES=	https://archives.fedoraproject.org/pub/archive/fedora/linux/releases/${LINUX_DIST_VER}/Everything/i386/os/Packages/ \
		http://ftp.rhd.ru/pub/fedora/linux/releases/${LINUX_DIST_VER}/Everything/i386/os/Packages/ \
		http://ftp.udl.es/pub/fedora/linux/releases/${LINUX_DIST_VER}/Everything/i386/os/Packages/
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	SDL graphics drawing primitives (Linux Fedora 10)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_NAME=	SDL_gfx
LINUX_DIST_VER=	10
RPMVERSION=	5.fc9
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libSDL_gfx.so usr/lib/libSDL_gfx.so.0 usr/lib/libSDL_gfx.so.0.0.16
PLIST_DIRSTRY=	usr/share/doc usr/share usr/lib usr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING LICENSE README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-install:
		@cd ${PREFIX}/usr/lib ; ${LN} -sf libSDL_gfx.so.0 libSDL_gfx.so

.include <bsd.port.mk>
