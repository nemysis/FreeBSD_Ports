# Created by: ijliao
# $FreeBSD: head/graphics/diacanvas2/Makefile 318677 2013-05-21 11:35:49Z kwm $

PORTNAME=	diacanvas2
PORTVERSION=	0.15.4
PORTREVISION=	4
CATEGORIES=	graphics gnome
MASTER_SITES=	SF/diacanvas/DiaCanvas2/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General drawing canvas from dia dialog editor

LICENSE=	GPLv2

USES=		pathfix pkgconfig
USE_GNOME=	pygnome2
USE_PYTHON=	2.2+
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_DISPLAY=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	NLS PRINT
OPTIONS_DEFAULT=PRINT
PRINT_DESC=	GNOME print support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	APIDOCS=""
.else
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPRINT}
USE_GNOME+=	libgnomeprintui
CONFIGURE_ARGS+=--enable-gnome-print
.else
CONFIGURE_ARGS+=--disable-gnome-print
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in
.endif

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|po diacanvas po |diacanvas |g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
