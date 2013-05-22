# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	brickout
PORTVERSION=	2002.06.09
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/agenda/brickout/src/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Ball-and-paddle game where it's your objective to destroy bricks

LICENSE=	GPLv2

USE_GMAKE=	yes
ALL_TARGET=	host-sdl
USE_SDL=	image mixer sdl

PORTDOCS=	CHANGES.txt README.txt TODO.txt

INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="Brickout" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|brickout.sdl brickout.sdl|brickout brickout|' \
		-e 's|IMAGEDIR=images/|IMAGEDIR=${DATADIR}/images/|' \
		-e 's|IMAGEDIR=images-sdl/|IMAGEDIR=${DATADIR}/images-sdl/|' \
		-e 's|SOUNDDIR=sounds/|SOUNDDIR=${DATADIR}/sounds/|' \
		-e 's|MUSICDIR=music/|MUSICDIR=${DATADIR}/music/|' \
		-e 's|CFLAGS=-O2 -Wall -I/usr/include|CFLAGS+=-I${PREFIX}/include|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images images-sdl music sounds" ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
