# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/sysutils/gigolo/Makefile 316464 2013-04-24 18:10:30Z ak $

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
USES=		gettext
USE_GNOME=	gtk20 gvfs
USE_XORG=	x11
USE_PYTHON=	yes

MAN1=		gigolo.1

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ! exists(${LOCALBASE}/libexec/gvfs-fuse-daemon)
IGNORE=	Enable FUSE support in ${PORTSDIR}/devel/gvfs
.endif

# Only i386/amd64 due to limitations of fusefs-kmod
.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=	Does not compile on other than i386/amd64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|COPYING ||' ${WRKSRC}/wscript

.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|bld.install_files|#bld.install_files|' ${WRKSRC}/wscript
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf configure --mandir=${PREFIX}/man

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install
	${INSTALL_DATA} ${_DISTDIR}/network.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
