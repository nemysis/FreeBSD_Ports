# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/puckman/Makefile 304631 2012-09-21 13:13:03Z bsam $

PORTNAME=	puckman
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://github.com/downloads/patapizza/puckman/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Unofficial clone of the original Pac-Man game

LICENSE=	GPLv3

FETCH_ARGS?=	-Fpr
USE_GMAKE=	yes
USE_SDL=	sdl image gfx

PORTDOCS=	README.md

DESKTOP_ENTRIES="Puck-Man" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
		-DDATA_PREFIX=\"${DATADIR}/\" \
		-lm `${SDL_CONFIG} --cflags --libs` -lSDL -lSDL_image -lSDL_gfx -lm puckman.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} images ${DATADIR})
	${LN} -sf ${DATADIR}/images/puckman.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
