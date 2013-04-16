# Created by: Bernhard Fröhlich <decke@bluelife.at>
# $FreeBSD: head/audio/vagalume/Makefile 315714 2013-04-03 21:00:33Z decke $

PORTNAME=	vagalume
PORTVERSION=	0.8.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://vagalume.igalia.com/files/source/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	GTK+-based client for the Last.fm online radio

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
USE_GSTREAMER=	good mad gconf
INSTALLS_ICONS=	yes

MAN1=		vagalume.1

OPTIONS_DEFINE=	DBUS TRAY NLS GCONF
OPTIONS_DEFAULT=	DBUS TRAY
TRAY_DESC=	Tray icon and libnotify support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDBUS}
CONFIGURE_ARGS+=--enable-dbus --enable-im-status
LIB_DEPENDS+=	dbus-glib:${PORTSDIR}/devel/dbus-glib
PLIST_SUB+=	DBUS=""
MAN1+=		vagalumectl.1
.else
CONFIGURE_ARGS+=--disable-dbus --disable-im-status
PLIST_SUB+=	DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MTRAY}
CONFIGURE_ARGS+=--enable-tray-icon
BUILD_DEPENDS+=	notify-send:${PORTSDIR}/devel/libnotify
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-tray-icon
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gconf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|serviceentrydir = @serviceentrydir@|serviceentrydir = ${PREFIX}/share/dbus-1/services|' \
		${WRKSRC}/Makefile.in
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|SUBDIRS = src po|SUBDIRS = src|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps
	@-update-desktop-database -q

.include <bsd.port.mk>
