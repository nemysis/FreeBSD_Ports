# Created by: pgs
# $FreeBSD: head/graphics/hobbes-icons-xpm/Makefile 311027 2013-01-26 16:34:39Z dinoex $

PORTNAME=	hobbes-icons-xpm3
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTNAME=	${PORTNAME}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Collection of over 3000 icons in XPM3 format

NO_BUILD=	yes

# Where it will be installed (change pkg/PLIST if you change this)
LIBDIR=		${PREFIX}/include/X11/pixmaps

PORTDOCS=	README readem.shar

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${LIBDIR}
	${CP} -R ${WRKSRC}/* ${LIBDIR}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${LIBDIR}
	@(cd ${LIBDIR} && ${RM} README readem.shar)

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
