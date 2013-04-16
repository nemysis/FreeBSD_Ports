# $FreeBSD: head/games/abuse_sdl/Makefile 304219 2012-09-13 14:17:00Z swills $

PORTNAME=	abuse_sdl
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	GENTOO/distfiles \
		http://abuse.zoy.org/raw-attachment/wiki/download/
DISTNAME=	abuse-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	SDL port of the Abuse game engine

LICENSE=	GPLv2

USE_GNOME=	gnomehack
USE_GL=		gl
USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-assetdir=${DATADIR} --enable-release
MAKE_JOBS_SAFE=	yes

MAN6=		abuse.6 abuse-tool.6

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

DESKTOP_ENTRIES="Abuse-SDL" "${COMMENT}" "abuse" \
		"abuse" "Game;StrategyGame;" ${FALSE}

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/abuse.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
