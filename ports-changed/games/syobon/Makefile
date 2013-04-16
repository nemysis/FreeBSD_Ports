# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/syobon/Makefile 303158 2012-08-25 21:45:11Z jgh $

PORTNAME=	syobon
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://download.zapek.com/software/${PORTNAME}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}_${DISTVERSION}_src${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}_${DISTVERSION}_src${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Platform game as Super Mario Bros

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_DOS2UNIX=	*.txt
ALL_TARGET=	${PORTNAME}
USE_SDL=	sdl gfx image mixer ttf
MAKE_JOBS_SAFE=	yes

MAKE_ENV=	GAMEDATA="${DATADIR}"

PORTDOCS=	README.txt

DESKTOP_ENTRIES="Syobon Action" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "BGM SE res" ${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
