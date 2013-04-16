# Created by	nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	libsndfile
PORTVERSION=	1.0.20
CATEGORIES=	audio linux
MASTER_SITES=	https://archives.fedoraproject.org/pub/archive/fedora/linux/updates/${LINUX_DIST_VER}/i386/ \
		http://ftp.udl.es/pub/fedora/linux/updates/${LINUX_DIST_VER}/i386/
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Reading and writing files containing sampled sound (Linux Fedora 10)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	libvorbis
LINUX_DIST_VER=	10
RPMVERSION=	3.fc10
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-install:
		@cd ${PREFIX}/usr/lib ; ${LN} -sf libsndfile.so.1 libsndfile.so

.include <bsd.port.mk>
