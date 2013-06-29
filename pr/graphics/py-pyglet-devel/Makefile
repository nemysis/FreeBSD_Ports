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
RUN_DEPENDS=	avbin>=0:${PORTSDIR}/multimedia/avbin

USE_PYTHON=	yes
USE_GL=		gl glu
USE_OPENAL=	al

PORTDOCS=	CHANGELOG NOTICE README
PORTEXAMPLES=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

PYDISTUTILS_EGGINFO=	${DISTNAME}-py${PYTHON_VER}.egg-info

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -name '*.py' | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/include|${PREFIX}/include|g'
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@(cd ${WRKSRC}/pyglet && ${COPYTREE_SHARE} . ${PREFIX}${PYTHON_SITELIBDIR:S|${LOCALBASE}||}/${PORTNAME}${PKGNAMESUFFIX})

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
