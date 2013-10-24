# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/magicmaze/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	magicmaze
PORTVERSION=	1.4.3.6
PORTREVISION=	2
CATEGORIES=	games ruby
MASTER_SITES=	RUBYFORGE
DISTNAME=	${PORTNAME}-${DISTVERSION:S/./_/g}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Simple and low-tech monster-bashing maze game

LICENSE=	GPLv2

#RUN_DEPENDS=	ruby18-sdl>=0:${PORTSDIR}/devel/ruby-sdl

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/./_/g}

USE_SDL=	sdl image mixer
USE_RUBY=	yes
NO_BUILD=	yes

PORTDOCS=	*

SUB_FILES=	${PORTNAME}
SUB_LIST=	RUBY=${RUBY}

DESKTOP_ENTRIES="Magic Maze" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data magicmaze" ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKSRC}/*.rb ${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/data/gfx/icon.png
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${WRKSRC}/doc/BUGS.TXT ${WRKSRC}/doc/TODO.TXT ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
