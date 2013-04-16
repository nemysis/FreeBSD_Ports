# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD: head/graphics/pure-gl/Makefile 302037 2012-08-04 22:52:02Z kwm $

PORTNAME=	pure-gl
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	graphics
#MASTER_SITES	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
MASTER_SITES=	https://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface to OpenGL

LICENSE=	BSD

USES=		pure:ffi
USE_GL=		glut

MAKE_ARGS+=	LinkGL="-lglut -lGLU -lGL"

PORTDOCS=	README
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
