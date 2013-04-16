# Created by: Andrey Zakhvatov
# $FreeBSD: head/games/gemdropx/Makefile 304062 2012-09-10 19:52:36Z swills $

PORTNAME=	gemdropx
PORTVERSION=	0.9
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/gemdropx/src/ \
		ftp://ftp.billsgames.com/unix/x/gemdropx/src/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Interesting one-player puzzle game for X (SDL)

LICENSE=	GPLv2

ALL_TARGET=	${PORTNAME}
USE_SDL=	image mixer sdl

USE_GMAKE=	yes

PORTDOCS=	AUTHORS.txt CHANGES.txt ICON.txt README.txt TODO.txt

DESKTOP_ENTRIES="Gem Drop X" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
	-e 's|sdl-config|$(SDL_CONFIG)|' \
	-e 's|CC=gcc|CC?=g++|' \
	-e 's|CXX=gcc|CXX?=g++|' \
	-e 's|CFLAGS=-Wall $(SDL_CFLAGS)|CFLAGS+=$(SDL_CFLAGS)|' \
		${WRKSRC}/Makefile
	@${FIND} ${WRKDIR} -name .xvpics | ${XARGS} ${RM} -rf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "images sounds" ${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
