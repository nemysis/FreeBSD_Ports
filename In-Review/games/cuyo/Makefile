# Created by: Matthew Gibson <mdg583@hotmail.com>
# $FreeBSD: head/games/cuyo/Makefile 327730 2013-09-20 17:36:33Z bapt $

PORTNAME=	cuyo
PORTVERSION=	2.0.0
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Nice, innovative, challenging Tetris-like game

LICENSE=	GPLv2

LIB_DEPENDS=	libaa.so:${PORTSDIR}/graphics/aalib \
		libmikmod.so:${PORTSDIR}/audio/libmikmod

USES=		gmake iconv
GNU_CONFIGURE=	yes
USE_SDL=	mixer image
USE_XORG=	xdmcp xau x11
CFLAGS+=	-w

INSTALLS_ICONS=	yes

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/64x64/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
