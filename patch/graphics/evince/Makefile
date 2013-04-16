# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD: head/graphics/evince/Makefile 300896 2012-07-14 13:54:48Z beat $
#    $MCom: ports/graphics/evince/Makefile,v 1.147 2010/09/28 07:27:12 kwm Exp $

PORTNAME=	evince
PORTVERSION=	2.32.0
PORTREVISION=	10
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 multi-format document viewer

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	poppler-glib:${PORTSDIR}/graphics/poppler-glib \
		spectre.1:${PORTSDIR}/print/libspectre
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		yelp:${PORTSDIR}/x11/yelp

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix desktopfileutils \
		gnomedocutils ltasneededhack gconf2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml
GCONF_SCHEMAS=	\
		evince-thumbnailer.schemas \
		evince-thumbnailer-ps.schemas

PLIST_SUB+=	VERSION=2.32

MAN1=		evince.1

PORTDOCS=	*

OPTIONS_DEFINE=	NLS DVI T1LIB NAUTILUS KEYRING DBUS COMICS IMPRESS DJVU

DVI_DESC=		Enable DVI viewer support
T1LIB_DESC=		Enable T1LIB for TYPE1 fonts to DVI (Enables DVI)
NAUTILUS_DESC=		Enable Nautilus plugin
KEYRING_DESC=		Enable Gnome-Keyring without Nautilus
COMICS_DESC=		Enable comic book archives support
IMPRESS_DESC=		Enable Impress presentations support
DJVU_DESC=		Enable DJVU support

OPTIONS_DEFAULT=	NAUTILUS KEYRING DBUS COMICS

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(PACKAGE_BUILDING) || exists(${LOCALBASE}/lib/libdbus-glib-1.so)
WITH_DBUS=	yes
.endif

.if ${PORT_OPTIONS:MDVI} || ${PORT_OPTIONS:MT1LIB} || exists(${LOCALBASE}/lib/libkpathsea.a)
BUILD_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base

CONFIGURE_ARGS+=	--enable-dvi
GCONF_SCHEMAS+=	evince-thumbnailer-dvi.schemas
PLIST_SUB+=		DVI=""
. if${PORT_OPTIONS:MT1LIB}
LIB_DEPENDS+=	t1.5:${PORTSDIR}/devel/t1lib

CONFIGURE_ARGS+=	--enable-t1lib
. endif
.else
PLIST_SUB+=		DVI="@comment "
.endif

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=		nautilus2
CONFIGURE_ARGS+=	--enable-nautilus
PLIST_SUB+=		NAUTILUS=""
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
RUN_DEPENDS+=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
.if ${PORT_OPTIONS:MKEYRING}
LIB_DEPENDS+=	gnome-keyring:${PORTSDIR}/security/libgnome-keyring
.else
CONFIGURE_ARGS+=	--without-keyring
.endif
CONFIGURE_ARGS+=	--disable-nautilus
PLIST_SUB+=		NAUTILUS="@comment "
.endif

.if ${PORT_OPTIONS:MIMPRESS}
CONFIGURE_ARGS+=	--enable-impress
PLIST_SUB+=		IMPRESS=""
.else
CONFIGURE_ARGS+=	--disable-impress
PLIST_SUB+=		IMPRESS="@comment "
.endif

.if ${PORT_OPTIONS:MDJVU}
LIB_DEPENDS+=		djvulibre:${PORTSDIR}/graphics/djvulibre
CONFIGURE_ARGS+=	--enable-djvu
GCONF_SCHEMAS+=		evince-thumbnailer-djvu.schemas
PLIST_SUB+=		DJVU=""
.else
CONFIGURE_ARGS+=	--disable-djvu
PLIST_SUB+=		DJVU="@comment "
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib:${PORTSDIR}/devel/dbus-glib
.endif

.if ${PORT_OPTIONS:MCOMICS}
RUN_DEPENDS+=		unzip:${PORTSDIR}/archivers/unzip
CONFIGURE_ARGS+=	--enable-comics
GCONF_SCHEMAS+=		evince-thumbnailer-comics.schemas
PLIST_SUB+=		COMICS=""
.else
CONFIGURE_ARGS+=	--disable-comics
PLIST_SUB+=		COMICS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g' \
		-e 's|" == "|" = "|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^DOC_MODULE_VERSION/d' \
		${WRKSRC}/help/reference/libdocument/Makefile.in \
		${WRKSRC}/help/reference/libview/Makefile.in

post-install:
	@-update-desktop-database -q

.include <bsd.port.post.mk>
