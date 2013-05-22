# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD: head/graphics/mhgui/Makefile 302037 2012-08-04 22:52:02Z kwm $

PORTNAME=	mhgui
PORTVERSION=	0.2
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	SF/makehuman/MakeHuman%20Source/MakeHuman_091

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GUI widget library for MakeHuman

LICENSE=	GPLv2

LIB_DEPENDS=	animorph.0:${PORTSDIR}/graphics/animorph \
		png15:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		pkgconfig
USE_LDCONFIG=	yes
USE_XORG=	xi xmu ice sm
USE_GL=		glut

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS TODO

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^libmhguidocdir =/ s|doc/|share/doc/|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir =/ s|\$$(libdir)|\$$(exec_prefix)/libdata|' ${WRKSRC}/Makefile.in

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -i '' '/install-libmhguidocDATA: $$(libmhguidoc_DATA)/,/done/s/^/#/' \
		${WRKSRC}/Makefile.in
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -i '' '/libmhguidoc_DATA =/,/TODO/s/^/#/' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
