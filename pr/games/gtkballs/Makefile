# Created by: Andrey Zakhvatov
# $FreeBSD: head/games/gtkballs/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	gtkballs
PORTVERSION=	3.1.5
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://gtkballs.antex.ru/dist/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Lines-like simple logic game for X Window System

LICENSE=	GPLv2

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN6=		gtkballs.6x

PORTDOCS=	AUTHORS ChangeLog NEWS README README.russian TODO

OPTIONS_DEFINE=	DOCS NLS

DESKTOP_ENTRIES="GtkBalls" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} \
	-e 's|$$(INSTALL_DATA) COPYING $$(DESTDIR)$$(datadir)/gtkballs||' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/gnome-gtkballs.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
