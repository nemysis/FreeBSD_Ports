# Created by: Dominik Brettnacher <domi@nonsensss.de>
# $FreeBSD: head/graphics/xsane/Makefile 316464 2013-04-24 18:10:30Z ak $

PORTNAME=	xsane
PORTVERSION=	0.999
CATEGORIES=	graphics
MASTER_SITES=	http://www.xsane.org/download/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Gtk-based X11 frontend for SANE (Scanner Access Now Easy)

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		freetype:${PORTSDIR}/print/freetype2 \
		lcms.1:${PORTSDIR}/graphics/lcms
BUILD_DEPENDS=	scanimage:${PORTSDIR}/graphics/sane-backends
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		desktop-file-utils
USE_GNOME=	gtk20 gdkpixbuf2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		${PORTNAME}.1

PORTDOCS=	*.html *.jpg

OPTIONS_DEFINE=	GIMP NLS
GIMP_DESC=	GIMP plugin support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -lintl"
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGIMP}
SUB_FILES+=	pkg-message
RUN_DEPENDS+=	${LOCALBASE}/bin/gimp:${PORTSDIR}/graphics/gimp-app
CONFIGURE_ARGS+=--enable-gimp2
.else
CONFIGURE_ARGS+=--disable-gimp
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| $$(DESTDIR)$$(sbindir)||' \
		-e 's|$$(DESTDIR)$$(xsanedocdir)||' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|@POSUB@ doc|@POSUB@|' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.man ${MAN1PREFIX}/man/man1/${PORTNAME}.1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MGIMP}
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
