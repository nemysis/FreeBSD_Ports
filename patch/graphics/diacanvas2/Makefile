# Created by: ijliao
# $FreeBSD: head/graphics/diacanvas2/Makefile 315433 2013-03-28 03:28:30Z eadler $

PORTNAME=	diacanvas2
PORTVERSION=	0.15.4
PORTREVISION=	4
CATEGORIES=	graphics gnome
MASTER_SITES=	SF/diacanvas/DiaCanvas2/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General drawing canvas from dia dialog editor

LICENSE=	GPLv2

USES=		pathfix
USE_GNOME=	pygnome2
USE_PYTHON=	2.2+
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_DISPLAY=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	APIDOCS=""
.else
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/garray.h|glib.h|' ${WRKSRC}/diacanvas/dia-canvas.c

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in
.endif

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|po diacanvas po |diacanvas |g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
