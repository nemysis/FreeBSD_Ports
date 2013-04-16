# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD: head/graphics/cairomm/Makefile 300896 2012-07-14 13:54:48Z beat $
#   $MCom: ports/graphics/cairomm/Makefile,v 1.19 2011/06/07 14:00:26 kwm Exp $

PORTNAME=	cairomm
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo

LICENSE=	LGPL20

LIB_DEPENDS=	xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26 \
		cairo.2:${PORTSDIR}/graphics/cairo

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	ltverhack
USES=		pathfix
CONFIGURE_ENV=	AUTOMAKE="${TRUE}" AUTOCONF="${TRUE}" DOXYGEN="${TRUE}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-1.0

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog MAINTAINERS NEWS README

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--disable-documentation

.else
post-configure:
	@${TOUCH} -f ${WRKSRC}/docs/reference/html/index.html
PLIST_FILES+=	share/devhelp/books/cairomm-1.0/cairomm-1.0.devhelp2
PLIST_DIRS+=	share/devhelp/books/cairomm-1.0
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
