# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/patapizza-tetris/Makefile 304720 2012-09-22 20:01:11Z bsam $

PORTNAME=	patapizza-tetris
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://github.com/patapizza/tetris/downloads/
DISTNAME=	${PORTNAME:S/patapizza-//}-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Unofficial clone of the original Tetris game

LICENSE=	GPLv3

FETCH_ARGS?=	-Fpr
USE_GMAKE=	yes
USE_SDL=	sdl image gfx ttf

PORTDOCS=	README.md

SUB_FILES=	${PORTNAME}.sh

DESKTOP_ENTRIES="Patapizza Tetris" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
		-DDATA_PREFIX=\"${DATADIR}/\" \
		-lm `${SDL_CONFIG} --cflags --libs` -lSDL -lSDL_image -lSDL_gfx -lSDL_ttf -lm tetris.c

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} images ${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${DATADIR}
	${LN} -sf ${DATADIR}/images/logo.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
