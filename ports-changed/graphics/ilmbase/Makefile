# Created by: nork@FreeBSD.org
# $FreeBSD: head/graphics/ilmbase/Makefile 312101 2013-02-12 11:33:04Z bapt $

PORTNAME=	ilmbase
PORTVERSION=	2.0.0
CATEGORIES=	graphics devel
MASTER_SITES=	SAVANNAH/openexr/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	ILM Base libraries a.k.a. Half, IlmThread, Imath, and Iex

LICENSE=	BSD

CONFLICTS=	OpenEXR-1.[0-4].*

USES=		cmake pkgconfig
CMAKE_VERBOSE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog README

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
