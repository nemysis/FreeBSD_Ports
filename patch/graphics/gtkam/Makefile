# Created by: ports@FreeBSD.org
# $FreeBSD: head/graphics/gtkam/Makefile 314141 2013-03-14 08:17:39Z pclin $

PORTNAME=	gtkam
PORTVERSION=	0.2.0
CATEGORIES=	graphics
MASTER_SITES=	SF/gphoto/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Download and view files from various digital cameras

LICENSE=	GPLv2

LIB_DEPENDS=	exif-gtk.5:${PORTSDIR}/graphics/libexif-gtk \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2

WANT_GNOME=	yes
USE_GNOME=	gnomehack gnomehier gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gtkam.1

PORTDOCS=	AUTHORS CHANGES ChangeLog NEWS README TODO

OPTIONS_DEFINE=	GIMP NLS
GIMP_DESC=	GIMP plugin support

.include <bsd.port.pre.mk>

#.if ${PORT_OPTIONS:MGIMP}
#.if exists(${LOCALBASE}/lib/libgimp-2.0.so) && !defined(WITHOUT_GIMP)
#WITH_GIMP=	yes
#.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGIMP}
#gimp>0:${PORTSDIR}/graphics/gimp
LIB_DEPENDS+=	gimp-2.0:${PORTSDIR}/graphics/gimp
PLIST_SUB+=	GIMP=""
.else
CONFIGURE_ARGS+=	--without-gimp
PLIST_SUB+=	GIMP="@comment "
.endif

.if ${HAVE_GNOME:Mlibgnomeui}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	gnomeprefix libgnomeui
INSTALLS_OMF=	yes
MAKE_ENV+=	GNOME_SUBDIRS="help omf-install"
.else
CONFIGURE_ARGS+=	--without-bonobo --without-gnome
MAKE_ENV+=	GNOME_SUBDIRS=""
.endif

pre-everything::
#.if !defined(WITH_GIMP)
.if !  ${PORT_OPTIONS:MGIMP}
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with plugin for The GIMP,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_GIMP=yes\""
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|GIMP_VERSION="2.0"|GIMP_VERSION="2.6"|g ; \
		 s|images/gtkam|gtkam/images|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|images/gtkam|gtkam/images|g ; \
		 s|$$(libdir)/gimp/|$$(libexecdir)/gimp/|g'

post-install:
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gtkam.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gtkam.png ${PREFIX}/share/pixmaps
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
