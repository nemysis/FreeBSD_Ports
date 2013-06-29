# Created by: Tim Cas <ports@stdrand.com>
# $FreeBSD: head/devel/ChipmunkPhysics/Makefile 320626 2013-06-11 18:44:16Z rakuco $

PORTNAME=	ChipmunkPhysics
PORTVERSION=	6.1.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://chipmunk-physics.net/release/Chipmunk-6.x/ \
		http://files.slembcke.net/chipmunk/release/Chipmunk-6.x/ \
		http://files.libsiege.org/chipmunk/
DISTNAME=	Chipmunk-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@stdrand.com
COMMENT=	2D physics engine written in C

LICENSE=	MIT

USES=		cmake
USE_GL=		glut
USE_XORG=	x11 xext xmu
CMAKE_VERBOSE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	README.textile VERSION.txt
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES DEMOS
DEMOS_DESC=	Install Demos programs
OPTIONS_DEFAULT=	DEMOS

.include <bsd.port.options.mk>

PLIST_SUB=	MAJORVER=6.1.5

.if ${PORT_OPTIONS:MDEMOS}
PLIST_SUB+=	DEMOS=""
.else
CMAKE_ARGS=	-DBUILD_DEMOS=OFF
PLIST_SUB+=	DEMOS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDEMOS}
	${INSTALL_PROGRAM} ${WRKSRC}/Demo/chipmunk_demos ${PREFIX}/bin
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
