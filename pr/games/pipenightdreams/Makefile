# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD: head/games/pipenightdreams/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	pipenightdreams
PORTVERSION=	0.10.0
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/pipenightdreams/packages/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Puzzle game similar to PipeMania

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_SDL=	image sdl
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN6=		pipenightdreams.6

PORTDOCS=	AUTHORS ChangeLog NEWS README

DESKTOP_ENTRIES="PipeNightDreams" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g; \
		s|SDL_LIBSS|SDL_LIBS|g; s|datadir/games|datadir|;' \
		${WRKSRC}/configure
	${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} 's|/games/|/|g; \
			s/^pipenightdreams_LDADD.+//g;'
	${REINPLACE_CMD} "s|/usr/share/games|${LOCALBASE}/share|g" \
		${WRKSRC}/src/main.cpp

post-install:
	${LN} -sf ${DATADIR}/images/default/splash.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
