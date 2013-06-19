# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	glfw
PORTVERSION=	3.0.1
CATEGORIES=	graphics
MASTER_SITES=	SF
PKGNAMESUFFIX=	3

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Portable framework for OpenGL development

LICENSE=	ZLIB

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		drm:${PORTSDIR}/graphics/libdrm

USE_BZIP2=	yes
USES=		cmake
USE_XORG=	x11 xau xcb xdamage xdmcp xext xfixes xi xrandr xrender xxf86vm
USE_GL=		glu
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.md

DOCSRCDIR2=	${WRKSRC}/docs/html/search
DOCSDIR2=	${DOCSDIR}/docs/html/search
DOC_FILES2=	*

DOCSRCDIR3=	${WRKSRC}/docs/html
DOCSDIR3=	${DOCSDIR}/docs/html
DOC_FILES3=	*.html *.png *.css *.js

PORTEXAMPLES=	*

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

EXAMPLESSRCDIR1=	${WRKSRC}/examples
EXAMPLES_FILES1=	boing gears heightmap simple splitview wave

EXAMPLESSRCDIR2=	${WRKSRC}/tests
EXAMPLESDIR2=		${EXAMPLESDIR}/tests
EXAMPLES_FILES2=	accuracy clipboard defaults events fsaa  gamma glfwinfo iconify \
			joysticks modes peter reopen sharing tearing threads title windows

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${DOCSDIR3}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES1:S|^|${EXAMPLESSRCDIR1}/|} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR2}
	${INSTALL_PROGRAM} ${EXAMPLES_FILES2:S|^|${EXAMPLESSRCDIR2}/|} ${EXAMPLESDIR2}
.endif

.include <bsd.port.mk>
