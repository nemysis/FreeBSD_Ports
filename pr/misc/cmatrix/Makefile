# Created by: Andrey Zakhvatov
# $FreeBSD: head/misc/cmatrix/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	cmatrix
PORTVERSION=	1.2a
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Show a scrolling 'Matrix' like screen

LICENSE=	GPLv2

RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

FONTDIR=	${PREFIX}/lib/X11/fonts/misc

SUB_FILES=	pkg-deinstall

PLIST_FILES=	bin/cmatrix \
		${FONTDIR}/mtx.pcf
PLIST_DIRS=	${FONTDIR}

MAN1=		cmatrix.1

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/X11/fonts/misc|${FONTDIR}|' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/mtx.pcf ${FONTDIR}
	@(cd ${FONTDIR} ; mkfontdir)
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
