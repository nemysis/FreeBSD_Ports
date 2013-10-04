# Created by: Tim Cas <ports@stdrand.com>
# $FreeBSD: head/devel/ChipmunkPhysics/Makefile 327726 2013-09-20 17:17:44Z bapt $

PORTNAME=	ChipmunkPhysics
PORTVERSION=	6.2.0
CATEGORIES=	devel
MASTER_SITES=	http://chipmunk-physics.net/release/Chipmunk-6.x/ \
		http://files.slembcke.net/chipmunk/release/Chipmunk-6.x/
DISTNAME=	Chipmunk-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@stdrand.com
COMMENT=	2D physics engine written in C

BUILD_DEPENDS=	${LOCALBASE}/lib/libglfw.a:${PORTSDIR}/graphics/glfw

LICENSE=	MIT

USES=		cmake
USE_GL=		glew
USE_XORG=	x11 xext xmu
USE_LDCONFIG=	yes

PORTDOCS=	README.textile VERSION.txt
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DEMOS DOCS EXAMPLES
DEMOS_DESC=	Install Demos programs
OPTIONS_DEFAULT=	DEMOS

OPTIONS_SUB=	yes

DEMOS_CMAKE_ON=		-DBUILD_DEMOS=ON
DEMOS_CMAKE_OFF=	-DBUILD_DEMOS=OFF

.include <bsd.port.options.mk>

PLIST_SUB+=	MAJORVER=6.2.0

post-install:
.if ${PORT_OPTIONS:MDEMOS}
	${INSTALL_PROGRAM} ${WRKSRC}/Demo/chipmunk_demos ${STAGEDIR}${PREFIX}/bin/
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
