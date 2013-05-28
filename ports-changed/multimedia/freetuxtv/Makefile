# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/multimedia/freetuxtv/Makefile 319055 2013-05-25 14:37:02Z zeising $

PORTNAME=	freetuxtv
PORTVERSION=	0.6.5
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	nemysis@gmx.ch
COMMENT=	WebTV player based on GTK2+ and LibVLC

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	vlc:${PORTSDIR}/multimedia/vlc \
		dbus-glib:${PORTSDIR}/devel/dbus-glib \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		curl:${PORTSDIR}/ftp/curl \
		notify:${PORTSDIR}/devel/libnotify \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

USES=		iconv pkgconfig
USE_GNOME=	glib20 gtk20
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext xfixes \
		xi xinerama xrandr xrender
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gtk=2.0
USE_GMAKE=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${pkgdatadir}/doc|$${PREFIX}/share/doc/${PORTNAME}|' \
		-e 's|install-data-am: install-freetuxtvdocDATA|install-data-am: |' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(prefix)/$$(DATADIRNAME)/locale|$$(prefix)/share/locale|' \
		${WRKSRC}/po/Makefile.in.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
