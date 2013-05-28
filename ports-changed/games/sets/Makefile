# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/sets/Makefile 302851 2012-08-21 09:21:36Z jgh $

PORTNAME=	sets
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/sets/downloads/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Implementation of the sets game

LICENSE=	GPLv3

USE_SDL=	sdl image
USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README

DESKTOP_ENTRIES="Sets" "${COMMENT}" "${PORTNAME}" \
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
