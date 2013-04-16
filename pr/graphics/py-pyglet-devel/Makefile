# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	pyglet
PORTVERSION=	1.2
CATEGORIES=	graphics multimedia x11-toolkits python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${DISTVERSION}alpha1

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Cross-platform windowing and multimedia library for Python

LICENSE=	BSD

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GL=		gl glu
USE_OPENAL=	al
CONFLICTS=	py-pyglet-[0-9]*

PORTDOCS=	CHANGELOG NOTICE README
PYDISTUTILS_EGGINFO=	${DISTNAME}-py${PYTHON_VER}.egg-info

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -name '*.py' | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/include|${PREFIX}/include|g'
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
