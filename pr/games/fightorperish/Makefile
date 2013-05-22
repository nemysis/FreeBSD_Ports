# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	fightorperish
PORTVERSION=	0.5
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/fop/src/
DISTNAME=	fop-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Dungeon-crawling game

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/fop-${DISTVERSION}

USE_GMAKE=	yes
USE_SDL=	image mixer sdl
USES=		desktop-file-utils
MAKE_JOBS_SAFE=	yes

PORTDOCS=	CHANGES.txt README.txt TODO.txt

INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="Fight or Perish" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/data/|' \
		-e 's|char [256],|char [512],|' ${WRKSRC}/src/fop.c
	@${REINPLACE_CMD} -e 's|CFLAGS=-Wall -O2|CFLAGS+=|' \
		-e 's|SDL_CFLAGS=|SDL_CFLAGS+=|' \
		-e 's|SDL_LIBS=|SDL_LIBS+=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fop ${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "images maps sounds" ${DATADIR}/data)
	${LN} -sf ${WRKSRC}/data/images/title.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
