# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	sdl_ttf
PORTVERSION=	2.0.9
CATEGORIES=	graphics linux
MASTER_SITES=	https://archives.fedoraproject.org/pub/archive/fedora/linux/releases/${LINUX_DIST_VER}/Everything/i386/os/Packages/ \
		http://ftp.rhd.ru/pub/fedora/linux/releases/${LINUX_DIST_VER}/Everything/i386/os/Packages/ \
		http://ftp.udl.es/pub/fedora/linux/releases/${LINUX_DIST_VER}/Everything/i386/os/Packages/
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Library to use TrueType fonts in SDL applications (Linux Fedora 10)

CONFLICTS=	linux-sdl_ttf-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_NAME=	SDL_ttf
LINUX_DIST_VER=	10
RPMVERSION=	4.fc9
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libSDL_ttf-2.0.so usr/lib/libSDL_ttf-2.0.so.0 usr/lib/libSDL_ttf-2.0.so.0.6.3
PLIST_DIRSTRY=	usr/share/doc usr/share usr/lib usr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	CHANGES COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-install:
		@cd ${PREFIX}/usr/lib ; ${LN} -sf libSDL_ttf-2.0.so.0 libSDL_ttf-2.0.so

.include <bsd.port.mk>
