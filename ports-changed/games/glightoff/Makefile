# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/glightoff/Makefile 309484 2012-12-25 14:28:20Z mva $

PORTNAME=	glightoff
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple (but not so easy to solve!) puzzle game

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils glib20 gtk20
USE_XORG=	x11

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-configure:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} 's|src po|src|' ${WRKSRC}/Makefile
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@-update-desktop-database -q

.include <bsd.port.mk>
