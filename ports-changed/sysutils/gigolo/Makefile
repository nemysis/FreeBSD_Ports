# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/sysutils/gigolo/Makefile 308356 2012-12-06 00:02:45Z jgh $

PORTNAME=	gigolo
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://files.uvena.de/gigolo/ \
		http://www.uvena.de/gigolo/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		network.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Frontend to easily manage filesystem connections

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USE_BZIP2=	yes
USE_GNOME=	gtk20 gvfs
USE_XORG=	x11
USE_PYTHON=	yes
USE_GETTEXT=	yes

MAN1=		gigolo.1

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO COPYING

.include <bsd.port.pre.mk>

.if ! exists(${LOCALBASE}/libexec/gvfs-fuse-daemon)
IGNORE=	Enable FUSE support in ${PORTSDIR}/devel/gvfs
.endif

# Only i386/amd64 due to limitations of fusefs-kmod
.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=	Does not compile on other than i386/amd64
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf configure --mandir=${PREFIX}/man

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install
	${INSTALL_DATA} ${_DISTDIR}/network.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.post.mk>
