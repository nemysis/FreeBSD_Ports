# Created by: Andrey Zakhvatov
# $FreeBSD: head/games/icbm3d/Makefile 304016 2012-09-10 02:53:42Z swills $

PORTNAME=	icbm3d
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/icbm3d/  \
		ftp://ftp.billsgames.com/unix/x/icbm3d/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}.${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}.${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Inter-Continental Ballistic Missiles, 3D

WRKSRC=		${WRKDIR}/icbm3d

USE_XORG=	x11
MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README.txt

DESKTOP_ENTRIES="Inter-Continental Ballistic Missiles, 3D" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
