# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/multimedia/freetuxtv/Makefile 336621 2013-12-16 11:11:09Z zeising $

PORTNAME=	freetuxtv
PORTVERSION=	0.6.6
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	WebTV and WebRadio player

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	libvlc.so:${PORTSDIR}/multimedia/vlc \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USES=		gmake iconv pathfix pkgconfig
USE_GNOME=	gtk20 cairo
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext xfixes \
		xi xinerama xrandr xrender
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gtk=2.0
CFLAGS=		-Wno-return-type
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|$${pkgdatadir}/doc|$${PREFIX}/share/doc/${PORTNAME}|' \
		-e 's|install-data-am: install-freetuxtvdocDATA|install-data-am: |' \
		${WRKSRC}/Makefile.in
# Fix for GTK2 r744
	@${REINPLACE_CMD} -e 's|box_new(GTK_ORIENTATION_VERTICAL|vbox_new(FALSE|' \
		${WRKSRC}/src/freetuxtv-player-error-dialog.c \
		${WRKSRC}/src/gtk-progress-dialog.c
	@${REINPLACE_CMD} -e 's|box_new(GTK_ORIENTATION_HORIZONTAL|hbox_new(FALSE|' \
		${WRKSRC}/src/gtk-date-time-picker.c

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
